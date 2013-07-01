// structure.cpp : Defines the entry point for the console application.
//put where he attacks player1.ammo-=1
//if(player1.ammo>0)
//{
//attack
//}
//else
//{
//cout<<"you are out of ammo"
//}
//if(bow1.ammo>0)
//{attack with bow}
//else()
//{attack with dagger}

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

using namespace std;

class monster
{
public:
	int health;
	int strength;
	bool has_fists;
};
class player 
{
public:
	int upgradepoints;
	int health;
	int maxhealth;
	int strength;
	int magic;
	int money;
	int levels;
	int ammo;
	bool has_dagger;
	bool has_sword;
	bool has_bow;
	bool has_shield;
	string name;
	player()
	{
		upgradepoints=250;
	}


	void attack()
	{
		cout<<"attack";
	}
	void defend()
	{
		cout<<"defend";
	}

};
struct weapon
{
	int damage;
	int range;
};
struct sword
{
	int damage;
	int range;
};
struct bow
{
	int damage; 
	int range;
};
struct dagger
{
	int damage;
	int range;
};
struct fists
{
	int damage;
	int range;
};

void scrollingText(string message)
{
	for(int i = 0; i < message.length(); i++)
	{
		Sleep(60);
		cout << message.c_str()[i];

	}
}

int randomnumber()
{
	return rand()%1;
}


void print_info(player player1)
{
	cout<<player1.name;
}

int _tmain(int argc, _TCHAR* argv[])

{
	string nametown;
	string choice2;
	string choice;
	string exit;
	string s;
	string f;
	string yes;
	string attack;
	string finalize1;
	player player1;
	monster monster1;
	sword  sword1;
	bow  bow1;
	
	dagger dagger1;
	fists fists1;

	bow1.damage=20;
	bow1.range=10;
	player1.ammo=12;
	player1.money=100;
	player1.levels=1;

	monster1.health=50;
	monster1.strength=50;

	fists1.damage=8;
	fists1.range=2;

	sword1.damage=30;
	sword1.range=3;

	dagger1.damage=5;
	dagger1.range=1;

	player1.has_dagger=false;
	player1.has_sword=false;
	player1.has_bow=false;
	monster1.has_fists=true;
	do
	{

		scrollingText("enter your name player 1");
		getline(cin,player1.name);
		scrollingText("you have 250 upgrade points.");

		scrollingText(" how many points would you like to use for health");
		cin>>player1.health;
		player1.upgradepoints-=player1.health;
		player1.maxhealth=player1.health;
		if(player1.upgradepoints > 0)
		{
			scrollingText("how points would you like to use for strength");
			cin>>player1.strength;
			player1.upgradepoints-=player1.strength;

			if(player1.upgradepoints > 0)
			{
				scrollingText("how many points would you like to use for magic");
				cin>>player1.magic;
				player1.upgradepoints-=player1.magic;
			}
			else
			{
				cout<<"you have run out of points";
			}
		}
		else
		{
			cout<<"you have run out of points";
		}

		scrollingText("would you like a bow or sword");
		cin>>choice;

		if(choice=="bow")
		{
			player1.has_bow=true;
			player1.has_dagger=true;
			player1.has_shield=false;
		}
		else if(choice=="sword")
		{
			player1.has_sword=true;
		}
		cout<<"would you like to finalize information";
		cin>>finalize1;
	}
	while (finalize1!="yes");
	scrollingText(" welcome ");
	print_info(player1);
	scrollingText(" name your town here");
	cin>>nametown;
	scrollingText(" earth is being taken over by a mysterious enemy.");
	scrollingText(" you must fight creatures and defend your town.");
	scrollingText(" you will have to kill the mysterious enemy to win.");
	scrollingText(" it is your  first day in town.");
	scrollingText(" you were assigned to gaurd the west side of town.");
	scrollingText(" you are walking outside the wall and everything was fine until you smell a horrible smell.");
	scrollingText (" suddenly a few creatures come out of the ground.");
	scrollingText (" would you like to attack the creature or escape.");
	cin>>attack;
	if(attack=="attack")
	{
		scrollingText (" you and the other soliders attack the creatures.");

		do
		{
			if(player1.has_sword==true)
			{ 
				cout<<"you attacked the monster with the sword";
				monster1.health-=sword1.damage;

				if(randomnumber()==0)
				{
					scrollingText("you have blocked the attack");
				}
				else
				{
					player1.health-=fists1.damage;
				}
			}
			if(player1.has_bow==true)
			{
				if(player1.ammo>0)
				{
					monster1.health -= bow1.damage; 
					player1.ammo-=1;
					scrollingText(" you shot the monster with the bow.");

					scrollingText(" The monster misses.");

				}
				else
				{
					monster1.health -= dagger1.damage; 
					scrollingText(" you stab the monster with the dagger.");

					scrollingText( " The monster hit you.");
					player1.health -= fists1.damage;
				}
			}
		}


			while(player1.health > 0 && monster1.health > 0);
			scrollingText("you and your allies have defeated the monsters");
			scrollingText("you were rewared with 100 gold");
			player1.money+=100;
			cout<<"you have leveled up";
			player1.levels+=1;
			scrollingText("would you like to go to market");
			cin>>yes;
			if(yes=="yes")
			{
				do{
			 if(player1.has_bow==true)
			 {
				 cout<<"1 arrows 20 gold each";
				 cout<<"2 healing potion 50 gold";
				 cout<<"3 exit";
				cin>>choice;
				 if(choice=="1")
				 {
					 player1.money-=20;
					 player1.ammo+=1;
				 }
				 if(choice=="2")
				 {
					 player1.health=player1.maxhealth;
				 }
 			 }
			 else
			 {
				 cout<<"1 healing potion 50 gold";
				 cout<<"2 exit"; 
				 cin>>choice2;
				 if(choice2=="1")
				 {

				 }
			 }
				}while(choice!="3"&&choice2!="2");
			}
			

		}
	else
	{
		cout<<" your action has caused your allies to get outnumbered and die. the king banishes you from the kingdom."; 
	}
	return 0;
	}