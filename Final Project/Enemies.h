#ifndef GMAN_H
#define GMAN_H

#include "Character.h"
#include <iostream>
#include <string>


class Gman: public Character{
public:
    Gman(): Character() {}
    Gman(std::string nm, size_t h, double t): Character(nm, h, t) {}
    ~Gman() {}

    std::string charAscii();
    std::string lineIntro();
    std::string lineIntro2();
    std::string lineFinal();
	std::string linePlayer();
    bool takeDamage() { return false; }
};

class Guard: public Character{
public:
    Guard(): Character() {}
    Guard(std::string nm, size_t h, double t, Item* itm):
        Character(nm, h, t, itm) {}
    ~Guard() {}

    std::string charAscii(bool type);
    std::string lineAlerted();
	std::string lineConfused();
	std::string lineLeave();
    std::string lineCooperation();
	std::string lineKnife();
	std::string lineFinal();
};

#endif
