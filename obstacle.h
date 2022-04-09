
#pragma once
#include "tenant.h"

class behavior;

class obstacle : public tenant
{
private:
	behavior* myBehavior;
public:
	obstacle();
	~obstacle();
	void act() override;
	void setBehavior(behavior* newBehavior) override;
	char draw() override;
};
