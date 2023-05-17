#include "Character.h"
#include <iostream>
#include <ctime>

enum
{
	MAIN=0,
	COMBAT,
	SHOP
}MENUS_TYPES;

bool b;
unsigned short int menu;
Character player;
unsigned int gold;
Npc monster;

Weapon wList[4];
Armor aList[BODY_PARTS_MAX];

void draw();
void input();
void update();

int main()
{
	srand(time(NULL));
	b=false;
	gold=100;
	menu=MAIN;
	//WEAPONS LIST
	//FISTS
	wList[0].setName("Fists");
	wList[0].setDice(6,2);
	//SWORD
	wList[1].setName("Sword");
	wList[1].setDice(6,3,3);
	wList[1].setPrice(20);
	//AXE
	wList[2].setName("Axe");
	wList[2].setDice(8,2);
	wList[2].setPrice(10);
	//SPEAR
	wList[3].setName("Spear");
	wList[3].setDice(6,2,1);
	wList[3].setPrice(15);
	//ARMORS LIST
	//HELMET
	aList[0].setName("Helmet");
	aList[0].setDEF(5);
	aList[0].setPartCover(HEAD);
	aList[0].setPrice(20);
	//CHEST PLATE
	aList[1].setName("Chest plate");
	aList[1].setDEF(10);
	aList[1].setPartCover(TORSO);
	aList[1].setPrice(40);
	//GREAVES
	aList[2].setName("Greaves");
	aList[2].setDEF(5);
	aList[2].setPartCover(LEGS);
	aList[2].setPrice(20);
	//BOOTS
	aList[3].setName("Boots");
	aList[3].setDEF(7);
	aList[3].setPartCover(FOOTS);
	aList[3].setPrice(15);
	//PLAYER INITIALIZE
	player.setHP_MAX(100);
	player.setMP_MAX(100);
	player.setHP_CURRENT(player.getHP_MAX());
	player.setMP_CURRENT(player.getMP_MAX());
	player.setWeapon(wList[0]);
	player.getInv().setExpandable(true);
	system("clear");
	while(!b)
	{
		draw();
		input();
		update();
	}
	return 0;
}

