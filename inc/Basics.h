#ifndef BASICS_H
#define BASICS_H

#include <cstdlib>

struct Dice
{
	unsigned int FACES;
	unsigned int ROLLS;
	int MOD;
};

int roll(unsigned int faces,unsigned int rolls,int mod=0);
int rollDice(Dice d);

#endif
