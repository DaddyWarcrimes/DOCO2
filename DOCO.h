#pragma once
#include <string>

using namespace std;
class map;

class DOCO
{
private:
    map* myMap;
    int azimuthX;
    int azimuthY;
    int mapX;
    int mapY;
    int age;
    unsigned int energy;
    void alterCourse();
    void move();
public:
    DOCO();
    DOCO(map* newMap, int x, int y, int e);
    ~DOCO();
    void setLocation(int x, int y);
    void act();
    void addEnergy(unsigned int e);
    void addMap(map* newMap);
	string getAzimuth();
    unsigned int getEnergy();
    string report();
};

