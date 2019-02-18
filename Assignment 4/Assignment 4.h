#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <algorithm>
using namespace std;

class galaxy{
    // Class that describes a galaxy.
private:
    // Galaxy properties.
    string hubbleType; double redShift, totalMass, stellarMassFrac;

    // Functions that check if the input of the user is correct.
    void invalidInput();
    string chkType(string);
    double chkRshift(double);
    double chkTMass(double);
    double chkSMassF(double);
public:
    galaxy() : hubbleType{"None"}, redShift{0}, totalMass{0}, stellarMassFrac{0} {}
    galaxy(string type, double z, double M, double fstar):
        hubbleType{chkType(type)}, redShift{chkRshift(z)},
        totalMass{chkTMass(M)}, stellarMassFrac{chkSMassF(fstar)}
    {}

    ~galaxy(){cout<<"Galaxy of type "<<hubbleType<<" has been destroyed.\n";}
    double stellarMass(){ return stellarMassFrac*totalMass; }
    void printData();
};
