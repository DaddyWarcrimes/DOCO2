#pragma once
#include <vector>
#include "location.h"
#include "tenant.h"

class tenant;
class location;

class map
{
private:
	int maxX;
	int maxY;
	location** grid;
	void populateGrid();
public:
	map();
	map(int mx, int my);
	~map();
	int getMaxX();
	int getMaxY();
	void addTenant(tenant* newTenant, int x, int y);
	void removeTenant(int x, int y);
	bool inRange(int x, int y);
	bool isOccupied(int x, int y);
	int pelletCount(int x, int y);
	void addPellet(int x, int y);
	void draw();
	int feed(int x, int y);
};

