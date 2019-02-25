#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "Complex.h"

void greetingsInstructions();
void mainMenuInstructions();
void selectOneInstructions();
void selectMultipleInstructions();
bool selectOneMenu(std::vector<complex> numberList);
bool selectMultipleMenu(std::vector<complex> numberList);
bool mainMenu(std::vector<complex> numberList);

#endif
