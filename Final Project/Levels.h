#ifndef LEVELS_H
#define LEVELS_H

#include <conio.h>
#include <algorithm>
#include "Utility.h"
#include "Enemies.h"
#include "Environment.h"
#include "Items.h"

typedef std::vector < std::string > strVect;

char spawnOptions(std::string environment, size_t paddH, size_t paddW, strVect choices);
void findItem(Character* player, Item* itm);
bool checkForCellGuard(strVect &choices, Character* guard);

bool cellLevel(Character* player, Character* guard);
void screamHelp(strVect &choices, Character* guard);
bool leaveCell(strVect &choices, Character* guard);
void attackGuard(strVect &choices, Character* player, Character* guard, size_t &angry);
void guardRiposte(Character* guard, Character* player, size_t angry);
void missSwing(Character* guard);

bool corridorLevel(Character* player);
void hearPatrol();
void ventInitial();

bool kitchenLevel(Character* player);
void kitchenLevelEpi();

bool finalLevel(Character* player, Character* guard);
bool duelOfFaith(Character* player, Character* guard);
void finalShowdown(Character* player, Character* guard);
void gmanEpilogue(Character* gman);

bool lockerLevel(Character* player, std::string lockerCode);
bool checkNumbers(std::string code, Character* gman);
void giveCrowbar(Character* player, Character* gman);
void getCrowbar(Character* player);
void openCode(Character* player, std::string code);
void openCrowbar(Character* player);
void getGun(Character* player);
bool goExit(Character* player);


bool happyEnd(Character* guard);
void getCaughtEnd();
void bloodyEnd();

void dead();

#endif