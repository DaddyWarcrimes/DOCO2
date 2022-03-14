#pragma once
class DOCO;

class creaturelist
{
private:
	DOCO* list;
	int iterator;

public:
	creaturelist();
	creaturelist(int size);
	~creaturelist();
	void init(int size);
	void addDOCO(DOCO newDOCO);
	void act();
	bool extinct();
	void report();
};

