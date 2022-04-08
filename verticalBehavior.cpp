#include "verticalBehavior.h"
#include "map.h"
#include <random>
#include <vector>
#include "config.h"

verticalBehavior::verticalBehavior()
{
	marker = '|';
	return;
}
verticalBehavior::~verticalBehavior()
{
	return;
}
char verticalBehavior::getMarker()
{
	return marker;
}
void verticalBehavior::alterCourse(int* azimuthX, int* azimuthY, map* myMap, int mapX, int mapY)
{
#ifdef DEBUG
	printf("%s%d%s%d\n","---DEBUG---alterCourse",*azimuthX,"-",*azimuthY);
#endif
	
	struct pair {int potentialX; int potentialY;};
	std::vector<pair> pairs;
	for(int i = -1; i < 2; i++ )
	{
		if (i == 0)
		{
			continue;
		}
		else if (myMap->inRange(mapX,mapY + i) && !myMap->isOccupied(mapX, mapY + i))
		{
			pair potential;
			potential.potentialX = 0;
			potential.potentialY = i;
			pairs.push_back(potential);
		}
	}
	if(pairs.size() == 0 )
	{
		 *azimuthX = 0;
		 *azimuthY = 0;
	}
	else
	{
		pair select = pairs.at(rand() % pairs.size());
		*azimuthX = select.potentialX;
		*azimuthY = select.potentialY;
#ifdef DEBUG
		printf("%s%d%s%d\n","---DEBUG--- verticalBehavior alterCourse",*azimuthX,"-",*azimuthY );
#endif
		

	}
	return;
}

void verticalBehavior::act(int* azimuthX, int* azimuthY, map* myMap, int* mapX, int* mapY) 
{
	struct pair {int potentialX; int potentialY;};
	//DOCO is dead
	if (*mapX == -1)
	{
		return;
	}
	
	//check for pellets
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (!myMap->inRange(*mapX + i, *mapY + j))
			{
				continue;
			}
			else if (myMap->pelletCount(i + *mapX,j + *mapY) > 0)
			{
				myMap->removeTenant(*mapX, *mapY);
				*mapX += i;
				*mapY += j;
//Move this to DOCO act		myMap->addTenant(this, mapX, mapY);
//				addEnergy(myMap->feed(mapX, mapY));
				return;
			}
		}
	}
	//Checks if it can move on current azimuth
	
	//can move
	if(myMap->inRange(*mapX, *mapY + *azimuthY) && !myMap->isOccupied(*mapX , *mapY + *azimuthY) )
	{
		myMap->removeTenant(*mapX, *mapY);
		*mapY += *azimuthY;
		return;

	}
	// map edge
	else if(!myMap->inRange(*mapX, *mapY + *azimuthY) )
	{
		//shift left or right
		std::vector<int> xOffsets;
		int divisor = 0;
		if(myMap->inRange(*mapX - 1, *mapY && !myMap->isOccupied(*mapX - 1, *mapY)) )
		{
			 xOffsets.push_back(-1);
			 divisor ++;
		}
		if(myMap->inRange(*mapX + 1, *mapY && !myMap->isOccupied(*mapX + 1, *mapY)) )
		{
			 xOffsets.push_back(1);
			 divisor ++;
		}
		if(divisor > 0)
		{
			int Offset = xOffsets[rand() % divisor];
			myMap->removeTenant(*mapX, *mapY);
			*mapX += Offset;
			*azimuthY *= -1;
			return;
		}
		//can't shift left or right, must go diaonal
		else
		{
			xOffsets.clear();
			if (myMap->inRange(*mapX -1, *mapY - *azimuthY) && !myMap->isOccupied(*mapX -1, *mapY - *azimuthY))
			{
				xOffsets.push_back(-1);
				divisor ++;
			}
			if (myMap->inRange(*mapX + 1, *mapY - *azimuthY) && !myMap->isOccupied(*mapX + 1, *mapY - *azimuthY))
			{
				xOffsets.push_back(-1);
				divisor ++;
			}
			if (divisor > 0)
			{
				int Offset = xOffsets[rand() % divisor];
				myMap->removeTenant(*mapX, *mapY);
				*mapX += Offset;
				*mapY -= *azimuthY;
				*azimuthY *= -1;
				return;
			}
			else
			{
				return;
			}
		}
	}

	// Occupied in path
	// Occupied in path and reverse
	
	return;

}
