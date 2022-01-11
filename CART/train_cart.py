#!/usr/bin/env python3

import pandas as pd
from matplotlib import pyplot as plt
from sklearn import tree
from sklearn.metrics import ConfusionMatrixDisplay, confusion_matrix
from sklearn.model_selection import train_test_split
import graphviz
from CART import *

# Extract dataset training
dataset = './DATA/features_training.csv'
#dataset = '../DATA/features_prof.csv'
crop_df = pd.read_csv(dataset, header=0)

print("Head training:\n", crop_df.head)

Y_train = crop_df.Style.values
features = crop_df.columns.values[:-2]
crop_df = crop_df.drop('Style', axis=1)
crop_df = crop_df.drop('FileName', axis=1)
X_train = crop_df.values
classes = np.unique(Y_train)

print(features, classes)
print("Nb classes:", classes.shape)

# Extract dataset testing
dataset = './DATA/features_testing.csv'
crop_df = pd.read_csv(dataset, header=0)

print("Head testing:\n", crop_df.head)

Y_test = crop_df.Style.values
features = crop_df.columns.values[:-2]
crop_df = crop_df.drop('Style', axis=1)
crop_df = crop_df.drop('FileName', axis=1)
X_test = crop_df.values

# TRAIN/TEST SPLIT
#X_train, X_test, Y_train, Y_test = train_test_split(X_train, Y_train, test_size=0.33, random_state=42)
#print("Splitting test, train", X_train.shape, X_test.shape)

# My CART_TREES TREE
print("Training !")
myclassifier = CartTree(max_depth=12);
myclassifier.fit(X_train, Y_train)
print(myclassifier)
myclassifier.generate_prefict_cpp()

# SKLEARN CART_TREES TREE
clf = tree.DecisionTreeClassifier(random_state=None, max_depth=12)
clf = clf.fit(X_train, Y_train)

dot_data = tree.export_graphviz(clf,
                                out_file=None,
                                feature_names=features,
                                class_names=classes,
                                filled=True,
                                rounded=True,
                                special_characters=True)
graph = graphviz.Source(dot_data)
graph.render("./CART/Crop recommandations")

# PREDICTIONS
Y_pred = myclassifier.predict(X_test)
print(confusion_matrix(Y_test, Y_pred, labels=classes))
ConfusionMatrixDisplay.from_predictions(Y_test, Y_pred, display_labels=classes)
plt.title("My predictions")
plt.show()

Y_pred = clf.predict(X_test)
ConfusionMatrixDisplay.from_predictions(Y_test, Y_pred, display_labels=classes)
plt.title("SKLEARN")
plt.show()
