import tensorflow as tf
import tensorflow.keras as keras
from sklearn.metrics import confusion_matrix, classification_report
from tensorflow.keras import datasets, layers, models
from keras.models import Sequential
import os
import numpy as np
import pandas as pd
from sklearn import preprocessing
import matplotlib.pyplot as plt
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

input_shape = (512, 1)
nb_classes = 10
nb_epochs = 100

DATA_DIR = "./DATA"
FEAT_TRAIN_FILE = "features_training.csv"
FEAT_TEST_FILE = "features_testing.csv"
ANN_WEIGHTS_FILE = "ann_weights.txt"
ANN_STATS_FILE = "ann_stats.txt"

def learningCurves(history,title):
    f, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 5))
    t = f.suptitle(title, fontsize=12)
    f.subplots_adjust(top=0.85, wspace=0.3)

    epochs = list(range(1,nb_epochs+1))
    ax1.plot(epochs, history['accuracy'], label='Train Accuracy')
    ax1.plot(epochs, history['val_accuracy'], label='Validation Accuracy')
    ax1.set_xticks(epochs)
    ax1.set_ylabel('Accuracy Value')
    ax1.set_xlabel('Epoch')
    ax1.set_title('Accuracy')
    ax1.legend()

    ax2.plot(epochs, history['loss'], label='Train Loss')
    ax2.plot(epochs, history['val_loss'], label='Validation Loss')
    ax2.set_xticks(epochs)
    ax2.set_ylabel('Loss Value')
    ax2.set_xlabel('Epoch')
    ax2.set_title('Loss')
    ax2.legend()
    plt.plot()


def load_data(filename):
    data_path = os.path.join(DATA_DIR, filename)
    data_df = pd.read_csv(data_path, sep=',', header=0)

    y = data_df.Style.values
    classes = np.unique(y)

    features = data_df.columns.values[:-2]
    data_df = data_df.drop('Style', axis=1)
    data_df = data_df.drop('FileName', axis=1)

    X = data_df.values

    return X, y, classes


def model_generator(X):
    model = tf.keras.Sequential()
    model.add(tf.keras.layers.Dense(64, activation='relu', input_dim=X.shape[1]))
    model.add(tf.keras.layers.Dense(32, activation='relu'))
    model.add(tf.keras.layers.Dense(nb_classes, activation='softmax'))
    return model


if __name__ == "__main__":

    #splitting train, test and classes
    X_test, Y_test, classes = load_data(FEAT_TEST_FILE)  # features, label, vector of the classes

    scaler = StandardScaler()
    scaler.fit(X_test)

    X_train, Y_train, _ = load_data(FEAT_TRAIN_FILE)
    X_train, X_val, Y_train, Y_val = train_test_split(X_train, Y_train, test_size=0.25)

    #labels
    unq, tags = np.unique(Y_train, return_inverse=True)
    Y_train = tags
    unq, tags = np.unique(Y_test, return_inverse=True)
    Y_test = tags
    unq, tags = np.unique(Y_val, return_inverse=True)
    Y_val = tags

    # Normalisation
    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train)  # learn the mean and var from training set
    X_val = scaler.transform(X_val)          # and apply to the other ones
    X_test = scaler.transform(X_test)

    # defining model
    model = keras.models.Sequential([
        keras.layers.Dense(units=256, activation='relu', input_dim=X_train.shape[1]), # kernel_regularizer=tf.keras.regularizers.L2(l2=0.5)),
        keras.layers.Dense(units=64, activation='relu'),
        keras.layers.Dense(units=32, activation='relu'),
        keras.layers.Dense(units=10, activation='softmax')])
#    model = model_generator(X_train)

    optimizer = keras.optimizers.Adam(learning_rate=0.0001)

    model.compile(loss="sparse_categorical_crossentropy",
                  optimizer=optimizer, metrics=["accuracy"])

    history = model.fit(X_train, Y_train, validation_data=(X_val, Y_val), epochs=100)

    # evaluation
    result = model.evaluate(x=X_test, y=Y_test)

    # architecture
    model.summary()

    # curves
    learningCurves(history.history, "learning curves")
    plt.show()

    # confusion matrix result
    predictions = model.predict(X_test)
    matrix = confusion_matrix(Y_test, predictions.argmax(axis=1))
    print("\nConfusion Matrix:")
    print(matrix)

    print("predictions:", predictions[:5].argmax(axis=1))
    print("Y_test:", Y_test[:5])
    print("Accuracy:", float(np.sum(predictions.argmax(axis=1) == Y_test))/len(Y_test))

    print("Generating weights file")
    with open(os.path.join(DATA_DIR, ANN_WEIGHTS_FILE), "w+") as f_ann:

        f_ann.write("{}\n".format(len(model.layers)))  # first line shows how many layers are there to read
        # export the trained weights
        for i,layer in enumerate(model.layers):
            weights = layer.get_weights()[0]
            bias = layer.get_weights()[1]

            # start each layer with the shape of the matrix representing it
            # always assuming last column will be composed of the bias
            # e.g. in a layer with 512 inputs and 64 neurons,
            # it will be a matrix with 64 lines and 513 columns, each line
            # representing the processing in a single neuron
            f_ann.write("{} {}\n".format(weights.shape[1], weights.shape[0]+1))

            for i,w in enumerate(weights.T):
                # store the matrix line by line
                line = ",".join(map(str,w)) + ",{}\n".format(bias[i])
                f_ann.write(line)

    print("Generating normalization stats file")
    with open(os.path.join(DATA_DIR, ANN_STATS_FILE), "w+") as f_stats:
        mean, stddev = scaler.mean_, scaler.scale_
        mean = mean.reshape((len(mean),1))
        stddev = stddev.reshape((len(stddev),1))
        header = ['AVG{}'.format(i) for i in range(len(mean)+1)] + ['STDDEV{}'.format(i) for i in range(len(stddev)+1)]

        print("mean shape", mean.shape)
        print("stddev shape", stddev.shape)

        np.savetxt(f_stats, np.concatenate((mean,stddev), axis=0).T, header=','.join(header), delimiter=',', comments='')

    print("Finished saving model")
