#include <exception>
#include <assert.h>
#include <iostream>
#include "tests.h"

using namespace std;

void Tests::testMedicine() {
	Medicine med("Atorvastatin", 19.99, "Lipitor", "atorvastatin calcium trihydrate");
	assert(med.getName().compare("Atorvastatin") == 0);
	assert(med.getPrice() == 19.99);
	assert(med.getProducer().compare("Lipitor") == 0);
	assert(med.getSubstance().compare("atorvastatin calcium trihydrate") == 0);
	Medicine eq("Atorvastatin", 17.99, "Lipitor", "calcium trihydrate");
	assert(med.equal(eq));
}

void Tests::testValidator() {
	Validator valid;
	valid.validateMedicineName("Atorvastatin");
	try {
		valid.validateMedicineName("Art");
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	valid.validateMedicinePrice(29.99);
	try {
		valid.validateMedicinePrice(0);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	valid.validateMedicineProducer("Lipitor");
	try {
		valid.validateMedicineProducer("John");
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	valid.validateMedicineSubstance("atorvastatin calcium trihydrate");
	try {
		valid.validateMedicineSubstance("sugar");
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
}

void Tests::testRepository() {
	Pharmacy pharmacy;
	Medicine med1("Atorvastatin", 19.99, "Lipitor", "atorvastatin calcium trihydrate");
	Medicine med2("Augmentin", 24.99, "Trimox", "amoxicillin");
	Medicine med3("Lisinopril", 17.99, "Zestril", "torasemide");
	Medicine med4("Levothyroxine", 14.99, "Synthroid", "levothyroxine sodium");
	pharmacy.addMedicine(med1);
	pharmacy.addMedicine(med2);
	pharmacy.addMedicine(med3);

	assert(pharmacy.getLength() == 3);
	assert(pharmacy.getMedicineAt(0).equal(med1));
	assert(pharmacy.getMedicineAt(1).equal(med2));
	assert(pharmacy.getMedicineAt(2).equal(med3));
	try {
		pharmacy.getMedicineAt(3);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	assert(pharmacy.findMedicine(med1) == 0);
	assert(pharmacy.findMedicine(med2) == 1);
	assert(pharmacy.findMedicine(med3) == 2);
	assert(pharmacy.findMedicine(med4) == -1);
	
	pharmacy.updateMedicine(1, med4);
	assert(pharmacy.getMedicineAt(0).equal(med1));
	assert(pharmacy.getMedicineAt(1).equal(med4));
	assert(pharmacy.getMedicineAt(2).equal(med3));
	assert(pharmacy.findMedicine(med2) == -1);

	assert(pharmacy.removeMedicine(0).equal(med1));
	assert(pharmacy.getMedicineAt(0).equal(med4));
	assert(pharmacy.getMedicineAt(1).equal(med3));
	try {
		pharmacy.removeMedicine(2);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	assert(pharmacy.removeMedicine(1).equal(med3));
	assert(pharmacy.removeMedicine(0).equal(med4));
	assert(pharmacy.getLength() == 0);
}

void Tests::testAll() {
	testMedicine();
	testValidator();
	testRepository();
	cout << "Tests passed successfully!\n\n";
}