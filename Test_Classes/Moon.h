#pragma once
#include <iostream>
using namespace std;
Class Moon;
{
	Private;
	double earthWeight;
	double moonWeight;
	Public;
	moonWeight(double ew);
	{ earthWeight = ew;
	moonWeight = earthWeight / 6; }
	double getMoonWeight();
	{return moonWeight; }
}