#include <iostream>
#include "NeuralNetwork/neuralNet.h"
#include "PNGProcessing.h"
#include "Utility.h"
#include "Freeman.h"
#include "Enemies.h"
#include "Items.h"

NeuralNetwork<784, 30, 10> NN;

void loadNeuralNet(){
    // Load neural network that reads digits.
    std::ifstream importFile("NeuralNetwork/exportedNetwork.txt");
    NN.importNeuralNet(importFile);
}

int main(){
    loadNeuralNet();
    Freeman gFreeman("Gordon", 100, 0.2);
    Gman gman("Gman", 100, 1.0);
    Guard barney("barney", 100, 0.5, Pistol(100));

    animateText(gman.lineIntro());

    return 0;
}
