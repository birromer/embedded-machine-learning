# build feature extraction
mkdir -p build
cmake -S Extraction -B build  # "Extraction" may be replaced by the desired module or . for the entire project
make -C build

# extract features
./build/EXTRACTION

# train cart tree
python3 CART/train_cart.py

# train svm model
python3 SVM/train_svm.py

# train ann
python3 ANN/train_ann.py
