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

// Learned SVM coefficients
const std::string path_svm_coeff = "./DATA/svm_coeff.csv";
const std::string path_svm_stats = "./DATA/svm_feat_stats.csv";

#define N_CLASSES 10

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
    // matrix multiplication, line by line, base value of the sum being the bias
    // this can be done without extra steps as the function respects the size of the first parameters
    // letting the bias be present without being used in the main sum
    double y_n = std::inner_product(feat_vec.begin(), feat_vec.end(), duel.begin(), *(duel.end()-1));
    Y.push_back(y_n);
  }

  // we'll have a 45x1 vector (10x9/2 classes) with all duels on
  // the 1v1 classifier, must choose the one that wins the most
  // they are in the order 0v1, 0v2, 0v3, ..., NvN-1

  // counter of duels won by each class
  std::vector<int> duels_score( N_CLASSES, 0);

  int i = 0;
  for (int p1 = 0; p1 < N_CLASSES; p1++) {
    for (int p2 = p1+1; p2 < N_CLASSES; p2++) {

      if (Y[i] > 0) {
        duels_score[p1]++;
      } else {
        duels_score[p2]++;
      }

      i++;
    }
  }

  // gets the position of the maximum value with iterator arithmetic
  int argmax = std::max_element(duels_score.begin(), duels_score.end()) - duels_score.begin();

  return argmax;
}
