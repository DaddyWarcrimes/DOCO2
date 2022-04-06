#pragma once
#include <string>
#include "tenant.h"

using namespace std;
class map;
class tenantlist;
class behavior;

class DOCO : public tenant
{
private:
    map* myMap;
    tenantlist * list;
    int azimuthX;
    int azimuthY;
    int mapX;
    int mapY;
    int age;
    unsigned int energy;
    void alterCourse();
    void move();
    behavior* myBehavior;
public:
    DOCO();
    DOCO(map* newMap, int x, int y, int e);
    ~DOCO();
    void setLocation(int x, int y);
    void act() override;
    void setBehavior(behavior* addBehavior);
    void addEnergy(unsigned int e);
    void addMap(map* newMap);
	string getAzimuth();
    unsigned int getEnergy();
    string report();
};

