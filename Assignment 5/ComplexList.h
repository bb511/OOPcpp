#ifndef COMPLEXLIST_H
#define COMPLEXLIST_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Complex.h"

complex selectNumber(std::vector<complex> numberList);
std::vector<complex> selectNumbers(std::vector<complex> numberList);
void displayNumbers(std::vector<complex>);
void addNumbers(std::vector<complex> numberList);
void subtractNumbers(std::vector<complex> numberList);
void multiplyNumbers(std::vector<complex> numberList);
void divideNumbers(std::vector<complex> numberList);

#endif
