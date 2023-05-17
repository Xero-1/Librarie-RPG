#include "Level.h"

Level::Level(unsigned int level,unsigned int exp_next,unsigned int exp_current)
{
	this->iLEVEL=level;
	this->iEXP_NEXT=exp_next;
	this->iEXP_CURRENT=exp_current;
}
Level::~Level(){}
