// Implementation of utility methods used throughout the code.
#include "Utility.h"
#include "WindowsDisplay.h"

double generateRandomNumber(){
    // Generate a random number from 0 to 1.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    return dis(gen);
}

void timer(){
    // Create the timer. Display it at the top right corner.
	int xCoord, yCoord;
	for (int i = 0; i < 300; i++){
		xCoord = consoleX(); yCoord = consoleY();
		placeCursor(0, 0);
		std::cout << 300-i<<"     ";
		placeCursor(xCoord, yCoord);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	exit(1);
}
