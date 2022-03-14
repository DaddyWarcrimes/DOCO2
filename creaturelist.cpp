#include "creaturelist.h"
#include "DOCO.h"
#include <iostream>

//#define DEBUG

creaturelist::creaturelist()
{

}
creaturelist::creaturelist(int size)
{
	list = new DOCO[size];
	iterator = 0;
}
creaturelist::~creaturelist()
{
	delete[] list;
}

void creaturelist::init(int size)
{
	list = new DOCO[size];
	iterator = 0;
}

void creaturelist::addDOCO(DOCO newDOCO)
{
	list[iterator] = newDOCO;
	iterator++;
}

//Signals all DOCOs to take their turn (one at a time)
void creaturelist::act()
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
bool creaturelist::extinct()
{
	int sum = 0;
	for (int i = 0; i < iterator; i++)
	{
		sum += list[i].getEnergy();
	}
	return(sum == 0);
}

void creaturelist::report()
{
	for (int i = 0; i < iterator; i++)
	{
		std::cout << i << ". " << list[i].report() << std::endl;
	}
	return;
}
