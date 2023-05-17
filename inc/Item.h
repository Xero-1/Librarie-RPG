#ifndef ITEM_H
#define ITEM_H

#include "Creature.h"

enum
{
	WEAPON=1,
	ARMOR
}ITEM_TYPES;

class Item: public Entity
{
private:
	unsigned int iPrice;
	unsigned short int iType;
public:
	Item();
	Item(std::string name,std::string desc,unsigned int price,unsigned short int type);
	~Item();
	virtual Item* clone(){return nullptr;}
	inline unsigned int getPrice(){return this->iPrice;}
	inline unsigned short int getType(){return this->iType;}
	inline void setPrice(unsigned int i){this->iPrice=i;}
	inline void setType(unsigned short int i){this->iType=i;}
	virtual void use(Creature* cObjetive){}
};

#endif
