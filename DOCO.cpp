#include "DOCO.h"
#include <random>
#include "map.h"
#include <string.h>
#include <iostream>
#include "config.h"
#include "behavior.h"
#include "DOCOFactory.h"


using namespace std;

DOCO::DOCO()
{
	energy = 500;
	azimuthX = rand() % 2 - 1;
	azimuthY = rand() % 2 - 1;
	if (azimuthX == 0 && azimuthY == 0)
	{
		azimuthX += 1;
	}
}
DOCO::~DOCO()
{
}
DOCO::DOCO(map* newMap, int x, int y, int e)
{
	myMap = newMap;
	tenant* temp = this;
	myMap->addTenant(temp, x, y);
	age = 0;
	mapX = x;
	mapY = y;
	energy = e;
/* 
 * azimuthX = rand() % 2 - 1;
	azimuthY = rand() % 2 - 1;
	if (azimuthX == 0 && azimuthY == 0)
	{
		azimuthX += 1;
	}
	*/
	// TODO: Set azimuth some other way
	azimuthX = 0;
	azimuthY = 0;
}

void DOCO::setLocation(int x, int y)
{
	mapX = x;
	mapY = y;
	return;
}
void DOCO::setBehavior(behavior* newBehavior)
{
	myBehavior = newBehavior;
	return;
}

//DOCO takes it's turn based upon surrounding conditions
void DOCO::act()
{
	int tempX = mapX;
	int tempY = mapY;
	myBehavior->act(&azimuthX, &azimuthY,myMap,&mapX,&mapY);
	tenant* self = this;
	myMap->addTenant(self, mapX, mapY);
	if(tempX != mapX || tempY != mapY )
	{
		 energy -= ENERGYUSE;
	}
	
	// Death 
	if (energy <= 0)
	{
		myMap->removeTenant(mapX, mapY);
		mapX = -1; //skip future activity
	}
	// Split
	if(energy >= ENERGYSPLIT)
	{
		energy /= 2;
		DOCOFactory* df = df->getInstance();
		df->clone(mapX,mapY,azimuthX,azimuthY,energy,myBehavior->getMarker());
		// Add back because clone will clear the location.
		tenant* self = this;
		myMap->addTenant(self, mapX,mapY);
	}
	
	return;
}

void DOCO::addEnergy(unsigned int e)
{
	energy += e; //Overflows deliberately left in; if DOCO overeats it dies.
	return;
}

//Finds a new course based on surrounding conditions
void DOCO::alterCourse()
{
	if(myBehavior != NULL )
	{
		 int changeX = azimuthX;
		 int changeY = azimuthY;
		 myBehavior->alterCourse(&changeX, &changeY, myMap, mapX, mapY);
		 azimuthX = changeX;
		 azimuthY = changeY;
		 return;
	}
	//Original algorithm, should not run
	
	//Ordered pair coordinate
	struct pair {
		int x;
		int y;
	};
	//Aggregation of ordered pairs
	vector<pair> pairs;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if (myMap->inRange(mapX + i, mapY + j) && !myMap->isOccupied(mapX + i, mapY + j))
			{
				pair t;
				t.x = i;
				t.y = j;
				pairs.push_back(t);
			}
		}
	}

	//DOCO cannot move in any direction
	if (pairs.size() == 0)
	{
		azimuthX = 0;
		azimuthY = 0;
	}
	else
	{
		pair select = pairs.at(rand() % pairs.size());
		azimuthX = select.x;
		azimuthY = select.y;
	}
	return;
}

string DOCO::getAzimuth()
{
	std::string out;
	out.append("(");
	out.append(to_string(azimuthX));
	out.append(",");
	out.append(to_string(azimuthY));
	out.append(")");

	return out;
}

unsigned int DOCO::getEnergy()
{
	return energy;
}

//DOCO moves on current azimuth, do not invoke before checking availability of destination
void DOCO::move()
{
#ifdef DEBUG
	std::cout << "Standard move " << getAzimuth() << std::endl;
#endif
	if (azimuthX == 0 && azimuthY == 0)
	{
#ifdef DEBUG
		std::cout << "No direction\n";
#endif
		return;
	}
	else
	{
		energy -= 10;
		age++;
		myMap->removeTenant(mapX, mapY);
		mapX += azimuthX;
		mapY += azimuthY;
		tenant* temp = this;
		myMap->addTenant(temp, mapX, mapY);
	}
}

//character that represents the DOCO on the map
char DOCO::draw()
{
	return (myBehavior->getMarker());
}
//Report the the status of the DOCO as a string
string DOCO::report()
{
	string out = "STATUS";
	if (energy == 0)
	{
		out.append(" Dead ");
	}
	else
	{
		out.append(" Live ");
	}
	out.append("Age: ");
	out.append(to_string(age));
	out.append(" Energy: ");
	out.append(to_string(energy));
	return out;
}
