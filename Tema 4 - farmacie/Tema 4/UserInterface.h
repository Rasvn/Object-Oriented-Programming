#pragma once
#include <string>
#include "service.h"
#include "MedicineListRepository.h"
#include "MedicineRecipeRepository.h"
#include "Validator.h"

using namespace std;

class UserInterface {
private:
	Validator validator;
	MedicineListRepository& medicineListRepository;
	MedicineRecipeRepository medicineRecipeRepository;
	Service service;

	Medicine readMedicine(string COLOR);
	void writeMedicine(const Medicine& medicine, string COLOR);
	void writeMedicine(string name, double price, string producer, string substance, string COLOR);
	void writeMedicine(const Medicine& medicine, string name, double price, string producer, string substance, string COLOR);

	int globalMenu();

	void medicineList();
	int medicineListMenu();
	void populateMedicineList();
	void displayMedicineList(const vector<Medicine>& medicineList);
	void addMedicine();
	void removeMedicine();
	void updateMedicine();
	void findMedicineList();
	void filterMedicineList();
	void sortMedicineList();
	void producerReportMap();

	void medicineRecipe();
	int medicineRecipeMenu();
	void displayMedicineRecipe();
	void addMedicineToRecipe();
	void resetRecipe();
	void generateMedicinesToTheRecipe();
	void exportRecipe();

public:
	UserInterface(MedicineListRepository& input) noexcept :
		service(input, medicineRecipeRepository),
		medicineListRepository(input) {};
	void begin();
};