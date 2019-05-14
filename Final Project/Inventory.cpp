// Method implementation of class that represents a characters inventory
// in a text based adventure game.
#include "Inventory.h"

Inventory::Inventory(Item* itm1){
    // Parametrized constructor that adds one item.
	items[itm1->getName()] = itm1->Clone();
}

Inventory::Inventory(Item* itm1, Item* itm2){
    // Parametrized constructor that adds two items.
	items[itm1->getName()] = itm1->Clone();
	items[itm2->getName()] = itm2->Clone();
}

bool Inventory::checkForItem(std::string itemName){
    // Checks if an item exists in the inventory.
	inventoryMap::iterator it;
	it = items.find(itemName);
	if (it != items.end())
		return true;
	return false;
}

bool Inventory::pickItem(Item* itm){
    // Gets an item and puts it in the inventory.
    bool fullInventory(items.size() >= 2);
    if(fullInventory) return false;
	else items[itm->getName()] = itm->Clone();
    return true;
}

bool Inventory::dropItem(const std::string itmName){
    // Erases an item from the inventory.
	try{ items.erase(itmName); return true; }
    catch(const std::exception& e){
        return false;
    }
}


