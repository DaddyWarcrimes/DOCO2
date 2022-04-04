#pragma once
class DataParser;
class DOCO;
class tenantlist;
class map;

class DOCOFactory
{
private:
	DataParser* dp;

public:
	DOCOFactory();
	~DOCOFactory();
	DOCOFactory* getInstance();
	DOCO* createDOCO(map* myMap,int mapX, int mapY, unsigned int energy, char* behavior);
	DOCO* cloneDOCO(DOCO* parent);
	int countInstance();
};
