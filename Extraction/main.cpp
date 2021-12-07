#include <iostream>
#include <chrono>
#include <tuple>
#include "../Helpers/file_helpers.h"
#include "features_extraction.h"
#include <fstream>


int main() {
    auto beg = std::chrono::high_resolution_clock::now();
    auto dirs = alpha_dir_listing("../data/");
    std::vector<std::filesystem::path> training_files;
    std::vector<std::filesystem::path> testing_files;

    // Select random files of each music style
    for (auto dir_path: dirs) {
        std::cout << dir_path << std::endl;
        auto files = alpha_files_listing(dir_path);
        std::vector<std::filesystem::path> training;
        std::vector<std::filesystem::path> testing;
        std::tie(training, testing) = select_train_test_files(files, 0.3);
        training_files.insert(training_files.end(), training.begin(), training.end());
        testing_files.insert(testing_files.end(), testing.begin(), testing.end());
    }

    std::cout << "# training -->  " << training_files.size() << std::endl;
    std::cout << "# testing -->  " << testing_files.size() << std::endl;

//    for (auto elem: training_files)
//        std::cout << "Training --> " << elem << std::endl;

    std::ofstream paths_file("../data/test_paths.txt");

    for (auto elem: testing_files) {
        std::cout << "Testing --> " << elem << std::endl;
        paths_file << elem << std::endl;
    }

    paths_file.close();

//    for (auto file: training_files)
//        auto f = compute_features_for(file);

    compute_set_of_features(training_files);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end - beg).count() << " s" << std::endl;
    return 0;
}
