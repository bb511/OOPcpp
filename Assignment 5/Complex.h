#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>
#include <math.h>
#include "Checks.h"

class complex{
    // Class that encodes a complex number of the form z = x + iy.
private:
    double realPart, imagPart;
public:
    complex(): realPart{0}, imagPart{0} {}
    complex(double x, double y):
        realPart{x}, imagPart{y} {}
    ~complex(){std::cout<<"";}
    // Fundamental functions:
    const double getReal() const {return realPart;}
    const double getImag() const {return imagPart;}
    const double modulus() const;
    const double argument() const;
    const complex conjugate() const;
    // Operator overload:
    complex operator+(const complex &z) const{
        complex temp(realPart+z.getReal(), imagPart+z.getImag());
        return temp;
    }
    complex operator-(const complex &z) const{
        complex temp(realPart-z.getReal(), imagPart-z.getImag());
        return temp;
    }
    complex operator*(const complex &z) const{
        complex temp(realPart*z.getReal()-imagPart*z.getImag(),
                     realPart*z.getImag()+imagPart*z.getReal());
        return temp;
    }
    complex operator/(const double realNumber){
        complex temp(realPart/realNumber, imagPart/realNumber);
        return temp;
    }
    complex operator/(const complex &z) const{
        return complex(realPart, imagPart)*z.conjugate()/z.modulus();
    }
    // Friends:
    friend std::ostream & operator<<(std::ostream &os, const complex &z);
    friend std::istream & operator>>(std::istream &os, complex &z);
};

#endif
