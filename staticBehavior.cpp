#include "staticBehavior.h"
#include "config.h"
#include <stdio.h>

staticBehavior::staticBehavior()
{
	marker = '#';
	return;
}
staticBehavior::~staticBehavior()
{
	return;
}
char staticBehavior::getMarker()
{
	return marker;
}
void staticBehavior::alterCourse(int* azimuthX, int* azimuthY, map* myMap, int mapX, int mapY)
{
	return;
}

void staticBehavior::act(int* azimuthX, int* azimuthY, map* myMap, int* mapX, int* mapY) 
{
	return;
}

