// Classes for all the items in the game. These are all derived from either the
// the UtilityItem or DamageItem base classes.
#ifndef ITEMS_H
#define ITEMS_H

#include "ItemsAbstract.h"

class Crowbar: public UtilityItem{
public:
    Crowbar(): UtilityItem() {}
    Crowbar(double successMultiplier);
    // Overwrite attack method since crowbar special item.
    size_t attack(double);
    ~Crowbar() {}
};

class Pen: public DamageItem{
public:
    Pen(): DamageItem() {}
    Pen(size_t damage);
    ~Pen() {}
};

class Knife: public DamageItem{
public:
    Knife(): DamageItem() {}
    Knife(size_t damage);
    // Overwrite pryOpen method since knife special item.
    bool pryOpen(double);
    ~Knife() {}
};

class Pistol: public DamageItem{
public:
    Pistol(): DamageItem() {}
    Pistol(size_t damage);
    ~Pistol() {}
};

#endif
