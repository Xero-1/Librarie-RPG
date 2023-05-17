#include "Character.h"

Character::Character(): Creature_complex(), Level()
{}
Character::Character(std::string name,std::string desc,float hp_max,float mp_max,unsigned int ac,unsigned int evasion,
unsigned int level,unsigned int exp_next,unsigned int exp_current,
unsigned int inventory_capacity,bool inventory_expandable)
	:Creature_complex(name,desc,hp_max,mp_max,ac,evasion,inventory_capacity,inventory_expandable)
	,Level(level,exp_next,exp_current)
{}
Character::~Character(){}

bool Character::attack(Npc* cObjetive)
{
	bool b=Creature_complex::attack(cObjetive);
	if(cObjetive->getHP_CURRENT()<0)
		setEXP_CURRENT(getEXP_CURRENT()+cObjetive->getEXP_VALUE());
	return b;
}
void Character::equipItem(Item* cItem)
{
	Weapon* w=dynamic_cast<Weapon*>(cItem);
	Armor* a=dynamic_cast<Armor*>(cItem);
	if(w)
	{
		setWeapon(*w);
	}else if(a)
	{
		cArmorSet[a->getPartCover()]=*a;
		unsigned int tempAC=0;
		for(int i=HEAD;i<BODY_PARTS_MAX;i++)
			tempAC+=cArmorSet[i].getDEF();
		setAC(tempAC);
	}
}
void Character::equipFromInv(unsigned int index)
{
	if(index<getInv().getNrItems())
	{
		equipItem(getInv()[index]);
		getInv().removeItem(index);
	}
}
