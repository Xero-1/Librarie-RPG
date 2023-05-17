#ifndef CREATURE_COMPLEX_H
#define CREATURE_COMPLEX_H

#include "Weapon.h"
#include "Inventory.h"
#include "Magic.h"

class Creature_complex: public Creature
{
private:
	Weapon cWeapon;
	Inventory cInv;
	Magic cSpellBook;
public:
	Creature_complex();
	Creature_complex(std::string name,std::string desc,float hp_max,float mp_max,unsigned int ac,unsigned int evasion,
	unsigned int inventory_capacity,bool inventory_expandable);
	~Creature_complex();
	inline Weapon getWeapon(){return this->cWeapon;}
	inline Inventory& getInv(){return this->cInv;}
	inline Magic& getSpellBook(){return this->cSpellBook;}
	inline void setWeapon(Weapon w){this->cWeapon=w;}
	bool attack(Creature* cObjetive) override;
	bool castSpell(Spell* cSpell,Creature* cObjetive);
	void castFromSpellBook(unsigned int index,Creature* cObjetive);
};

#endif
