#include "Creature.h"

Creature::Creature(): Entity()
{
	this->fHP_MAX=0;
	this->fHP_CURRENT=0;
	this->fMP_MAX=0;
	this->fMP_CURRENT=0;
	this->iAC=0;
	this->iEVASION=0;
}
Creature::Creature(std::string name,std::string desc,float hp_max,float mp_max,unsigned int ac,unsigned int evasion)
	:Entity(name,desc)
{
	this->fHP_MAX=hp_max;
	this->fHP_CURRENT=hp_max;
	this->fMP_MAX=mp_max;
	this->fMP_CURRENT=mp_max;
	this->iAC=ac;
	this->iEVASION=evasion;
}
Creature::~Creature(){}

void Creature::update()
{
	for(int i=0;i<cStatus.size();i++)
	{
		if(cStatus[i].getDuration())
		{
			cStatus[i].setDuration(cStatus[i].getDuration()-1);
			this->fHP_CURRENT+=cStatus[i].getModifiers()[HP];
			this->fMP_CURRENT+=cStatus[i].getModifiers()[MP];
		}else
			cStatus.erase(cStatus.begin()+i);
	}
}
unsigned int Creature::getStatusAC()
{
	int mod=0;
	for(int i=0;i<cStatus.size();i++)
		mod-=cStatus[i].getModifiers()[AC];
	if(iAC-mod<0)
		return 0;
	else
		return iAC-mod;
}
unsigned int Creature::getStatusEVASION()
{
	int mod=0;
	for(int i=0;i<cStatus.size();i++)
		mod-=cStatus[i].getModifiers()[EVASION];
	if(iEVASION-mod<0)
		return 0;
	else
		return iEVASION-mod;
}
