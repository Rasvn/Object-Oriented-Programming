#pragma once
#include <vector>

#include "Medicine.h"

using namespace std;

class MedicineListRepository {
private:
	vector<Medicine> list;
public:
	MedicineListRepository() = default;
	MedicineListRepository(vector<Medicine>& list) {
		this->list = list;
	}

	/// Returns the size of the repository
	unsigned getLength() const noexcept;
	/// Returns the medicine to a given position
	const Medicine& getMedicineAt(unsigned i) const;
	/// Returns the list of medicines
	const vector<Medicine>& getMedicineList() const noexcept;

	/// Adds a new medicine to the repository
	void addMedicine(const Medicine& medicine);
	/// Removes a medicine from a given position
	void deleteMedicine(unsigned i);
	/// Modifies a medicine from a given position
	void updateMedicine(const Medicine& medicine, unsigned i);
	/// Returns the position of the medicine or the length if it doesn't exists in the repository
	unsigned findMedicine(const Medicine& medicine);
};
