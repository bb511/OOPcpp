#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "Inventory.h"
#include <iostream>
#include <string>

class Character: public Inventory{
protected:
    std::string name;
    size_t health;
    double threshold;
public:
    Character(): name("Empty char"), health(0), threshold(0), Inventory() {}
    Character(std::string nm, size_t h, double t):
        name(nm), health(h), threshold(t), Inventory() {}
    Character(std::string nm, size_t h, double t, Item* itm):
        name(nm), health(h), threshold(t), Inventory(itm) {}
    haracter(std::string nm, size_t h, double t, Item* itm1, Item* itm2):
        name(nm), health(h), threshold(t), Inventory(itm, itm2) {}
    virtual ~Character() {}

    virtual void showCharacter()=0;
    virtual bool takeDamage(size_t dmg);
    virtual bool dealDamage(Item*, Character*);

    void addHealth(size_t h) { health += h; }
    void addName(std::string nm) { name = nm; }
    void addThreshold(double t) { threshold = t; }
    void displayHealth() { std::cout<<"Health: "<<health; }
    double getCharThreshold() { return threshold; }
};

#endif
