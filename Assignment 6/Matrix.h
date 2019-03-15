#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <math.h>

class matrix{
private:
    size_t rows, cols;
    double* mdata;
public:
    // Constructors and destructor.
    matrix(){rows=cols=0; mdata=0;}
    matrix(const size_t rw, const size_t cl);
    matrix(matrix& mat);
    matrix(matrix&& mat);
    ~matrix(){delete[] mdata;}

    // Access Functions
    size_t index(size_t i, size_t j);
    size_t rowsln() const{ return rows; }
    size_t colsln() const{ return cols; }

    // Overloaded operators
    double& operator()(size_t i, size_t j){ return mdata[index(i,j)]; }
    matrix& operator=(matrix& mat);
    matrix& operator=(matrix&& mat);
    matrix operator+(matrix& mat);
    matrix operator-(matrix& mat);
    matrix operator*(matrix& mat);

    // Manipulation functions
    matrix getMinor(size_t row, size_t col);
    double determinant();

    // Friends
    friend std::ostream& operator<<(std::ostream &os, matrix& mat);
    friend std::istream& operator>>(std::istream &os, matrix& mat);
};

#endif
