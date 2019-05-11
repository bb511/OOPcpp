#include "ItemTypes.h"
#include "Utility.h"

size_t DamageItem::attack(double threshold){
    double roll{generateRandomNumber()};
    if(roll > threshold){
        return damageDealt;
    }
    return 0;
}

bool DamageItem::pryOpen(double threshold){
    double roll{generateRandomNumber()};
    if(roll > threshold + 0.5)
        return true;
    return false;
}

size_t UtilityItem::attack(double threshold){
    return 0;
}

bool UtilityItem::pryOpen(double threshold){
    double roll{generateRandomNumber()};
    if(successMultiplier*roll > threshold)
        return true;
    return false;
}
