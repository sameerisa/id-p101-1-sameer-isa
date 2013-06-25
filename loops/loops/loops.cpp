// loops.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
int count;
do
{
cout<< "enter a number between 1 and 4";
cin>>count;
}while(count >0 && count<5);
	return 0;
}

