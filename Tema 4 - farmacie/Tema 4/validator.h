#pragma once
#include <string>

using namespace std;

class Validator {
public:
	// Throws exception if the length of the string is less than 4
	void validateMedicineName(string);
	// Throws exception if the value of the number is less or equal than 0
	void validateMedicinePrice(double);
	// Throws exception if the length of the string is less than 5
	void validateMedicineProducer(string);
	// Throws exception if the length of the string is less than 6
	void validateMedicineSubstance(string);

	void validateInteger(string);

	void validateRealNumber(string);
};