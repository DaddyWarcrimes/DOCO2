#include "tenantlist.h"
#include "tenant.h"
#include "config.h"
#include <iostream>

//#define DEBUG

tenantlist::tenantlist()
{

}
tenantlist::tenantlist(int size)
{
	list.reserve(size);
}
tenantlist::~tenantlist()
{
	
}

void tenantlist::init(int size)
{
	list.reserve(size);
	iterator = 0;
}

void tenantlist::addTenant(tenant* newTenant)
{
	list.push_back(newTenant);
}

//Signals all tenants to take their turn (one at a time)
void tenantlist::act()
{
	for(int i = 0; i < list.size(); i++)
	{
		 list.at(i)->act();
	}
	
/* 
 * for (int i = 0; i < iterator; i++)
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
*/
	
}

//returns true if all tenants are dead
bool tenantlist::extinct()
{
/* Won't work correctly for tenant class 
 * int sum = 0;
	for (int i = 0; i < iterator; i++)
	{
		sum += list[i].getEnergy();
	}
	return(sum == 0);
	*/
	return false;
}

void tenantlist::report()
{
/* Won't work correctly for tenant class 
 * for (int i = 0; i < iterator; i++)
	{
		std::cout << i << ". " << list[i].report() << std::endl;
	}
	*/
	return;
}
