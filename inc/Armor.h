#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

enum
{
	HEAD=0,
	TORSO,
	LEGS,
	FOOTS,
	BODY_PARTS_MAX
}BODY_PARTS;

class Armor: public Item
{
private:
	unsigned int iDEF;
	unsigned short int iPartCover;
public:
	Armor();
	Armor(std::string name,std::string desc,unsigned int price,unsigned int def,unsigned short int partCover);
	~Armor();
	Armor* clone();
	inline unsigned int getDEF(){return this->iDEF;}
	inline unsigned short int getPartCover(){return this->iPartCover;}
	inline void setDEF(unsigned int i){this->iDEF=i;}
	inline void setPartCover(unsigned short int i){this->iPartCover=i;}
	std::string getSimpleDesc();
};

#endif
