#include "obstacle.h"
#include "behavior.h"

obstacle::obstacle()
{
	return;
}
obstacle::~obstacle()
{
	return;
}
void obstacle::setBehavior(behavior* newBehavior)
{
	myBehavior = newBehavior;
}
char obstacle::draw()
{
	return myBehavior->getMarker();
}
void obstacle::act()
{
	return;
}
