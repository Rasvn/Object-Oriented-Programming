#pragma once
#include <string>
#include "repository.h"
#include "medicine.h"

class Service {
private:
	Pharmacy* repo;
public:
	Service(Pharmacy*);
	void addMedicine(string, double, string, string);
	Medicine removeMedicine(string, string);
	Medicine updateMedicine(unsigned, string, double, string, string);
	~Service();
};