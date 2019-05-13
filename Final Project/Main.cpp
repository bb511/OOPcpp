/*
Title: Freeman escapes prison
Author: Patrick Odagiu

Simple text based adventure game where a neural network is implemented to
add to the player experience. The player is presented with choices in each
level and he must choose wisely to win.
*/
#include <iostream>
#include <stdexcept>
#include "NeuralNetwork/neuralNet.h"
#include "PNGProcessing.h"

#include "WindowsDisplay.h"
#include "Character.h"
#include "Enemies.h"
#include "Items.h"
#include "Environment.h"
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
	// The intro screen to the game.
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
	// The game begins with instructions for the player.
	char userInput;
	clearScreen();
	displayCentredObject(cellDoorClosed(),14,8);
	displayCentredText("You are G. Freeman, inmate at the Manny penitentiary.",
					   0, true);
	displayCentredText("Today is the day you escape. You have 5 minutes to"
					   "do so.", 1, true);
	displayCentredText("Use the numbers on your keyboard (1-9) to make choices.",
					   2, true);
	displayCentredText("The clock is ticking (top right).", 3, true);
	displayCentredText("[ENTER] Escape!", 7, false);
	userInput = _getch();
	if (userInput == '\r') return false;
	return true;
}

void firstPart(){
	// The first part of the game. At the end, the main character always dies.
	if(!cellLevel(&mainChar, &barney)) throw std::runtime_error("Cell level error!");
	if(!corridorLevel(&mainChar)) throw std::runtime_error("Corridor level error!");
	if(!kitchenLevel(&mainChar)) throw std::runtime_error("Kitchen level error!");
	if(!finalLevel(&mainChar, &adrian)) throw std::runtime_error("Final level error!");
	gmanEpilogue(&gman);
}

std::string lockerCode(){
	// The locker code is read from the gameImg.png file that is supposed to be
	// edited by the player given instructions in the game.
	loadNeuralNet();
	PNGImage img("gameImg.png");
	int digitOne{NN.forwardPass(img.getGreyScalePointer(0))};
	int digitTwo{NN.forwardPass(img.getGreyScalePointer(32))};
	int digitThr{NN.forwardPass(img.getGreyScalePointer(64))};
	std::ostringstream code;
	code<<digitOne<<digitTwo<<digitThr;
	return code.str();
}

void secondPart(std::string code){
	// The second part of the game. The true ending is achieved here.
	if (!checkNumbers(code, &gman))
		giveCrowbar(&mainChar, &gman);
	if(!lockerLevel(&mainChar, code)) throw std::runtime_error("Locker level error!");
	if(!finalLevel(&mainChar, &adrian)) throw std::runtime_error("Final level error!");
}

int main(){
	// Implementation of text based adventure game using neural network.
	maximizeConsole(); getConsoleSize();
	if (!gameIntro()) return 0;
	// Start the timer.
	auto future{std::async(timer)};

	// Start the game.
	while (closedDoor());
	firstPart();
	std::string code{lockerCode()};
	secondPart(code);
    return 0;
}
