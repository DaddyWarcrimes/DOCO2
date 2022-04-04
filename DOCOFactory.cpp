#include "DOCOFactory.h"
#include "DataParser.h"
#include "DOCO.h"
#include "tenantlist.h"
#include "map.h"
#include "config.h"
#include <stdio.h>
#include <iostream>

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

