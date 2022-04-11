#pragma once
#include "behavior.h"
class behavior;
class horizontalBehavior : public behavior
{
private:
	char marker;
public:
	horizontalBehavior();
	~horizontalBehavior();
	char getMarker() override;
	void alterCourse(int* azimuthX, int* azimuthY, map* myMap, int mapX, int mapY) override;
	void act(int* azimuthX, int* azimuthY, map* myMap, int* mapX, int* mapY) override;
};
