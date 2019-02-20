#include "Menu.h"
using namespace std;

void greetingsInstructions(){
    // Displays a greeting to the user and provides some instructions.
    cout<<"Welcome to this simple galaxy storer.\n";
    cout<<"First, please provide, on one line, the Hubble type, redshift, "
          "total mass, and stellar mass fraction for your galaxy.\n";
    cout<<"Continue one galaxy at a time.\n";
    cout<<"To exit the data input phase please type \"stop\".\n";
}

void menuOptions(){
    // Displays all the options in the main menu.
    cout<<"\nPlease choose an option by inputting the number of the option.\n";
    cout<<"1. Display all stored galaxies.\n";
    cout<<"2. Select a particular galaxy for further options.\n";
    cout<<"3. Quit.\n";
}

void showGalaxy(vector<galaxy>::iterator &chosenGalaxy, size_t number){
    cout<<"Galaxy number "<<number<<endl;
    cout<<"==============="<<endl;
    chosenGalaxy->printGalaxy();
}

void displayGalaxies(vector<galaxy> galaxyList){
    vector<galaxy>::iterator iter{galaxyList.begin()};
    size_t number{1};
    while(iter != galaxyList.end()){
        showGalaxy(iter, number);
        iter++; number++; cout<<endl;
    }
}

void displayGalaxiesWithSatellites(vector<galaxy> galaxyList){
    vector<galaxy>::iterator iter{galaxyList.begin()};
    size_t number{1}; cout<<endl;
    while(iter != galaxyList.end()){
        showGalaxy(iter, number);
        cout<<"---------------\n";
        cout<<"With satellites\n";
        cout<<"---------------\n";
        displayGalaxies(iter->getSatellites());
        iter++; number++; cout<<endl;
    }
}

vector<galaxy>::iterator selectGalaxy(vector<galaxy> &galaxyList){
    size_t galaxyNumber;
    cout<<"Please type a number from 1 to "<<galaxyList.size()<<" to select: ";
    cin>>galaxyNumber; cout<<endl;
    auto chosenGalaxy{galaxyList.begin() + (galaxyNumber - 1)};
    return chosenGalaxy;
}

void displayStellarMass(vector<galaxy>::iterator &chosenGalaxy){
    double stellarMass{chosenGalaxy->stellarMass()};
    cout<<"The stellar mass is: "<<stellarMass<<endl;
}

void changeGalaxyType(vector<galaxy>::iterator &chosenGalaxy){
    string otherType;
    cout<<"Please give the other type of galaxy you want: "; cin>>otherType;
    try{ chosenGalaxy->changeType(otherType); }
    catch(const exception& e){ cout<<e.what(); }
}

void afterSelectionMenuOptions(){
    cout<<"Please choose what to do with the selected galaxy.\n";
    cout<<"1. Change the galaxy's Hubble type.\n";
    cout<<"2. Calculate stellar mass and display it.\n";
}

void afterSelectionMenu(vector<galaxy> &galaxyList){
    size_t option;
    auto chosenGalaxy{selectGalaxy(galaxyList)};
    afterSelectionMenuOptions(); cin>>option;
    switch(option){
        case 1: changeGalaxyType(chosenGalaxy); break;
        case 2: displayStellarMass(chosenGalaxy); break;
        default: cout<<"Sorry, that is not a valid option.\n"; break;
    }
}

bool mainMenu(vector<galaxy> &galaxyList){
    size_t option;
    menuOptions(); cin>>option;

    switch(option){
        case 1: displayGalaxiesWithSatellites(galaxyList); break;
        case 2: afterSelectionMenu(galaxyList); break;
        case 3: return false;
        default: cout<<"Sorry, that is not a valid option.\n"; break;
    }
    return true;
}
