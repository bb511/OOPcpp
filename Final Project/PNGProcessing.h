#ifndef PNGPROCESSING_H
#define PNGPROCESSING_H

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <cmath>
#include <vector>

class PNGImage{
private:
    unsigned width, height;
    std::vector<unsigned char> image;
    std::vector<double> imageGreyScale;
public:
    // Constructors and destructors.
    PNGImage(): width(0), height(0) {}
    PNGImage(const char* filename);
    PNGImage(PNGImage& img);
    PNGImage(PNGImage&& img);
    ~PNGImage() {}

    // Assignment and copy operators.
    PNGImage& operator=(PNGImage& img);
    PNGImage& operator=(PNGImage&& img);

    // Access functions.
    unsigned getWidth() const { return width; }
    unsigned getHeight() const { return height; }
    std::vector<unsigned char> getImage() const { return image; }
    std::vector<double> getImageGreyScale() const { return imageGreyScale; }
    const double* getGreyScalePointer() { return &imageGreyScale[0]; }
    void showGreyScaleImage();
};

#endif
