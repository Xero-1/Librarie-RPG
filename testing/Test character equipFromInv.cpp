#include "Character.h"
#include <iostream>

int main()
{
	Character player;
	Weapon w;
	w.setName("WEAPON");
	w.setDice(10,25,2);
	player.getInv().addItem(&w);
	Armor a;
	a.setDEF(20);
	player.getInv().addItem(&a);
	player.equipFromInv(0);
	player.equipFromInv(0);

	std::cout<<"Player weapon="<<player.getWeapon().getName()<<"<"<<player.getWeapon().getDice().ROLLS<<">"<<"\n";
	std::cout<<"Player AC="<<player.getAC()<<"\n";
	std::cout<<"Inv="<<player.getInv().getNrItems()<<"/"<<player.getInv().getCapacity()<<"\n";

	std::cin.get();

	return 0;
}
