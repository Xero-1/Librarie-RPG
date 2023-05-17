#include "Spell_buff.h"

Spell_buff::Spell_buff(): Spell()
{
	setType(BUFF);
}
Spell_buff::Spell_buff(std::string name,std::string desc,unsigned int costMP)
	:Spell(name,desc,costMP,BUFF)
{}
Spell_buff::~Spell_buff(){}
Spell_buff* Spell_buff::clone() {return new Spell_buff(*this);}

void Spell_buff::use(Creature* cObjetive)
{
	if(getEffect().getDuration())
		cObjetive->getStatus().push_back(getEffect());
}
