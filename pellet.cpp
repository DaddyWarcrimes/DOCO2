#include "pellet.h"

pellet::pellet()
{
	energy = 50;
	return;
}
pellet::~pellet() 
{
	return;
}

int pellet::getEnergy()
{
	return(energy);
}
