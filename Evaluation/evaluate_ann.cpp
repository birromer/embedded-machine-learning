#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <fstream>
#include <filesystem>
#include "../Helpers/globals.h"
#include "../Helpers/print_helpers.h"
#include "../Helpers/music_style_helpers.h"
#include "../ANN/prediction_ann.cpp"

using namespace std;

// File containing the path of all testing files
const string path_list_test = "./DATA/file_list_test.txt";

// Extracted features of the testing files
string path_features_testing = "./DATA/features_testing.csv";

int main() {
  // load weights and biases for all layers in the neural network
  vector<vector<vector<double>>> ann_model = load_ann_model();
  vector<vector<double>> ann_stats = load_ann_stats();

  int count_hits = 0;
  int total_read = 0;

  // each line is a known class, each column is the predictions that should have been the same as the line
  vector<vector<int>> confusion_matrix(CLASS_N, vector<int>(CLASS_N, 0));

  #ifdef VERBOSE
  bool verbose = true;
  #endif

  #ifndef VERBOSE
  bool verbose = false;
  #endif

  #ifdef USE_TESTS_FILE
  cout << endl << "Extracting features from paths in file: " << path_list_test << endl;

  ifstream paths_testing_files(path_list_test);
  vector<filesystem::path> testing_files;
  string temp_str;

  while (getline(paths_testing_files, temp_str)) {
    testing_files.push_back(temp_str);
  }

  auto all_features = compute_set_of_features(testing_files, path_features_testing, verbose);

  for (auto it = all_features.begin(); it != all_features.end(); it+=1) {
    string music_type = it->first.parent_path().filename();
    vector<double> feature_vector;

    for (auto const &entry: it->second)
       for (auto elem: entry.second)
         feature_vector.push_back(elem);
  #endif

  #ifndef USE_TESTS_FILE
  cout << endl << "Using extracted testing features:" << path_features_testing << endl;
  ifstream features_testing(path_features_testing);

  // load testing features
  string temp_str, header, music_type, filename;

  getline(features_testing, header);

  while (getline(features_testing, temp_str)) {
    vector<double> feature_vector;

    stringstream ss(temp_str);
    string feat_val;

    for (size_t i=0; i<N; i++) {
      getline(ss, feat_val, ',');
      feature_vector.push_back(stod(feat_val));
    }

    getline(ss, music_type, ',');
    getline(ss, filename, ',');

    // remove quotation marks
    music_type.pop_back();
    music_type.erase(0,2);

    if (verbose)
      cout << "Read file -> " << filename << endl;
    #endif

    feature_vector = normalize(feature_vector, ann_stats[0], ann_stats[1]);

    int prediction = ann_predict(feature_vector, ann_model);

    MUSIC_STYLE pred = music_style_from_int(prediction);
    MUSIC_STYLE truth = music_style_from_string(music_type);

    #ifdef VERBOSE
    cout << "Music type: " << music_type << " | Prediction: " << music_style_to_string(pred);
    cout << " --> " << (pred == truth ? "Correct" : "Wrong") << endl << endl;
    #endif

    if (pred == truth)
      count_hits += 1;

    confusion_matrix[(int)truth][(int)pred] += 1;

    total_read += 1;
  }

  cout << "ANN accuracy: " << (float) count_hits / (float) total_read << endl;
  cout << "Confusion matrix:" << endl;

  #ifdef VERBOSE
  print_confusion_matrix(confusion_matrix);
  #endif

  #ifndef VERBOSE
  for (vector<int> known_class : confusion_matrix) {
    for (int hits : known_class) {
      cout << setfill(' ') << setw(3) << hits;
    }
    cout << endl;
  }
  #endif

  return 0;
}
