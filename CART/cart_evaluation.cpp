#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include "../Helpers/globals.h"
#include "../Extraction/features_extraction.h"
#include "music_styles.cpp"


int main() {
  std::ifstream paths_testing_files("../data/test_paths.txt");
  std::vector<std::filesystem::path> testing_files;
  std::string temp_str;

  while (std::getline(paths_testing_files, temp_str)) {
    testing_files.push_back(temp_str);
  }

  auto all_features = compute_set_of_features(testing_files, "features_testing.csv", false);

  int count_hits = 0;

  for (auto it = all_features.begin(); it != all_features.end(); it+=1) {
    std::string music_type = it->first.parent_path().filename();
    std::vector<double> feature_vector;

    for (auto const &entry: it->second)
       for (auto elem: entry.second)
         feature_vector.push_back(elem);

    std::string prediction = cart_predict(feature_vector);

    std::cout << "music type: " << music_type << " | prediction: " << prediction << " | good? " << !prediction.compare(music_type) << std::endl;

    if (!prediction.compare(music_type)) {
      count_hits += 1;
    }
  }

  std::cout << "hits: " << count_hits << std::endl;
  std::cout << "total: " << all_features.size() << std::endl;
  std::cout << "accuracy: " << (float) count_hits / (float) all_features.size() << std::endl;

  return 0;
}
