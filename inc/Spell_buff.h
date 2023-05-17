#ifndef SPELL_BUFF
#define SPELL_BUFF

#include "Spell.h"

class Spell_buff: public Spell
{
private:
public:
	Spell_buff();
	Spell_buff(std::string name,std::string desc,unsigned int costMP);
	~Spell_buff();
	Spell_buff* clone();
	void use(Creature* cObjetive);
};

#endif
