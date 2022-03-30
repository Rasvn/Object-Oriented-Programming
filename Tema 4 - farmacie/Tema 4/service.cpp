#include <exception>
#include "service.h"

Service::Service(Pharmacy* pharmacy) {
	repo = pharmacy;
};

void Service::addMedicine(string name, double price, string producer, string substance) {
	Medicine newMed(name, price, producer, substance);
	if (repo->findMedicine(newMed) != -1) {
		throw exception("There is already a medicine with the same name and the same producer!");
	}
	repo->addMedicine(newMed);
}

Medicine Service::removeMedicine(string name, string producer) {
	Medicine toRemoveMed(name, 0, producer, "");
	int position = repo->findMedicine(toRemoveMed);
	if (position == -1) {
		throw exception("The name or the producer of the medicine is entered incorrectly!");
	}
	Medicine oldMed = repo->removeMedicine(position);
	return oldMed;
}

Medicine Service::updateMedicine(unsigned position, string newName, double newPrice, string newProducer, string newSubstance) {
	Medicine updatedMed(newName, newPrice, newProducer, newSubstance);
	int findMed = repo->findMedicine(updatedMed);
	if (findMed != -1 && findMed != position) {
		throw exception("There is already a medicine with the same name and the same producer!");
	}
	return repo->updateMedicine(position, updatedMed);
}

Service::~Service() {
	repo->~Pharmacy();
}