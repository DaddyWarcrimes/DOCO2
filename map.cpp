#include "map.h"
#include "location.h"
#include <iostream>
#include <string.h>
#include "tenant.h"

using namespace std;

map::map()
{
	grid = NULL;
}

map::~map()
{

}

map::map(int mx, int my)
{
/* 
	maxX = mx;
	maxY = my;
	*/
	grid = NULL;
	populateGrid(mx,my);
}

//Builds all locations on the map, and adds them to the grid
void map:: populateGrid(int x, int y)
{
	if(grid != NULL )
	{
		 delete grid;
	}
	maxX = x;
	maxY = y;
	grid = new location*[maxY];
	for (int i = 0; i < maxX; i++)
	{
		grid[i] = new location[maxX];
		for (int j = 0; j < maxY; j++)
		{
			location t;
			grid[i][j] = t;
		}
	}
}

int map::getMaxX()
{
	return maxX;
}

int map::getMaxY()
{
	return maxY;
}

void map::addTenant(tenant* newTenant, int x, int y)
{
	grid[x][y].addTenant(newTenant);
}

void map::removeTenant(int x, int y)
{
	grid[x][y].removeTenant();
}

//returns true if a specified location is actually on the map
bool map::inRange(int x, int y)
{
	return (x >= 0 && y >= 0 && x < maxX && y < maxY);
}

//returns true if a tenant is at the specified location
bool map::isOccupied(int x, int y)
{
	return grid[x][y].isOccupied();
}

void map::addPellet(int x, int y)
{
	grid[x][y].addPellet();
	return;
}

//Prints coordinates, locations, tenants and pellets in map format to the screen
void map::draw()
{
	std::cout <<"  ";
	for(int i = 0; i < maxX; i++ )
	{
		std::cout << i / 10;
	}
	std::cout << "\n  ";
	for(int i = 0l; i < maxX; i++ )
	{
		std::cout << i % 10;
	}
	std::cout << std::endl;
	for(int j = 0; j < maxY; j++ )
	{
		 if(j < 10 )
		 {
			 std::cout << ' ';
		 }
		 std::cout << j;

		 for(int i = 0; i < maxX; i++ )
		 {
			 std::cout << grid[i][j].draw();
		 }
		std::cout << std::endl;
	}


	return;
}
char map::drawLocation(int x, int y)
{
	return grid[x][y].draw();
}
//Number of pellets at a specified map location
int map::pelletCount(int x, int y)
{
	return (grid[x][y].pelletCount());
}

//tenant eats all the pellets at a map location
int map::feed(int x, int y)
{
	return grid[x][y].feed();
}
