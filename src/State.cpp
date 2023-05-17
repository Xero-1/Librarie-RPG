#include "State.h"

State::State(): Entity()
{
	this->iDuration=0;
	for(int i=HP;i<MODIFIERS_MAX;i++)
		this->fModifiers[i]=0;
}
State::State(std::string name,std::string desc,unsigned int duration)
	:Entity(name,desc)
{
	this->iDuration=duration;
}
State::~State(){}
