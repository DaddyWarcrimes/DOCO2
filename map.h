#pragma once
#include <vector>
#include "location.h"
#include "DOCO.h"

class DOCO;
class location;

class map
{
private:
	int maxX;
	int maxY;
	//std::vector<std::vector<location*>> grid;
	location** grid;
	void populateGrid();
public:
	map();
	map(int mx, int my);
	~map();
	int getMaxX();
	int getMaxY();
	void addDOCO(DOCO* newDOCO, int x, int y);
	void removeDOCO(int x, int y);
	bool inRange(int x, int y);
	bool isOccupied(int x, int y);
	int pelletCount(int x, int y);
	void addPellet(int x, int y);
	void draw();
	int feed(int x, int y);
};

