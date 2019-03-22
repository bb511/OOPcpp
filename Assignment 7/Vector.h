#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdlib.h>

class vector{
// n-dimensional vector class.
protected:
    size_t dimension;
    double* components;
public:
    // Constructors and destructors.
    vector(){dimension=0; components=0;}
    vector(const size_t);
    vector(vector&);
    vector(vector&&);
    ~vector(){delete[] components;}

    // Access functions.
    size_t getDimension() const{ return dimension; }
    double& operator()(const size_t);

    // Operators.
    vector& operator=(vector&);
    vector& operator=(vector&&);

    // Functionality.
    double dot(vector&);

    // Friends.
    friend std::ostream& operator<<(std::ostream&, vector&);
    friend std::istream& operator>>(std::istream&, vector&);
};
#endif
