#pragma warning (disable: 26823) // Dereferencing a possibly null pointer 'i'. It can't be a null pointer because is from the C++11 range loop

#include <algorithm>
#include <map>

#include "MedicineListRepository.h"
#include "Exceptions.h"
#include "Medicine.h"
#include "Service.h"

using namespace std;

void Service::addMedicine(string name, double price, string producer, string substance) {
	Medicine newMed(name, price, producer, substance);
	if (medicineListRepository.findMedicine(newMed) != medicineListRepository.getLength()) {
		throw ExistentMedicineException();
	}
	medicineListRepository.addMedicine(newMed);
}

void Service::deleteMedicine(unsigned position) {
	medicineListRepository.deleteMedicine(position);
}

void Service::updateMedicine(unsigned position, string newName, double newPrice, string newProducer, string newSubstance) {
	Medicine updatedMed(newName, newPrice, newProducer, newSubstance);
	const int findMed = medicineListRepository.findMedicine(updatedMed);
	if (findMed != medicineListRepository.getLength() && findMed != position) {
		throw ExistentMedicineException();
	}
	medicineListRepository.updateMedicine(updatedMed, position);
}

vector<Medicine> Service::findMedicineList(string namePattern) {
	vector<Medicine> searchedItems(medicineListRepository.getLength());
	const auto& iterator = copy_if(medicineListRepository.getMedicineList().begin(),
		medicineListRepository.getMedicineList().end(), searchedItems.begin(), [&](const Medicine& other) {
			return other.getName().find(namePattern) != -1; });
	searchedItems.resize(distance(searchedItems.begin(), iterator));
	return searchedItems;
}

vector<Medicine> Service::filterMedicinePriceRange(double minPrice, double maxPrice) {
	vector<Medicine> filteredItems(medicineListRepository.getLength());
	const auto& iterator = copy_if(medicineListRepository.getMedicineList().begin(),
		medicineListRepository.getMedicineList().end(), filteredItems.begin(), [&](const Medicine& other) noexcept {
			return other.getPrice() >= minPrice && other.getPrice() <= maxPrice; });
	filteredItems.resize(distance(filteredItems.begin(), iterator));
	return filteredItems;
}

vector<Medicine> Service::sortMedicineList(bool (*cmp)(const Medicine&, const Medicine&), bool reversed) {
	if (!cmp) {
		throw OtherException("Comparing function is invalid!");
	}
	vector<Medicine> sortedMedicineList = medicineListRepository.getMedicineList();
	reversed ? sort(sortedMedicineList.begin(), sortedMedicineList.end(), [&](const Medicine& medicine, const Medicine& other) noexcept {
		return !cmp(medicine, other) && cmp(other, medicine); }) : sort(sortedMedicineList.begin(), sortedMedicineList.end(), cmp);
	return sortedMedicineList;
}

map<string, unsigned> Service::producerReportMap() {
	map<string, unsigned> report;
	for (const auto& i : medicineListRepository.getMedicineList()) {
		report[i.getProducer()]++;
	}
	return report;
}



void Service::addMedicineToRecipe(unsigned position) {
	const auto& medicine = medicineListRepository.getMedicineAt(position);
	medicineRecipeRepository.addMedicine(medicine);
}

void Service::resetRecipe() noexcept {
	medicineRecipeRepository.resetRecipe();
}

void Service::generateMedicinesToTheRecipe(unsigned numberOfMedicines) {
	medicineRecipeRepository.generateMedicines(medicineListRepository.getMedicineList(), numberOfMedicines);
}
