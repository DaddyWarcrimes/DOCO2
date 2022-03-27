#pragma once
#include <iostream>

class tenant
{
private:
	unsigned int age;
public:
	tenant();
	~tenant();
	virtual void act() {
		std::cout << "Virtual function 'act'" << std::endl;
		
		return;};
};

