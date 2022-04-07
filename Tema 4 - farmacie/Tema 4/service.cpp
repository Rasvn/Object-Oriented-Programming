#include <exception>
#include "service.h"
#include "repository.h"
#include "medicine.h"

void Service::addMedicine(string name, double price, string producer, string substance) {
	Medicine newMed(name, price, producer, substance);
	if (repo.findMedicine(newMed) != repo.getLength()) {
		throw exception("There is already a medicine with the same name and the same producer!");
	}
	repo.addMedicine(newMed);
}
void Service::deleteMedicine(unsigned position) {
	repo.deleteMedicine(position);
}
void Service::updateMedicine(unsigned position, string newName, double newPrice, string newProducer, string newSubstance) {
	Medicine updatedMed(newName, newPrice, newProducer, newSubstance);
	const int findMed = repo.findMedicine(updatedMed);
	if (findMed != repo.getLength() && findMed != position) {
		throw exception("There is already a medicine with the same name and the same producer!");
	}
	repo.updateMedicine(updatedMed, position);
}
Repository Service::findMedicineList(string namePattern) {
	Repository searchedItems;
	for (unsigned i = 0; i < repo.getLength(); ++i) {
		if (repo.getMedicineAt(i).getName().find(namePattern) != -1) {
			searchedItems.addMedicine(repo.getMedicineAt(i));
		}
	}
	return searchedItems;
}
Repository Service::filterMedicinePriceRange(double minPrice, double maxPrice) {
	Repository filteredItems;
	for (unsigned i = 0; i < repo.getLength(); ++i) {
		if (repo.getMedicineAt(i).getPrice() >= minPrice && repo.getMedicineAt(i).getPrice() <= maxPrice) {
			filteredItems.addMedicine(repo.getMedicineAt(i));
		}
	}
	return filteredItems;
}
Repository Service::sortMedicineList(bool (*cmp)(const Medicine&, const Medicine&)) {
	if (!cmp) {
		throw exception("Comparing function is invalid!");
	}
	Repository sortedMedicineList = repo;
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (unsigned i = 0; i < sortedMedicineList.getLength() - 1; ++i) {
			if (!cmp(sortedMedicineList.getMedicineAt(i), sortedMedicineList.getMedicineAt(i + 1))) {
				sortedMedicineList.swapMedicines(i, i + 1);
				sorted = false;
			}
		}
	}
	return sortedMedicineList;
}