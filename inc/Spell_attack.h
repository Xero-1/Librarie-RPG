#ifndef SPELL_ATTACK
#define SPELL_ATTACK

#include "Spell.h"

class Spell_attack: public Spell
{
private:
	Dice dAttack;
public:
	Spell_attack();
	Spell_attack(std::string name,std::string desc,unsigned int costMP,
	unsigned int diceFaces,unsigned int diceRolls,int diceMod);
	~Spell_attack();
	Spell_attack* clone();
	inline Dice getDice(){return this->dAttack;}
	inline void setDice(unsigned int faces,unsigned int rolls,int mod=0)
	{
		this->dAttack.FACES=faces;
		this->dAttack.ROLLS=rolls;
		this->dAttack.MOD=mod;
	}
	void use(Creature* cObjetive) override;
};

#endif
