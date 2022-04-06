
#include <iostream>
#include <string.h>
#include "location.h"
#include "pellet.h"
#include "DOCO.h"
#include <vector>

using namespace std;

location::location()
{
	occupant = nullptr;
}

location::~location()
{
}

void location::addDOCO(DOCO* newDOCO)
{
	occupant = newDOCO;
	return;
}

void location::removeDOCO()
{
	occupant = nullptr;
	return;
}

bool location::isOccupied()
{
	return !(occupant == nullptr);
	return false;
}

int location::pelletCount()
{
	return ((int)pellets.size());
}

void location::addPellet()
{
	if (pellets.size() == 3)
	{
		return;
	}
	pellet p; 
	pellets.push_back(p);
	return;
}

// Returns the total energy of all pellets at the location, and removes them. Simulates DOCO eating the pellets
int location::feed()
{
	int sum = 0;
	for (int i = 0; i < (int)pellets.size(); i++ )
	{
		sum += pellets.at(i).getEnergy();
	}
	pellets.clear();
	return (sum);
}

//retuns the character of the occupant
char location::draw()
{
	if(occupant != NULL)
	{
		 return occupant->draw();
	}
	else if ((int)pellets.size() == 0)
	{
		return '-';
	}
	else
	{
		return '.';
	}
}
