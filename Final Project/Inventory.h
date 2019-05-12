#ifndef INVENTORY_H
#define INVENTORY_H

#include "ItemsAbstract.h"
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <stdexcept>

typedef std::map<std::string, Item*> inventoryMap;

class Inventory{
protected:
    inventoryMap items;
public:
    // Constructors and destructors.
    Inventory() {}
    Inventory(Item* itm1);
    Inventory(Item* itm1, Item* itm2);
    ~Inventory() {}

    // Access functions.
    Item* operator[](std::string itmName) { return items[itmName]; }
    int getItemsNumber() const { return items.size(); }
    inventoryMap getItems() const { return items; }
    inventoryMap::iterator begin() { return items.begin(); }
    inventoryMap::iterator end() { return items.end(); }
	bool checkForItem(std::string itemName);

    // Functionality.
    bool pickItem(Item* itm);
    bool dropItem(const std::string itmName);
};

#endif
