import tensorflow as tf
import tensorflow.keras as keras
from tensorflow.keras import datasets, layers, models
from keras.models import Sequential
import os
import numpy as np
import pandas as pd
from sklearn import preprocessing

input_shape = (512, 1)
nb_classes = 10
nb_epochs = 100

DATA_DIR = "./DATA"
FEAT_TRAIN_FILE = "features_training.csv"
FEAT_TEST_FILE = "features_testing.csv"
ANN_WEIGHTS_FILE = "ann_weights.txt"


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
    model.add(tf.keras.layers.Dense(256, activation='relu', input_dim=X.shape[1]))
    model.add(tf.keras.layers.Dense(64, activation='relu'))
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

    print("Generating weights file")
    with open(os.path.join(DATA_DIR, ANN_WEIGHTS_FILE), "w+") as f_ann:

        f_ann.write("{}\n".format(len(model.layers)))  # first line shows how many layers are there to read
        # export the trained weights
        for i,layer in enumerate(model.layers):
            print("Layer", i)

            weights = layer.get_weights()[0]
            bias = layer.get_weights()[1]

            # start each layer with the shape of the matrix representing it
            # always assuming last column will be composed of the bias
            f_ann.write("{} {}\n".format(weights.shape[0], weights.shape[1]+1))

            for w,b in zip(weights,bias):
                # store the matrix line by line
                line = ",".join(map(str,w)) + ",{}\n".format(b)
                f_ann.write(line)

    print("Finished saving model")
