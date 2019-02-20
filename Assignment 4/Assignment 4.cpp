/*
Title: Assignment 4: A Class for Galaxies
Author: Patrick Odagiu

This simple program does blah.
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <algorithm>

#include "Galaxy.h"
#include "Checks.h"
#include "Menu.h"

using namespace std;

void galaxy::printGalaxy(){
    // Prints out the data associated with a galaxy object.
    cout.precision(3);
    cout<<"Hubble type: "<<hubbleType<<endl;
    cout<<"Redshift: "<<redShift<<endl;
    cout<<"Total mass: "<<totalMass<<endl;
    cout<<"Stellar mass fraction: "<<stellarMassFrac<<endl;
    cout<<"Number of satellites: "<<satellites.size()<<endl;
}

tuple<string, double, double, double> getUserInput(){
    // Reads in the user input and returns a tuple.
    string hubbleType; double redShift, totalMass, stellarMassFrac;
    cin>>hubbleType;
    if(!hubbleType.compare("stop")) return make_tuple("stop", 0, 0, 0);
    cin>>redShift>>totalMass>>stellarMassFrac;
    return make_tuple(hubbleType, redShift, totalMass, stellarMassFrac);
}

void storeGalaxy(vector<galaxy> &galaxyList, auto uIn){
    try{galaxyList.push_back(
        galaxy(get<0>(uIn), get<1>(uIn), get<2>(uIn), get<3>(uIn)));
        cout<<"Galaxy stored!\n";}
    catch(const exception& e){
        cout<<e.what(); cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');}
}

void populateGalaxies(vector<galaxy> &galaxyList){
    while(true){
        auto userInput = getUserInput();
        if (!get<0>(userInput).compare("stop")) {cout<<endl; break;}
        storeGalaxy(galaxyList, userInput);
    }
}

void storeSatellite(vector<galaxy>::iterator &chosenGalaxy, auto uIn){
    try{chosenGalaxy->addSatellite(
        galaxy(get<0>(uIn), get<1>(uIn), get<2>(uIn), get<3>(uIn)));
        cout<<"Satellite stored!\n";}
    catch(const exception& e){
        cout<<e.what(); cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');}
}

void populateSatellites(vector<galaxy> &galaxyList){
    auto chosenGalaxy{selectGalaxy(galaxyList)};
    while(true){
        auto userInput = getUserInput();
        if (!get<0>(userInput).compare("stop")) break;
        storeSatellite(chosenGalaxy, userInput);
    }
}

bool checkAnotherChoice(){
    cout<<"Would you like to add satellites to any other galaxy?(y/n)\n";
    char choice; cin>>choice;
    if(choice == 'y') return true;
    return false;
}

int main()
{
    vector<galaxy> galaxyList;
    greetingsInstructions();
    populateGalaxies(galaxyList);
    displayGalaxies(galaxyList);
    cout<<"Choose galaxy and give its satellites and say stop for stopping!\n";
    do{populateSatellites(galaxyList);} while(checkAnotherChoice());
    while(mainMenu(galaxyList));
    return 0;
}
