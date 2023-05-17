#ifndef MAGIC_H
#define MAGIC_H

#include "Spell.h"

class Magic
{
private:
	std::vector<Spell*> cSpells;
public:
	Magic();
	~Magic();
	inline unsigned int getNrSpells(){return this->cSpells.size();}
	inline Spell* operator[](unsigned int index){return this->cSpells[index];}
	void addSpell(Spell* newSpell);
	bool removeSpell(unsigned int index);
};

#endif
