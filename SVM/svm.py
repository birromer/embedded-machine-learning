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

def load_parameters(filename):
    pass

if __name__ == "__main__":
    feat_train_path = os.path.join(DATA_DIR, FEAT_TRAIN_FILE)
