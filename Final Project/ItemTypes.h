#ifndef ITEMTYPES_H
#define ITEMTYPES_H

#include <iostream>
#include <string>
#include <random>

typedef std::string str;

class Item{
protected:
    str itemName;
    str asciiArt;
    str iconAsciiArt;
public:
    // Constructors and destructors.
    Item(): asciiArt("Empty"), iconAsciiArt("Empty"), itemName("None") {}
    Item(str name, str aArt, str iconAArt):
        itemName(name), asciiArt(aArt), iconAsciiArt(iconAArt) {}
    virtual ~Item() {}

    // Functionality.
    virtual double attack(double)=0;
    virtual bool pryOpen(double)=0;
    virtual str itemType()=0;

    void changeName(str name) { itemName = name; }
    void changeAsciiArt(str aArt) { asciiArt = aArt; }
    void changeIcon(str iconAArt) { iconAsciiArt = iconAArt; }

    // Access functions.
    str getName() { return itemName; }
    str getAscii() { return asciiArt; }
    str getIcon() { return iconAsciiArt; }
    void showName() { std::cout<<itemName; }
    void showAscii() { std::cout<<asciiArt; }
    void showIcon() { std::cout<<iconAsciiArt; }
};

class DamageItem: public Item{
protected:
    size_t damageDealt;
public:
    DamageItem(): Item(), damageDealt(0) {}
    DamageItem(str name, str aArt, str iconAArt, size_t damage):
        Item(name, aArt, iconAArt) { damageDealt = damage; }
    virtual ~DamageItem() {}
    virtual bool pryOpen(double);
    double attack(double);
    size_t getDamageDealt() { return damageDealt; }
    str itemType() { return "damage"; }
};

class UtilityItem: public Item{
protected:
    double successMultiplier;
public:
    UtilityItem(): Item(), successMultiplier(0) {}
    UtilityItem(str name, str aArt, str iconAArt, double success):
        Item(name, aArt, iconAArt) { successMultiplier = success; }
    virtual ~UtilityItem() {}
    virtual double attack(double);
    bool pryOpen(double);
    double getSuccessMultiplier() { return successMultiplier; }
    str itemType() { return "utility"; }
};

#endif
