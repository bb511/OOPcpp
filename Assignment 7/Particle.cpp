#include "Particle.h"
using namespace std;

double particle::checkMass(double m){
    if(m<0) throw invalid_argument("Mass cannot be lower than 0!");
    return m;
}

ostream& operator<<(ostream& os, particle& p){
    os<<"Particle details: \n";
    os<<"Mass: "<<p.getMass()<<endl;
    fourVector pos; pos = p.getPosition();
    os<<"Position: "<<pos<<endl;
    vector b(3); b = p.getBeta();
    os<<"Beta: "<<b<<endl;

    return os;
}
