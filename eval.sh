# build evaluation code
mkdir -p build/eval
cmake -S Evaluation -B build/eval -DUSE_TESTS_FILE=OFF -DVERBOSE=OFF
make -C build/eval

# CART evaluation
./build/eval/EVALUATION_CART

# SVM evaluation
./build/eval/EVALUATION_SVM

# ANN evaluation
./build/eval/EVALUATION_ANN
