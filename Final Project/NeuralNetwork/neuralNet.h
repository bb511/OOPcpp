/*
Simple neural network consisting of three layers of neurons.
Its purpose is to identify the digit in a 28x28 image of a handwritten digit.
This neural network is trained using the MNIST data set (dataLoader.h).
Recipe from: http://neuralnetworksanddeeplearning.com/chap1.html.
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
    std::array<double, hiddenNeurons> hidLayerOuts;
    std::array<double, outputNeurons> outLayerOuts;
    // Biases and weights for each neuron.
    std::array<double, hiddenNeurons> hidLayerBias;
    std::array<double, outputNeurons> outLayerBias;
    std::array<double, inputsNeurons*hiddenNeurons> hidLayerWeights;
    std::array<double, outputNeurons*hiddenNeurons> outLayerWeights;
    // Derivaties of biases and weights for one training image.
    std::array<double, hiddenNeurons> hidLayerBiasDCost;
    std::array<double, outputNeurons> outLayerBiasDCost;
    std::array<double, inputsNeurons*hiddenNeurons> hidLayerWeightsDCost;
    std::array<double, outputNeurons*hiddenNeurons> outLayerWeightsDCost;
    // Derivatives of biases and weights for a batch of images.
    std::array<double, hiddenNeurons> batchHidLayerBiasDCost;
    std::array<double, outputNeurons> batchOutLayerBiasDCost;
    std::array<double, inputsNeurons*hiddenNeurons> batchHidLayerWeightsDCost;
    std::array<double, outputNeurons*hiddenNeurons> batchOutLayerWeightsDCost;
    // Batch generation.
    std::vector<size_t> trainingOrder;
private:
    // Get index of connection between two neurons.
    size_t hiddenLayerWIdx(size_t inIndex, size_t hiddenLayerNIndex){
        return hiddenLayerNIndex*inputsNeurons + inIndex; }
    size_t outputLayerWIdx(size_t hiIndex, size_t outputLayerNIndex){
        return outputLayerNIndex*hiddenNeurons + hiIndex; }
    // Backpropagation functions in the different layers.
    void oLayerBPass(uint8_t correctLabel);
    void hLayerBPass(const double* pixels, uint8_t correctLabel);

    // Helper functions. Used to make the code more modular and readable.
    void genTrainOrder(const MNISTData& trainData);
    void shuffleTrainingOrder();
    void clearBatchDerivatives();
    void saveBatchDerivatives();
    void applyBiasNWeights(double batchLearningRate);
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
