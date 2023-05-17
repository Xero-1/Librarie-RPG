#include "Creature_complex.h"

Creature_complex::Creature_complex(): Creature()
{}
Creature_complex::Creature_complex(std::string name,std::string desc,float hp_max,float mp_max,
unsigned int ac,unsigned int evasion,unsigned int inventory_capacity,bool inventory_expandable)
	:Creature(name,desc,hp_max,mp_max,ac,evasion)
{
	cInv.setCapacity(inventory_capacity);
	cInv.setExpandable(inventory_expandable);
}
Creature_complex::~Creature_complex(){}

bool Creature_complex::attack(Creature* cObjetive)
{
	if(roll(20,1)>=roll(20,1,cObjetive->getEVASION()))//NPC dice vs objetive dice+EVASION
	{
		cWeapon.use(cObjetive);
		return true;
	}else
		return false;
}
bool Creature_complex::castSpell(Spell* cSpell,Creature* cObjetive)
{
	if(getMP_CURRENT()-cSpell->getCostMP()>=0)
	{
		setMP_CURRENT(getMP_CURRENT()-cSpell->getCostMP());
		cSpell->use(cObjetive);
		return true;
	}else
		return false;
}
void Creature_complex::castFromSpellBook(unsigned int index,Creature* cObjetive)
{
	castSpell(cSpellBook[index],cObjetive);
}
