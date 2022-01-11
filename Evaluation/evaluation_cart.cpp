#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include "../Helpers/globals.h"
#include "../Extraction/features_extraction.h"
#include "../CART/music_styles_cart.h"


int main() {
  std::ifstream features_testing("./DATA/features_testing.csv");
//  std::ifstream features_testing("./DATA/features_prof.csv");

  std::vector<std::filesystem::path> testing_files;
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

    music_type.pop_back();
    music_type.erase(0,2);

    std::string prediction = cart_predict(feature_vector);

    std::cout << "Rad file -> " << filename << std::endl;
    std::cout << "Music type: " << music_type << " | Prediction: " << prediction << " --> " << (!prediction.compare(music_type) ? "Correct" : "Wrong") << std::endl << std::endl;

    if (!prediction.compare(music_type))
      count_hits += 1;

    total_read += 1;
  }

  std::cout << "accuracy: " << (float) count_hits / (float) total_read << std::endl;

  return 0;
}
