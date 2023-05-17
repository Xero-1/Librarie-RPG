#ifndef LEVEL_H
#define LEVEL_H

class Level
{
private:
	unsigned int iLEVEL;
	unsigned int iEXP_NEXT;
	unsigned int iEXP_CURRENT;
public:
	Level(unsigned int level=0,unsigned int exp_next=0,unsigned int exp_current=0);
	~Level();
	inline unsigned int getLEVEL(){return this->iLEVEL;}
	inline unsigned int getEXP_NEXT(){return this->iEXP_NEXT;}
	inline unsigned int getEXP_CURRENT(){return this->iEXP_CURRENT;}
	inline void setLEVEL(unsigned int i){this->iLEVEL=i;}
	inline void setEXP_NEXT(unsigned int i){this->iEXP_NEXT=i;}
	inline void setEXP_CURRENT(unsigned int i){this->iEXP_CURRENT=i;}
};

#endif
