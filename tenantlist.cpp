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
	return;
}

void tenantlist::addTenant(tenant* newTenant)
{
	list.push_back(newTenant);
	return;
}
void tenantlist::addDynamic(tenant* newTenant)
{
	list.insert(list.begin(),newTenant);
	return;
}
//Signals all tenants to take their turn (one at a time)
void tenantlist::act()
{
	for(int i = 0; i < (int)list.size(); i++)
	{
		 list.at(i)->act();
	}
	

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
	for(int i = 0; i < (int)list.size(); i++ )
	{
		std::cout << i << ": " << list[i]->draw() << std::endl;
	}
	
	return;
}