void draw()
{
	std::cout<<"----------------------------"<<"\n";
	std::cout<<player.getName()<<"\n";
	std::cout<<"HP="<<(int)player.getHP_CURRENT()<<"/"<<(int)player.getHP_MAX()<<"\n";
	std::cout<<"MP="<<(int)player.getMP_CURRENT()<<"/"<<(int)player.getMP_MAX()<<"\n";
	std::cout<<"AC="<<player.getAC()<<"\n";
	std::cout<<"WEAPON="<<player.getWeapon().getSimpleDesc()<<"\n";
	std::cout<<"GOLD="<<gold<<"\n";
	std::cout<<"----------------------------"<<"\n";
	switch(menu)
	{
		case MAIN:
			std::cout<<"1]Combat"<<"\n";
			std::cout<<"2]Shop"<<"\n";
			std::cout<<"3]Rest"<<"\n";
			std::cout<<"4]Inventory"<<"\n";
			std::cout<<"5]Equipment"<<"\n";
			std::cout<<"0]Exit"<<"\n";
			break;
		case COMBAT:
			std::cout<<"1]Attack"<<"\n";
			std::cout<<"2]Escape"<<"\n";
			break;
		case SHOP:
			std::cout<<"1]Buy item"<<"\n";
			std::cout<<"2]Sell item"<<"\n";
			std::cout<<"3]Leave shop"<<"\n";
			break;
	}
	std::cout<<"----------------------------"<<"\n";
}
void input()
{
	std::cout<<"<<";
	unsigned int opt;
	std::cin>>opt;
	system("clear");
	if(menu==MAIN)
	{
		switch(opt)
		{
			case 0://EXIT
				b=true;
				break;
			case 1://COMBAT
				menu=COMBAT;
				monster.setName("Goblin");
				monster.setAC(5);
				monster.setWeapon(wList[3]);
				monster.setHP_CURRENT(30);
				break;
			case 2://SHOP
				menu=SHOP;
				break;
			case 3://REST
				player.setHP_CURRENT(player.getHP_MAX());
				player.setMP_CURRENT(player.getMP_MAX());
				std::cout<<"You rest and felt good back again."<<"\n";
				break;
			case 4://INVENTORY
				if(!player.getInv().getNrItems())
					std::cout<<"Your inventory is empty."<<"\n";
				else
				{
					for(int i=0;i<player.getInv().getNrItems();i++)
						std::cout<<i+1<<"]"<<player.getInv()[i]->getSimpleDesc()<<"\n";
					std::cout<<"Select an item(Press '0' for cancel)=";
					unsigned int itemIndex;
					std::cin>>itemIndex;
					if(itemIndex--)
					{
						std::cout<<"1]Drop item"<<"\n";
						std::cout<<"2]Examine item"<<"\n";
						std::cout<<"3]Equip item"<<"\n";
						std::cout<<"0]Cancel"<<"\n";
						std::cout<<"<<";
						std::cin>>opt;
						switch(opt)
						{
							case 1://DROP
								std::cout<<"You drop your "<<player.getInv()[itemIndex]->getName()<<"."<<"\n";
								player.getInv().removeItem(itemIndex);
								break;
							case 2://EXAMINE
								std::cout<<player.getInv()[itemIndex]->getName()<<"\n";
								std::cout<<player.getInv()[itemIndex]->getDesc()<<"\n";
								break;
							case 3://EQUIP
								switch(player.getInv()[itemIndex]->getType())
								{
									case WEAPON:
										if(player.getWeapon().getName()!="Fists")
										{
											Weapon* preW=player.getWeapon().clone();
											player.getInv().addItem(preW);
											delete preW;
										}
										break;
									case ARMOR:
										Armor* a=dynamic_cast<Armor*>(player.getInv()[itemIndex]->clone());
										if(player.getArmorSet()[a->getPartCover()].getName()!="NONE")
										{
											Armor* preA=player.getArmorSet()[a->getPartCover()].clone();
											player.getInv().addItem(preA);
											delete preA;
										}
										delete a;
										break;
								}
								player.equipFromInv(itemIndex);
								break;
						}
					}
				}
				break;
			case 5://EQUIPMENT
				std::cout<<"Equipment:"<<"\n";
				std::cout<<"\n";
				std::cout<<"WEAPON="<<player.getWeapon().getSimpleDesc()<<"\n";
				std::cout<<"\n";
				std::cout<<"TOTAL AC:"<<player.getAC()<<"\n";
				for(int i=HEAD;i<BODY_PARTS_MAX;i++)
				{
					switch(i)
					{
						case HEAD:
							std::cout<<"HEAD=";
							break;
						case TORSO:
							std::cout<<"TORSO=";
							break;
						case LEGS:
							std::cout<<"LEGS=";
							break;
						case FOOTS:
							std::cout<<"FOOTS= ";
							break;
					}
					std::cout<<player.getArmorSet()[i].getSimpleDesc()<<"\n";
				}
				break;
		}
	}else if(menu==COMBAT)
	{
		switch(opt)
		{
			case 1://ATTACK
				std::cout<<"You attacked the "<<monster.getName()<<"."<<"\n";
				if(player.attack(&monster))
					std::cout<<"You hit the "<<monster.getName()<<"."<<"\n";
				else
					std::cout<<"You miss."<<"\n";
				break;
			case 2://ESCAPE
				menu=MAIN;
				std::cout<<"You run away from the "<<monster.getName()<<"."<<"\n";
				break;
		}
	}else if(menu==SHOP)
	{
		switch(opt)
		{
			case 1://BUY
				std::cout<<"Categories:"<<"\n";
				std::cout<<"1]Weapons"<<"\n";
				std::cout<<"2]Armors"<<"\n";
				std::cout<<"Selec a category(Press '0' for cancel)=";
				std::cin>>opt;
				if(opt)
				{
					switch(opt)
					{
						case WEAPON:
							std::cout<<"WEAPONS:"<<"\n";
							for(int i=1;i<4;i++)
								std::cout<<i<<"]"<<wList[i].getSimpleDesc()<<"[GOLD="<<wList[i].getPrice()<<"]"<<"\n";
							break;
						case ARMOR:
							std::cout<<"ARMORS:"<<"\n";
							for(int i=HEAD;i<BODY_PARTS_MAX;i++)
								std::cout<<i+1<<"]"<<aList[i].getSimpleDesc()<<"[GOLD="<<aList[i].getPrice()<<"]"<<"\n";
							break;
					}
					unsigned int itemIndex;
					std::cout<<"Selec an item(Press '0' for cancel)=";
					std::cin>>itemIndex;
					if(itemIndex--)
					{
						switch(opt)
						{
							case WEAPON:
								if(gold-wList[++itemIndex].getPrice()>0)
								{
									gold-=wList[itemIndex].getPrice();
									player.getInv().addItem(&wList[itemIndex]);
								}else
									std::cout<<"You can't buy that weapon."<<"\n";
								break;
							case ARMOR:
								if(gold-aList[itemIndex].getPrice()>0)
								{
									gold-=aList[itemIndex].getPrice();
									player.getInv().addItem(&aList[itemIndex]);
								}else
									std::cout<<"You can't buy that armor."<<"\n";
								break;
						}
					}
				}
				break;
			case 2://SELL
				if(player.getInv().getNrItems())
				{
					for(int i=0;i<player.getInv().getNrItems();i++)
					{
						std::cout<<i+1<<"]"<<player.getInv()[i]->getSimpleDesc();
						std::cout<<"[GOLD="<<player.getInv()[i]->getPrice()<<"]"<<"\n";
					}
					std::cout<<"Select an item(Press '0' for cancel)=";
					std::cin>>opt;
					if(opt--)
					{
						std::cout<<"You sell your "<<player.getInv()[opt]->getName()<<"."<<"\n";
						gold+=player.getInv()[opt]->getPrice();
						player.getInv().removeItem(opt);
					}
				}else
					std::cout<<"You doesn't have anything to sell."<<"\n";
				break;
			case 3://LEAVE
				menu=MAIN;
				std::cout<<"You leave the shop."<<"\n";
				break;
		}
	}
}
void update()
{
	if((int)player.getHP_CURRENT()>0)
	{
		if(menu==COMBAT)
		{
			std::cout<<"The "<<monster.getName()<<" attacks you."<<"\n";
			float f=player.getHP_CURRENT();
			if(monster.attack(&player))
			{
				std::cout<<"It hits you";
				if(f==player.getHP_CURRENT())
					std::cout<<",but it doesn't do any damage";
				std::cout<<".\n";
			}else
				std::cout<<"It missed."<<"\n";
			if((int)monster.getHP_CURRENT()<=0)
			{
				menu=MAIN;
				std::cout<<"The "<<monster.getName()<<" died."<<"\n";
				switch(rand()%4)
				{
					case 1://GOLD
						std::cout<<"It drop some gold."<<"\n";
						gold+=roll(10,1);
						break;
					case 2://WEAPON
						std::cout<<"It dropped a weapon,you put it into your inventory."<<"\n";
						player.getInv().addItem(&wList[rand()%3+1]);
						break;
					case 3://ARMOR
						std::cout<<"It dropped an armor piece,you it into your inventory."<<"\n";
						player.getInv().addItem(&aList[rand()%BODY_PARTS_MAX]);
						break;
				}
			}
		}
	}
	if((int)player.getHP_CURRENT()<=0)
	{
		b=true;
		std::cout<<"YOU DIED"<<"\n";
		std::cin.ignore();
		std::cin.get();
	}
}
