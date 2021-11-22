#include <numeric>
#include <fstream>
#include "features_extraction.h"
#include "../Helpers/globals.h"
#include "../Helpers/signal.h"
#include "../Helpers/au_reading.h"

std::map<FTYPE, DataVector> stft(DataVector &signal) {
    //TODO compute STFT with the help of signal.h
    auto avg = DataVector(FFT_SIZE);
    auto stddev = DataVector(FFT_SIZE);
    //TODO compute bins average and stddev
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
        auto features = stft(data);
        all_features.push_back(std::make_pair(file, features));
        //std::cout << "Training parameters size --> " << features[FTYPE::BINAVG].size() << "x" << features[FTYPE::BINSTDEV].size() << std::endl;
    }
    std::cout << "Ready to write file --> " << "features.csv" << std::endl;
    std::cout << "Training features size --> " << all_features.size() << std::endl;
    write_csv("features.csv", all_features);
    std::cout << "File written !" << std::endl;
}



