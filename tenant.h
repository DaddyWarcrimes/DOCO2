#pragma once
#include <iostream>

class behavior;

class tenant
{
private:
	unsigned int age;
	behavior* myBehavior;
public:
	tenant();
	~tenant();
	virtual void act() {
		std::cout << "Virtual function 'act'" << std::endl;
		
		return;};
	virtual char draw(){
		return '!';
	}
	virtual void setBehavior(behavior* newBehavior){
		return;
	}
};

