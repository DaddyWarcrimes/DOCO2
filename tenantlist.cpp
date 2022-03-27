#include "tenantlist.h"
#include "DOCO.h"
#include <iostream>

//#define DEBUG

tenantlist::tenantlist()
{

}
tenantlist::tenantlist(int size)
{
	list = new DOCO[size];
	iterator = 0;
}
tenantlist::~tenantlist()
{
	delete[] list;
}

void tenantlist::init(int size)
{
	list = new DOCO[size];
	iterator = 0;
}

void tenantlist::addDOCO(DOCO newDOCO)
{
	list[iterator] = newDOCO;
	iterator++;
}

//Signals all DOCOs to take their turn (one at a time)
void tenantlist::act()
{
	for (int i = 0; i < iterator; i++)
	{
		list[i].act();
	}
#ifdef DEBUG
	std::cout << "Current energy : ";
	for (int i = 0; i < iterator; i++)
	{
		std::cout << i << "=" << list[i].getEnergy() << " ";
	}
	std::cout << std::endl;
#endif
	
}

//returns true if all DOCOs are dead
bool tenantlist::extinct()
{
	int sum = 0;
	for (int i = 0; i < iterator; i++)
	{
		sum += list[i].getEnergy();
	}
	return(sum == 0);
}

void tenantlist::report()
{
	for (int i = 0; i < iterator; i++)
	{
		std::cout << i << ". " << list[i].report() << std::endl;
	}
	return;
}
