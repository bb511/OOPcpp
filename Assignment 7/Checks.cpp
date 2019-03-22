#include "Checks.h"
using namespace std;

void checkIndexInside(size_t idx, size_t dimension){
    if(idx > dimension || idx < 1)
        throw invalid_argument("Index outside bounds!");
}

void checkValidDimension(const size_t dimension){
    if(dimension < 1)
        throw invalid_argument("The dimension cannot be less than 1!");
}

void checkEqualDimensions(size_t dimension1, size_t dimension2){
    if(dimension1 != dimension2)
        throw runtime_error("The two vectors have different dimensions!");
}

void check3Vector(size_t dimension){
    if(dimension != 3)
        throw invalid_argument("Not a 3D vector!");
}

vector checkValidBeta(vector& beta){
    check3Vector(beta.getDimension());
    if(beta(1) >= 1 || beta(2) >= 1 || beta(3) >= 1)
        throw invalid_argument("Beta comps cannot be large than 1!");
    return beta;
}
