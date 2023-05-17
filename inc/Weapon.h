#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon: public Item
{
private:
	Dice dAttack;
public:
	Weapon();
	Weapon(std::string name,std::string desc,unsigned int price,
	unsigned int diceFaces,unsigned int diceRolls,int diceMod);
	~Weapon();
	Weapon* clone();
	inline Dice getDice(){return this->dAttack;}
	inline void setDice(unsigned int faces,unsigned int rolls,int mod=0)
	{
		this->dAttack.FACES=faces;
		this->dAttack.ROLLS=rolls;
		this->dAttack.MOD=mod;
	}
	std::string getSimpleDesc();
	void use(Creature* cObjetive) override;
};

#endif
