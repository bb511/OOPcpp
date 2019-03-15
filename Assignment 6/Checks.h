#ifndef CHECKS_H
#define CHECKS_H

#include <iostream>
#include <stdexcept>

bool checkRowsCols(size_t rows, size_t cols);
bool checkRowCol(size_t row, size_t col);
bool checkSquareMat(size_t rows, size_t cols);
bool checkCompatDim(size_t rows1, size_t cols1, size_t rows2, size_t cols2);

#endif
