#include <iostream>
#include <stdexcept>
#include "NeuralNetwork/neuralNet.h"
#include "PNGProcessing.h"

#include "WindowsDisplay.h"
#include "Character.h"
#include "Utility.h"

#include "Levels.h"

// Initialise the neural network.
NeuralNetwork<784, 30, 10> NN;

// Initialise the playable and non-playable characters.
static Character mainChar("Freeman", 100, 0.3);
static Gman gman("Gman", 100, 1.0);
static Guard barney("Barney", 2, 0.5, &Pistol(100));
static Guard adrian("Adrian", 150, 0.7, &Pistol(150));

void loadNeuralNet(){
    // Import neural network that reads digits.
    // This was trained by myself. Please see the NeuralNetwork folder.
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
	displayCentredText("You are G. Freeman, inmate at the Manny penitentiary.",
					   0, true);
	displayCentredText("Today is the day you escape. You have 5 minutes to"
					   "do so.", 1, true);
	displayCentredText("Use the numbers on your keyboard to make choices.",
					   2, true);
	displayCentredText("The clock is ticking (top right).", 3, true);
	displayCentredText("[ENTER] Escape!", 7, false);
	userInput = _getch();
	if (userInput == '\r') return false;
	return true;
}

void firstPart(){
	if(!cellLevel(&mainChar, &barney)) throw runtime_error("Cell level error!");
	if(!corridorLevel(&mainChar)) throw runtime_error("Corridor level error!");
	if(!kitchenLevel(&mainChar)) throw runtime_error("Kitchen level error!");
	if(!finalLevel(&mainChar, &adrian)) throw runtime_error("Final level error!");
	gmanEpilogue(&gman);
}

std::string lockerCode(){
	loadNeuralNet();
	PNGImage img("img.jpg");
	int digitOne{NN.forwardPass(img.getGreyscalePointer(0))};
	int digitTwo{NN.forwardPass(img.getGreyscalePointer(32))};
	int digitThr{NN.forwardPass(img.getGreyscalePointer(63))};
	std::ostringstream code;
	code<<digitOne<<digitTwo<<digitThr;
	return code.str();
}

void secondPart(std::string code){
	if (!checkNumbers(code, &gman))
		giveCrowbar(&mainChar, &gman);
	if(!lockerLevel(&mainChar, code)) throw runtime_error("Locker level error!");
	if(!finalLevel(&mainChar, &adrian)) throw runtime_error("Final level error!");
}

int main(){
	maximizeConsole(); getConsoleSize();
	if (!gameIntro()) return 0;
	auto future{std::async(timer)};
	while (closedDoor());
	firstPart();
	std::string code{lockerCode()};
	secondPart(code);
    return 0;
}
