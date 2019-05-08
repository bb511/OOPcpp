#ifndef GMAN_H
#define GMAN_H

#include "Character.h"
#include <string>
#include <iostream>

class Gman: public Character{
public:
    Gman(): Character() {}
    Gman(std::string nm, size_t h, double t): Character(nm, h, t) {}
    ~Gman() {}

    void showCharacter();
    std::string lineIntro();
    std::string lineIntro2();
    std::string lineFinal();
    bool takeDamage() { return false; }
};

class Guard: public Character{
public:
    Guard(): Character() {}
    Guard(std::string nm, size_t h, double t, Item* itm):
        Character(nm, h, t, itm) {}
    ~Guard() {}

    void showCharacter();
    std::string lineAlerted();
    std::string lineCooperation();
    std::string lineWrongPath();
};

#endif
