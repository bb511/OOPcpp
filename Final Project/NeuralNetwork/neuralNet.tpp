/*
Implementations of all the functions in the neuralNet.h file.
Description of larger purpose found in associated header file.
*/

template <size_t in, size_t hid, size_t out>
NeuralNetwork<in,hid,out>::NeuralNetwork(){
    /* Use random device to seed the Mersene Twister 19937 generator.
       Initialize the NN biases and weights from a gaussian distribution
       with mean 0 and STD 1. */
    std::random_device rd; std::mt19937 randNum(rd());
    std::normal_distribution<double> gaussian(0, 1);
    for(double& elem : hidLayerBias) elem = gaussian(randNum);
    for(double& elem : outLayerBias) elem = gaussian(randNum);
    for(double& elem : hidLayerWeights) elem = gaussian(randNum);
    for(double& elem : outLayerWeights) elem = gaussian(randNum);
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::shuffleTrainingOrder(){
    // Shuffle the training data to create random training batches.
    static std::random_device rd;
    static std::mt19937 randNum(rd());
    std::shuffle(trainingOrder.begin(), trainingOrder.end(), randNum);
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::genTrainOrder(const MNISTData& trainData){
    // Generate the training order after the data.
    if(trainingOrder.size() != trainData.imagesNumber()){
        trainingOrder.resize(trainData.imagesNumber());
        size_t idx{0};
        for(size_t& elem : trainingOrder){ elem = idx; idx++; }
    }
    shuffleTrainingOrder();
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::oLayerBPass(uint8_t correctLabel){
    // Backpropagation in the output layer.
    // More details at: http://neuralnetworksanddeeplearning.com/chap2.html.
    for(size_t neuIdx=0; neuIdx<out; neuIdx++){
        double desiredOutput{(correctLabel == neuIdx) ? 1.0:0.0};
        double deltaCostDelta0{outLayerOuts[neuIdx] - desiredOutput};
        double delta0DeltaZ{outLayerOuts[neuIdx] * (1.0-outLayerOuts[neuIdx])};

        outLayerBiasDCost[neuIdx] = deltaCostDelta0*delta0DeltaZ;

        for(size_t inIdx=0; inIdx<hid; ++inIdx)
            outLayerWeightsDCost[this->outputLayerWIdx(inIdx, neuIdx)] = \
            outLayerBiasDCost[neuIdx] * hidLayerOuts[inIdx];
        }
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::hLayerBPass(const double* pixels,
                                            uint8_t correctLabel){
    // Backpropagation in the hidden layer.
    // More details at: http://neuralnetworksanddeeplearning.com/chap2.html.
    for(size_t neuIdx=0; neuIdx<hid; neuIdx++){
        double deltaCostDeltaO{0.0};
        for(size_t destNIdx=0; destNIdx<out; destNIdx++)
            deltaCostDeltaO += outLayerBiasDCost[destNIdx] * \
                outLayerWeights[this->outputLayerWIdx(neuIdx, destNIdx)];

        double deltaODeltaZ{hidLayerOuts[neuIdx] * (1.0f-hidLayerOuts[neuIdx])};
        hidLayerBiasDCost[neuIdx] = deltaCostDeltaO * deltaODeltaZ;

        for(size_t inIdx=0; inIdx<in; ++inIdx)
            hidLayerWeightsDCost[this->hiddenLayerWIdx(inIdx, neuIdx)] = \
                hidLayerBiasDCost[neuIdx] * pixels[inIdx];
    }
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::clearBatchDerivatives(){
    // Clear out the batch derivative arrays.
    std::fill(batchHidLayerBiasDCost.begin(),batchHidLayerBiasDCost.end(), 0.0);
    std::fill(batchOutLayerBiasDCost.begin(),batchOutLayerBiasDCost.end(), 0.0);
    std::fill(batchHidLayerWeightsDCost.begin(), batchHidLayerWeightsDCost.end(), 0.0);
    std::fill(batchOutLayerWeightsDCost.begin(), batchOutLayerWeightsDCost.end(), 0.0);
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::saveBatchDerivatives(){
    // Save obtained training (1 image) derivatives.
    for(size_t idx=0; idx<hidLayerBiasDCost.size(); idx++)
        batchHidLayerBiasDCost[idx] += hidLayerBiasDCost[idx];
    for(size_t idx=0; idx<outLayerBiasDCost.size(); idx++)
        batchOutLayerBiasDCost[idx] += outLayerBiasDCost[idx];
    for(size_t idx=0; idx<hidLayerWeightsDCost.size(); idx++)
        batchHidLayerWeightsDCost[idx] += hidLayerWeightsDCost[idx];
    for(size_t idx=0; idx<outLayerWeightsDCost.size(); idx++)
        batchOutLayerWeightsDCost[idx] += outLayerWeightsDCost[idx];
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::applyBiasNWeights(const double batchLearnRate){
    // Apply the biases and the weights resulted from training with data batch.
    for(size_t idx=0; idx<hidLayerBias.size(); idx++)
        hidLayerBias[idx] -= batchHidLayerBiasDCost[idx] * batchLearnRate;
    for(size_t idx=0; idx<outLayerBias.size(); idx++)
        outLayerBias[idx] -= batchOutLayerBiasDCost[idx] * batchLearnRate;
    for(size_t idx=0; idx<hidLayerWeights.size(); idx++)
        hidLayerWeights[idx] -= batchHidLayerWeightsDCost[idx] * batchLearnRate;
    for(size_t idx=0; idx<outLayerWeights.size(); idx++)
        outLayerWeights[idx] -= batchOutLayerWeightsDCost[idx] * batchLearnRate;
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::forwardPassHiddenLayer(const double* pixels){
    // Pass the input pixels of the image to the hidden layer sigmoid neurons.
    for(size_t neuIdx=0; neuIdx<hid; neuIdx++){
        double Z{hidLayerBias[neuIdx]};
        for(size_t inIdx=0; inIdx<in; inIdx++)
            Z += pixels[inIdx] * hidLayerWeights[hiddenLayerWIdx(inIdx, neuIdx)];
        hidLayerOuts[neuIdx] = 1.0 / (1.0 + std::exp(-Z));
    }
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::forwardPassOutputLayer(){
    // Pass the hidden layer data into the output layer sigmoid neurons.
    for(size_t neuIdx=0; neuIdx<out; neuIdx++){
        double Z{outLayerBias[neuIdx]};
        for(size_t inIdx=0; inIdx<hid; inIdx++)
            Z += hidLayerOuts[inIdx] * \
                 outLayerWeights[outputLayerWIdx(inIdx, neuIdx)];
        outLayerOuts[neuIdx] = 1.0 / (1.0 + std::exp(-Z));
    }
}

template <size_t in, size_t hid, size_t out>
uint8_t NeuralNetwork<in,hid,out>::forwardPass(const double* pixels){
    // Pass the images through the two layers (sigmoid neurons) of the
    // neural network. The output neuron with the most activation is returned.
    forwardPassHiddenLayer(pixels); forwardPassOutputLayer();
    double maxOutput{outLayerOuts[0]}; uint8_t maxLabel{0};
    for(uint8_t neuIdx=1; neuIdx<out; neuIdx++)
        if (outLayerOuts[neuIdx] > maxOutput){
            maxOutput = outLayerOuts[neuIdx];
            maxLabel = neuIdx;
        }
    return maxLabel;
}


template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::train(const MNISTData& trData, size_t batchSize,
                                      double rate){
    // Train the neural network by splitting trData into batches.
    genTrainOrder(trData);
    size_t trIdx{0}, batchIdx; uint8_t imgLabel, deducedLabel;
    const double* pixels; double batchLearnRate;
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
        batchLearnRate = rate / double(batchIdx);
        applyBiasNWeights(batchLearnRate);
    }
}

template<std::size_t SIZE>
void writeArrayToFile(std::array<double, SIZE>& arr, std::ofstream& file){
    // Small helper function that writes array of SIZE to file.
    for(double& elem : arr) file<<elem<<" ";
    file<<std::endl;
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::exportNeuralNet(){
    // Write biases of weights of neural network to file.
    std::ofstream exportedNetwork("exportedNetwork.txt");
    if(!exportedNetwork) {std::cerr<<"Unable to open export file!\n"; exit(1);}
    writeArrayToFile(hidLayerBias, exportedNetwork);
    writeArrayToFile(hidLayerWeights, exportedNetwork);
    writeArrayToFile(outLayerBias, exportedNetwork);
    writeArrayToFile(outLayerWeights, exportedNetwork);
    exportedNetwork.close();
}

template<std::size_t SIZE>
void readArrayFromFile(std::array<double, SIZE>& arr, std::ifstream& file){
    // Small helper function that reads an exported neural network from a file.
    std::string line; getline(file, line);
    std::istringstream strstream(line);
    for(size_t idx; idx < arr.size(); idx++) strstream>>arr[idx];
    if(strstream.peek() != ' ')
        std::cout<<"Dimensions of import NN do not correspond to assigned NN!\n";
}

template <size_t in, size_t hid, size_t out>
void NeuralNetwork<in,hid,out>::importNeuralNet(std::ifstream& file){
    // Import biases and weights of neural network from file.
    // Must keep the order of export neural net.
    if(!file) {std::cerr<<"Unable to open import file! "; exit(1);}
    readArrayFromFile(hidLayerBias, file);
    readArrayFromFile(hidLayerWeights, file);
    readArrayFromFile(outLayerBias, file);
    readArrayFromFile(outLayerWeights, file);
}
