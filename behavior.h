#pragma once
#include <iostream>
class map;

class behavior
{
	private:
		char marker;
	public:
		behavior();
		~behavior();
		virtual char getMarker()
		{
			std::cout << "virtual char getMarker\n";
			return '\0';
		};
		virtual void alterCourse(int* azimuthX, int* azimuthY, map* myMap, int mapX, int mapY)
		{
			std::cout << "virtual oid alterCourse\n";
		};
		virtual void act(int* azimuthX, int* azimuthY, map* myMap, int* mapX, int* mapY);
};
