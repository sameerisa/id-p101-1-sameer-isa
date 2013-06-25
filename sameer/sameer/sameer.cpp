// sameer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string name;
	string home;
	string hello;
	string hi;
	cout <<"enter your name";
	getline(cin,name);
	cout <<"hello," <<name;
	cout << " where are you from?";
	getline(cin,home);
	cout << "whats your favorite subject?";
	cin >>hello;
	cout <<"what sports do you play?";
	getline(cin,hi);
	cout<<"/in";


	return 0;
}

