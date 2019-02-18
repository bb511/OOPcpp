/*
Title: Assignment 4: A Class for Galaxies
Author: Patrick Odagiu

This simple program does blah.
*/
#include "Assignment 4.h"
#include "Checks.h"

void galaxy::printData(){
    // Prints out the data associated with a galaxy object.
    cout.precision(3);
    cout<<"Hubble type: "<<hubbleType<<endl;
    cout<<"Redshift: "<<redShift<<endl;
    cout<<"Total mass: "<<totalMass<<endl;
    cout<<"Stellar mass fraction: "<<stellarMassFrac<<endl;
}

void greetingsInstructions(){
    // Displays a greeting to the user and provides some instructions.
    cout<<"Welcome to this simple galaxy storer.\n";
    cout<<"First, please provide, on one line, the Hubble type, redshift, "
          "total mass, and stellar mass fraction for your galaxy (or galaxies).\n";
    cout<<"To exit the data input phase please type \"stop\".\n";
}

tuple<string, double, double, double> getUserInput(){
    // Reads in the user input and returns a tuple.
    string hubbleType; double redShift, totalMass, stellarMassFrac;
    cin>>hubbleType;
    if(!hubbleType.compare("stop")) return make_tuple("stop", 0, 0, 0);
    cin>>redShift>>totalMass>>stellarMassFrac;
    return make_tuple(hubbleType, redShift, totalMass, stellarMassFrac);
}

void populateGalaxies(vector<galaxy> &galaxyList){
    while(true){
        auto uIn = getUserInput();
        if (!get<0>(uIn).compare("stop")) break;

        try{galaxyList.push_back(
            galaxy(get<0>(uIn), get<1>(uIn), get<2>(uIn), get<3>(uIn)));
            cout<<"Galaxy was stored in vector!\n";}
        catch(const exception& e){
            cout<<e.what(); cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');}
    }
}

int main()
{
    vector<galaxy> galaxyList;
    greetingsInstructions();
    populateGalaxies(galaxyList);
    return 0;
}
