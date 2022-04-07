#pragma once
#include <string>
#include "service.h"
#include "repository.h"
#include "validators.h"

using namespace std;

class UserInterface {
private:
	Validators validator;
	Repository repo;
	Service serv;

	int readInteger();
	double readDouble();
	string readString();

	void populateMedicineList();
	int globalMenu();
	void displayMedicineList(Repository repo);
	void addMedicine();
	void removeMedicine();
	void updateMedicine();
	void findMedicineList();
	void filterMedicineList();
	void sortMedicineList();

public:
	UserInterface(Repository input) noexcept :
		serv(&repo),
		repo(input) {};
	void begin();
};