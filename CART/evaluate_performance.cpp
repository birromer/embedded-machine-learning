#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../Helpers/globals.h"
#include "predict_cart.cpp"

using namespace std;

int main() {


  for (auto file: files) {
    std::cout << "Reading --> " << file.filename() << std::endl;
    auto data = readAuFile(file);
    std::cout << "finished reading au file" << std::endl;
    auto features = stft(data);
    all_features.push_back(std::make_pair(file, features));
    std::cout << "Training parameters size --> " << features[FTYPE::BINAVG].size() << "x" << features[FTYPE::BINSTDEV].size() << std::endl;
  }

  return 0;
}
