#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <fstream>
#include <filesystem>
#include "../Helpers/globals.h"
#include "../Helpers/music_style_helpers.h"
#include "../Extraction/features_extraction.h"
#include "../Helpers/au_reading.h"

// Learned SVM coefficients
const std::string path_svm_coeff = "../DATA/svm_coeff.csv";
const std::string path_svm_stats = "../DATA/svm_feat_stats.csv";

// File containing the path of all testing files
const std::string path_list_test = "../DATA/file_list_test.txt";

// Extracted features of the testing files
const std::string path_features_testing = "../DATA/features_testing.csv";

#define N_CLASSES 10

int get_val_class(std::string music_type);
std::string get_class_val(int music_type);
int svm_predict(std::vector<double> feat_vec, std::vector<std::vector<double>> duel_coeffs);
std::vector<std::vector<double>> load_svm_model();

int main() {
  std::ifstream features_testing(path_features_testing);

  // svm model for all 1v1 duels
  std::vector<std::vector<double>> svm_model = load_svm_model();
  std::cout << "Loaded SVM model" << std::endl;

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


    int prediction = svm_predict(feature_vector, svm_model);
    std::cout << "prediction: " << prediction << std::endl;

    std::cout << "Read file -> " << filename << std::endl;
    std::cout << "Music type: " << music_style_from_string(music_type) << " | Prediction: " << music_style_from_int(prediction);
    std::cout << " --> " << (music_style_from_int(prediction) == music_style_from_string(music_type) ? "Correct" : "Wrong") << std::endl << std::endl;

    if (music_style_from_int(prediction) == music_style_from_string(music_type))
      count_hits += 1;

    total_read += 1;
  }

  std::cout << "Accuracy: " << (float) count_hits / (float) total_read << std::endl;

  return 0;
}

std::vector<std::vector<double>> load_svm_model() {
  std::ifstream svm_coeffs(path_svm_coeff);
  std::string temp_str, header, bias, filename;

  std::getline(svm_coeffs, header);

  std::vector<std::vector<double>> duel_coeffs;  // where all 1v1 classifies are stored

  while (std::getline(svm_coeffs, temp_str)) {
    std::vector<double> coeffs_vector;  // where each 1v1 classifier is stored

    std::stringstream ss(temp_str);
    std::string coeff_val;

    // store the coefficients for each feature dimension on the duel
    for (std::size_t i=0; i<N; i++) {
      std::getline(ss, coeff_val, ',');
      coeffs_vector.push_back(std::stod(coeff_val));
    }

    // the last coeff is the bias value
    std::getline(ss, coeff_val, ',');
    coeffs_vector.push_back(std::stod(coeff_val));

    duel_coeffs.push_back(coeffs_vector);
  }

  return duel_coeffs;
}

int svm_predict(std::vector<double> feat_vec, std::vector<std::vector<double>> duel_coeffs) {
  std::vector<double> Y;

  // apply Y = A@X + B, where A has the coefficients (coef_),
  // B has the bias (intercept_) and X is the features vector

  // perform each of the 45 duels
  for (std::vector<double> duel : duel_coeffs) {
    // matrix multiplication, line by line
    double y_n = std::inner_product(feat_vec.begin(), feat_vec.end(), duel.begin(), 0);
    y_n +=  duel[-1]; // add bias
    Y.push_back(y_n);
  }

  // we'll have a 45x1 vector (10x9/2 classes) with all duels on
  // the 1v1 classifier, must choose the one that wins the most
  // they are in the order 0v1, 0v2, 0v3, ..., NvN-1

  // counter of duels won by each class
  // index 0 stores the values for the last class
  std::vector<int> duels_score( N_CLASSES, 0);

  int i = 0;
  for (int p1 = 0; p1 < N_CLASSES; p1++) {
    for (int p2 = p1+1; p2 < N_CLASSES; p2++) {
      duels_score[p1] += Y[i];
      duels_score[p2] -= Y[i];
      i++;
    }
  }

  int argmax = std::max_element(duels_score.begin(), duels_score.end()) - duels_score.begin();

//  int argmax = std::max_element(Y.begin(), Y.end()) - Y.begin();

  return argmax;
}
