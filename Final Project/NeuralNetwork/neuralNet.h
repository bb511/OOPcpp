/*
Simple neural network consisting of three layers of neurons.
Its purpose is to identify the digit in a 28x28 image of handwritten digit.
This neural network is trained using the MNIST data set (dataLoader.h).
Recipe taken from: http://neuralnetworksanddeeplearning.com/chap1.html.
Help with implementation from: https://github.com/Atrix256/MNIST1.
*/

#ifndef NEURALNET_H
#define NEURALNET_H

#include "dataLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <array>
#include <vector>

#include <random>
#include <stdint.h>
#include <cmath>
#include <algorithm>

// Chose not to use namespace here since tpp file method seems cleaner.
template <size_t inputsNeurons, size_t hiddenNeurons, size_t outputNeurons>
class NeuralNetwork{
private:
    // Neuron values (initialised with 0, 1 when activated).
    std::array<double, hiddenNeurons> hiddenLayerOutputs;
    std::array<double, outputNeurons> outputLayerOutputs;
    // Biases and weights for each neuron.
    std::array<double, hiddenNeurons> hiddenLayerBiases;
    std::array<double, outputNeurons> outputLayerBiases;
    std::array<double, inputsNeurons*hiddenNeurons> hiddenLayerWeights;
    std::array<double, outputNeurons*hiddenNeurons> outputLayerWeights;
    // Derivaties of biases and weights for one training image.
    std::array<double, hiddenNeurons> hiddenLayerBiasesDCost;
    std::array<double, outputNeurons> outputLayerBiasesDCost;
    std::array<double, inputsNeurons*hiddenNeurons> hiddenLayerWeightsDCost;
    std::array<double, outputNeurons*hiddenNeurons> outputLayerWeightsDCost;
    // Derivatives of biases and weights for a batch of images.
    std::array<double, hiddenNeurons> batchHiddenLayerBiasesDCost;
    std::array<double, outputNeurons> batchOutputLayerBiasesDCost;
    std::array<double, inputsNeurons*hiddenNeurons> batchHiddenLayerWeightsDCost;
    std::array<double, outputNeurons*hiddenNeurons> batchOutputLayerWeightsDCost;
    // Batch generation.
    std::vector<size_t> trainingOrder;
private:
    // Functions to get the index of a connection between two neurons.
    size_t hiddenLayerWIdx(size_t inIndex, size_t hiddenLayerNIndex){
        return hiddenLayerNIndex*inputsNeurons + inIndex; }
    size_t outputLayerWIdx(size_t hiIndex, size_t outputLayerNIndex){
        return outputLayerNIndex*hiddenNeurons + hiIndex; }
    // Backpropagation functions in the different layers.
    void oLayerBPass(uint8_t correctLabel);
    void hLayerBPass(const double* pixels, uint8_t correctLabel);

    // Helper functions. Used to make the code more modular and readable.
    void generateTrainingOrder(const MNISTData& trainingData);
    void shuffleTrainingOrder();
    void clearBatchDerivatives();
    void saveBatchDerivatives();
    void applyBiasesAndWeights(double batchLearningRate);
    void forwardPassHiddenLayer(const double* pixels);
    void forwardPassOutputLayer();
public:
    // Constructor and destructor.
    NeuralNetwork();
    ~NeuralNetwork() {}

    // Basic functionality.
    void train(const MNISTData& trainingData, size_t batchSize, double rate);
    void exportNeuralNet();
    void importNeuralNet(std::ifstream& file);
    uint8_t forwardPass(const double* pixels);
};
#include "neuralNet.tpp"

#endif
