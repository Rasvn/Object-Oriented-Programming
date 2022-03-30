#pragma once
#include "medicine.h"
#include "repository.h"
#include "service.h"
#include "validator.h"

class UserInterface {
private:
	Pharmacy repo;
	Service srv;
	int globalMenu();
	void populateMedicineList();
	void displayMedicineList();
	void addMedicine();
	void removeMedicine();
	void updateMedicine();
public:
	UserInterface(Pharmacy);
	void begin();
	~UserInterface();

};