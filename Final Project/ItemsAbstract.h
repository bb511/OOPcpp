// Base item classes. All items in the game are derived from these classes.
#ifndef ITEMSABSTRACT_H
#define ITEMSABSTRACT_H

#include <iostream>
#include <string>
#include <random>

typedef std::string str;

class Item{
// Abstract base class containing functionality that all items should have.
protected:
    str itemName;
    str asciiArt;
public:
    // Constructors and destructors.
    Item(): asciiArt("Empty"),  itemName("None") {}
    Item(str name, str aArt): itemName(name), asciiArt(aArt) {}
	virtual Item* Clone() const = 0;
    virtual ~Item() {}

    // Functionality.
    virtual size_t attack(double)=0;
    virtual bool pryOpen(double)=0;
	virtual void changeDmgDealt(size_t dmg) {}
	virtual void changeSMulti(double success) {}

    // Access functions.
    str getName() { return itemName; }
    str getAscii() { return asciiArt; }

};

class DamageItem: public Item{
// Base class for items that are mainly used to deal damage.
protected:
    size_t damageDealt;
public:
    // Constructors and destructor.
    DamageItem(): Item(), damageDealt(0) {}
    DamageItem(str name, str aArt, size_t damage):
        Item(name, aArt) { damageDealt = damage; }
    // Functionality
	virtual DamageItem* Clone() const { return new DamageItem(*this); }
    virtual ~DamageItem() {}
    virtual bool pryOpen(double);
    size_t attack(double);
	void changeDamageDealt(size_t dmg) { damageDealt = dmg; }
};

class UtilityItem: public Item{
// Base class for items that are mainly used to unlock environment objects.
protected:
    double successMultiplier;
public:
    // Constructors and destructor.
    UtilityItem(): Item(), successMultiplier(0) {}
    UtilityItem(str name, str aArt, double success):
        Item(name, aArt) { successMultiplier = success; }
    // Functionality.
	virtual UtilityItem* Clone() const { return new UtilityItem(*this); }
    virtual ~UtilityItem() {}
    virtual size_t attack(double);
    bool pryOpen(double);
    void changeSMulti(double success) { successMultiplier = success; }
};

#endif
