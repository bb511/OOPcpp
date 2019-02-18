#include "Checks.h"
#include "Assignment 4.h"
using namespace std;

void galaxy::invalidInput(){
    if(cin.fail() || cin.peek() != '\n')
        throw invalid_argument("Your input was invalid!\n");
}

string galaxy::chkType(string hubbleType){
    // Check if the type of galaxy is correct.
    int aux{0};
    array<string, 14> validTypes{"E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7",
                                 "S0", "Sa", "Sb", "Sc", "SBa", "SBb"};
    for(const auto& type : validTypes)
        if(!type.compare(hubbleType)) aux = 1;
    if(aux == 0) throw invalid_argument("That type of galaxy does not exist!\n");
    return hubbleType;
}

double galaxy::chkRshift(double redShift){
    // Check if the redshift of the galaxy has correct values.
    galaxy::invalidInput();
    if(redShift < 0 || redShift > 10)
        throw invalid_argument("Redshift must be between 0 and 10!\n");
    return redShift;
}

double galaxy::chkTMass(double totalMass){
    // Check if the total mass of the galaxy has correct values.
    galaxy::invalidInput();
    if(totalMass < pow(10,7) || totalMass > pow(10,12))
        throw invalid_argument("Total mass must be between 1e7 and 1e12 Msun!\n");
    return totalMass;
}

double galaxy::chkSMassF(double stellarMassFrac){
    // Check if the stellar mass fraction of the galaxy has correct values.
    galaxy::invalidInput();
    if(stellarMassFrac < 0 || stellarMassFrac > 0.05)
        throw invalid_argument("Stellar mass fraction must be between"
                               "0 and 0.05 inclusive\n");
    return stellarMassFrac;
}
