#pragma once
#include "pellet.h"
#include <vector>

class DOCO;
class location
{
private:
	std::vector<pellet> pellets;
	DOCO* occupant;

public:
	location();
	~location();
	void addDOCO(DOCO* newDOCO);
	void removeDOCO();
	bool isOccupied();
	int pelletCount();
	void addPellet();
	int feed();

};

