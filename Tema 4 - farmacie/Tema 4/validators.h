#pragma once
#include <string>

using namespace std;

class Validators {
public:
	// Throws an exception if the length of the string is less than 4
	void validateMedicineName(string);
	// Throws an exception if the value of the number is less or equal than 0
	void validateMedicinePrice(double);
	// Throws an exception if the length of the string is less than 5
	void validateMedicineProducer(string);
	// Throws an exception if the length of the string is less than 6
	void validateMedicineSubstance(string);
	// Throws an exception if the string can't be converted into an integer
	void validateInteger(string);
	// Throws an exception if the string can't be converted into a double
	void validateRealNumber(string);
};