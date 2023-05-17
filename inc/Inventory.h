#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>

class Inventory
{
private:
	unsigned int iCapacity;
	bool bExpandable;
	std::vector<Item*> cItems;
public:
	Inventory();
	~Inventory();
	inline unsigned int getNrItems(){return this->cItems.size();}
	inline unsigned int getCapacity(){return this->iCapacity;}
	inline bool getExpandable(){return this->bExpandable;}
	inline void setCapacity(unsigned int i){this->iCapacity=i;}
	inline void setExpandable(bool b){this->bExpandable=b;}
	inline Item* operator[](unsigned int index){return this->cItems[index];}
	bool addItem(Item* newItem);
	bool removeItem(unsigned int index);
};

#endif
