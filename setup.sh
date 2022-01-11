# build feature extraction
mkdir -p build/setup
cmake -S Extraction -B build/setup  # "Extraction" may be replaced by the desired module or . for the entire project
make -C build/setup

# extract features
./build/setup/EXTRACTION

# train cart tree
python3 CART/train_cart.py

# train svm model
python3 SVM/train_svm.py

# train ann
python3 ANN/train_ann.py
