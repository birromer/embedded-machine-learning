#ifndef GLOBAL_H
#define GLOBAL_H
#include "etypes.h"

constexpr std::size_t N = 512;      // WINDOW SIZE
constexpr real Fs = 22050.0;        // SAMPLING FREQUENCY
const std::size_t FFT_SIZE = N / 2;
constexpr std::size_t CLASS_N = 10; // CLASS NUMBER
constexpr std::size_t FEAT_N = 512; // FEATURES NUMBER (if AVG and STD)
constexpr std::size_t OVO_CLASS_N = 45; // One Versus One CLASS NUMBER

#endif //GLOBAL_H
