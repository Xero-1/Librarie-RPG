#include "Spell.h"

Spell::Spell(): Entity()
{
	this->iCostMP=0;
	this->iType=0;
}
Spell::Spell(std::string name,std::string desc,unsigned int costMP,unsigned short int type)
	:Entity(name,desc)
{
	this->iCostMP=costMP;
	this->iType=type;
}
Spell::~Spell(){}
