#pragma once
#include <string>
#include "service.h"
#include "repository.h"
#include "medicine.h"

using namespace std;

class Service {
private:
	Repository& repo;
public:
	/// Service Class Constructor
	Service(Repository* repo) noexcept :
		repo(*repo) {}
	/// Service Class Destructor
	~Service() = default;

	/// Adds a medicine to the repository
	void addMedicine(string name, double price, string producer, string substance);
	/// Removes a medicine from the repository
	void deleteMedicine(unsigned position);
	/// Updates a medicine from the list
	void updateMedicine(unsigned position, string newName, double newPrice, string newProducer, string newSubstance);
	/// Returns a repository with the medicines containing a substring
	Repository findMedicineList(string namePattern);
	/// Returns a repository with the medicines with the price in the specified range
	Repository filterMedicinePriceRange(double minPrice, double maxPrice);
	/// Returns a repository sorted by the function given as a parameter
	Repository sortMedicineList(bool (*cmp)(const Medicine&, const Medicine&));
};