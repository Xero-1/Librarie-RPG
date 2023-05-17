#ifndef ENTITY_H
#define ENTITY_H

#include "Basics.h"
#include <string>

class Entity
{
private:
	std::string sName;
	std::string sDesc;
public:
	Entity(std::string name="NONE",std::string desc="NONE");
	~Entity();
	inline std::string getName(){return this->sName;}
	inline std::string getDesc(){return this->sDesc;}
	inline void setName(std::string s){this->sName=s;}
	inline void setDesc(std::string s){this->sDesc=s;}
	virtual std::string getSimpleDesc(){return "NONE";}
};

#endif
