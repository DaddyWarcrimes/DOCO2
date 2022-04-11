#pragma once
#include "behavior.h"
class behavior;
class diagonalBehavior : public behavior
{
private:
	char marker;
public:
	diagonalBehavior();
	~diagonalBehavior();
	char getMarker() override;
	void alterCourse(int* azimuthX, int* azimuthY, map* myMap, int mapX, int mapY) override;
	void act(int* azimuthX, int* azimuthY, map* myMap, int* mapX, int* mapY) override;
};
