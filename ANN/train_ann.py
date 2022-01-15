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

input_shape = (512, 1)
nb_classes = 10
nb_epochs = 100

DATA_DIR = "./DATA"
FEAT_TRAIN_FILE = "features_training.csv"
FEAT_TEST_FILE = "features_testing.csv"
ANN_WEIGHTS_FILE = "ann_weights.txt"

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
    X_train, Y_train, classes = load_data(FEAT_TRAIN_FILE)  # features, label, vector of the classes
    X_test, Y_test, _ = load_data(FEAT_TEST_FILE)

    unq, tags = np.unique(Y_train, return_inverse=True)
    Y_train = tags

    unq, tags = np.unique(Y_test, return_inverse=True)
    Y_test = tags

    #Y = encName2Ind.transform(Y)
    print(Y_train)

    #ds_train = tf.data.Dataset.from_tensor_slices((X, Y))

    model = model_generator(X_train)
    model.summary()

    #optimizer = keras.optimizers.SGD(learning_rate=0.001, momentum=0.9, decay=0.01)
    optimizer = keras.optimizers.RMSprop(0.0001)

    model.compile(loss="sparse_categorical_crossentropy",
                  optimizer=optimizer,
                  metrics=["accuracy"]
                  )

    history = model.fit(X_train, Y_train, epochs=nb_epochs, validation_split=0.4)

    learningCurves(history.history, "learning curves")

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

    print("Finished saving model")
