#include "Character.h"
#include "Spell_attack.h"
#include <iostream>
#include <ctime>

enum
{
	MAIN=1,
	COMBAT,
	SHOP
};

bool b;
unsigned short int menu;
unsigned short int gold;

Character player;
Npc monsterList[3];
State stateList[1];
Spell_attack sAttackList[2];

void init();
void draw();
void input();
void update();

int main()
{
	init();
	while(!b)
	{
		draw();
		input();
		update();
	}
	return 0;
}

void init()
{
	srand(time(NULL));
	b=false;
	menu=MAIN;
	gold=0;
	//STATE LIST
	//FIRE
	stateList[0].setDuration(6);
	stateList[0].getModifiers()[HP]=-5;
	//SPELLS ATTACK LIST
	//WIND BLADE
	sAttackList[0].setName("Wind blade");
	sAttackList[0].setDesc("It creates a blade of wind that hits the target and causes a <3D3> of damage.");
	sAttackList[0].setCostMP(7);
	sAttackList[0].setDice(3,3);
	//FIREBALL
	sAttackList[1].setName("Fireball");
	sAttackList[1].setDesc("It creates a fireball that hit the target and causes a <3D4> of damage,it also put the target on fire.");
	sAttackList[1].setCostMP(15);
	sAttackList[1].setDice(4,3);
	sAttackList[1].setEffect(stateList[0]);
	//MONSTER LIST
	//GOBLIN
	monsterList[0].setName("Goblin");
	monsterList[0].setHP_MAX(30);
	monsterList[0].setAC(5);
	//ORC
	monsterList[1].setName("Orc");
	monsterList[1].setHP_MAX(50);
	monsterList[1].setAC(30);
	//CHAMAN
	monsterList[2].setName("Green chaman");
	monsterList[2].setHP_MAX(40);
	monsterList[2].setAC(20);
	//PLAYER
	player.setHP_MAX(25);
	player.setHP_CURRENT(player.getHP_MAX());
	player.setMP_MAX(60);
	player.setMP_CURRENT(player.getMP_MAX());
	player.setLEVEL(1);
	player.setEXP_NEXT(30);
	std::string s;
	system("clear");
	std::cout<<"NAME= ";
	getline(std::cin,s);
	player.setName(s);
}
void draw()
{
	std::cout<<"-----------------------------------------------"<<"\n";
	std::cout<<player.getName()<<"\n";
	std::cout<<"HP="<<player.getHP_CURRENT()<<"/"<<player.getHP_CURRENT()<<"\n";
	std::cout<<"HP="<<player.getMP_CURRENT()<<"/"<<player.getMP_CURRENT()<<"\n";
	std::cout<<"Level="<<player.getLEVEL()<<"\n";
	std::cout<<"Next level="<<player.getEXP_CURRENT()<<"/"<<player.getEXP_NEXT()<<"\n";
	std::cout<<"-----------------------------------------------"<<"\n";
	switch(menu)
	{
		case MAIN:
			std::cout<<"1]Combat"<<"\n";
			std::cout<<"2]Shop"<<"\n";
			std::cout<<"3]Cast spell"<<"\n";
			std::cout<<"4]Rest"<<"\n";
			std::cout<<"0]Exit"<<"\n";
			break;
		case COMBAT:
			std::cout<<"1]Cast spell"<<"\n";
			std::cout<<"2]Regen some mana"<<"\n";
			std::cout<<"3]Escape"<<"\n";
			break;
		case SHOP:
			std::cout<<"1]Buy spell"<<"\n";
			std::cout<<"2]Leave shop"<<"\n";
			break;
	}
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
				std::cout<<"You go to fight a random monster."<<"\n";
				menu=COMBAT;
				break;
			case 2://SHOP
				std::cout<<""<<"\n";
				break;
			case 3://CAST SPELL
				std::cout<<""<<"\n";
				break;
			case 4://REST
				std::cout<<"You rest for a while."<<"\n";
				player.setHP_CURRENT(player.getHP_MAX());
				player.setMP_CURRENT(player.getMP_MAX());
				break;
		}
	}else if(menu==COMBAT)
	{
		switch(opt)
		{
			case 1://CAST SPELL
				break;
			case 2://REGEN MANA
				std::cout<<"You focus your will for attract some mana energy."<<"\n";
				if(roll(20,1,(int)player.getLEVEL()/2)>10)
				{
					std::cout<<"You fell the mana coming to your body."<<"\n";
					player.setMP_CURRENT(player.getMP_MAX()+roll(15,1,4));
				}else
					std::cout<<"You don't felt anything."<<"\n";
				break;
			case 3://ESCAPE
				if(roll(20,1,player.getEVASION())>10)
				{
					std::cout<<"You escape from the fight."<<"\n";
					menu=MAIN;
				}else
					std::cout<<"You can't escape from the fight."<<"\n";
				break;
		}
	}else if(menu==SHOP)
	{
	}
}
void update()
{
	
}
