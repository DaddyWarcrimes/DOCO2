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
	map* factoryMap;
	tenantlist* factoryList;
public:
	DOCOFactory();
	~DOCOFactory();
	DOCOFactory* getInstance();
	DOCO* createDOCO(map* myMap, tenantlist* clist,int mapX, int mapY, unsigned int energy, char* behavior);
	DOCO* cloneDOCO(DOCO* parent);
	void populateList(tenantlist* clist, map* myMap, std::string file);
	void populateObstacles(tenantlist* clist, map* myMap, std::string file);
	int countInstance();
	void clone(int mapX, int mapY, int azimuthX, int azimuthY, int energy, char direction);
};
