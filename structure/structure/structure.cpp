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

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include <Windows.h>

using namespace std;

class player 
{
public:
	int upgradepoints;
	int health;
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

void scrollingText(string message)
{
	for(int i = 0; i < message.length(); i++)
	{
		Sleep(60);
		cout << message.c_str()[i];

	}
}


void print_info(player player1)
{
	cout<<player1.name;
}

int _tmain(int argc, _TCHAR* argv[])

{
	string nametown;
	string finalize1;
	player player1;
	sword  sword1;
	bow  bow1;
	string choice;
	dagger dagger1;
	
	bow1.damage=8;
	bow1.range=10;
	player1.ammo=12;
	player1.money=100;
	player1.levels=1;


	sword1.damage=10;
	sword1.range=3;

	dagger1.damage=5;
	dagger1.range=1;

	player1.has_dagger=false;
	player1.has_sword=false;
    player1.has_bow=false;
   do
   {
	
	scrollingText("enter your name player 1");
	getline(cin,player1.name);
	scrollingText("you have 250 upgrade points.");
	scrollingText(" how many points would you like to use for health");
	cin>>player1.health;
	player1.upgradepoints-=player1.health;
	scrollingText("how points would you like to use for strength");
	cin>>player1.strength;
	player1.upgradepoints-=player1.strength;
	scrollingText("how many points would you like to use for magic");
	cin>>player1.magic;
	player1.upgradepoints-=player1.magic;
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
	scrollingText("name your town here");
	cin>>nametown;
	scrollingText(" earth is being taken over by a mysterious enemy.");
	scrollingText(" you must fight creatures and defend your town.");
	scrollingText(" you will have to kill the mysterious enemy to win.");
	scrollingText(" it is your first day in town.");
	scrollingText(" you were assighed to gaurd the west side of town.");

   
	
	return 0;	
}