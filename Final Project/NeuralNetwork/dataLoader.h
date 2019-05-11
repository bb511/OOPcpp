// Loads the MNIST digit data used for training/validating the neural network.
// Complete description given here: http://yann.lecun.com/exdb/mnist/
// Help with reading the data from: https://bit.ly/2VMttm2
#ifndef DATALOADER_H
#define DATALOADER_H

#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>

class MNISTData{
private:
    size_t imageCount;
    // The nature of the data dictates these unconventional types.
    uint8_t* labelData; uint8_t* imageData;
    uint8_t* labels; uint8_t* pixels;
    std::vector<double> imagePixels;
    // Helper functions.
    bool processLabels();
    bool processImages();
    bool checkOpenFile(FILE* file);
    long getFileSize(FILE* file);
    void convertPixelsToFloat();
public:
    // Contructor and destructor.
    MNISTData(): labelData(nullptr), imageData(nullptr), imageCount(0),
                 labels(nullptr), pixels(nullptr) {}
    ~MNISTData(){ delete[] labelData; delete[] imageData;
                  delete[] labels; delete[] pixels;}

    // Main functionality.
    bool readLabels(bool training);
    bool readImages(bool training);
    bool load(bool training);
    const double* getImage(size_t index, uint8_t& label) const;
    size_t imagesNumber() const { return imageCount; }
};

#endif
