#include "Weapon.h"

Weapon::Weapon(): Item()
{
	setType(WEAPON);
	this->dAttack.FACES=0;
	this->dAttack.ROLLS=0;
	this->dAttack.MOD=0;
}
Weapon::Weapon(std::string name,std::string desc,unsigned int price,
unsigned int diceFaces,unsigned int diceRolls,int diceMod)
	:Item(name,desc,price,WEAPON)
{
	this->dAttack.FACES=diceFaces;
	this->dAttack.ROLLS=diceRolls;
	this->dAttack.MOD=diceMod;
}
Weapon::~Weapon(){}
Weapon* Weapon::clone() {return new Weapon(*this);}

std::string Weapon::getSimpleDesc()
{
	std::string s=getName()+"<"+std::to_string(dAttack.ROLLS)+"D"+std::to_string(dAttack.FACES);
	s+=dAttack.MOD>=0?"+":"";
	s+=std::to_string(dAttack.MOD)+">";
	return s;
}
void Weapon::use(Creature* cObjetive)
{
	unsigned int damage=rollDice(dAttack);
	if(cObjetive->getAC())
	{
		if(cObjetive->getAC()/2>=damage)
		{
			damage/=2;
		}
	}
	cObjetive->setHP_CURRENT(cObjetive->getHP_CURRENT()-damage);
}
