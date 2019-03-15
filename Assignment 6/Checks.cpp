#include "Checks.h"
using namespace std;

bool checkRowsCols(size_t rows, size_t cols){
    if(rows>1 && cols>1) return true;
    throw invalid_argument("Wrong matrix def!");
}

bool checkRowCol(size_t row, size_t col){
    if(row>0 && col>0) return true;
    throw invalid_argument("Wrong index to compute minor!");
}

bool checkSquareMat(size_t rows, size_t cols){
    if(rows==cols) return true;
    throw invalid_argument("Cannot calculate determinant for non-square mat!");
}

bool checkCompatDim(size_t rows1, size_t cols1, size_t rows2, size_t cols2){
    if(rows1 == rows2 && cols1 == cols2) return true;
    throw invalid_argument("Adding matrices with different dimensions!");
}
