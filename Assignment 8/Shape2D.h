#ifndef SHAPE2D_H
#define SHAPE2D_H
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include "Shapes.h"

class rectangle: public shape2D{
// A geometrical rectangle shape.
protected:
    double length, width;
public:
    rectangle(): shape2D(4), length(0), width(0) {}
    rectangle(double l, double w): shape2D(4)
    {length = l; width = w;}
    ~rectangle() {std::cout<<"Destructed rectangle.\n";}

    // Functionality
    double area()  {return length*width;}

    // Access functions.
    double getLength() { return length; }
    double getWidth() { return width; }
};

class square: public rectangle{
// A geometrical square shape.
public:
    square(): rectangle() {}
    square(double l): rectangle(l,l) {}
    ~square() {std::cout<<"Destructed square.\n";}
};

class ellipse: public shape2D{
// A geometircal ellipse shape.
protected:
    double semimajor, semiminor;
public:
    ellipse(): shape2D(1), semimajor(0), semiminor(0) {}
    ellipse(double a, double b): shape2D(1)
    {semimajor = a; semiminor = b;}
    ~ellipse() {std::cout<<"Destructed ellipse.\n";}

    // Functionality
    double area() {return M_PI*semimajor*semiminor;}

    // Access fuctnions.
    double getSMajor() { return semimajor; }
    double getSMinor() { return semiminor; }
};

class circle: public ellipse{
// A geometrical circle shape.
public:
    circle(): ellipse() {}
    circle(double radius): ellipse(radius, radius) {}
    ~circle() {std::cout<<"Destructed circle.\n";}
};

#endif
