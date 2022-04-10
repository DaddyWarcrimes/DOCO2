#pragma once
#include <vector>
class tenant;

class tenantlist
{
private:
	std::vector<tenant*> list;
	int iterator;
	std::vector<tenant*> myQueue;

public:
	tenantlist();
	tenantlist(int size);
	~tenantlist();
	void init(int size);
	void addTenant(tenant* newTenant);
	void addDynamic(tenant* newTenant);
	void act();
	bool extinct();
	void report();
};

