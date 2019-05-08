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

bool Inventory::pickItem(Item* itm){
    bool fullInventory(items.size() >= 2);
    if(fullInventory) { std::cout<<"Sorry, inventory is full!"; return false; }
    else items[itm->getName()] = itm;
    return true;
}

void Inventory::dropItem(const std::string itmName){
    try{ items.erase(itmName); std::cout<<"Item dropped!\n"; }
    catch(const std::exception& e){
        std::cout<<"You selected to drop an inexistent item somehow!\n";
    }
}

std::ostream & operator<<(std::ostream &os, Inventory& inv){
    for(auto itr = inv.begin(); itr != inv.end(); itr++)
        os<<itr->second->getIcon()<<'\t';
    return os;
}


