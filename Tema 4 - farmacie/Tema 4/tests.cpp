#include <assert.h>
#include "medicine.h"
#include "tests.h"
#include "dynamic_vector.h"
#include "repository.h"
#include "validators.h"
#include "service.h"

using namespace std;

void Tests::runAllTests() {
	runMedicineTests();
	runDynamicVectorTests();
	runValidatorsTests();
	runRepositoryTests();
	runServiceTests();
}

void Tests::runMedicineTests() {
	Medicine medicine("Atorvastatin", 19.99, "Lipitor", "atorvastatin calcium trihydrate");
	assert(medicine.getName() == "Atorvastatin");
	assert(medicine.getPrice() == 19.99);
	assert(medicine.getProducer() == "Lipitor");
	assert(medicine.getSubstance() == "atorvastatin calcium trihydrate");
	Medicine eq("Atorvastatin", 17.99, "Lipitor", "calcium trihydrate");
	assert(medicine == eq);
	swap(medicine, eq);
	assert(medicine.getPrice() == 17.99);
	Medicine copy = medicine;
	assert(copy.getName() == "Atorvastatin");
	assert(copy.getPrice() == 17.99);
}

void Tests::runDynamicVectorTests() {
	DynamicVector<Medicine> v(1);
	assert(v.size() == 0);
	v.push_back(Medicine("Atorvastatin", 18.43, "Viatris", "atorvastatin calcium trihydrate"));
	v.push_back(Medicine("Augmentin", 12.44, "GSK", "amoxicillin"));
	v.push_back(Medicine("Lisinopril", 34.74, "Almus", "torasemide"));
	v.push_back(Medicine("Levothyroxine", 14.99, "Wockhardt", "levothyroxine sodium"));
	v.push_back(Medicine("Albuterol", 19.05, "Prahem", "albuterol sulfate"));
	v.push_back(Medicine("Metformin", 89.99, "Bristol-Myers Squibb", "metformin hydrochloride"));
	v.push_back(Medicine("Amlodipine", 17.86, "Synthon Pharmaceuticals", "amlodipine maleate"));
	v.push_back(Medicine("Metoprolol", 13.59, "Taj Pharma", "metoprolol tartrate"));
	v.insert(Medicine("Paracetamol", 0.63, "Zentiva", "paracetamol"), 7);
	v.insert(Medicine("Omeprazole", 69.96, "Astra Zeneca", "disodium hydrogen phosphate"), 9);
	try {
		v.insert(Medicine("Omeprazole", 69.96, "Astra Zeneca", "disodium hydrogen phosphate"), 11);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	assert(v.size() == 10);
	assert(v.at(3).getName() == "Levothyroxine");
	assert(v.at(4).getPrice() == 19.05);
	assert(v.at(5).getProducer() == "Bristol-Myers Squibb");
	assert(v.at(6).getSubstance() == "amlodipine maleate");
	try {
		v.at(10);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	v.assign(Medicine("Amlodipine", 17.86, "Synthon Pharmaceuticals", "maleate"), 6);
	assert(v.at(6).getSubstance() == "maleate");
	try {
		v.assign(Medicine("Amlodipine", 17.86, "Synthon Pharmaceuticals", "maleate"), 10);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	assert(v.search(Medicine("Omeprazole", 69.96, "Astra Zeneca", "disodium hydrogen phosphate")) == 9);
	v.remove(9);
	assert(v.size() == 9);
	assert(v.search(Medicine("Omeprazole", 69.96, "Astra Zeneca", "disodium hydrogen phosphate")) == 9);
	try {
		v.remove(9);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	v.swap(1, 2);
	assert(v.at(1).getName() == "Lisinopril");
	assert(v.at(2).getName() == "Augmentin");
	try {
		v.swap(1, 9);
		assert(false);
	}
	catch (exception&) {
		assert(v.at(1).getName() == "Lisinopril");
	}
}

void Tests::runValidatorsTests() {
	Validators valid;
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
	valid.validateInteger("-1512");
	try {
		valid.validateInteger("15.12");
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	try {
		valid.validateInteger("-");
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}

	valid.validateRealNumber("-15.12");
	try {
		valid.validateRealNumber("15.1.2");
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		valid.validateRealNumber("-");
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
}

void Tests::runRepositoryTests() {
	Repository repo;
	repo.addMedicine(Medicine("Atorvastatin", 18.43, "Viatris", "atorvastatin calcium trihydrate"));
	repo.addMedicine(Medicine("Augmentin", 12.44, "GSK", "amoxicillin"));
	repo.addMedicine(Medicine("Lisinopril", 34.74, "Almus", "torasemide"));
	repo.addMedicine(Medicine("Levothyroxine", 14.99, "Wockhardt", "levothyroxine sodium"));
	repo.addMedicine(Medicine("Albuterol", 19.05, "Prahem", "albuterol sulfate"));
	repo.addMedicine(Medicine("Metformin", 89.99, "Bristol-Myers Squibb", "metformin hydrochloride"));
	repo.addMedicine(Medicine("Amlodipine", 17.86, "Synthon Pharmaceuticals", "amlodipine maleate"));
	repo.addMedicine(Medicine("Metoprolol", 13.59, "Taj Pharma", "metoprolol tartrate"));
	assert(repo.getLength() == 8);
	assert(repo.getMedicineAt(2).getName() == "Lisinopril");
	assert(repo.getMedicineAt(3).getPrice() == 14.99);
	assert(repo.getMedicineAt(4).getProducer() == "Prahem");
	assert(repo.getMedicineAt(5).getSubstance() == "metformin hydrochloride");
	repo.updateMedicine(Medicine("Amlodipine", 17.86, "Synthon Pharmaceuticals", "maleate"), 6);
	assert(repo.getMedicineAt(6).getSubstance() == "maleate");
	try {
		repo.updateMedicine(Medicine("Amlodipine", 17.86, "Synthon Pharmaceuticals", "maleate"), 10);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	repo.deleteMedicine(7);
	assert(repo.getLength() == 7);
	try {
		repo.deleteMedicine(7);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
}

void Tests::runServiceTests() {
	Repository repo;
	Service serv(&repo);
	serv.addMedicine("Atorvastatin", 18.43, "Viatris", "atorvastatin calcium trihydrate");
	serv.addMedicine("Augmentin", 12.44, "GSK", "amoxicillin");
	serv.addMedicine("Lisinopril", 34.74, "Almus", "torasemide");
	serv.addMedicine("Levothyroxine", 14.99, "Wockhardt", "levothyroxine sodium");
	serv.addMedicine("Albuterol", 19.05, "Prahem", "albuterol sulfate");
	serv.addMedicine("Metformin", 89.99, "Bristol-Myers Squibb", "metformin hydrochloride");
	serv.addMedicine("Amlodipine", 17.86, "Synthon Pharmaceuticals", "amlodipine maleate");
	serv.addMedicine("Metoprolol", 13.59, "Taj Pharma", "metoprolol tartrate");
	serv.addMedicine("Paracetamol", 0.63, "Zentiva", "paracetamol");
	assert(repo.getLength() == 9);
	assert(repo.getMedicineAt(1).getName() == "Augmentin");
	assert(repo.getMedicineAt(2).getPrice() == 34.74);
	assert(repo.getMedicineAt(3).getProducer() == "Wockhardt");
	assert(repo.getMedicineAt(4).getSubstance() == "albuterol sulfate");
	try {
		serv.addMedicine("Amlodipine", 14.54, "Synthon Pharmaceuticals", "maleate");
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	serv.deleteMedicine(3);
	assert(repo.getLength() == 8);
	assert(repo.getMedicineAt(3).getProducer() == "Prahem");
	try {
		repo.deleteMedicine(8);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	serv.updateMedicine(2, "Levothyroxine", 14.99, "Wockhardt", "levothyroxine sodium");
	assert(repo.getMedicineAt(2).getProducer() == "Wockhardt");
	try {
		serv.updateMedicine(8, "Levothyxine", 14.99, "Wockhardt", "levothyroxine sodium");
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		serv.updateMedicine(5, "Levothyroxine", 13.29, "Wockhardt", "sodium");
		assert(false);
	}
	catch (exception&) {
		assert(repo.getMedicineAt(5).getName() == "Amlodipine");
	}

	Repository patternList = serv.findMedicineList("ol");
	assert(patternList.getLength() == 3);
	assert(patternList.getMedicineAt(0).getName() == "Albuterol");
	assert(patternList.getMedicineAt(1).getName() == "Metoprolol");
	assert(patternList.getMedicineAt(2).getName() == "Paracetamol");

	Repository priceRange = serv.filterMedicinePriceRange(12, 18);
	assert(priceRange.getLength() == 4);
	assert(priceRange.getMedicineAt(0).getPrice() == 12.44);
	assert(priceRange.getMedicineAt(1).getPrice() == 14.99);
	assert(priceRange.getMedicineAt(2).getPrice() == 17.86);
	assert(priceRange.getMedicineAt(3).getPrice() == 13.59);

	Repository sortedMedicineList = serv.sortMedicineList([](const Medicine& m1, const Medicine& m2) noexcept { return m1.getPrice() > m2.getPrice(); });
	assert(sortedMedicineList.getLength() == 8);
	assert(sortedMedicineList.getMedicineAt(0).getPrice() == 89.99);
	assert(sortedMedicineList.getMedicineAt(1).getPrice() == 19.05);
	assert(sortedMedicineList.getMedicineAt(2).getPrice() == 18.43);

	try {
		Repository sortedMedicineList = serv.sortMedicineList(nullptr);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
}
