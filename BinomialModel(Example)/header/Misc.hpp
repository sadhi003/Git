// Version 1.0
// 11/9/2014

#ifndef MISC_HPP
#define MISC_HPP

#include"Misc.h"

void Print(vector<double> v)
{
	for(int i = 0; i < (int) v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

void Print(vector<int> v)
{
	for(int i = 0; i < (int) v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

#endif
