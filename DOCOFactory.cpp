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
#include "horizontalBehavior.h"
#include "diagonalBehavior.h"

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
	factoryList = clist;
	factoryMap = myMap;
	char direction[10];
	int u,v; 
	behavior* addVert = new verticalBehavior;
	behavior* addHor = new horizontalBehavior;
	behavior* addDiag = new diagonalBehavior;
	DataParser* dp = dp->getInstance(file.c_str());
	while(dp->getDOCOData(direction,&u,&v) )
	{
		tenant* addition = new DOCO(myMap, u,v,STARTENERGY);
		if (direction[0] == 'V')
		{
		addition->setBehavior(addVert);
		}
		else if(direction[0] == 'H' )
		{
		addition->setBehavior(addHor);
		}
		else if(direction[0] == 'D' )
		{
		addition->setBehavior(addDiag);
		}
		
		clist->addTenant(addition);
	}
	return;

}

void DOCOFactory::populateObstacles(tenantlist* clist, map* myMap, std::string file)
{
	DataParser* dp = dp->getInstance(file.c_str());
	behavior* addBeh = new staticBehavior;
	int u,v;
	while(dp->getObstacleData(&u, &v))
	{
		tenant* addition = new obstacle;
		addition->setBehavior(addBeh);
		myMap->addTenant(addition, u, v);
		std::cout << (char)128 << addBeh->getMarker();
	}
	std::cout << std::endl;
	return;
}
void DOCOFactory::clone(int mapX, int mapY, int azimuthX, int azimuthY, int energy, char direction)
{
	tenant* newClone = new DOCO(factoryMap, mapX, mapY, energy);
	behavior* addBeh;
	if(direction == '|')
	{
		 addBeh = new verticalBehavior;
	}
	else if(direction == '=' )
	{
		addBeh = new horizontalBehavior;
	}
	else if(direction == 'X' )
	{
		addBeh = new diagonalBehavior;
	}
	newClone->setBehavior(addBeh);
	//move clone off of parent location;
	newClone->act();
	//add clone to front of the list so it won't be called to act this round
	factoryList->addDynamic(newClone);
	return;
}
