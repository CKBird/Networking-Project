//events.c

#include "stdafx.h"
#include "stdio.h"
#include "iostream"
#include "stdlib.h"
#include "math.h"
#include <queue>
#include <list>
#include "events.h"

using namespace std;

float mu, lambda;
#define extraCredit 0

static int timeToNext;

events::events()
{
	//Constructor
};

events::~events()
{
	//Destructor
};

arrival::arrival(double currentTime)
{
	//Constructor
	timeOE = currentTime;
};

arrival::~arrival()
{
	//Destructor
};

double arrival::generateTimeToNext()
{
	if (!extraCredit)
	{
		double u; //w
		u = (rand() / (RAND_MAX + 1.0));
		return ((-1 / lambda) * log(1 - u)); //Make sure that we convert from double to int before returning
	}
	else
	{
		double u; //w
		u = (rand() / (RAND_MAX + 1.0));
		return ((-1 / lambda) * log(1 - u)); //Make sure that we convert from double to int before returning
	}
}

departure::departure()
{
	//Constructor
	serviceTime = generateServiceTime();
};

departure::~departure()
{
	//Destructor
};

double departure::generateServiceTime()
{
	if (!extraCredit)
	{
		//Using Mu to generate service time of CURRENT event
		double u; //w
		u = (rand() / (RAND_MAX + 1.0));
		return ((-1 / mu) * log(1 - u));
	}
	else
	{
		//Using Mu to generate service time of CURRENT event
		double u; //w
		u = (rand() / (RAND_MAX + 1.0));
		return ((-1 / mu) * log(1 - u));
	}
}