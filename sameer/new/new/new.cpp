// new.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string choice;
	do
	{
		cout<<"chose an option: fruits,and vegtables, ";
		cin>>choice;
		if(choice=="fruits")
		{
			cout<<"first option";
		}
		else
		{
			cout<<"incorrect option";
		}
	}while(choice != "quit");
	return 0;
}

