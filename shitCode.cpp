//Extra Code that may be used later

//loop goes until end of clock
//Create arrival based on prev TTN
//create departure based on service time and store in queue
//loop goes until smallest time vaule is the new arrival
//store next item in queue -> GEL
//store arrival into GEL


int point2, point4, point6, point8, one, two, three;
point2 = point4 = point6 = point8 = one = two = three = 0;
for (int i = 0; i < 100000; i++)
{
	double time = arrival::generateTimeToNext();
	if (time < .2)
		point2++;
	else if (time < .4)
		point4++;
	else if (time < .6)
		point6++;
	else if (time < .8)
		point8++;
	else if (time < 1)
		one++;
	else if (time < 2)
		two++;
	else
		three++;

}
cout << "Point2, Point4, Point6, Point8, ONE, TWO, THREE" << endl << point2 << " " << point4 << " " << point6 << " " << point8 << " " << one << " " << two << " " << three << " " << endl;