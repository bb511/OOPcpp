#include "Inventory.h"

Inventory::Inventory(Item* itm1){
    items[itm1->getName()] = itm1;
}

Inventory::Inventory(Item* itm1, Item* itm2){
    items[itm1->getName()] = itm1;
    items[itm2->getName()] = itm2;
}

bool Inventory::checkForItem(std::string itemName){
	inventoryMap::iterator it;
	it = items.find(itemName);
	if (it != items.end())
		return true;
	return false;
}

bool Inventory::pickItem(Item* itm){
    bool fullInventory(items.size() >= 2);
    if(fullInventory) return false;
	else items[itm->getName()] = itm->Clone();
    return true;
}

bool Inventory::dropItem(const std::string itmName){
	try{ items.erase(itmName); return true; }
    catch(const std::exception& e){
        return false;
    }
}


