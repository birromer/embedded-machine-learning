#ifndef GLOBAL_H
#define GLOBAL_H

#include "etypes.h"

constexpr std::size_t N = 512;      // WINDOW SIZE
constexpr real Fs = 22050.0;        // SAMPLING FREQUENCY
const std::size_t FFT_SIZE = N / 2;
constexpr std::size_t CLASS_N = 10; // CLASS NUMBER
constexpr std::size_t FEAT_N = 512; // FEATURES NUMBER STFT (if AVG and STD)
constexpr std::size_t OVO_CLASS_N = CLASS_N * (CLASS_N - 1) / 2; // One Versus One CLASS NUMBER
constexpr std::size_t MEL_N = 26;
constexpr std::size_t MEL_FILTERS_N = MEL_N - 2;


//#define "blues" 1
//#define "classical" 2
//#define "country" 3
//#define "disco" 4
//#define "hiphop" 5
//#define "jazz" 6
//#define "metal" 7
//#define "pop" 8
//#define "reggae" 9
//#define "rock" 10

#endif //GLOBAL_H
