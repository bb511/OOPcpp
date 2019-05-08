#include "Character.h"

bool Character::takeDamage(size_t dmg){
    health -= dmg;
    std::cout<<"You dealt "<<dmg<<std::endl;
    if(health<=0){
        std::cout<<name<<" died!\n"<<std::endl;
        return false;
    }
    return true;
}

bool Character::dealDamage(Item* attackItm, Character* attackedChar){
    double damageDealt{attackItm->attack(attackedChar->getCharThreshold())};
    return attackedChar->takeDamage(damageDealt);
}
