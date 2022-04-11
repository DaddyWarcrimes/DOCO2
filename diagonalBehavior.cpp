#include "diagonalBehavior.h"
#include "map.h"
#include <random>
#include <vector>
#include "config.h"

diagonalBehavior::diagonalBehavior()
{
	marker = 'X';
	return;
}
diagonalBehavior::~diagonalBehavior()
{
	return;
}
char diagonalBehavior::getMarker()
{
	return marker;
}
void diagonalBehavior::alterCourse(int* azimuthX, int* azimuthY, map* myMap, int mapX, int mapY)
{
#ifdef DEBUG
	printf("%s%d%s%d\n","---DEBUG---alterCourse",*azimuthX,"-",*azimuthY);
#endif
	
	struct pair {int potentialX; int potentialY;};
	std::vector<pair> pairs;
	int divisor = 0;
	for(int i = -1; i < 2; i +=2)
	{
		for(int j = -1; j < 2; j +=2)
		{
			if(myMap->inRange(mapX + i, mapX + j) && !myMap->isOccupied(mapX + i, mapY + j) )
			{
				pair add;
				add.potentialX = i;
				add.potentialY = j;
				pairs.push_back(add);
				divisor ++;
			}
		}
	}
	pair select = pairs[rand() % divisor];
	*azimuthX = select.potentialX;
	*azimuthY = select.potentialY;
	return;
}

void diagonalBehavior::act(int* azimuthX, int* azimuthY, map* myMap, int* mapX, int* mapY) 
{
	if(*azimuthX == 0 && *azimuthY == 0 )
	{
		 alterCourse(azimuthX,azimuthY,myMap,*mapX,*mapY);
	}

	if(*azimuthX == 0 && *azimuthY == 0 )
	{
		return;
	}
	
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
	if(myMap->inRange(*mapX + *azimuthX, *mapY + *azimuthY) && !myMap->isOccupied(*mapX  + *azimuthX, *mapY + *azimuthY) )
	{
		myMap->removeTenant(*mapX, *mapY);

		*mapY += *azimuthY;
		*mapX += *azimuthX;
		return;

	}
	// map edge
	else if(!myMap->inRange(*mapX + *azimuthX, *mapY + *azimuthY) )
	{

		diagonalBehavior::alterCourse(azimuthX, azimuthY, myMap, *mapX, *mapY);
		std::vector<pair> pairs;
		int divisor = 0;
		for(int i = -1; i < 2; i += 2)
		{
			if(myMap->inRange(*mapX + i, *mapY) && !myMap->isOccupied(*mapX + i, *mapY) )
			{
				 pair add;
				 add.potentialX = i;
				 add.potentialY = 0;
				 pairs.push_back(add);
				 divisor ++;
			}
			if(myMap->inRange(*mapX, *mapY + i) && !myMap->isOccupied(*mapX, *mapY + i) )
			{
				 pair add;
				 add.potentialX = 0;
				 add.potentialY = i;
				 pairs.push_back(add);
				 divisor ++;
			}
		}
		pair select = pairs[rand() % divisor];
		myMap-> removeTenant(*mapX,*mapY);
		*mapX += select.potentialX;
		*mapY += select.potentialY;
		return;
	}
	// Occupied in path
	else if(myMap->isOccupied(*mapX + *azimuthX,*mapY + *azimuthY) && myMap->inRange(*mapX - *azimuthX, *mapY - *azimuthY) && !myMap->isOccupied(*mapX - *azimuthX, *mapY - *azimuthY) )
	{
		myMap->removeTenant(*mapX, *mapY);
		*azimuthY *= -1;
		*azimuthX *= -1;
		*mapY += *azimuthY;
		*mapX += *azimuthX;
		return;	
	}
	
	// Occupied in path and reverse
	else if(myMap->isOccupied(*mapX, *mapY + *azimuthY) && (myMap->isOccupied(*mapX, *mapY - *azimuthY) || !myMap->inRange(*mapX, *mapY - *azimuthY)))
	{
		std::vector<pair> pairs;
		int divisor = 0;
		for(int i = -1; i < 2; i += 2)
		{
			if(myMap->inRange(*mapX + i, *mapY) && !myMap->isOccupied(*mapX + i, *mapY) )
			{
				 pair add;
				 add.potentialX = i;
				 add.potentialY = 0;
				 pairs.push_back(add);
				 divisor ++;
			}
				if(myMap->inRange(*mapX, *mapY + i) && !myMap->isOccupied(*mapX, *mapY + i) )
			{
				 pair add;
				 add.potentialX = 0;
				 add.potentialY = i;
				 pairs.push_back(add);
				 divisor ++;
			}		
		}
		pair select = pairs[rand() % divisor];
		myMap->removeTenant(*mapX, *mapY);
		*mapX += select.potentialX;
		*mapY += select.potentialY;

	}
	
	return;

}
