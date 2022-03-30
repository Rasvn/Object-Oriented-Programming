#pragma once
#include <vector>
#include "medicine.h"

class Pharmacy {
private:
	vector<Medicine> list;
	unsigned length;
public:
	Pharmacy();
	Medicine getMedicineAt(unsigned);
	unsigned getLength();
	void addMedicine(Medicine);
	Medicine removeMedicine(unsigned);
	Medicine updateMedicine(unsigned, Medicine);
	int findMedicine(Medicine);
	~Pharmacy();
};