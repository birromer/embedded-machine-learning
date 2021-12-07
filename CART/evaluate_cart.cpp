#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

#include "../Helpers/globals.h"
#include "predict_cart.cpp"

std::vector<double> read_csv(std::filesystem::path) {

}

int main() {

  std::ifstream paths_file("../data/test_paths.txt");
  std::vector<std::filesystem::path> files;


  for (auto file: files) {
    std::cout << "feading --> " << file.filename() << std::endl;
    auto data = read_csv(file);
  }

  return 0;
}
