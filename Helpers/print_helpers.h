#ifndef PRINT_HELPERS_H
#define PRINT_HELPERS_H

#include <iterator>
#include <iostream>
#include <iomanip>
#include "etypes.h"
#include "globals.h"
#include "music_style_helpers.h"

template<typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &v) {
    s << '[';
    if (!v.empty()) {
        std::copy(v.cbegin(), v.cend() - 1, std::ostream_iterator<T>(s, ", "));
        s << v.back();
    }
    return s << ']';
}


std::ostream &operator<<(std::ostream &s, const DataVector &v) {
    s << '[';
    if (!v.empty()) {
        std::copy(v.cbegin(), v.cend() - 1, std::ostream_iterator<real>(s, ", "));
        s << v.back();
    }
    return s << ']';
}

template<typename T, size_t SIZE>
std::ostream &operator<<(std::ostream &s, const std::array<T, SIZE> &a) {
    s << '[';
    if (!a.empty()) {
        std::copy(a.cbegin(), a.cend() - 1, std::ostream_iterator<T>(s, ", "));
        s << a.back();
    }
    return s << ']';
}

void print_confusion_matrix(std::vector<std::vector<int>> confusion_matrix) {
  std::cout << "          ";
  for (std::size_t i=0; i<CLASS_N; i++) {
    std::cout << std::setfill(' ') << std::setw(10) << music_style_to_string(music_style_from_int(i));
  }
  std::cout << std::endl;

  int i=0;
  for (std::vector<int> known_class : confusion_matrix) {
    std::cout << std::setfill(' ') << std::setw(10) << music_style_to_string(music_style_from_int(i));
    for (int hits : known_class) {
      std::cout << std::setfill(' ') << std::setw(10) << hits;
    }
    i++;
    std::cout << std::endl;
  }
}

#endif //PRINT_HELPERS_H
