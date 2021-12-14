#!/usr/bin/env python3

import os
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.svm import LinearSVC
from sklearn.metrics import ConfusionMatrixDisplay, confusion_matrix
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

DATA_DIR = "../data"
FEAT_TRAIN_FILE = "features_training.csv"
FEAT_TEST_FILE = "features_testing.csv"
ALL_DATA_FILE = "features_prof.csv"

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


if __name__ == "__main__":
    # load data
#    X_train, y_train, _ = load_data(FEAT_TRAIN_FILE)
#    X_test, y_test, classes = load_data(FEAT_TEST_FILE)

    X, Y, classes = load_data(ALL_DATA_FILE)
#    X, Y, classes = load_data(FEAT_TRAIN_FILE)
    X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.33, random_state=42)
    print("Splitting test, train", X_train.shape, X_test.shape)

    print("Loaded training and testing data.")

    # reduce the dimension and train
    svm_clf = Pipeline([
        ("scaler", StandardScaler()),
        ("linear_svc", LinearSVC(C=1.0, loss="hinge", verbose=1)),
    ])

    svm_clf.fit(X_train, y_train)
    print("Fit SVM model with train data.")

    print("shape X test:", X_test.shape)
    print("shape y test:", y_test.shape)

    predictions = svm_clf.predict(X_test)

    print("Confurion matrix:\n", confusion_matrix(y_test, predictions, labels=classes))

    ConfusionMatrixDisplay.from_predictions(y_test, predictions, display_labels=classes)
    plt.title("Predictions confusion matrix")
    plt.show()

    print("Accuracy:", float(np.sum(predictions == y_test))/len(y_test))
