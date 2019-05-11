#include "Inventory.h"

Inventory::Inventory(Item* itm1){
    items[itm1->getName()] = itm1;
}

Inventory::Inventory(Item* itm1, Item* itm2){
    items[itm1->getName()] = itm1;
    items[itm2->getName()] = itm2;
}

Inventory::Inventory(Inventory& inv){
    if(inv.getItemsNumber() != 0)
        items = inv.getItems();
}

Inventory::Inventory(Inventory&& inv){
    items = inv.items;
    inv.items.clear();
}

Inventory& Inventory::operator=(Inventory& inv){
    if(&inv == this) return *this;
    items.clear();
    if(inv.getItemsNumber() != 0) items = inv.getItems();
    return *this;
}

Inventory& Inventory::operator=(Inventory&& inv){
    items.swap(inv.items);
    return *this;
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


