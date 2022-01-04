cmake_minimum_required(VERSION 3.16)
project(EML)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -O3  -Wall -Wextra -ggdb -std=c++20")

add_subdirectory(Extraction)
add_subdirectory(CART)
add_subdirectory(SVM)
#add_subdirectory(RF)
#add_subdirectory(ANN)
