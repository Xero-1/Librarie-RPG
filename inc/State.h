#ifndef STATE_H
#define STATE_H

#include "Entity.h"

enum
{
	HP=0,
	MP,
	AC,
	EVASION,
	MODIFIERS_MAX
}MODIFIERS;

class State: public Entity
{
private:
	unsigned int iDuration;
	float fModifiers[MODIFIERS_MAX];
public:
	State();
	State(std::string name,std::string desc,unsigned int duration);
	~State();
	inline unsigned int getDuration(){return this->iDuration;}
	inline float* getModifiers(){return this->fModifiers;}
	inline void setDuration(unsigned int i){this->iDuration=i;}
};

#endif
