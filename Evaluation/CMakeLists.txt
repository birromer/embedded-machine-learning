add_executable(EVALUATION_CART
  ../Extraction/features_extraction.cpp
  ../Helpers/music_style_helpers.cpp
  ../CART/music_styles_cart.cpp
  evaluation_cart.cpp)

#add_executable(EVALUATION_RF
#  ../Extraction/features_extraction.cpp
#  ../Helpers/music_style_helpers.cpp
#  ../RF/music_style_rf.cpp
#  evaluation_rf.cpp)

add_executable(EVALUATION_SVM
  ../Extraction/features_extraction.cpp
  ../Helpers/music_style_helpers.cpp
  ../SVM/music_styles_svm.cpp
  evaluation_svm.cpp)

#add_executable(EVALUATION_ANN
#  ../Extraction/features_extraction.cpp
#  ../Helpers/music_style_helpers.cpp
#  ../ANN/music_styles_ann.cpp
#  evaluation_ann.cpp)
