//events.h
#ifndef EVENTS_H
#define EVENTS_H

#include <string>
using namespace std; 

class events
{
public:
	events();
	~events();
	virtual string toString()			{ return "Shit"; }
	inline double returnTime()			{ return timeOE; }
	inline void setTimeOE(double time)	{ timeOE = time; }

private:

protected:
	double timeOE; //Time event occurred

};

class arrival : public events //Stuff here is only for arrival type
{
public:
	arrival(double currentTime);
	~arrival();
	static double generateTimeToNext(); //Not in source
	inline string toString()				{ return "Arrival"; }

private:

protected:

};

class departure : public events //Stuff here is only for departure
{
public:
	departure();
	~departure();
	double generateServiceTime();
	inline double getServiceTime()			{ return serviceTime; }
	inline string toString()				{ return "Departure"; }

private:
	double serviceTime;

protected:


};

#endif