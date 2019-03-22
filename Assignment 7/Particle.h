#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <math.h>
#include <stdexcept>
#include "Vector.h"
#include "FourVector.h"

class particle{
private:
    double mass;
    fourVector position;
    vector beta;
    double checkMass(double);
public:
    // Constructors and destructors.
    particle(): mass(0), position(), beta() {}
    particle(double m, fourVector r, vector be):
        mass(checkMass(m)), position(r), beta(checkValidBeta(be)) {}
    ~particle() {}

    // Functionality.
    double gamma(){ return 1/(1-sqrt(beta.dot(beta))); }
    double energy(){ return this->gamma()*mass; }
    double momentum(){ return this->gamma()*mass*std::sqrt(beta.dot(beta)); }

    // Access functions.
    double getMass() { return mass; }
    fourVector getPosition() { return position; }
    vector getBeta() { return beta; }

    // Friends.
    friend std::ostream& operator<<(std::ostream& os, particle& p);
};

#endif
