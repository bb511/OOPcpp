#ifndef ITEMS_H
#define ITEMS_H

#include "ItemTypes.h"

class Crowbar: public UtilityItem{
public:
    Crowbar(): UtilityItem() {}
    Crowbar(double successMultiplier);
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
