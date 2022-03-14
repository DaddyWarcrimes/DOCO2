#pragma once
#include "map.h"
#include "creaturelist.h"


class map;
class creaturelist;
class DOCO;
class DataParser;

class world
{
private: 
	map* myMap;
	int maxX;
	int maxY;
	creaturelist clist;
	void turn();

public:
	world(const char* fileName);
	~world();
	void seed();
	void init(const char* fileName);
	void run(int turns);
};
