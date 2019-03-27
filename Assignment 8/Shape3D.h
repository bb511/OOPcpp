#ifndef SHAPE3D_H
#define SHAPE3D_H
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include "Shapes.h"

class cuboid: public shape3D{
// A geometrical cuboid shape.
protected:
    double length, width, height;
public:
    cuboid(): shape3D(12), length(0), width(0), height(0) {}
    cuboid(double l, double w, double h): shape3D(12)
    {length = l; width = w; height = h;}
    ~cuboid() {std::cout<<"Destructed cuboid.\n";}

    // Functionality
    double volume() {return length*width*height;}

    // Access functions.
    double getLength() { return length; }
    double getWidth() { return width; }
    double getHeight() { return height; }
};

class cube: public cuboid{
// A geometrical cube shape.
public:
    cube(): cuboid() {}
    cube(double l): cuboid(l,l,l) {}
    ~cube(){std::cout<<"Desctructed cube.\n";}
};

class ellipsoid: public shape3D{
// A geometrical ellipsoid shape.
protected:
    double semiaxa, semiaxb, semiaxc;
public:
    ellipsoid(): shape3D(1), semiaxa(0), semiaxb(0), semiaxc(0) {}
    ellipsoid(double a, double b, double c): shape3D(1)
    {semiaxa = a; semiaxb = b; semiaxc = c;}
    ~ellipsoid(){std::cout<<"Desctructed ellipsoid.\n";}

    // Functionality
    double volume() {return 4*M_PI*semiaxa*semiaxb*semiaxc/3;}

    // Access functions.
    double getSemiaxa() { return semiaxa; }
    double getSemiaxb() { return semiaxb; }
    double getSemiaxc() { return semiaxc; }
};

class sphere: public ellipsoid{
// A geometrical sphere shape.
public:
    sphere(): ellipsoid() {}
    sphere(double r): ellipsoid(r,r,r) {}
    ~sphere(){std::cout<<"Desctructed cube.\n";}
};

class prism: public shape3D{
// A geometrical prism shape.
private:
    double depth;
    shape2D* base;
public:
    prism(): shape3D(9), depth(0), base(0) {}
    prism(double d, shape2D* b): shape3D(b->getSides()*3), depth(d), base(b) {}
    ~prism() {std::cout<<"Desctructed prism.\n";}

    double volume() {return base->area()*depth;}
};

#endif
