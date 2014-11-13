// Version 1.1
// 11/11/2014

#ifndef BINOMIALCONFIG_H
#define BINIMIALCONFIG_H

#include <iostream>
#include "Misc.hpp"
using namespace std;

/*
This will create an object (class) which will contain a vector of +/- 1's following a binomial distribution with probability p (like an unfair coin. Heads could be +1 while tails -1). 
You can set the number of trials and the probability to whatever you want. 
This code is functional but does not have any error handling capabilities (ie. you can set probability greater than 1 or less than 0) and it does not have a destructor.
*/

class BinomialConfiguration{ 
	public:

		//These are only the function prototypes. What these functions actually do are defined in the .hpp file. 

		//setters
		void SetLength(int lengthOfConfig); 
		void SetP(double p1); 
		void SetConfig(); 

		//getters
		vector<double> GetConfig();
		void PrintLength();
		void PrintP();
		void PrintConfig();

		//constructors
		BinomialConfiguration();
		BinomialConfiguration(int lengthOfConfig,double p1);

	private:
		vector<double> config;
		int length;
		double p;
};

#endif
