#pragma once
#include <string>
class DataParser;
class DOCO;
class tenantlist;
class map;
class behavior;

class DOCOFactory
{
private:
	DataParser* dp;
public:
	DOCOFactory();
	~DOCOFactory();
	DOCOFactory* getInstance();
	DOCO* createDOCO(map* myMap, tenantlist* clist,int mapX, int mapY, unsigned int energy, char* behavior);
	DOCO* cloneDOCO(DOCO* parent);
	void populateList(tenantlist* clist, map* myMap, std::string file);
	int countInstance();
};
