// Implementations of all the functions in the neuralNet.h file.
// Go there for description of larger purpose.

template <size_t i, size_t h, size_t o>
NeuralNetwork<i,h,o>::NeuralNetwork(){
    // Use random device to seed the Mersene Twister 19937 generator.
    // Initialize the weights and biases from a gaussian distribution
    // with mean 0 and STD 1.
    std::random_device rd; std::mt19937 randNum(rd());
    std::normal_distribution<double> gaussian(0, 1);
    for(double& elem : hiddenLayerBiases) elem = gaussian(randNum);
    for(double& elem : outputLayerBiases) elem = gaussian(randNum);
    for(double& elem : hiddenLayerWeights) elem = gaussian(randNum);
    for(double& elem : outputLayerWeights) elem = gaussian(randNum);
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::oLayerBPass(uint8_t correctLabel){
    // Backpropagation in the output layer.
    // More details at: http://neuralnetworksanddeeplearning.com/chap2.html.
    for(size_t neuronIdx=0; neuronIdx<o; neuronIdx++){
        double desiredOutput{(correctLabel == neuronIdx) ? 1.0:0.0};
        double deltaCostDelta0{outputLayerOutputs[neuronIdx] - desiredOutput};
        double delta0DeltaZ{outputLayerOutputs[neuronIdx] * (1.0 - outputLayerOutputs[neuronIdx])};
        outputLayerBiasesDCost[neuronIdx] = deltaCostDelta0*delta0DeltaZ;

        for(size_t inIdx=0; inIdx<h; ++inIdx)
            outputLayerWeightsDCost[this->outputLayerWIdx(inIdx, neuronIdx)] = \
            outputLayerBiasesDCost[neuronIdx] * hiddenLayerOutputs[inIdx];
        }
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::hLayerBPass(const double* pixels, uint8_t correctLabel){
    // Backpropagation in the hidden layer.
    // More details at: http://neuralnetworksanddeeplearning.com/chap2.html.
    for(size_t neuronIdx=0; neuronIdx<h; neuronIdx++){
        double deltaCostDeltaO{0.0};
        for(size_t destNIdx=0; destNIdx<o; destNIdx++)
            deltaCostDeltaO += outputLayerBiasesDCost[destNIdx] * \
            outputLayerWeights[this->outputLayerWIdx(neuronIdx, destNIdx)];
        double deltaODeltaZ{hiddenLayerOutputs[neuronIdx] * (1.0f - hiddenLayerOutputs[neuronIdx])};
        hiddenLayerBiasesDCost[neuronIdx] = deltaCostDeltaO * deltaODeltaZ;

        for(size_t inIdx=0; inIdx<i; ++inIdx)
            hiddenLayerWeightsDCost[this->hiddenLayerWIdx(inIdx, neuronIdx)] = \
            hiddenLayerBiasesDCost[neuronIdx] * pixels[inIdx];
    }
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::shuffleTrainingOrder(){
    // Shuffle the training data to create random batches.
    // Make generated rn static during runtime (in case of multiple calls).
    static std::random_device rd;
    static std::mt19937 randNum(rd());
    std::shuffle(trainingOrder.begin(), trainingOrder.end(), randNum);
}


template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::generateTrainingOrder(const MNISTData& trainingData){
    // Generate the training order after the data.
    if(trainingOrder.size() != trainingData.imagesNumber()){
        trainingOrder.resize(trainingData.imagesNumber());
        size_t idx{0};
        for(size_t& elem : trainingOrder){ elem = idx; idx++; }
    }
    shuffleTrainingOrder();
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::clearBatchDerivatives(){
    // Clear out the batch derivative arrays.
    std::fill(batchHiddenLayerBiasesDCost.begin(),
              batchHiddenLayerBiasesDCost.end(), 0.0);
    std::fill(batchOutputLayerBiasesDCost.begin(),
              batchOutputLayerBiasesDCost.end(), 0.0);
    std::fill(batchHiddenLayerWeightsDCost.begin(),
              batchHiddenLayerWeightsDCost.end(), 0.0);
    std::fill(batchOutputLayerWeightsDCost.begin(),
              batchOutputLayerWeightsDCost.end(), 0.0);
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::saveBatchDerivatives(){
    // Save obtained training (1 image) derivatives.
    for(size_t idx=0; idx<hiddenLayerBiasesDCost.size(); idx++)
        batchHiddenLayerBiasesDCost[idx] += hiddenLayerBiasesDCost[idx];
    for(size_t idx=0; idx<outputLayerBiasesDCost.size(); idx++)
        batchOutputLayerBiasesDCost[idx] += outputLayerBiasesDCost[idx];
    for(size_t idx=0; idx<hiddenLayerWeightsDCost.size(); idx++)
        batchHiddenLayerWeightsDCost[idx] += hiddenLayerWeightsDCost[idx];
    for(size_t idx=0; idx<outputLayerWeightsDCost.size(); idx++)
        batchOutputLayerWeightsDCost[idx] += outputLayerWeightsDCost[idx];
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::applyBiasesAndWeights(const double batchLearningRate){
    // Apply the biases and the weights resulted from training with data batch.
    for(size_t idx=0; idx<hiddenLayerBiases.size(); idx++)
        hiddenLayerBiases[idx] -= batchHiddenLayerBiasesDCost[idx] * \
                                  batchLearningRate;
    for(size_t idx=0; idx<outputLayerBiases.size(); idx++)
        outputLayerBiases[idx] -= batchOutputLayerBiasesDCost[idx] * \
                                  batchLearningRate;
    for(size_t idx=0; idx<hiddenLayerWeights.size(); idx++)
        hiddenLayerWeights[idx] -= batchHiddenLayerWeightsDCost[idx] * \
                                   batchLearningRate;
    for(size_t idx=0; idx<outputLayerWeights.size(); idx++)
        outputLayerWeights[idx] -= batchOutputLayerWeightsDCost[idx] * \
                                   batchLearningRate;
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::forwardPassHiddenLayer(const double* pixels){
    // Pass the input pixels of the image to the hidden layer sigmoid neurons.
    for(size_t neuronIdx=0; neuronIdx<h; neuronIdx++){
        double Z{hiddenLayerBiases[neuronIdx]};
        for(size_t inIdx=0; inIdx<i; inIdx++)
            Z += pixels[inIdx] * \
                 hiddenLayerWeights[hiddenLayerWIdx(inIdx, neuronIdx)];
        hiddenLayerOutputs[neuronIdx] = 1.0 / (1.0 + std::exp(-Z));
    }
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::forwardPassOutputLayer(){
    // Pass the hidden layer data into the output layer sigmoid neurons.
    for(size_t neuronIdx=0; neuronIdx<o; neuronIdx++){
        double Z{outputLayerBiases[neuronIdx]};
        for(size_t inIdx=0; inIdx<h; inIdx++)
            Z += hiddenLayerOutputs[inIdx] * \
                 outputLayerWeights[outputLayerWIdx(inIdx, neuronIdx)];
        outputLayerOutputs[neuronIdx] = 1.0 / (1.0 + std::exp(-Z));
    }
}

template <size_t i, size_t h, size_t o>
uint8_t NeuralNetwork<i,h,o>::forwardPass(const double* pixels){
    // Pass the images through the two layers (sigmoid neurons) of the
    // neural network. The output neuron with the most activation is returned.
    forwardPassHiddenLayer(pixels); forwardPassOutputLayer();
    double maxOutput{outputLayerOutputs[0]}; uint8_t maxLabel{0};
    for(uint8_t neuronIdx=1; neuronIdx<o; neuronIdx++)
        if (outputLayerOutputs[neuronIdx] > maxOutput){
            maxOutput = outputLayerOutputs[neuronIdx];
            maxLabel = neuronIdx;
        }
    return maxLabel;
}


template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::train(const MNISTData& trData, size_t batchSize, double rate){
    // Train the neural network by splitting trData into batches.
    generateTrainingOrder(trData);
    size_t trIdx{0}, batchIdx; uint8_t imgLabel, deducedLabel;
    const double* pixels; double batchLearningRate;
    while(trIdx<trData.imagesNumber()){
        batchIdx = 0; clearBatchDerivatives();
        while(batchIdx<batchSize && trIdx<trData.imagesNumber()){
            imgLabel = 0;
            pixels = trData.getImage(trainingOrder[trIdx], imgLabel);
            deducedLabel = forwardPass(pixels);
            oLayerBPass(imgLabel); hLayerBPass(pixels, imgLabel);
            saveBatchDerivatives();
            trIdx++; batchIdx++;
        }
        batchLearningRate = rate / double(batchIdx);
        applyBiasesAndWeights(batchLearningRate);
    }
}

template<std::size_t SIZE>
void writeArrayToFile(std::array<double, SIZE>& arr, std::ofstream& file){
    // Small helper function that writes array of SIZE to file.
    for(double& elem : arr) file<<elem<<" ";
    file<<std::endl;
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::exportNeuralNet(){
    // Write biases of weights of neural network to file.
    std::ofstream exportedNetwork("exportedNetwork.txt");
    if(!exportedNetwork) {std::cerr<<"Unable to open export file!\n"; exit(1);}
    writeArrayToFile(hiddenLayerBiases, exportedNetwork);
    writeArrayToFile(hiddenLayerWeights, exportedNetwork);
    writeArrayToFile(outputLayerBiases, exportedNetwork);
    writeArrayToFile(outputLayerWeights, exportedNetwork);
    exportedNetwork.close();
}

template<std::size_t SIZE>
void readArrayFromFile(std::array<double, SIZE>& arr, std::ifstream& file){
    // Small helper function that reads an exported neural network from a file.
    std::string line;
    getline(file, line);
    std::istringstream strstream(line);
    for(size_t i=0; i<SIZE; i++) strstream>>arr[i];
    if(strstream.peek() != ' ')
        std::cout<<"Dimensions of import NN do not correspond to assigned NN!\n";
}

template <size_t i, size_t h, size_t o>
void NeuralNetwork<i,h,o>::importNeuralNet(std::ifstream& file){
    // Import biases and weights of neural network from file.
    // Must keep the order of export neural net.
    if(!file) {std::cerr<<"Unable to open import file! "; exit(1);}
    readArrayFromFile(hiddenLayerBiases, file);
    readArrayFromFile(hiddenLayerWeights, file);
    readArrayFromFile(outputLayerBiases, file);
    readArrayFromFile(outputLayerWeights, file);
}
