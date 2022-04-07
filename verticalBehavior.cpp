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
	vector<pair> pairs;
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
