#include <iostream>
#include "NeuralNetwork/neuralNet.h"
#include "PNGProcessing.h"

#include "Character.h"
#include "Items.h"
#include "Utility.h"

#include "Levels.h"

NeuralNetwork<784, 30, 10> NN;

static Character mainChar("Freeman", 100, 0.3);
static Gman gman("Gman", 100, 1.0);
static Guard barney("Barney", 2, 0.5, &Pistol(100));
static Guard adrian("Adrian", 150, 0.7, &Pistol(150));

void loadNeuralNet(){
    // Load neural network that reads digits.
    std::ifstream importFile("NeuralNetwork/exportedNetwork.txt");
    NN.importNeuralNet(importFile);
}

bool gameIntro(){
	char choice;
	displayCentredObject(gman.charAscii(),0,0);
	displayCentredText(gman.lineIntro(), 0, true);
	displayCentredText("Press [ANY KEY] to start...", 5, false);
	displayCentredText("Press [E] to exit.", 6, false);
	choice = _getch();
	if (choice == 'E' || choice == 'e') return false;
	return true;
}

bool closedDoor(){
	char userInput;
	clearScreen();
	displayCentredObject(cellDoorClosed(),14,8);
	displayCentredText("You are G. Freeman, inmate at the Manny penitentiary.", 0, true);
	displayCentredText("Today is the day you escape. You have 5 minutes to do so.", 1, true);
	displayCentredText("Use the numbers on your keyboard to make choices.", 2, true);
	displayCentredText("The clock is ticking (top right).", 3, true);
	displayCentredText("[ENTER] Escape!", 7, false);
	userInput = _getch();
	if (userInput == '\r') return false;
	return true;
}

bool firstPart(){
	size_t okCheck{ 0 };
	if (cellLevel(&mainChar, &barney)) okCheck++;
	if (corridorLevel(&mainChar)) okCheck++;
	if (kitchenLevel(&mainChar)) okCheck++;
	if (finalLevel(&mainChar, &adrian)) okCheck++;
	gmanEpilogue(&gman);
	if (okCheck == 4) return true;
	return false;
}

std::string lockerCode(){
	loadNeuralNet();
	PNGImage img("img.jpg");
	int digitOne{ 0 };
	int digitTwo{ 1 };
	int digitThr{ 2 };
	std::ostringstream code;
	code << digitOne << digitTwo << digitThr;
	return code.str();
}

void secondPart(std::string code){
	if (!checkNumbers(code, &gman))
		giveCrowbar(&mainChar, &gman);
	lockerLevel(&mainChar, code);
	finalLevel(&mainChar, &adrian);
}

int main(){
	maximizeConsole(); getConsoleSize();
	if (!gameIntro()) return 0;
	auto future{std::async(timer)};
	while (closedDoor());
	if (firstPart()){
		std::string code{ lockerCode() };
		secondPart(code);
	}
    return 0;
}
