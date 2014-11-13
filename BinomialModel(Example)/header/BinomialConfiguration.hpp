// Version 1.1
// 11/11/2014

#ifndef BINOMIALCONFIG_HPP
#define BINIMIALCONFIG_HPP

#include "BinomialConfiguration.h"
#include<TRandom3.h>
using namespace std;

//setters
void BinomialConfiguration::SetLength(int lengthOfConfig)
{
	length = lengthOfConfig;
}

void BinomialConfiguration::SetP(double p1)
{
	p = p1;
}

void BinomialConfiguration::SetConfig()
{
	TRandom3 *r = new TRandom3(0);
	for(int i = 0; i < length; i++)
	{
		if(r->Uniform(0.0,1.0) < p)
			config.push_back(1.0);
		else
			config.push_back(-1.0);
	}
}

//getters
void BinomialConfiguration::PrintLength()
{
	cout << "The length set for this configuration is " << length << "\n";
}

void BinomialConfiguration::PrintP()
{
	cout << "The probability of +1 is " << p << "\n";
}

void BinomialConfiguration::PrintConfig()
{
	Print(config);
}

vector<double> BinomialConfiguration::GetConfig()
{
	vector<double> x = config;
	return x;
}


//constructors
BinomialConfiguration::BinomialConfiguration()
{
	length = 1000;
	p = .5;
}

BinomialConfiguration::BinomialConfiguration(int lengthOfConfig, double p1)
{
	length = lengthOfConfig;
	p = p1;
	SetConfig();
}

#endif
