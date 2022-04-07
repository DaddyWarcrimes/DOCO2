#pragma once
#include "pellet.h"
#include <vector>

class tenant;
class location
{
private:
	std::vector<pellet> pellets;
	tenant* occupant;

public:
	location();
	~location();
	void addTenant(tenant* newTenant);
	void removeTenant();
	bool isOccupied();
	int pelletCount();
	void addPellet();
	int feed();
	char draw();

};

