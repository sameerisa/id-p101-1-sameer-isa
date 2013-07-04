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
#include <WinCon.h>

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
	int ammo2;
	bool has_dagger;
	bool has_sword;
	bool has_bow;
	bool has_shield;
	bool has_sword2;
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
struct ammo
{
	int damage;
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

void greenText ()
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_GREEN);
}

void redText ()
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_RED);
}

void print_info(player player1)
{
	cout<<player1.name;
}
void redtext()
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_RED);
}

void checkHealth(player player1)
{
	if (player1.health < 20)
	{
		redText();
	}
	else
	{
		greenText();
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	string nametown;
	string choice2;
	string choice;
	string exit;
	string s;
	string f;
	string choice3;
	string choice4;
	string yes;
	string attack;
	string finalize1;
	player player1;
	monster monster1;
	sword  sword1;
	bow  bow1;
	sword sword2;
	ammo ammo1;
	ammo ammo2;
	dagger dagger1;
	fists fists1;

	ammo1.damage=20;
	ammo2.damage=30;
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

	sword2.damage=40;
	sword2.range=3;

	dagger1.damage=5;
	dagger1.range=1;

	player1.has_dagger=false;
	player1.has_sword=false;
	player1.has_bow=false;
	monster1.has_fists=true;

	greenText();
	do
	{
		scrollingText("made by sameer isa ");
		scrollingText("this game has not been completed ");

		scrollingText("enter your name player 1 ");
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
	do
	{
		scrollingText(" earth is being taken over by a mysterious dark force.");
		scrollingText(" you must fight creatures and defend your town.");
		scrollingText(" you will have to kill the mysterious force to win.");
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
						checkHealth(player1);
					}
				}
				if(player1.has_bow==true)
				{
					if(player1.ammo>0)
					{
						monster1.health -= ammo1.damage; 
						player1.ammo-=1;
						scrollingText(" you shot the monster with the bow. ");

						scrollingText(" The monster misses.");

					}
					else
					{
						monster1.health -= dagger1.damage; 
						scrollingText(" you stab the monster with the dagger.");

						scrollingText( " The monster hit you.");
						player1.health -= fists1.damage;
						checkHealth(player1);
					}
				}
			}


			while(player1.health > 0 && monster1.health > 0);
			scrollingText(" you and your allies have defeated the monsters");
			scrollingText(" you were rewared with 100 gold");
			player1.money+=100;
			cout<<" you have leveled up";
			player1.levels+=1;
			sword1.damage+=5;
			ammo1.damage+=5;
			ammo2.damage+=5;
			player1.health+=5;
			player1.maxhealth+=5;
			scrollingText(" would you like to go to market");
			cin>>yes;
			if(yes=="yes")
			{
				do{
					if(player1.has_bow==true)
					{
						cout<<"healing potions heal right when bought";	
						cout<<" 1 arrows 20 gold each ";
						cout<<" 2 healing potion 50 gold ";
						cout<<" 3 exit ";
						cout<<"you have"<<player1.money<<"gold";
						cout<< "you have"<<player1.health<<"health";

						cin>>choice;
						if(choice=="1")
						{
							if(player1.money>=20)
							{
								player1.money-=20;
								player1.ammo+=1;
							}
							else
							{
								cout<<"dont have enough money";
							}
							if(choice=="2")
							{
								if(player1.money>=50)
								{
									player1.money-=50;
									player1.health=player1.maxhealth;
								}
								else
								{
									cout<<"dont have enough money";
								}

							}

						}


					}
				}while(choice != "3");
			}
			else
			{	
				{
					cout<<"healing potions heal you completly once bought";
					cout<<"1 healing potion 50 gold";
					cout<<"you have"<<player1.money<<"gold";
					cout<< "you have"<<player1.health<<"health";
					cout<<"2 exit"; 
					cin>>choice2;
					if(choice2=="2")
					{
						if(player1.money>=50)
						{

							player1.health=player1.maxhealth;
						}
						else
						{
							cout<<" you dont have enough money.";
						}
					}

				}

			}while(choice!="3"&&choice2!="2");
			do{


				scrollingText( "you have exited the market and you are going to the king for your next asighnment");
				scrollingText(" the king wasent on his throne and every one was scared. ");
				scrollingText("you help the other soliders find the king. ");
				scrollingText("as you are walking down the town you see fait black goo on the ground");
				scrollingText("would you like to follow the black goo or search the town with your soliders");
				scrollingText("choice 1 or choice 2");
				cin>>choice3;
				if(choice3=="choice1"||choice3=="1"||choice3=="choice 1")
				{
					scrollingText( "you follow the goo through town.");
					scrollingText("You keep following and you see the king he is covered in black goo and stuck to the the wall of the town");
					scrollingText("the king was being treated by a docter and he told us that the monsters weakness is light.");
					cout<< "would you like to go back to the market (recomended)";
					cin>>choice4;
					if(choice4=="yes")
					{
						do{
							if(player1.has_bow==true)
							{
								cout<<"healing potions heal right when bought";	
								cout<<" 1 arrows 20 gold each ";
								cout<<" 2 flaming arrow 50 gold";
								cout<<" 3 healing potion 50 gold ";
								cout<<" 4 exit ";
								cout<<"you have"<<player1.money<<"gold";
								cout<< "you have"<<player1.health<<"health";

								cin>>choice;
								if(choice=="1")
								{
									if(player1.money>=20)
									{
										player1.money-=20;
										player1.ammo+=1;
									}
									else
									{
										cout<<"dont have enough money";
									}
									if(choice=="3")
									{
										if(player1.money>=+50)
										{
											player1.money-=50;
											player1.health=player1.maxhealth;
										}
										else
										{
											cout<<"dont have enough money";
										}
										if(choice=="2")
										{
											if(player1.money>=50)
											{
												player1.ammo2+=1;
											}
											else
											{
												cout<<"you are out of money";
											}
										}
									}


								}
								else
								{
									cout<<"healing potions heal you completly once bought";
									cout<<"1 flaming sword 150 gold";
									cout<<"2 healing potion 50 gold";
									cout<<"you have"<<player1.money<<"gold";
									cout<< "you have"<<player1.health<<"health";
									cout<<"3 exit"; 
									cin>>choice2;
									if(choice2=="2")
									{
										if(player1.money>=50)
										{

											player1.health=player1.maxhealth;
										}
										else
										{
											cout<<" you dont have enough money.";
										}
									}
									if(choice2=="1")
									{
										if(player1.money>=150)
										{
											player1.has_sword=false;
											player1.has_sword2=true;
										}
									}
								}
							}
						}while(choice!="3"&&choice2!="2");
						scrollingText("the next day the king sent me to scout the area where the monsters escaped from");
						scrollingText("you are leaving the town and you see a hole");
						scrollingText("would you like to examine the hole or go where the king sent you");
						cout<<"1 or 2 ";
						if (s=="1")
						{
							scrollingText("you examine the hole");
							scrollingText("and your suprised to see........its the kings dead body. then you realize you were being sent into a trap.");
							scrollingText("you bring his body back to town and you see the soliders fighting and you quickly join the fight");
							if(player1.has_bow=true)

							{
								cout<<"would you like to use the flaming arrow (1) or the regular (2)";
								cin>>choice;
								if(choice=="1")
								{
									player1.ammo2-=1;
									scrollingText("you missed your shot but you hit the ground and iluminated the night. all the monsters ran away");
								}
								else
								{
									monster1.health-=ammo1.damage;
									scrollingText("you shot the monster in the head and it instantly died");
									scrollingText("you and the other soliders fought away the monsters.");
								}

							}
							else
							{
								if (player1.has_sword=true)
								{
									cout<<"you charge behind with the kings body and block attacks with you shield.";
									scrollingText("you find the nearest torch and trow it at the monsters, all the monsters run away. ");
								}
								else
								{
									scrollingText("you leave the kings body and take out your sword. you ignite the ground scaring the monsters. they are distracted and they try to run but the soldiers kill them.");
								}
							}
							scrollingText("you have succsefully fought off the monsters" );
							scrollingText("the town buries the king");
							scrollingText("you become the new king.");
							
						
						}
						else
						{
							scrollingText("you wall the path the king told you you see a hut");
							scrollingText("then all of a sudden monsters surrouned you like they knew you were coming");
							cout<<"you have died would you like to retry";
							cin>>f;


						}
					}
				}


			}while(f=="yes");



			

		}
		cout<<" your action has caused your allies to get outnumbered and die. the king banishes you from the kingdom."; 
		cout<<"would you like to retry";
		cin>>s;
	}while(s=="yes");

	return 0;
}