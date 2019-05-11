#ifndef UTILITY_H
#define UTILITY_H

#include "Character.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <random>
#include <chrono>
#include <future>
#include <string>


double generateRandomNumber();
void maximizeConsole();
void getConsoleSize();
void placeCursor(const size_t x, const size_t y);
void centreText(size_t idx, size_t &indConst, char currChar);
void displayCentredText(std::string line, int rowsDown, bool animate);
void displayCentredObject(std::string charAscii, int xpad, int ypad);
void clearScreen();
void timer();
int consoleY();
int consoleX();
void displayChoices(std::vector<std::string> choices);

#endif
