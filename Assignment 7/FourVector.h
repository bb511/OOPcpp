#ifndef FOURVECTOR_H
#define FOURVECTOR_H

#include "Vector.h"
#include "Checks.h"
#include <iostream>
#include <math.h>

class fourVector: public vector{
// 4-dimensional vector class
public:
    // Constructors and destructors.
    fourVector(): vector(4) {}
    fourVector(double ct, double x, double y, double z): vector(4)
    { components[0] = ct; components[1] = x; components[2] = y; components[3] = z; }
    fourVector(double ct, vector& r): vector(4)
    { check3Vector(r.getDimension()); components[0] = ct;
      components[1] = r(1); components[2] = r(2); components[3] = r(3); }
    fourVector(fourVector& fourV): vector(fourV) {}
    fourVector(fourVector&& fourV): vector(std::move(fourV)) {}
    ~fourVector() {}

    // Operators.
    fourVector& operator=(fourVector& fourV){ vector::operator=(fourV); return *this; }
    fourVector& operator=(fourVector&& fourV){ vector::operator=(std::move(fourV)); return *this; }

    // Accesors.
    double getct(){ return components[0]; }
    double getx(){ return components[1]; }
    double gety(){ return components[2]; }
    double getz(){ return components[3]; }
    vector spacePart();

    // Functionality.
    double dot(fourVector&);
    fourVector boost(vector&);

    // Friends.
    friend std::ostream& operator<<(std::ostream& os, fourVector& fourV);
    friend std::istream& operator>>(std::istream& is, fourVector& fourV);
};

#endif
