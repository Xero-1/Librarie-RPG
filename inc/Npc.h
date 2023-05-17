#ifndef NPC_H
#define NPC_H

#include "Creature_complex.h"

class Npc: public Creature_complex
{
private:
	unsigned int iEXP_VALUE;
public:
	Npc();
	Npc(std::string name,std::string desc,float hp_max,float mp_max,unsigned int ac,unsigned int evasion,
	unsigned int exp_value,unsigned int inventory_capacity=5,bool inventory_expandable=false);
	~Npc();
	inline unsigned int getEXP_VALUE(){return this->iEXP_VALUE;}
	inline void setEXP_VALUE(unsigned int i){this->iEXP_VALUE=i;}
};

#endif
