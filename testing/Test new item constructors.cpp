#include "Character.h"
#include "Spell_Attack.h"
#include <iostream>
#include <ctime>

int main()
{
	Weapon* w=new Weapon("Neno","Neno",1,1,2,4);
    std::cout<<w->getName()<<"\n";
	std::cout<<w->getDesc()<<"\n";
	std::cout<<w->getSimpleDesc()<<"\n";
	delete w;
	std::cin.get();
	return 0;
}
