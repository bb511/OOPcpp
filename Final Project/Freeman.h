#ifndef FREEMAN_H
#define FREEMAN_H

#include "Character.h"
#include <string>

class Freeman: public Character{
public:
    Freeman(): Character() {}
    Freeman(std::string nm, size_t h, double t): Character(nm, h, t) {}
    ~Freeman() {}

    void showCharacter() { std::cout<<"Playable char never shown!"; }
};

#endif
