#include <iostream>
#include <chrono>
#include <tuple>
#include "../Helpers/file_helpers.h"
#include "features_extraction.h"
#include <fstream>


int main() {
    auto beg = std::chrono::high_resolution_clock::now();
    auto dirs = alpha_dir_listing("./DATA/");
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

    std::ofstream paths_train("./DATA/file_list_train.txt");
    for (auto elem: training_files) {
        std::cout << "Training --> " << elem << std::endl;
        paths_train << elem.string() << std::endl;
    }
    paths_train.close();

    std::ofstream paths_test("./DATA/file_list_test.txt");
    for (auto elem: testing_files) {
        std::cout << "Testing --> " << elem << std::endl;
        paths_test << elem.string() << std::endl;
    }
    paths_test.close();

    compute_set_of_features(training_files, "./DATA/features_training.csv", true);

    // In a real world application, the input audio files may come from outside this
    // file list but here they are computed for diminishing repetitive computations,
    // as we don't change those sets

    if (testing_files.size() > 0)
      compute_set_of_features(testing_files, "./DATA/features_testing.csv", true);

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end - beg).count() << " s" << std::endl;
    return 0;
}
