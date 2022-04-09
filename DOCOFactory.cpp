#include "DOCOFactory.h"
#include "DataParser.h"
#include "DOCO.h"
#include "obstacle.h"
#include "tenantlist.h"
#include "map.h"
#include "config.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "verticalBehavior.h"
#include "staticBehavior.h"



DOCOFactory::DOCOFactory()
{
	return;
}
DOCOFactory::~DOCOFactory()
{
	return;
}
DOCOFactory* DOCOFactory::getInstance()
{
	static DOCOFactory* instance = NULL;

	if(instance == NULL )
	{
		instance = new DOCOFactory();
	}
	else
	{
		std::cout << "instance already exists" << std::endl ;
	}
	
#ifdef DEBUG
	printf("%s%p\n","---DEBUG---",instance);
#endif
	
	return instance;
}
DOCO* DOCOFactory::createDOCO(map* myMap, tenantlist* clist,int mapX, int mapY, unsigned int energy, char* behavior)
{
	DOCO* subject = new DOCO(myMap, mapX, mapY, energy);
	tenant* t = subject;
	clist->addTenant(t);
	return subject;
}
void DOCOFactory::populateList(tenantlist* clist, map* myMap, std::string file)
{
	char direction[10];
	int u,v; 

	DataParser* dp = dp->getInstance(file.c_str());
	while(dp->getDOCOData(direction,&u,&v) )
	{
		if (direction[0] == 'V')
		{
		tenant* addition = new DOCO(myMap, u,v,STARTENERGY);
		behavior* addBeh = new verticalBehavior();
		addition->setBehavior(addBeh);
		clist->addTenant(addition);
		}
	}
	return;

}

void DOCOFactory::populateObstacles(tenantlist* clist, map* myMap, std::string file)
{
	DataParser* dp = dp->getInstance(file.c_str());
	int u,v;
	while(dp->getObstacleData(&u, &v))
	{
		tenant* addition = new obstacle;
		behavior* addBeh = new staticBehavior;
		addition->setBehavior(addBeh);
		myMap->addTenant(addition, u, v);
		std::cout << (char)128 << addBeh->getMarker();
	}
	std::cout << std::endl;
	return;
}
