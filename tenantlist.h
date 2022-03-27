#pragma once
class DOCO;

class tenantlist
{
private:
	DOCO* list;
	int iterator;

public:
	tenantlist();
	tenantlist(int size);
	~tenantlist();
	void init(int size);
	void addDOCO(DOCO newDOCO);
	void act();
	bool extinct();
	void report();
};

