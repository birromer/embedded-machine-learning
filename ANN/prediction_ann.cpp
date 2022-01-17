#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <fstream>
#include <filesystem>
#include "../Helpers/globals.h"
#include "../Helpers/music_style_helpers.h"
#include "../Extraction/features_extraction.h"

// Learned ANN weights
const std::string path_ann_weights = "./DATA/ann_weights.txt";
const std::string path_ann_stats = "./DATA/ann_stats.txt";

#define N_CLASSES 10

// output is a vector of layers
// each layer is a matrix, vector of vectors
std::vector<std::vector<std::vector<double>>> load_ann_model() {
  std::ifstream weights_file(path_ann_weights);

  std::string tmp_line, tmp_val, bias;
  int n_layers, n_cols, n_rows;

  std::getline(weights_file, tmp_line);
  n_layers = std::stoi(tmp_line);  // get number of layers in the file

  std::vector<std::vector<std::vector<double>>> layers;

  for (int l=0; l<n_layers; l++) {
    std::getline(weights_file, tmp_line);
    std::stringstream ss(tmp_line);

    std::getline(ss, tmp_val, ' ');
    n_rows = std::stoi(tmp_val);

    std::getline(ss, tmp_val, '\n');
    n_cols = std::stoi(tmp_val);

//    std::cout << "Reading layer " << l << ", with " << n_rows << " rows and " << n_cols << " cols." << std::endl;

    std::vector<std::vector<double>> neuron;

    for (int i=0; i<n_rows; i++) {
      std::getline(weights_file, tmp_line);
      std::stringstream ss(tmp_line);

      std::vector<double> row;
//      std::cout << "row: " << i << std::endl;

      for (int j=0; j<n_cols; j++) {

        std::getline(ss, tmp_val, ',');
//        std::cout << "col: " << j << " | tmp_val: " << tmp_val << std::endl;
        row.push_back(std::stod(tmp_val));

      }

      neuron.push_back(row);
    }

    layers.push_back(neuron);
  }

  return layers;
}


// output is a vector of two vectors, with the stats for
// normalization,  the first is the mean of each feature
// the second is their scale (stddev)
std::vector<std::vector<double>> load_ann_stats() {
  std::ifstream stats_file(path_ann_stats);

  std::string tmp_line, tmp_val, bias;

  std::getline(stats_file, tmp_line);  // ignor the header

  std::vector<std::vector<double>> stats;  // where all stats are stored

  std::vector<double> means, stddevs;

  std::getline(stats_file, tmp_line);

  std::stringstream ss(tmp_line);

  for (std::size_t l=0; l<FEAT_N; l++) {  // iterate over the 512 means
    std::getline(ss, tmp_val, ',');
    means.push_back(std::stod(tmp_val));
  }

  for (std::size_t l=0; l<FEAT_N; l++) {  // iterate over the 512 scales
    std::getline(ss, tmp_val, ',');
    stddevs.push_back(std::stod(tmp_val));
  }

  stats.push_back(means);
  stats.push_back(stddevs);

  return stats;
}


// input: column vector with the computed output of each neuron of the layer
// output: column vector with relu function mapped to each dimension of the input
std::vector<double> relu(std::vector<double> input) {
  std::vector<double> please_give_me_fmap;
  please_give_me_fmap.resize(input.size());

  std::transform(input.begin(), input.end(),
                 please_give_me_fmap.begin(),
                 [] (double x) {return std::max(x,0.0);}
  );

  return please_give_me_fmap;
}

// input: column vector with output layer of the network (or not)
// output: column vector with softmax activation function to each dimension of the input
std::vector<double> softmax(std::vector<double> input) {
  std::vector<double> please_give_me_clean_lambdas;
  please_give_me_clean_lambdas.resize(input.size());

  double reduce_sum = std::transform_reduce(
    input.cbegin(), input.cend(),  // the dear test subject
    0.0,  // initial value
    std::plus<double>(),  // reduce
    [] (double x) {return exp(x);}  // transform
  );

  std::transform(
    input.cbegin(), input.cend(),
    please_give_me_clean_lambdas.begin(),
    [&] (double x) {return exp(x)/reduce_sum;}  // i really dislike functional c++
  );

  return please_give_me_clean_lambdas;
}

std::vector<double> normalize(std::vector<double> input, std::vector<double> mean, std::vector<double> stddev) {
  std::vector<double> once_upon_a_time_we_used_haskell(input.size(), 0);

  for (std::size_t i=0; i<input.size(); i++) {
    once_upon_a_time_we_used_haskell[i] = (input[i] - mean[i])/stddev[i];
  }

  return once_upon_a_time_we_used_haskell;
}

int ann_predict(std::vector<double> feat_vec, std::vector<std::vector<std::vector<double>>> layers) {

  // apply the feed forward through the layers
  std::vector<double> input(feat_vec.begin(), feat_vec.end());

  for (auto it = layers.begin(); it != layers.end(); it++) {
    std::vector<double> Y_layer;

    for (std::vector<double> neuron : *it) {
      // matrix multiplication, line by line, base value of the sum being the bias
      double y_n = std::inner_product(input.begin(), input.end(), neuron.begin(), *(neuron.end()-1));
      Y_layer.push_back(y_n);
    }

    input = relu(Y_layer);
  }

  input = softmax(input);

  // gets the position of the maximum value in output layer
  int argmax = std::max_element(input.begin(), input.end()) - input.begin();

  return argmax;
}
