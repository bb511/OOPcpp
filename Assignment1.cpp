/*
Assignment 1
Author: Denis-Patrick Odagiu
Date: 30/01/2019
*/

#include <iostream>
#include <iomanip>
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
	int Z;
	cout<<"Please input the atomic number (Z) of the atom:\n"
	cin>>Z;
	while(cin.fail() || Z == 0){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cin.clear(); cin.ignore(10000, '\n'); cin>>Z;
	}
	return Z;
}

int readInitialQuantumNumber(){
	int nInitial;
	cout<<"Please input initial quantum number (nInitial) of the transition:\n"
	cin>>nInitial;
	while(cin.fail() || nInitial == 0){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cin.clear(); cin.ignore(10000, '\n'); cin>>nInitial;
	};
	return nInitial;
}

int readFinalQuantumNumber(){
	int nFinal;
	cout<<"Please input the final quantum number (nFinal) of the transition:\n"
	cin>>nFinal;
	while(cin.fail() || nFinal == 0){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cin.clear(); cin.ignore(10000, '\n'); cin>>nFinal;
	}
	return nFinal;
}

int readDesiredFormat(){
	char energyUnits;
	cout<<"What units should the energy be in?:\n"
	cin>>energyUnits;
	while(cin.fail() || (energyUnits != 'J' || energyUnits != 'e')){
		cout<<"Sorry, your input was not valid, please try again:\n";
		cin.clear(); cin.ignore(10000, '\n'); cin>>energyUnits;
	}
	return energyUnits;
}

Transition readUserData(){
	// Function that reads the user input (i.e. fills the struct Transition).

	Transition transitionData;
	cout<<"These are instructions";

	return transitionData;
}

float calculateEnergy(Transition transitionData){
	// Function that calculates the energy of a transition

}

char askForRepeat(char repeat){
	cout<<"Would you like to repeat the calculation
	       with a different input? (y/n)";
	cin>>repeat;
	while(repeat != 'y' || repeat != 'n'){
		cout<<"Please enter either 'y' or 'n' (without the apostrophes)";
		cin<<repeat;
	};

	return repeat;
}

int main(){

	Transition transitionData;
	char repeat{'y'};

	while(repeat != 'n'){

		transitionData = readUserData();
		calculateEnergy(transitionData)
		askForRepeat(repeat);
	};
}
