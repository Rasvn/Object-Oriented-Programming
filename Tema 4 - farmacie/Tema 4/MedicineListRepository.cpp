#include <vector>
#include "Exceptions.h"
#include "MedicineListRepository.h"
#include "Medicine.h"

unsigned MedicineListRepository::getLength() const noexcept {
	return list.size();
}
const Medicine& MedicineListRepository::getMedicineAt(unsigned i) const {
	if (i >= list.size()) {
		throw IndexException();
	}
	return list.at(i);
}
void MedicineListRepository::addMedicine(const Medicine& medicine) {
	list.emplace_back(Medicine());
	list.back() = medicine;
}

void MedicineListRepository::deleteMedicine(unsigned i) {
	if (i >= list.size()) {
		throw IndexException();
	}
	list.erase(list.begin() + i);
}

void MedicineListRepository::updateMedicine(const Medicine& medicine, unsigned i) {
	if (i >= list.size()) {
		throw IndexException();
	}
	list.at(i) = medicine;
}

unsigned MedicineListRepository::findMedicine(const Medicine& medicine) {
	const auto& iterator = find_if(list.begin(), list.end(), [&](const Medicine& other) noexcept { return medicine == other; });
	return distance(list.begin(), iterator);
}

const vector<Medicine>& MedicineListRepository::getMedicineList() const noexcept {
	return list;
}
