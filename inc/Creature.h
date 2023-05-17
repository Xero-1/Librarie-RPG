#ifndef CREATURE_H
#define CREATURE_H

#include "State.h"
#include <vector>

class Creature: public Entity
{
private:
	float fHP_MAX;
	float fHP_CURRENT;
	float fMP_MAX;
	float fMP_CURRENT;
	unsigned int iAC;
	unsigned int iEVASION;
	std::vector<State> cStatus;
public:
	Creature();
	Creature(std::string name,std::string desc,float hp_max,float mp_max,unsigned int ac,unsigned int evasion);
	~Creature();
	inline float getHP_MAX(){return this->fHP_MAX;}
	inline float getHP_CURRENT(){return this->fHP_CURRENT;}
	inline float getMP_MAX(){return this->fMP_MAX;}
	inline float getMP_CURRENT(){return this->fMP_CURRENT;}
	inline unsigned int getAC(){return this->iAC;}
	inline unsigned int getEVASION(){return this->iEVASION;}
	inline std::vector<State>& getStatus(){return this->cStatus;}
	inline void setHP_MAX(float f){this->fHP_MAX=f;}
	inline void setHP_CURRENT(float f){this->fHP_CURRENT=f;}
	inline void setMP_MAX(float f){this->fMP_MAX=f;}
	inline void setMP_CURRENT(float f){this->fMP_CURRENT=f;}
	inline void setAC(unsigned int i){this->iAC=i;}
	inline void setEVASION(unsigned int i){this->iEVASION=i;}
	virtual bool attack(Creature* cObjetive){return false;}
	void update();
	unsigned int getStatusAC();
	unsigned int getStatusEVASION();
};

#endif
