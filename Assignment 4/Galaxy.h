#ifndef GALAXY_H
#define GALAXY_H

#include <iostream>
#include <vector>
#include <string>

class galaxy{
    // Class that describes a galaxy.
private:
    // Galaxy properties.
    std::string hubbleType; double redShift, totalMass, stellarMassFrac;
    std::vector<galaxy> satellites;
    // Functions that check if the input of the user is correct.
    void invalidInput();
    std::string chkType(std::string);
    double chkRshift(double);
    double chkTMass(double);
    double chkSMassF(double);
public:
    galaxy() : hubbleType{"None"}, redShift{0}, totalMass{0}, stellarMassFrac{0} {}
    galaxy(std::string type, double z, double M, double fstar):
        hubbleType{chkType(type)}, redShift{chkRshift(z)},
        totalMass{chkTMass(M)}, stellarMassFrac{chkSMassF(fstar)}
    {}

    ~galaxy(){}
    double stellarMass(){ return stellarMassFrac*totalMass; }
    void addSatellite(galaxy satellite){ satellites.push_back(satellite); }
    std::vector<galaxy> getSatellites(){ return satellites; }
    void changeType(std::string otherType){ hubbleType = otherType; }
    void printGalaxy();
};

#endif
