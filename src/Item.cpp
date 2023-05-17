#include "Item.h"

Item::Item(): Entity()
{
	this->iPrice=0;
	this->iType=0;
}
Item::Item(std::string name,std::string desc,unsigned int price,unsigned short int type)
	:Entity(name,desc)
{
	this->iPrice=price;
	this->iType=type;
}
Item::~Item(){}
