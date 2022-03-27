#pragma once
#include "map.h"
#include "tenantlist.h"


class map;
class tenantlist;
class DOCO;
class DataParser;

class world
{
private: 
	map* myMap;
	int maxX;
	int maxY;
	tenantlist clist;
	void turn();

public:
	world(const char* fileName);
	~world();
	void seed();
	void init(const char* fileName);
	void run(int turns);
};
