#ifndef CHARACTER_H
#define CHARACTER_H

#include "Npc.h"
#include "Armor.h"
#include "Level.h"

class Character: public Creature_complex, public Level
{
private:
	Armor cArmorSet[BODY_PARTS_MAX];
public:
	Character();
	Character(std::string name,std::string desc,float hp_max,float mp_max,unsigned int ac,unsigned int evasion,
	unsigned int level,unsigned int exp_next,unsigned int exp_current,
	unsigned int inventory_capacity=5,bool inventory_expandable=false);
	~Character();
	inline Armor* getArmorSet(){return this->cArmorSet;}
	bool attack(Npc* cObjetive);
	void equipItem(Item* cItem);
	void equipFromInv(unsigned int index);
};

#endif
