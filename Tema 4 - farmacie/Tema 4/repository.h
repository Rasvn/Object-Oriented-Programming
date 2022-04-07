#pragma once
#include "medicine.h"
#include "dynamic_vector.h"

using namespace std;

class Repository {
private:
	DynamicVector<Medicine> list;
public:
	/// Returns the size of the repository
	unsigned getLength() noexcept;
	/// Returns the medicine to a given position
	const Medicine& getMedicineAt(unsigned i);

	/// Adds a new medicine to the repository
	void addMedicine(const Medicine& med);
	/// Removes a medicine from a given position
	void deleteMedicine(unsigned i);
	/// Modifies a medicine from a given position
	void updateMedicine(const Medicine& med, unsigned i);
	/// Returns the position of the medicine or the length if it doesn't exists in the repository
	unsigned findMedicine(const Medicine& med) noexcept;
	/// Swaps the medicines at the given positions
	void swapMedicines(unsigned i, unsigned j);
};
