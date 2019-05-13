// Display of the text based adventure game.
// This is kept in a separate file and not included in the game classes
// since it is platform specific (windows only).
#ifndef WINDOWSDISPLAY_H
#define WINDOWSDISPLAY_H

#include <conio.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include <vector>

void maximizeConsole();
void getConsoleSize();
void placeCursor(const size_t x, const size_t y);
void centreText(size_t idx, size_t &indConst, char currChar);
void displayCentredText(std::string line, int rowsDown, bool animate);
void displayCentredObject(std::string charAscii, int xpad, int ypad);
void clearScreen();
int consoleY();
int consoleX();
void displayChoices(std::vector<std::string> choices);

#endif
