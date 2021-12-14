#!/usr/bin/env python3

import os
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.svm import LinearSVC
from sklearn.metrics import ConfusionMatrixDisplay, confusion_matrix
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler

DATA_DIR = "../data"
FEAT_TRAIN_FILE = "features_training.csv"
FEAT_TEST_FILE = "features_testing.csv"


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
    X_train, y_train, _ = load_data(FEAT_TRAIN_FILE)
    X_test, y_test, classes = load_data(FEAT_TEST_FILE)
    print("Loaded training and testing data.")

    # reduce the dimension and train
    svm_clf = Pipeline([
        ("scaler", StandardScaler()),
        ("linear_svc", LinearSVC(C=1.0, loss="hinge", max_iter=10000, verbose=1)),
    ])

    svm_clf.fit(X_train, y_train)
    print("Fit SVM model with train data.")

    print("shape X test:", X_test.shape)
    print("shape y test:", y_test.shape)

    prediction = svm_clf.predict(X_test)

    print("Confurion matrix:\n", confusion_matrix(y_test, prediction, labels=classes))

    print("Accuracy:", float(np.sum(prediction == y_test))/len(y_test))
