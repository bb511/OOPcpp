#ifndef SHAPES_H
#define SHAPES_H

#include <stdlib.h>

class shape{
// Abstract base class defining a geometrical shape.
protected:
    size_t sides;
public:
    shape(): sides(0) {}
    shape(size_t n): sides(n) {}
    virtual ~shape(){}
    virtual double area() {}
    virtual double volume() {}
    size_t getSides(){ return sides; }
};

class shape2D: public shape{
// Abstract base class defining a 2D geometrical shape.
public:
    shape2D(): shape() {}
    shape2D(size_t n): shape(n) {}
    virtual double area() {}
    virtual ~shape2D() {}
};

class shape3D: public shape{
// Abstract base class defining a 2D geometrical shape.
public:
    shape3D(): shape() {}
    shape3D(size_t n): shape(n) {}
    virtual double volume() {}
    virtual ~shape3D() {}
};

#endif
