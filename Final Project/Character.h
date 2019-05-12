#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "Inventory.h"
#include <iostream>
#include <string>

class Character{
protected:
    std::string name;
    int health;
    double agility;
public:
	Inventory charInv;
    Character(): name("Empty char"), health(0), agility(0), charInv() {}
    Character(std::string nm, size_t h, double t):
        name(nm), health(h), agility(t), charInv() {}
    Character(std::string nm, size_t h, double t, Item* itm):
        name(nm), health(h), agility(t), charInv(itm) {}
    Character(std::string nm, size_t h, double t, Item* itm1, Item* itm2):
        name(nm), health(h), agility(t), charInv(itm1, itm2) {}
    virtual ~Character() {}

	virtual std::string charAscii() { return "No ascii for this char!"; }
	virtual std::string charAscii(bool) { return "No ascii for this char!"; }
	virtual std::string charName() { return name; }
    virtual int takeDamage(size_t dmg);
    virtual int dealDamage(Item*, Character*);

	virtual std::string lineIntro() { return "Line not available!"; }
	virtual std::string lineIntro2() { return "Line not available!"; }
	virtual std::string lineFinal() { return "Line not available!"; }
	virtual std::string lineAlerted() { return "Line not available!"; }
	virtual std::string lineConfused() { return "Line not available!"; }
	virtual std::string lineLeave()  { return "Line not available!"; }
	virtual std::string lineCooperation() { return "Line not available!"; }
	virtual std::string lineKnife() { return "Line not available!";  }
	virtual std::string linePlayer() { return "Line not available!"; }

	int getHealth() { return health; }
    double getCharAgility() { return agility; }
};

#endif
