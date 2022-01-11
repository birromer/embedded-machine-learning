#ifndef EML_FEATURES_EXTRACTION_H
#define EML_FEATURES_EXTRACTION_H

#include <map>
#include <filesystem>
#include "../Helpers/etypes.h"
#include <numeric>
#include <fstream>

std::map<FTYPE, DataVector> stft(DataVector &signal);

void write_csv(std::string filename,
               std::vector<std::pair<std::filesystem::path, std::map<FTYPE, DataVector>>> &dataset);

std::map<FTYPE, DataVector> compute_features_for(std::filesystem::path &file_path);

//void compute_set_of_features(std::vector<std::filesystem::path> &files);
std::vector<std::pair<std::filesystem::path,std::map<FTYPE, DataVector>>> compute_set_of_features(std::vector<std::filesystem::path> &files, std::string features_path, bool verbose);

#endif //EML_FEATURES_EXTRACTION_H
