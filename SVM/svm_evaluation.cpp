#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <fstream>
#include <filesystem>
#include "../Helpers/globals.h"
#include "../Extraction/features_extraction.h"

const std::string path_svm_coeff = "../data/svm_coeff.csv";
const std::string path_svm_stats = "../data/svm_feat_stats.csv";
const std::string path_features_testing = "../data/features_testing.csv";


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

std::string svm_predict(std::vector<double> feat_vec, std::vector<std::vector<double>> duel_coeffs) {

  std::vector<double> Y;

  // apply Y = A@X + B where
  // A has the coefficients (coef_)
  // B has the bias (intercept_)
  // X is the features vector

  // perform each of the 45 duels
  for (int i=0; i<duel_coeffs.size(); i++) {
    // matrix multiplication line by line
    double y_n = std::inner_product(duel_coeffs[i].begin(), duel_coeffs[i].end()-1, feat_vec, 0);
    y_n +=  duel_coeffs[i][-1]; // add bias
    Y.push_back(y_n);
  }

  // we'll have a 45x1 vector (10x9/2 classes)
  // with all duels on the 1v1 classifiers
  // must choose the one that wins the most

  std::cout << "Y: ";
  for (auto y : Y) {
    std::cout << y << " ";
  }

}

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

    std::string prediction = svm_predict(feature_vector, svm_model);

//    std::cout << "Rad file -> " << filename << std::endl;
//    std::cout << "Music type: " << music_type << " | Prediction: " << prediction << " --> " << (!prediction.compare(music_type) ? "Correct" : "Wrong") << std::endl << std::endl;

//    if (!prediction.compare(music_type))
//      count_hits += 1;

//    total_read += 1;
  }

  std::cout << "accuracy: " << (float) count_hits / (float) total_read << std::endl;

  return 0;
}
