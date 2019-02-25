#include "Complex.h"
using namespace std;

const double complex::modulus() const{
    // Returns the modulus of a complex number.
    return sqrt(pow(realPart, 2) + pow(imagPart, 2));
}

const double complex::argument() const{
    // Returns the argument of a complex number.
    if(realPart > 0) return atan(imagPart/realPart);
    if(realPart < 0 && imagPart >= 0) return atan(imagPart/realPart) + M_PI;
    if(realPart < 0 && imagPart > 0) return atan(imagPart/realPart) + M_PI;
    if(realPart == 0 && imagPart > 0) return M_PI/2;
    if(realPart == 0 && imagPart < 0) return -M_PI/2;
    if(realPart == 0 && imagPart == 0) return nan("0/0");
}

const complex complex::conjugate() const{
    // Returns the complex conjugate of a complex number.
    return complex(realPart,-imagPart);
}

ostream & operator<<(ostream &os, const complex &z){
    // Modify the operator to output complex numbers properly.
    if(z.imagPart >= 0) os<<z.realPart<<"+"<<z.imagPart<<"i";
    else os<<z.realPart<<z.imagPart<<"i";
    return os;
}

istream & operator>>(istream &is, complex &z){
    // Modify operator to input complex numbers properly.
    is>>z.realPart>>z.imagPart;
    return is;
}
