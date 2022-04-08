#include "DOCOFactory.h"
#include "DataParser.h"
#include "DOCO.h"
#include "tenantlist.h"
#include "map.h"
#include "config.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include "verticalBehavior.h"


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
	int w = 0;

	DataParser* dp = dp->getInstance(file.c_str());
	while(dp->getDOCOData(direction,&u,&v) )
	{
		if (direction[0] == 'V')
		{
		tenant* addition = new DOCO(myMap, u,v,500);
		behavior* addBeh = new verticalBehavior();
		addition->setBehavior(addBeh);
		clist->addTenant(addition);
		}
	}
	return;

}

