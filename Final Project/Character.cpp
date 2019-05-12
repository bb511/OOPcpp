#include "Character.h"

int Character::takeDamage(size_t dmg){
    health -= dmg;
    if(health<=0)
		return 1;
    return 0;
}

int Character::dealDamage(Item* attackItm, Character* attackedChar){
	if (charInv.checkForItem(attackItm->getName())){
		double charThreshold{ attackedChar->getCharAgility() };
		size_t damageDealt{attackItm->attack(charThreshold)};
		return attackedChar->takeDamage(damageDealt);
	}
	return -1;
}

bool Character::bruteOpen(Item* utilityItem, double chestThreshold){
    if (charInv.checkForItem(utilityItem->getName())){
        if(utilityItem->pryOpen(chestThreshold))
            return true;
    return false;
}
