#include "ItemTypes.h"
#include "Utility.h"

double DamageItem::attack(double threshold){
    double roll{generateRandomNumber()};
    if(roll > threshold){
        std::cout<<"You hit and deal "<<damageDealt<< "damage.\n";
        return damageDealt;
    }
    std::cout<<"You miss and deal no damage.\n";
    return 0;
}

bool DamageItem::pryOpen(double threshold){
    double roll{generateRandomNumber()};
    std::cout<<"You try using the "<<itemName;
    if(roll > threshold + 0.5){
        std::cout<<" and succeed!\n";
        return true;
    }
    std::cout<<" and fail! The item also breaks.\n";
    return false;
}

double UtilityItem::attack(double threshold){
    std::cout<<"You deal no damage.\n";
    return 0;
}

bool UtilityItem::pryOpen(double threshold){
    double roll{generateRandomNumber()};
    std::cout<<"You try using the "<<itemName;
    if(successMultiplier*roll > threshold){
        std::cout<<" and succeed!\n";
        return true;
    }
    std::cout<<" and fail!";
    return false;
}
