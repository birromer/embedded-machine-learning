cmake_minimum_required(VERSION 3.16)
project(EVALUATION)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -O3  -Wall -Wextra -ggdb -std=c++20")

add_executable(EVALUATION_CART
  ../Extraction/features_extraction.cpp
  ../Helpers/music_style_helpers.cpp
  evaluation_cart.cpp)

#add_executable(EVALUATION_RF
#  ../Extraction/features_extraction.cpp
#  ../Helpers/music_style_helpers.cpp
#  ../RF/music_style_rf.cpp
#  evaluation_rf.cpp)

add_executable(EVALUATION_SVM
  ../Extraction/features_extraction.cpp
  ../Helpers/music_style_helpers.cpp
  evaluation_svm.cpp)

#add_executable(EVALUATION_ANN
#  ../Extraction/features_extraction.cpp
#  ../Helpers/music_style_helpers.cpp
#  ../ANN/music_styles_ann.cpp
#  evaluation_ann.cpp)
