# build evaluation code
cmake -S Evaluation -B build
make -C build

# execute cart evaluation
./build/EVALUATION_CART
