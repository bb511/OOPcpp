#ifndef WINDOWSDISPLAY_H
#define WINDOWSDISPLAY_H

#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <string>

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
