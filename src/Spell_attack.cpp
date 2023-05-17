#include "Spell_attack.h"

Spell_attack::Spell_attack(): Spell()
{
	setType(ATTACK);
	this->dAttack.FACES=0;
	this->dAttack.ROLLS=0;
	this->dAttack.MOD=0;
}
Spell_attack::Spell_attack(std::string name,std::string desc,unsigned int costMP,
unsigned int diceFaces,unsigned int diceRolls,int diceMod)
	:Spell(name,desc,costMP,ATTACK)
{
	this->dAttack.FACES=diceFaces;
	this->dAttack.ROLLS=diceRolls;
	this->dAttack.MOD=diceMod;
}
Spell_attack::~Spell_attack(){}
Spell_attack* Spell_attack::clone() {return new Spell_attack(*this);}

void Spell_attack::use(Creature* cObjetive)
{
	cObjetive->setHP_CURRENT(cObjetive->getHP_CURRENT()-rollDice(dAttack));
	if(getEffect().getDuration())
		cObjetive->getStatus().push_back(getEffect());
}
