#ifndef SPELL_H
#define SPELL_H

#include "Creature.h"

enum
{
	ATTACK=1,
	BUFF
}SPELL_TYPES;

class Spell: public Entity
{
private:
	unsigned int iCostMP;
	unsigned short int iType;
	State cEffect;
public:
	Spell();
	Spell(std::string name,std::string desc,unsigned int costMP,unsigned short int type);
	~Spell();
	virtual Spell* clone(){return nullptr;}
	inline unsigned short int getType(){return this->iType;}
	inline unsigned int getCostMP(){return this->iCostMP;}
	inline State getEffect(){return this->cEffect;}
	inline void setType(unsigned short int i){this->iType=i;}
	inline void setCostMP(unsigned int i){this->iCostMP=i;}
	inline void setEffect(State c){this->cEffect=c;}
	virtual void use(Creature* cObjetive){}
};

#endif
