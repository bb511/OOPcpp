// Functions that deal with the image processing in the main script.
#include "PNGProcessing.h"
#include "lodepng.h"

PNGImage::PNGImage(const char* filename){
    // Decode and read an image, provided the filename/complete path.
    unsigned error = lodepng::decode(image, width, height, filename);
    if(error) std::cout << "Decoder error " << error << ": " << \
                           lodepng_error_text(error) << std::endl;

    uint32_t r,g,b; double greyPixel;
    for(size_t i=0; i<image.size(); i=i+4){
        r = image[i]; g = image[i+1]; b = image[i+2];
        greyPixel = 255 - (r+g+b)/3.0;
        imageGreyScale.push_back(greyPixel/255.0);
    }
}

PNGImage::PNGImage(PNGImage& img){
    // Copy constructor.
    width = img.getWidth(); height = img.getHeight();
    bool copyCondition{width > 0 && height > 0};
    if(copyCondition){
        image = img.getImage();
        imageGreyScale = img.getImageGreyScale();
    }
}

PNGImage::PNGImage(PNGImage&& img){
    // Move constructor.
    width = img.width; height = img.height;
    image = img.image;
    imageGreyScale = img.imageGreyScale;
    img.width = 0; img.height = 0;
    img.image.clear(); img.imageGreyScale.clear();
}

PNGImage& PNGImage::operator=(PNGImage& img){
    // Copy assignment operator.
    if(&img == this) return *this;
    imageGreyScale.clear(); image.clear();
    width = img.getWidth(); height = img.getHeight();
    bool copyCondition{height > 0 && width > 0};
    if(copyCondition){
        image = img.getImage();
        imageGreyScale = img.getImageGreyScale();
    }
    return *this;
}

PNGImage& PNGImage::operator=(PNGImage&& img){
    // Move assignment operator.
    std::swap(height, img.height); std::swap(width, img.width);
    image.swap(img.image); imageGreyScale.swap(img.imageGreyScale);
    return *this;
}

void PNGImage::showGreyScaleImage(){
    // Show a greyscale image in ascii art (must be 28x28 pixels).
    size_t k{0};
    for(size_t i=0; i<height; i++){
        for(size_t j=0; j<width; j++){
            if(imageGreyScale[k] < 0.125) std::cout<<" ";
            else std::cout<<"+";
            k++;
        }
        std::cout<<std::endl;
    }
}
