#ifndef ITEMS_H
#define ITEMS_H

#include "ItemTypes.h"
#include <string>


class Spoon: public UtilityItem{
public:
    Spoon(): UtilityItem() {}
    Spoon(double successMultiplier);
    ~Spoon() {}
};

class Crowbar: public UtilityItem{
public:
    Crowbar(): UtilityItem() {}
    Crowbar(double successMultiplier);
    double attack(double);
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
