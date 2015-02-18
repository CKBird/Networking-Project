// Phase1Networking.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "events.h"
#include "stdio.h"
#include "iostream"
#include "time.h"
#include <queue>
#include <list>
#include <stack>

using namespace std;
extern float mu, lambda;

int BUFFER_INF = 0;
unsigned int BUFFER_MAX = 0;

int main(int argc, _TCHAR* argv[])
{
	mu = 1;
	char input;
	float lambdaArr[7] = { (float).1, (float).25, (float).4, (float).55, (float).65, (float).80, (float).90 };
	float lamdaArr2[5] = { (float).2, (float).4, (float).6, (float).8, (float).9 };
	unsigned int buffMax[3] = { 1, 20, 50 };
	for (int numExp = 0; numExp < 22; numExp++)
	{
		if (numExp < 7)
		{
			BUFFER_INF = 1;
			lambda = lambdaArr[numExp];
		}
		else
		{
			BUFFER_INF = 0;
			lambda = lamdaArr2[(numExp - 7) % 5];
			BUFFER_MAX = buffMax[(int)((numExp - 7) / 5)];
		}

		srand((unsigned int)time(NULL));
		double clock = 0;
		double NAT = arrival::generateTimeToNext();
		double NDT = 0;
		double downTime = 0.0;
		double totalSize = 0;
		int dropped = 0;

		queue<departure> buffer;
		list<events> GEL;
		stack<double> integralCalc;

		while (clock < 100000)
		{
			if ((NAT < NDT) || buffer.empty()) //Arrival is the next event to occur
			{
				clock = NAT;
				if (NDT < clock)
					downTime += (clock - NDT);

				if(buffer.size() > 1)
					integralCalc.push(clock);

				GEL.push_back(arrival(NAT));		//Adds new arrival with time NAT to GEL

				if (!BUFFER_INF && (buffer.size() > BUFFER_MAX))
				{
					dropped++;
				}
				else
				{
					buffer.push(departure());			//Puts new departure on buffer
					if (buffer.size() == 1)
					{
						NDT = clock + buffer.front().getServiceTime();
					}
				}
				NAT = clock + arrival::generateTimeToNext();
			}
			else //Departure is the next event to occur
			{
				clock = NDT;

				if(!integralCalc.empty()){
					totalSize += clock - integralCalc.top();
					integralCalc.pop();
				}

				GEL.push_back(buffer.front());
				GEL.back().setTimeOE(clock);
				buffer.pop();
				if (!buffer.empty())
					NDT = clock + buffer.front().getServiceTime(); //Set NDT to the time of the NEXT departure (currentTime + serviceTime)
				//cout << "d";
			}
			//cout << clock << "__" << endl;
		}

		while(!integralCalc.empty()){
			totalSize += clock - integralCalc.top();
			integralCalc.pop();
		}
		/*while (!GEL.empty())
		{
			events * evt = &GEL.front();
			cout << evt->returnTime() << " ";
			GEL.pop_front();
		}*/

		double meanSize = totalSize / clock;
		double fractionBusy = (downTime / clock) * 100;
		cout << endl << "Lambda Value: " << lambda << endl;
		cout << "Buffer Size: " << BUFFER_MAX << endl;
		cout << "Downtime: " << fractionBusy << "%" <<endl;
		cout << "Buffer Mean: " << meanSize << endl;
		cout << "Dropped packets: " << dropped << endl;
	}
	cout << "Done creating statistics" << endl;
	cin >> input;
	return 0;
}

