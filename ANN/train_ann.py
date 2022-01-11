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
    model=tf.keras.Sequential()
    model.add(tf.keras.layers.Dense(256, activation='relu', input_dim=X.shape[1]))
    model.add(tf.keras.layers.Dense(64, activation='relu'))
    model.add(tf.keras.layers.Dense(nb_classes, activation='softmax'))
    return model


if __name__ == "__main__":
    X, Y, classes = load_data(FEAT_TRAIN_FILE) #features, label, vector of the classes
    unq,tags = np.unique(Y, return_inverse=True)
    dict(zip(range(len(unq)),unq))
    Y=tags
    #Y = encName2Ind.transform(Y)
    print(Y)
    #ds_train = tf.data.Dataset.from_tensor_slices((X, Y))

    model = model_generator(X)
    #model.summary()
    #optimizer = keras.optimizers.SGD(learning_rate=0.001, momentum=0.9, decay=0.01)
    optimizer = keras.optimizers.RMSprop(0.0001)
    model.compile(loss="sparse_categorical_crossentropy", optimizer=optimizer,
                  metrics=["accuracy"])
    history = model.fit(X, Y, epochs=nb_epochs, validation_split = 0.4)
