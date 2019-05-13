// Levels for the current iteration of the game.
// These can be played with any character.
#ifndef LEVELS_H
#define LEVELS_H

#include "Character.h"
#include <conio.h>
#include <algorithm>

typedef std::vector <std::string> strVect;
typedef Character Cha;


char spawnOptions(std::string env, size_t paddH, size_t paddW, strVect choices);
void findItem(Cha* player, Item* itm);
bool checkForCellGuard(strVect &choices, Cha* guard);


bool cellLevel(Cha* player, Cha* guard);
void screamHelp(strVect &choices, Cha* guard);
bool leaveCell(strVect &choices, Cha* guard);
void attackGuard(strVect &choices, Cha* player, Cha* guard, size_t &angry);
void guardRiposte(Cha* guard, Cha* player, size_t angry);
void missSwing(Cha* guard);

bool corridorLevel(Cha* player);
void hearPatrol();
void ventInitial();


bool kitchenLevel(Cha* player);
void kitchenLevelEpi();


bool finalLevel(Cha* player, Cha* guard);
bool duelOfFaith(Cha* player, Cha* guard);
void finalShowdown(Cha* player, Cha* guard);
void gmanEpilogue(Cha* gman);


bool lockerLevel(Cha* player, std::string lockerCode);
bool checkNumbers(std::string code, Cha* gman);
void giveCrowbar(Cha* player, Cha* gman);
void getCrowbar(Cha* player);
void openCode(Cha* player, std::string code);
void openCrowbar(Cha* player);
void getGun(Cha* player);
bool goExit(Cha* player);

void dead();
void breakEnd();
void bloodyEnd();
void happyEnd(Character* guard);
void getCaughtEnd();
void bloodyEnd();

void dead();

#endif
