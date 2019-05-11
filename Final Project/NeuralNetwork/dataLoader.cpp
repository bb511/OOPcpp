// Loads the MNIST digit data used for training/validating the neural network.
// Complete description given here: http://yann.lecun.com/exdb/mnist/
// Help with reading the data from: https://bit.ly/2VMttm2
#include "dataLoader.h"

inline uint32_t endianSwap (uint32_t x){
    // Manually implemented endian swap.
    return (x<<24) | ((x<<8) & 0x00ff0000) |
           ((x>>8) & 0x0000ff00) | (x>>24);
}

bool MNISTData::checkOpenFile(FILE* file){
    // Checks if a file can be opened.
    if (!file){ std::cout<<"Could not open file for reading.\n"; return false;}
    return true;
}

long MNISTData::getFileSize(FILE* file){
    // Gets the size of a file.
    fseek(file, 0, SEEK_END);
    long fileSize{ftell(file)};
    fseek(file, 0, SEEK_SET);
    return fileSize;
}

bool MNISTData::readLabels(bool training){
    // Read the label data.
    const char* fileName{training ? "train-labels.idx1-ubyte"
                                  : "t10k-labels.idx1-ubyte"};
    FILE* file = fopen(fileName, "rb"); if(!checkOpenFile(file)) return false;
    long fileSize{getFileSize(file)};
    labelData = new uint8_t[fileSize];
    fread(labelData, fileSize, 1, file); fclose(file);
    return true;
}

bool MNISTData::readImages(bool training){
    // Read the image data.
    const char* fileName{training ? "train-images.idx3-ubyte"
                                  : "t10k-images.idx3-ubyte"};
    FILE* file = fopen(fileName, "rb"); if(!checkOpenFile(file)) return false;
    long fileSize{getFileSize(file)};
    imageData = new uint8_t[fileSize];
    fread(imageData, fileSize, 1, file); fclose(file);
    return true;
}

bool MNISTData::processLabels(){
    // Perform endian swap on labels data if needed; check if label header is
    // as expected; transfer the data body to relevant pointer.
    uint32_t* data{(uint32_t*)labelData};
    if(data[0] == 0x01080000){
        data[0] = endianSwap(data[0]); data[1] = endianSwap(data[1]);
    }
    if(data[0] != 2049 || data[1]!= imageCount){
        std::cout<<"Unexpected header values in labels.\n"; return false;
    }
    labels = (uint8_t*)&(data[2]);
    return true;
}

bool MNISTData::processImages(){
    // Perform endian swap on images data if needed; check if label header is
    // as expected; transfer the data body to relevant pointer.
    uint32_t* data{(uint32_t*)imageData};
    if(data[0] == 0x03080000){
        data[0] = endianSwap(data[0]); data[1] = endianSwap(data[1]);
        data[2] = endianSwap(data[2]); data[3] = endianSwap(data[3]);
    }
    if(data[0] != 2051 || data[1]!= imageCount || data[2] != 28 || data[3] != 28){
        std::cout<<"Unexpected header values in image.\n"; return false;
    }
    pixels = (uint8_t*)&(data[4]);
    return true;
}

void MNISTData::convertPixelsToFloat(){
    // Convert pixel data (0-255) to float and store in vector of images data.
    imagePixels.resize(28*28*imageCount);
    for(size_t i=0; i<28*28*imageCount; i++){
        imagePixels[i] = double(pixels[i]) / 255.0;
    }
}

bool MNISTData::load(bool training){
    // Loads the MNIST data for training/validating the neural network.
    imageCount = training ? 60000 : 10000;
    if(!(readLabels(training) && readImages(training))) return false;
    if(!(processLabels() && processImages())) return false;
    convertPixelsToFloat();
    if(imageCount == 60000) std::cout<<"Training data loaded successfully!\n";
    else std::cout<<"Test data loaded successfully!\n";
    return true;
}

const double* MNISTData::getImage(size_t index, uint8_t& label) const{
    // Get one image from the vector of images.
    label = labels[index];
    return &imagePixels[index*28*28];
}
