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
	int Z;
	cout<<"Please input the atomic number (Z) of the atom:\n";
	cin>>Z;
	int buffer = cin.peek();
	while(cin.fail() || Z <= 0 || buffer != '\n'){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cout<<"The atomic number should be a non-zero positive integer.\n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>Z;
		buffer = cin.peek();
	}
	return Z;
}

int readInitialQuantumNumber(){
	// Reads the initial quantum number and tests for valid input.
	int nInitial;
	cout<<"Please input initial quantum number (nInitial) of the transition:\n";
	cin>>nInitial;
	int buffer = cin.peek();
	while(cin.fail() || nInitial <= 1){
		cout<<"Sorry, your input was not valid.\n";
		cout<<"The initial quantum number must be a non-zero positive integer. "
			  "It also must not be one (no allowed transitions from 1). "
			  "Please try again:\n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>nInitial;
		buffer = cin.peek();
	};
	return nInitial;
}

int readFinalQuantumNumber(int nInitial){
	// Reads the final quantum number and tests for valid input.
	int nFinal;
	cout<<"Please input the final quantum number (nFinal) of the transition:\n";
	cin>>nFinal;
	int buffer = cin.peek();
	while(cin.fail() || nFinal <= 0 || (nInitial < nFinal)){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cout<<"The final quantum number must be a non-zero positive integer "
			  "that is lower than the initial quantum number. "
			  "Please try again:\n";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>nFinal;
		buffer = cin.peek();
	}
	return nFinal;
}

int readDesiredFormat(){
	// Reads the desired energy units and tests for valid input.
	char energyUnits;
	cout<<"What units should the energy be in, joules or eV? (J/e)\n";
	cin>>energyUnits;
	int buffer = cin.peek();
	while(cin.fail() || (energyUnits != 'J' && energyUnits != 'e')){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cout<<"The energy units can be either joules (input J) or electron "
			  "volts (input e): ";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>energyUnits;
		buffer = cin.peek();
	}
	return energyUnits;
}

Transition readUserData(){
	// Reads the input that the user needs to provide about the
	// transition he wants the energy calculated for.

	Transition transitionData;
	transitionData.Z = readAtomicNumber();
	transitionData.nI = readInitialQuantumNumber();
	transitionData.nF = readFinalQuantumNumber(transitionData.nI);
	transitionData.energyUnits = readDesiredFormat();

	return transitionData;
}

double calculateEnergy(Transition transitionData){
	// Calculates the energy of the transition described by transitionData.
	const double rydbergEnergy{13.6};
	return rydbergEnergy*pow(transitionData.Z,2)*(1/pow(transitionData.nF,2) -
		   1/pow(transitionData.nI, 2));
}

void outputFormattedEnergy(double energy, char energyUnits){
	// Formats and outputs the energy fo the transition.
	const double elementaryCharge{1.602*pow(10,-19)};
	cout<<"The energy of the transition is: ";
	if(energyUnits == 'J')
		cout<<setprecision(3)<<energy*elementaryCharge<<" J\n\n";
	else
		cout<<setprecision(5)<<energy<<" eV\n\n";
}

bool askForRepeat(){
	// Asks if the user wants to repeat the calculation with a different input
	// and checks if the input is valid.
	char repeat;
	cout<<"Would you like to repeat the calculation "
	      "with a different input? (y/n)\n";
	cin>>repeat;
	while(repeat != 'y' && repeat != 'n'){
		cout<<"Please enter either 'y' or 'n' (without the apostrophes): ";
		cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>repeat;
	};

	return repeat == 'n';
}

int main(){

	Transition transitionData;
	double energy;
	cout<<"Welcome to this simple single electron atom transition energy "
		  "calculator. Valid inputs for atomic number, initial quantum number "
		  "and final quantum number are non-zero positive integers. For the"
		  "energy units, this tool offers either Joules or electron volts.\n";

	while(true){
		transitionData = readUserData();
		energy = calculateEnergy(transitionData);
		outputFormattedEnergy(energy, transitionData.energyUnits);
		if(askForRepeat())
			break;
	};

	return 0;
}
