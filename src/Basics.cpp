#include "Basics.h"

int roll(unsigned int faces,unsigned int rolls,int mod)
{
	int result=0;
	for(int i=0;i<rolls;i++)
		result+=rand()%faces+1;
	return result-mod;
}
int rollDice(Dice d)
{
	return roll(d.FACES,d.ROLLS,d.MOD);
}
