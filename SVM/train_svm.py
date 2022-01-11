#!/usr/bin/env python3

import os
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.svm import LinearSVC
from sklearn.svm import SVC
from sklearn.metrics import ConfusionMatrixDisplay, confusion_matrix
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split

DATA_DIR = "./DATA"
FEAT_TRAIN_FILE = "features_training.csv"
FEAT_TEST_FILE = "features_testing.csv"
ALL_DATA_FILE = "features_prof.csv"
#ALL_DATA_FILE = "features.csv"

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

#    X, Y, classes = load_data(ALL_DATA_FILE)
#    X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.33, random_state=42)
#    print("Splitting test, train", X_train.shape, X_test.shape)

    print("Loaded training and testing data.")

    # reduce the dimension and train
    svm_clf = Pipeline([
        ("scaler", StandardScaler()),
        ("linear_svc", SVC(kernel='linear', class_weight='balanced', gamma=0.0001, C=1, decision_function_shape='ovo')),
#        ("linear_svc", LinearSVC(C=1.0, loss='hinge', verbose=0, max_iter=2000)),
    ])


    svm_clf.fit(X_train, y_train)
    print("Fit SVM model with train data.")

    print("shape X train:", X_train.shape)
    print("shape y train:", y_train.shape)

    print("shape X test:", X_test.shape)
    print("shape y test:", y_test.shape)

    predictions = svm_clf.predict(X_test)

    print("Confurion matrix:\n", confusion_matrix(y_test, predictions, labels=classes))

    ConfusionMatrixDisplay.from_predictions(y_test, predictions, display_labels=classes)
    plt.title("Predictions confusion matrix")
    plt.show()

    print("Accuracy:", float(np.sum(predictions == y_test))/len(y_test))

    # Save featues statistical data
    mean = svm_clf['scaler'].mean_  # mean value of each feature in the training set
    var = svm_clf['scaler'].var_    # variance of each feature in the training set
    mean = mean.reshape((len(mean),1))
    var = var.reshape((len(var),1))

    header = ['SVG{}'.format(i) for i in range(len(mean)+1)] + ['VAR{}'.format(i) for i in range(len(var)+1)]

    print("mean shape", mean.shape)
    print("var shape", var.shape)

    np.savetxt(os.path.join(DATA_DIR, 'svm_feat_stats.csv'), np.concatenate((mean,var), axis=0).T, header=','.join(header), delimiter=',', comments='')

    coef = svm_clf['linear_svc'].coef_  # feature weights in the learnt model
    bias = svm_clf['linear_svc'].intercept_  # bias in the decision function

    bias = bias.reshape((bias.shape[0], 1))

    print("coef shape", coef.shape)
    print("bias shape", bias.shape)

    header = ['COEF{}'.format(i) for i in range(coef.shape[1]+1)]+['BIAS']

    np.savetxt(os.path.join(DATA_DIR, 'svm_coeff.csv'), np.concatenate((coef,bias), axis=1), header=','.join(header), delimiter=',', comments='')
