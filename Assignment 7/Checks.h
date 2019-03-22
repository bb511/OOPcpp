#ifndef CHECKS_H
#define CHECKS_H

#include <iostream>
#include <stdexcept>
#include "Vector.h"

void checkIndexInside(size_t, size_t);
void checkValidDimension(const size_t);
void checkEqualDimensions(size_t, size_t);
void check3Vector(size_t);
vector checkValidBeta(vector&);

#endif
