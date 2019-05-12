/*
Class that handle png image processing using the lodepng decoder.
Once the image is processed, a grey scale equivalent is automatically generated.
The unsigned type is imposed by the png decoder.
The lodepng decoder is an external library from https://lodev.org/lodepng/.
*/

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
    const double* getGreyScalePointer(size_t i) { return &imageGreyScale[i]; }
    void showGreyScaleImage();
};

#endif
