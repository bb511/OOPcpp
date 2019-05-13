// Implementation of the methods present in the base item classes.
#include "ItemsAbstract.h"
#include "Utility.h"

size_t DamageItem::attack(double threshold){
    // Attack with item. The chance to miss is specified by threshold.
    double roll{generateRandomNumber()};
    if(roll > threshold){
        return damageDealt;
    }
    return 0;
}

bool DamageItem::pryOpen(double threshold){
    // Pry object open with damage item. Very hard to do so added threshold.
    double roll{generateRandomNumber()};
    if(roll > threshold + 0.5)
        return true;
    return false;
}

size_t UtilityItem::attack(double threshold){
    // Utility items deal no damage usually.
    return 0;
}

bool UtilityItem::pryOpen(double threshold){
    // Pry object opne with utility item. Added success change depending
    // on the item. Difficulty of opening set by the threshold.
    double roll{generateRandomNumber()};
    if(successMultiplier*roll > threshold)
        return true;
    return false;
}
