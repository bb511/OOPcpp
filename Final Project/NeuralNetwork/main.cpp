// Network is trained on the MNIST single handwritten digit data set.
// To learn more about the data or the neural net check included header files.
#include "dataLoader.h"
#include "neuralNet.h"
#include <iostream>
#include <stdint.h>
#include <stdexcept>

static const size_t inputsNeurons{784}; // 28x28 images.
static const size_t hiddenNeurons{30};  // 30 hidden neurons (optimal number).
static const size_t outputNeurons{10};  // 10 output neurons (0-9).

// Set how many training epochs, the training data batch size and
// the learning rate (optimal is about 3).
static const size_t trainingEpochs{30};
static const size_t batchSize{10};
static const double learningRate{3.0};

// Initialize the neural network.
NeuralNetwork<inputsNeurons, hiddenNeurons, outputNeurons> neuralNet;

double assessAccuracy(const MNISTData& data){
    // Assess the current accuracy of the neural network with respect to data.
    size_t correctItems{0};
    uint8_t label, deducedLabel;
    const double* pixels;

    for(size_t i=0; i<data.imagesNumber(); i++){
        pixels = data.getImage(i, label);
        uint8_t deducedLabel = neuralNet.forwardPass(pixels);
        if(deducedLabel == label) correctItems++;
    }
    return double(correctItems)/double(data.imagesNumber());
}

void dispEpochAccuracy(const MNISTData& trainingData, const MNISTData& testData){
    // Display the current
    double accuracyTraining{assessAccuracy(trainingData)};
    double accuracyTest{assessAccuracy(testData)};
    std::cout<<"Training Data Accuracy: "<<100.0*accuracyTraining<<"%; ";
    std::cout<<"Test Data Accuracy: "<<100.0*accuracyTest<<"%. ";
}

void trainOneEpoch(const MNISTData& trData, const MNISTData& tstData,
                   size_t epoch){
    std::cout<<"Epoch "<<epoch+1<<": ";
    dispEpochAccuracy(trData, tstData);
    neuralNet.train(trData, batchSize, learningRate);
    std::cout<<std::endl;
}

int main(){
    // Load the data.
    MNISTData trainingData; MNISTData testData;
    if(!(trainingData.load(true) && testData.load(false)))
        throw std::runtime_error("Could not load train data files correctly!");

    // Train the neural network.
    for(size_t epoch=0; epoch<trainingEpochs; epoch++)
        trainOneEpoch(trainingData, testData, epoch);
    neuralNet.exportNeuralNet();
    return 0;
}
