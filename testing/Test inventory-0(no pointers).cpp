#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include <iostream>

int main()
{
	system("clear");
	bool b=false;
	Inventory inv(5);
	Item tempItem;
	tempItem.setName("ITEM");
	Weapon tempW;
	tempW.setName("WEAPON");
	Armor tempA;
	tempA.setName("ARMOR");
	do
	{
		std::cout<<"Inventory capacity="<<inv.getNrItems()<<"/"<<inv.getCapacity()<<"\n";
		std::cout<<"----------------------------------------------"<<"\n";
		std::cout<<"ITEMS"<<"\n";
		for(int i=0;i<inv.getNrItems();i++)
			std::cout<<i+1<<"]"<<inv[i].getName()<<"\n";
		std::cout<<"----------------------------------------------"<<"\n";
		std::cout<<"1]Add Item"<<"\n";
		std::cout<<"2]Add Weapon"<<"\n";
		std::cout<<"3]Add Armor"<<"\n";
		std::cout<<"4]Remove Item"<<"\n";
		switch(std::cin.get())
		{
			case 'q':
				b=true;
				break;
			case '1':
				inv.addItem(tempItem);
				break;
			case '2':
				inv.addItem(tempW);
				break;
			case '3':
				inv.addItem(tempA);
				break;;
			case '4':
				inv.removeItem(0);
				break;
		}
		if(inv.getNrItems()>2)
			tempItem.setName("ITEMMMMMM");
		std::cin.ignore();
	}while(!b);

	return 0;
}
