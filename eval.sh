# build evaluation code
mkdir -p build/eval
cmake -S Evaluation -B build/eval
make -C build/eval

# CART evaluation
./build/eval/EVALUATION_CART

# SVM evaluation
./build/eval/EVALUATION_SVM

# ANN evaluation
./build/eval/EVALUATION_ANN
