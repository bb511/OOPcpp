// Enemy characters in the adventure game. All are derived from the Character
// base class.
#ifndef GMAN_H
#define GMAN_H

#include "Character.h"
#include <iostream>
#include <string>


class Gman: public Character{
public:
    // Constructors and destructors.
    Gman(): Character() {}
    Gman(std::string nm, size_t h, double t): Character(nm, h, t) {}
    ~Gman() {}

    // Dialogue lines for Gman.
    std::string charAscii();
    std::string lineIntro();
    std::string lineIntro2();
    std::string lineFinal();
	std::string linePlayer();

    // Gman cannot take damage.
    bool takeDamage() { return false; }
};

class Guard: public Character{
public:
    // Constructors and destructors.
    Guard(): Character() {}
    Guard(std::string nm, size_t h, double t, Item* itm):
        Character(nm, h, t, itm) {}
    ~Guard() {}

    // Dialogue lines for all guards.
    std::string charAscii(bool type);
    std::string lineAlerted();
	std::string lineConfused();
	std::string lineLeave();
    std::string lineCooperation();
	std::string lineKnife();
	std::string lineFinal();
};

#endif
