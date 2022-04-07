#include "repository.h"
#include "medicine.h"
#include "dynamic_vector.h"

unsigned Repository::getLength() noexcept {
	return list.size();
}
const Medicine& Repository::getMedicineAt(unsigned i) {
	return list.at(i);
}
void Repository::addMedicine(const Medicine& med) {
	list.push_back(med);
}

void Repository::deleteMedicine(unsigned i) {
	list.remove(i);
}

void Repository::updateMedicine(const Medicine& med, unsigned i) {
	list.assign(med, i);
}

unsigned Repository::findMedicine(const Medicine& med) noexcept {
	return list.search(med);
}

void Repository::swapMedicines(unsigned i, unsigned j) {
	list.swap(i, j);
}
