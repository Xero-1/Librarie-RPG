#include "Magic.h"

Magic::Magic(){}
Magic::~Magic()
{
	while(cSpells.size())
		removeSpell(0);
}

void Magic::addSpell(Spell* newSpell)
{
	this->cSpells.push_back(newSpell->clone());
}
bool Magic::removeSpell(unsigned int index)
{
	if(index<cSpells.size())
	{
		delete cSpells[index];
		cSpells.erase(cSpells.begin()+index);
		return true;
	}else
		return false;
}
