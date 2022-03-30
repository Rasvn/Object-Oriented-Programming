#include <exception>
#include "repository.h"

Pharmacy::Pharmacy() {
	length = 0;
}

Medicine Pharmacy::getMedicineAt(unsigned position) {
	if (position >= length) {
		throw exception("Invalid position!");
	}
	return list[position];
}

unsigned Pharmacy::getLength() {
	return length;
}

void Pharmacy::addMedicine(Medicine med) {
	list.push_back(med);
	length++;
}

Medicine Pharmacy::removeMedicine(unsigned position) {
	Medicine oldMed = getMedicineAt(position);
	list.erase(list.begin() + position);
	length--;
	return oldMed;
}

Medicine Pharmacy::updateMedicine(unsigned position, Medicine med) {
	Medicine oldMed = getMedicineAt(position);
	list[position] = med;
	return oldMed;
}

int Pharmacy::findMedicine(Medicine med) {
	for (unsigned i = 0; i < length; ++i) {
		if (list[i].equal(med)) {
			return i;
		}
	}
	return -1;
}

Pharmacy::~Pharmacy() {
	length = 0;
	list.clear();
	list.shrink_to_fit();
}