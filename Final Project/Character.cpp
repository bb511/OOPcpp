// Method implementation of Character base class.
#include "Character.h"

int Character::takeDamage(size_t dmg){
	// Character takes damage. Returns 1 if killed or 0 if survives.
    health -= dmg;
    if(health<=0)
		return 1;
    return 0;
}

int Character::dealDamage(Item* attackItm, Character* attackedChar){
	// Character deals damage with item to antoher character.
	// Returns 1 if the attacked character dies, 0 if damage was inflicted
	// or -1 if the current character does not posses the item.
	if(charInv.checkForItem(attackItm->getName())){
		double charThreshold{attackedChar->getCharAgility()};
		size_t damageDealt{attackItm->attack(charThreshold)};
		return attackedChar->takeDamage(damageDealt);
	}
	return -1;
}

bool Character::bruteOpen(Item* utilityItem, double chestThreshold){
	// Try to brute open an object in the game with ultility item.
	// The difficulty is set by the threshold.
	// Attempt can succeed (true) or fail (false).
	if (charInv.checkForItem(utilityItem->getName()))
		if (utilityItem->pryOpen(chestThreshold))
			return true;
	return false;

}
