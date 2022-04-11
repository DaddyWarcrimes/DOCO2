#include "horizontalBehavior.h"
#include "map.h"
#include <random>
#include <vector>
#include "config.h"

horizontalBehavior::horizontalBehavior()
{
	marker = '=';
	return;
}
horizontalBehavior::~horizontalBehavior()
{
	return;
}
char horizontalBehavior::getMarker()
{
	return marker;
}
void horizontalBehavior::alterCourse(int* azimuthX, int* azimuthY, map* myMap, int mapX, int mapY)
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
		else if (myMap->inRange(mapX + i,mapY) && !myMap->isOccupied(mapX +i, mapY))
		{
			pair potential;
			potential.potentialX = i;
			potential.potentialY = 0;
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
		printf("%s%d%s%d\n","---DEBUG--- horizontalBehavior alterCourse",*azimuthX,"-",*azimuthY );
#endif
		

	}
	return;
}

void horizontalBehavior::act(int* azimuthX, int* azimuthY, map* myMap, int* mapX, int* mapY) 
{
	if(*azimuthX == 0 && *azimuthY == 0 )
	{
		 alterCourse(azimuthX,azimuthY,myMap,*mapX,*mapY);
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
	if(myMap->inRange(*mapX + *azimuthX, *mapY) && !myMap->isOccupied(*mapX + *azimuthX , *mapY ) )
	{
		myMap->removeTenant(*mapX, *mapY);
		*mapX += *azimuthX;
		return;
	}
	// map edge
	else if(!myMap->inRange(*mapX + *azimuthX, *mapY ) )
	{
		//shift left or right
		std::vector<int> xOffsets;
		int divisor = 0;
		if(myMap->inRange(*mapX , *mapY -1) && !myMap->isOccupied(*mapX, *mapY -1)) 
		{
			 xOffsets.push_back(-1);
			 divisor ++;
		}
		if(myMap->inRange(*mapX , *mapY +1) && !myMap->isOccupied(*mapX, *mapY + 1) )
		{
			 xOffsets.push_back(1);
			 divisor ++;
		}
		if(divisor > 0)
		{
			int Offset = xOffsets[rand() % divisor];
			myMap->removeTenant(*mapX, *mapY);
			*mapY += Offset;
			*azimuthX *= -1;
			return;
		}
		//can't shift left or right, must go diaonal
		else
		{
			xOffsets.clear();
			if (myMap->inRange(*mapX - *azimuthX, *mapY - 1) && !myMap->isOccupied(*mapX - *azimuthX, *mapY - 1))
			{
				xOffsets.push_back(-1);
				divisor ++;
			}
			if (myMap->inRange(*mapX - *azimuthX, *mapY + 1) && !myMap->isOccupied(*mapX - *azimuthX, *mapY + 1))
			{
				xOffsets.push_back(1);
				divisor ++;
			}
			if (divisor > 0)
			{
				int Offset = xOffsets[rand() % divisor];
				myMap->removeTenant(*mapX, *mapY);
				*mapY += Offset;
				*mapX -= *azimuthX;
				*azimuthX *= -1;
				return;
			}
			else
			{
				return;
			}
		}
	}
	// Occupied in path
	else if(myMap->isOccupied(*mapX + *azimuthX,*mapY) && myMap->inRange(*mapX - *azimuthX, *mapY ) && !myMap->isOccupied(*mapX - *azimuthX, *mapY) )
	{
		myMap->removeTenant(*mapX, *mapY);
		*azimuthX *= -1;
		*mapX += *azimuthX;
		return;	
	}
	
	// Occupied in path and reverse
	else if(myMap->isOccupied(*mapX + *azimuthX, *mapY) && (myMap->isOccupied(*mapX - *azimuthX, *mapY) || !myMap->inRange(*mapX + *azimuthX, *mapY)))
	{
		std::vector<pair> pairs;
		int size = 0;
		for(int i = -1; i < 2; i++)
		{
			for(int j = -1; j < 2; j++)
			{
				if(i == 0 && j == 0 )
				{
				 	continue;
				}
				else if(myMap->inRange(*mapX + i, *mapY + j) && !myMap->isOccupied(*mapX + i, *mapY + j) )
				{
					pair add;
			       		add.potentialX = *mapX + i;
					add.potentialY = *mapY + j;		
					pairs.push_back(add);
					size ++;
				}
			}
		}
		pair select = pairs[rand() % size];
		myMap->removeTenant(*mapX, *mapY);
		*mapX = select.potentialX;
		*mapY = select.potentialY;


	}
	
	return;

}
