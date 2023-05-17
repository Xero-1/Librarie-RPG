#include "Npc.h"

Npc::Npc(): Creature_complex()
{
	this->iEXP_VALUE=0;
}
Npc::Npc(std::string name,std::string desc,float hp_max,float mp_max,unsigned int ac,unsigned int evasion,
	unsigned int exp_value,unsigned int inventory_capacity,bool inventory_expandable)
	:Creature_complex(name,desc,hp_max,mp_max,ac,evasion,inventory_capacity,inventory_expandable)
{
	this->iEXP_VALUE=exp_value;
}
Npc::~Npc(){}
