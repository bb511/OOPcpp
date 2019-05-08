#ifndef INVENTORY_H
#define INVENTORY_H

#include "ItemTypes.h"
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <memory>
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
    Inventory(Inventory&);
    Inventory(Inventory&&);
    ~Inventory() {}

    // Assignment and copy operators.
    Inventory& operator=(Inventory& inv);
    Inventory& operator=(Inventory&& inv);

    // Access functions.
    Item* operator[](std::string itmName) { return items[itmName]; }
    int getItemsNumber() const { return items.size(); }
    inventoryMap getItems() const { return items; }
    inventoryMap::iterator begin() { return items.begin(); }
    inventoryMap::iterator end() { return items.end(); }

    // Functionality.
    bool pickItem(Item* itm);
    void dropItem(const std::string itmName);

    friend std::ostream & operator<<(std::ostream &os, const Inventory &inv);
};

#endif
