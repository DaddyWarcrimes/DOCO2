#pragma once
#include "behavior.h"
class behavior;
class verticalBehavior : public behavior
{
	private:
		char marker;
	public:
		verticalBehavior();
		~verticalBehavior();
		char getMarker();
		void alterCourse(int* azimuthX, int* azimuthY, map* myMap, int mapX, int mapY);
};
