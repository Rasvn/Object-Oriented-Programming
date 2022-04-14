#pragma once
#include <vector>
#include "Medicine.h"

using namespace std;

class MedicineRecipeRepository {
private:
	vector<Medicine> recipe;
	double totalSum = 0;
public:
	MedicineRecipeRepository() = default;
	MedicineRecipeRepository(vector<Medicine>& recipe) {
		this->recipe = recipe;
	}
	/// Returns the size of the recipe
	unsigned getLength() const noexcept;
	/// Returns the total sum of the medicines
	double getSum() const noexcept;
	/// Returns the recipe of medicines
	const vector<Medicine>& getMedicineRecipe() const noexcept;

	/// Adds a new medicine to the recipe
	void addMedicine(const Medicine& medicine);
	/// Removes all the medicines from the recipe
	void resetRecipe() noexcept;
	/// Generates random medicines from a list of medicines
	void generateMedicines(const vector<Medicine>& medicineList, unsigned numberOfMedicines);
};
