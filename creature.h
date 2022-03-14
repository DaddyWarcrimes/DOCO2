#pragma once

class creature
{
private:
	unsigned int age;
public:
	creature();
	~creature();
	virtual void act();
};

