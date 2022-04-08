#pragma once
#include <vector>
#include "location.h"

class tenant;
class location;

class map
{
private:
	int maxX;
	int maxY;
	location** grid;
public:
	map();
	map(int mx, int my);
	~map();
	void populateGrid(int x, int y);
	int getMaxX();
	int getMaxY();
	void addTenant(tenant* newTenant, int x, int y);
	void removeTenant(int x, int y);
	bool inRange(int x, int y);
	bool isOccupied(int x, int y);
	int pelletCount(int x, int y);
	void addPellet(int x, int y);
	void draw();
	char drawLocation(int x, int y);
	int feed(int x, int y);
};

