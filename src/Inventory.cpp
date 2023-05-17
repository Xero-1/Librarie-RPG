#include "Inventory.h"

Inventory::Inventory()
{
	this->iCapacity=5;
	this->bExpandable=false;
}
Inventory::~Inventory()
{
	while(cItems.size())
		removeItem(0);
}

bool Inventory::addItem(Item* newItem)
{
	if(cItems.size()<iCapacity || bExpandable)
	{
		if(cItems.size()>=iCapacity)
			iCapacity+=5;
		cItems.push_back(newItem->clone());
		return true;
	}else
		return false;
}
bool Inventory::removeItem(unsigned int index)
{
	if(index<cItems.size())
	{
		delete cItems[index];
		cItems.erase(cItems.begin()+index);
		return true;
	}else
		return false;
}
