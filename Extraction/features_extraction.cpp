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

    int max_iter = signal.size() / N - 1;

    for (DataVector::const_iterator it = signal.begin(); it != signal.begin() + max_iter*N; it+=N) {
        // get the two overlapping chuncks from the sliding window
        std::vector<Complex> v1(it, it+N);
        std::vector<Complex> v2(it+N/2, it+N+N/2);

        // proceed with the windowing
        auto w = hamming_window();
        windowing(w, v1);
        windowing(w, v2);

        // compute the fft
        ite_dit_fft(v1);
        ite_dit_fft(v2);

        // compute the magnitude fft's output (which is a complex, with angle and phase)
        for (std::size_t i=0; i<FFT_SIZE; i++) {
            double abs_v1 = abs(v1[i])/(N*0.5);
            double abs_v2 = abs(v2[i])/(N*0.5);

            avg[i] +=  abs_v1;
            avg[i] +=  abs_v2;

            stddev[i] += pow(abs_v1, 2);
            stddev[i] += pow(abs_v2, 2);
        }
    }

    // compute scale to normalize
    for (std::size_t i=0; i<FFT_SIZE; i++) {
        // compute the average of the magnitudes
        avg[i] /= 2*max_iter;///scale_avg;
        stddev[i] = sqrt(stddev[i]/(2*max_iter) - pow(avg[i],2));
    }

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

std::vector<std::pair<std::filesystem::path,std::map<FTYPE, DataVector>>> compute_set_of_features(std::vector<std::filesystem::path> &files, std::string features_path, bool verbose) {
    std::vector<std::pair<std::filesystem::path, std::map<FTYPE, DataVector>>> all_features;
    for (auto file: files) {
        if (verbose) std::cout << "Reading --> " << file.filename() << std::endl;

        auto data = readAuFile(file);

        if (verbose) std::cout << "finished reading au file" << std::endl;

        auto features = stft(data);
        all_features.push_back(std::make_pair(file, features));

        if (verbose) std::cout << "Training parameters size --> " << features[FTYPE::BINAVG].size() << "x" << features[FTYPE::BINSTDEV].size() << std::endl;
    }

    if (verbose) {
      std::cout << "Ready to write file --> " << "features.csv" << std::endl;
      std::cout << "Training features size --> " << all_features.size() << std::endl;
    }

    write_csv(features_path, all_features);
    if (verbose) std::cout << features_path << " written !" << std::endl;

    return all_features;
}
