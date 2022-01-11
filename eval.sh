# build evaluation code
mkdir -p build/eval
cmake -S Evaluation -B build/eval
make -C build/eval

# execute cart evaluation
./build/eval/EVALUATION_CART
