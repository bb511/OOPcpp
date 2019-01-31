/*
Assignment 1
Author: Denis-Patrick Odagiu
Date: 30/01/2019
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <limits>
using namespace std;

struct Transition{
	// Z = atomic number of the atom experiencing the transition
	// nI = initial quantum number
	// nF = final quantum number
	// energyUnits = choose if the output is in Joules or electron volts

	unsigned int Z;
	unsigned int nI, nF;
	char energyUnits;
};

int readAtomicNumber(){
	// Reads the atomic number and tests for valid input.
	unsigned int Z;
	cout<<"Please input the atomic number (Z) of the atom:\n";
	cin>>Z;
	while(cin.fail() || Z == 0){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>Z;
	}
	return Z;
}

int readInitialQuantumNumber(){
	// Reads the initial quantum number and tests for valid input.
	unsigned int nInitial;
	cout<<"Please input initial quantum number (nInitial) of the transition:\n";
	cin>>nInitial;
	while(cin.fail() || nInitial == 0){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>nInitial;
	};
	return nInitial;
}

int readFinalQuantumNumber(unsigned int nInitial){
	// Reads the final quantum number and tests for valid input.
	unsigned int nFinal;
	cout<<"Please input the final quantum number (nFinal) of the transition:\n";
	cin>>nFinal;
	while(cin.fail() || nFinal == 0 || (nInitial < nFinal)){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>nFinal;
	}
	return nFinal;
}

int readDesiredFormat(){
	// Reads the desired energy units and tests for valid input.
	char energyUnits;
	cout<<"What units should the energy be in, joules or eV? (J/e)\n";
	cin>>energyUnits;
	while(cin.fail() || (energyUnits != 'J' && energyUnits != 'e')){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>energyUnits;
	}
	return energyUnits;
}

Transition readUserData(){
	// Reads the input that the user needs to provide about the
	// transition he wants the energy calculated for.

	Transition transitionData;
	cout<<"Welcome to this simple single electron atom transition calculator. "
		  "Valid inputs for atomic number, initial quantum number and final "
		  "quantum number are non-zero positive integers. For the energy units, "
		  "this tool offers either Joules or electron volts.\n";
	transitionData.Z = readAtomicNumber();
	transitionData.nI = readInitialQuantumNumber();
	transitionData.nF = readFinalQuantumNumber(transitionData.nI);
	transitionData.energyUnits = readDesiredFormat();

	return transitionData;
}

float calculateEnergy(Transition transitionData){
	// Calculates the energy of the transition described by transitionData.
	const float rydbergEnergy{13.6};
	return rydbergEnergy*pow(transitionData.Z,2)*(1/pow(transitionData.nF,2) -
		   1/pow(transitionData.nI, 2));
}

void outputFormattedEnergy(float energy, char energyUnits){
	// Formats and outputs the energy fo the transition.
	const float elementaryCharge{1.602*pow(10,-19)};
	cout<<"The energy of the transition is: "<<setprecision(3);
	if(energyUnits == 'J')
		cout<<energy*elementaryCharge<<" J\n\n";
	else
		cout<<energy<<" eV\n\n";
}

char askForRepeat(char repeat){
	// Asks if the user wants to repeat the calculation with a different input
	// and checks if the input is valid.
	cout<<"Would you like to repeat the calculation "
	      "with a different input? (y/n)\n";
	cin>>repeat;
	while(repeat != 'y' && repeat != 'n'){
		cout<<"Please enter either 'y' or 'n' (without the apostrophes) ";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>repeat;
	};

	return repeat;
}

int main(){

	Transition transitionData;
	char repeat{'y'};
	float energy;

	while(repeat != 'n'){
		transitionData = readUserData();
		energy = calculateEnergy(transitionData);
		outputFormattedEnergy(energy, transitionData.energyUnits);
		repeat = askForRepeat(repeat);
	};

	return 0;
}
