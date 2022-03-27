#include "config.h"
#include "world.h"
#include "map.h"
#include "tenantlist.h"
#include "DOCO.h"
#include "DataParser.h"
#include <iostream>
#include <random>
#include <vector>

//#define DEBUG

// Windows Definitions
#ifdef WINDOWS
//#define WAIT (timeout 1 /nobreak > nul)
//#define CLEARSCREEN cls
#endif

// Linux Definitions
#ifdef LINUX
#define WAIT ("sleep 1")
#define CLEARSCREEN ("clear")
#endif


world::world(const char* fileName)
{
	init(fileName);
}
world::~world()
{
	delete myMap;
}

//Seeds the map with food pellets
void world::seed()
{
	int reserve = 0; // represents how many pellets can be placed
	struct pair { // An available location for a food pellet
		int x;
		int y;
	};
	vector<pair> pairs; //all available locations for food pellets
	for (int i = 0; i < maxX; i++)
	{
		for (int j = 0; j < maxY; j++)
		{
			//Add location to pairs if unoccupied and less than 3 pellets
			if (!myMap->isOccupied(i,j) && myMap->pelletCount(i,j) < 3)
			{
				pair a = { i, j };
				#ifdef DEBUG
				printf("Possible seed %d, %d\n", i, j);
				#endif
				pairs.push_back(a);
				reserve += 3 - myMap->pelletCount(i,j);
			}
		}
	}
#ifdef DEBUG
	printf("Reserve: %d\n",reserve);
#endif
	int qty;
	// Use the lower of 10, or maximum possible pellet placements
	if (reserve < 10)
	{
		qty = rand() % reserve;
	}
	else
	{
		qty = rand() % 10;
	}
#ifdef DEBUG
	printf("qty: %d \n", qty);
#endif
	//randomly select positions from those previously identified as available
	for (int i = qty; i > 0; i-- )
	{
		int s = rand() % pairs.size();
		pair select = pairs.at(s);
#ifdef DEBUG
		printf("Selected: %d,%d ", select.x, select.y);
#endif
		myMap->addPellet(select.x, select.y);
		//remove location if it now contains 3 pellets
		if (myMap->pelletCount(select.x,select.y) == 3)
		{
			pairs.erase(pairs.begin() + s);
		}
//		reserve -= 1;

	}
	
	

}

//Initialize world based on datafile
void world::init(const char* fileName)
{

	DataParser* dp = dp->getInstance(fileName);
	maxX = dp->getDOCOWorldWidth();
	maxY = dp->getDOCOWorldHeight();
	myMap = new map(maxX, maxY);
	int DOCOcount = dp->getDOCOCount();
	clist.init(DOCOcount);
	char getDir;
	int getX, getY;
	while (dp->getDOCOData(&getDir, &getX, &getY))
	{
		DOCO a(myMap, getX, getY, 500);
		clist.addDOCO(a);
	}
}

//Each 1 second turn
void world::turn()
{
	clist.act();
	seed();
    system(WAIT);
	system(CLEARSCREEN);
	myMap->draw();

}

//Set the world in motion
void world::run(int turns)
{
	if (myMap == nullptr)
	{
		std::cout << "World not initialized" << std::endl;
		return;
	}
	//runs until all DOCOs die
	else if (turns == -1)
	{
		seed();
		myMap->draw();
		while (!clist.extinct())
		{
			turn();
		}
	}
	else
	{
		seed();
		myMap->draw();
		for (int i = 1; i <= turns; i++)
		{
			turn();
		}
	}
	std::cout << "Final Report:" << std::endl;
	clist.report();
	return;
}
