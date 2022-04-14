#include <vector>
#include <random>

#include "MedicineRecipeRepository.h"
#include "Medicine.h"

using namespace std;

unsigned MedicineRecipeRepository::getLength() const noexcept {
	return recipe.size();
}

double MedicineRecipeRepository::getSum() const noexcept {
	return totalSum;
}

const vector<Medicine>& MedicineRecipeRepository::getMedicineRecipe() const noexcept {
	return recipe;
}

void MedicineRecipeRepository::addMedicine(const Medicine& medicine) {
	recipe.push_back(medicine);
	totalSum += medicine.getPrice();
}

void MedicineRecipeRepository::resetRecipe() noexcept {
	totalSum = 0;
	recipe.clear();
}

void MedicineRecipeRepository::generateMedicines(const vector<Medicine>& medicineList, unsigned numberOfMedicines) {
	random_device device;
	mt19937 generator(device());
	const uniform_int_distribution<int> distribution(0, medicineList.size() - 1);

	while (numberOfMedicines) {
		const int random = distribution(generator);
		addMedicine(medicineList.at(random));
		--numberOfMedicines;
	}
}
