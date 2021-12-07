#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../Helpers/globals.h"
#include "predict_cart.cpp"

int main() {

  std::ifstream paths_file("../data/test_paths.txt");




  for (auto file: files) {
    std::cout << "feading --> " << file.filename() << std::endl;
    auto data = read_csv(file);
  }

  return 0;
}
