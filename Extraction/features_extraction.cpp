#include <numeric>
#include <fstream>
#include "features_extraction.h"
#include "../Helpers/globals.h"
#include "../Helpers/signal.h"
#include "../Helpers/au_reading.h"
#include <chrono>
using namespace std::chrono;

std::map<FTYPE, DataVector> stft(DataVector &signal) {
    auto avg = DataVector(FFT_SIZE);
    auto stddev = DataVector(FFT_SIZE);
    std::cout << "STFT called with signal of size " << signal.size() << std::endl;

    auto time_complex = high_resolution_clock::now() - high_resolution_clock::now();
    auto time_windowing = high_resolution_clock::now() - high_resolution_clock::now();
    auto time_fft = high_resolution_clock::now() - high_resolution_clock::now();
    auto time_magnitude = high_resolution_clock::now() - high_resolution_clock::now();
    auto time_average = high_resolution_clock::now() - high_resolution_clock::now();
    auto time_stddev = high_resolution_clock::now() - high_resolution_clock::now();

    int aa =0;

//    for (DataVector::const_iterator it = signal.begin(); it != signal.end()-2*N && it - signal.begin() <= FEAT_N; it+=N/2) {
    for (DataVector::const_iterator it = signal.begin(); it != signal.end()-2*N; it+=N/2) {
//        std::cout << "interation: " << aa++ << std::endl;

        // get the two overlapping chuncks from the sliding window
        auto start = high_resolution_clock::now();
        std::vector<Complex> v1(it, it+N);
        std::vector<Complex> v2(it+(N/2), it+(N+N/2));

        if (aa == 2047) {
          for (Complex c : v1) {
              std::cout << c.real() << " " << c.imag() << std::endl;
          }
        }
        int temp;
        std::cin >> temp;
        auto stop = high_resolution_clock::now();
        time_complex += (stop - start);

        start = high_resolution_clock::now();
        auto w = hamming_window();
        windowing(w, v1);
        windowing(w, v2);
        stop = high_resolution_clock::now();
        time_windowing += (stop-start);

        // compute the fft
        start = high_resolution_clock::now();
        ite_dit_fft(v1);
        ite_dit_fft(v2);
        stop = high_resolution_clock::now();
        time_fft += (stop-start);

        // compute the magnitude fft's output (which is a complex, with angle and phase)
        start = high_resolution_clock::now();
        DataVector v1_abs = DataVector(N);
        DataVector v2_abs = DataVector(N);

        for (std::size_t i=0; i<v1.size(); i++) {
            v1_abs.push_back(abs(v1[i]));
            v2_abs.push_back(abs(v2[i]));
        }
        stop = high_resolution_clock::now();
        time_average += (stop-start);

        // compute the average of the magnitudes
        start = high_resolution_clock::now();
        auto chunck_1_avg = std::accumulate(v1_abs.begin(), v1_abs.end(), 0)/v1_abs.size();
        auto chunck_2_avg = std::accumulate(v2_abs.begin(), v2_abs.end(), 0)/v2_abs.size();
        stop = high_resolution_clock::now();
        time_stddev += ((stop-start));

        avg.push_back(chunck_1_avg);
        avg.push_back(chunck_2_avg);

        // use the average to compute the std deviation
        start = high_resolution_clock::now();
        auto chunck_1_stddev = 0;
        auto chunck_2_stddev = 0;

        for (std::size_t i=0; i < v1_abs.size(); i++) {
            chunck_1_stddev += pow(v1_abs.at(i) - chunck_1_avg, 2);
            chunck_2_stddev += pow(v2_abs.at(i) - chunck_2_avg, 2);
        }

        stddev.push_back(chunck_1_stddev);
        stddev.push_back(chunck_2_stddev);
    }

    std::cout << "finished iterating signal" << std::endl;
    std::cout << "time for each part:" << std::endl;
    std::cout << "complex: " << time_complex.count() << std::endl;
    std::cout << "windowing: " << time_windowing.count() << std::endl;
    std::cout << "fft: " << time_fft.count() << std::endl;
    std::cout << "magnitude" << time_fft.count() << std::endl;
    std::cout << "average: " << time_average.count() << std::endl;
    std::cout << "sttdev: " << time_stddev.count() << std::endl;

    std::map<FTYPE, DataVector> features;
    //insert bins average and stddev in features
    features.insert({FTYPE::BINAVG, DataVector(avg.size())});
    features.insert({FTYPE::BINSTDEV, DataVector(stddev.size())});
    std::copy(avg.cbegin(), avg.cend(), features[FTYPE::BINAVG].begin());
    std::copy(stddev.cbegin(), stddev.cend(), features[FTYPE::BINSTDEV].begin());
    return features;
}


void write_csv(std::string filename,
               std::vector<std::pair<std::filesystem::path, std::map<FTYPE, DataVector>>> &dataset) {
    std::ofstream myFile(filename);
    auto datah = dataset[0];
    auto ith = datah.second.begin();
    std::map<FTYPE, std::string> type_names{{FTYPE::SPECCENT, "SPECCENT"},
                                            {FTYPE::BINAVG,   "BINAVG"},
                                            {FTYPE::BINSTDEV, "BINSTDEV"}};
    while (ith != datah.second.end()) {
        auto type_name = type_names[ith->first];
        auto data = ith->second;
        for (std::size_t i = 0; i < data.size(); ++i)
            myFile << type_name << i << ",";
        ith++;
    }
    myFile << "Style" << ",";
    myFile << "FileName" << "\n";

    auto it = dataset.begin();
    while (it != dataset.end()) {
        auto style = it->first.parent_path().filename();
        auto filename = it->first;
        for (auto const &entry: it->second) {
            //auto ftype = entry.first;
            for (auto elem: entry.second) {
                myFile << elem << ", ";
            }
        }
        myFile << style << ",";
        myFile << filename << "\n";
        it++;
    }
    myFile.close();
}


std::map<FTYPE, DataVector> compute_features_for(std::filesystem::path &file_path) {
    auto data = readAuFile(file_path);
    auto features = stft(data);
    return features;
}

void compute_set_of_features(std::vector<std::filesystem::path> &files) {
    std::vector<std::pair<std::filesystem::path, std::map<FTYPE, DataVector>>> all_features;
    for (auto file: files) {
        std::cout << "Reading --> " << file.filename() << std::endl;
        auto data = readAuFile(file);
        std::cout << "finished reading au file" << std::endl;
        auto features = stft(data);
        all_features.push_back(std::make_pair(file, features));
        std::cout << "Training parameters size --> " << features[FTYPE::BINAVG].size() << "x" << features[FTYPE::BINSTDEV].size() << std::endl;
    }
    std::cout << "Ready to write file --> " << "features.csv" << std::endl;
    std::cout << "Training features size --> " << all_features.size() << std::endl;
    write_csv("features.csv", all_features);
    std::cout << "File written !" << std::endl;
}



