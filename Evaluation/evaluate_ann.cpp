#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <fstream>
#include <filesystem>
#include "../Helpers/globals.h"
#include "../Helpers/music_style_helpers.h"
#include "../ANN/prediction_ann.cpp"

// File containing the path of all testing files
const std::string path_list_test = "./DATA/file_list_test.txt";

// Extracted features of the testing files
const std::string path_features_testing = "./DATA/features_testing.csv";

int main() {
  std::ifstream features_testing(path_features_testing);

  // load weights and biases for all layers in the neural network
  std::vector<std::vector<std::vector<double>>> ann_model = load_ann_model();

  // load testing features
  std::string temp_str, header, music_type, filename;

  std::getline(features_testing, header);

  int count_hits = 0;
  int total_read = 0;

  while (std::getline(features_testing, temp_str)) {
    std::vector<double> feature_vector;

    std::stringstream ss(temp_str);
    std::string feat_val;

    for (std::size_t i=0; i<N; i++) {
      std::getline(ss, feat_val, ',');
      feature_vector.push_back(std::stod(feat_val));
    }

    std::getline(ss, music_type, ',');
    std::getline(ss, filename, ',');

    // remove quotation marks
    music_type.pop_back();
    music_type.erase(0,2);

    int prediction = ann_predict(feature_vector, ann_model);

    std::cout << "Read file -> " << filename << std::endl;
    std::cout << "Music type: " << music_style_from_string(music_type) << " | Prediction: " << music_style_from_int(prediction);
    std::cout << " --> " << (music_style_from_int(prediction) == music_style_from_string(music_type) ? "Correct" : "Wrong") << std::endl << std::endl;

    if (music_style_from_int(prediction) == music_style_from_string(music_type))
      count_hits += 1;

    total_read += 1;
  }

  std::cout << std::endl << "ANN accuracy: " << (float) count_hits / (float) total_read << std::endl;

  return 0;
}