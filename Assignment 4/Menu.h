#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Galaxy.h"

void greetingsInstructions();
void menuOptions();
void displayGalaxies(std::vector<galaxy> galaxyList);
void afterSelectionMenuOptions();
void afterSelectionMenu(std::vector<galaxy> &galaxyList);
std::vector<galaxy>::iterator selectGalaxy(std::vector<galaxy> &galaxyList);
bool mainMenu(std::vector<galaxy> &galaxyList);

#endif
