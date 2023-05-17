#include "Armor.h"

Armor::Armor(): Item()
{
	setType(ARMOR);
	this->iDEF=0;
	this->iPartCover=0;
}
Armor::Armor(std::string name,std::string desc,unsigned int price,unsigned int def,unsigned short int partCover)
	:Item(name,desc,price,ARMOR)
{
	this->iDEF=def;
	this->iPartCover=partCover;
}
Armor::~Armor(){}
Armor* Armor::clone() {return new Armor(*this);}

std::string Armor::getSimpleDesc()
{
	return getName()+"<DEF+"+std::to_string(iDEF)+">";
}
