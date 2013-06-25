// calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	int b;
	int choice;
	
	
	cout<<"welcome to the awsome calculatror";
	
	cout<<"\n";

	cout<<"enter first number";
	cin>>a;
	cout<<"enter second number";
	cin>>b;
	cout<<"enter 1 for add, 2 for subtract, 3 for multiply, or 4 divide";
	cin>>choice;
	if(choice ==1)
	{
	cout<<"answer "<<a+b ;
	}
if(choice ==2)
	{
	cout<<"answer "<<a-b ;
	}
if(choice ==3)
	{
	cout<<"answer "<<a*b ;
	}
	if(choice ==4)
		{
	cout<<"answer "<<a/b ;
	}
	return 0;
}