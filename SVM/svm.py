#!/usr/bin/env python3

import os
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.svm import LinearSVC
from sklearn.metrics import ConfusionMatrixDisplay, confusion_matrix

DATA_DIR = "../data"
FEAT_TRAIN_FILE = "features_training.csv"
FEAT_TEST_FILE = "features_testing.csv"


def load_data(filename):
    data_path = os.path.join(DATA_DIR, filename)
    data_df = pd.read_csv(data_path, sep=',', header=0)

    Y = data_df.Style.values

    features = data_df.columns.values[:-2]
    data_df = data_df.drop('Style', axis=1)
    data_df = data_df.drop('FileName', axis=1)

    X = data_df.values

    return X, Y


if __name__ == "__main__":
    # load data
    X_train, Y_trian = load_data(FEAT_TRAIN_FILE)
    X_test, Y_test = load_data(FEAT_TEST_FILE)

    print(X_train)

    # reduce dimension of features

    # wat
    svm = LinearSVC(penalty='l2', loss='squared_hinge', dual=False,
                    multi_class='crammer_singer', )
