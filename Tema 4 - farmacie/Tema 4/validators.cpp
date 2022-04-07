#include <string>
#include <exception>
#include "validators.h"

using namespace std;

void Validators::validateMedicineName(string name) {
	if (name.length() < 4) {
		throw exception("Length of the medicine's name is invalid!");
	}
}
void Validators::validateMedicinePrice(double price) {
	if (price <= 0) {
		throw exception("Price of the medicine can't be less or equal than 0!");
	}
}
void Validators::validateMedicineProducer(string producer) {
	if (producer.length() < 5) {
		throw exception("Length of the medicine's producer is invalid!");
	}
}
void Validators::validateMedicineSubstance(string substance) {
	if (substance.length() < 6) {
		throw exception("Length of the medicine's substance is invalid!");
	}
}

void Validators::validateInteger(string buffer) {
	unsigned start = 0;
	if (buffer.at(start) == '-') {
		start++;
		if (buffer.size() == 1) {
			throw exception("The input should be an integer!");
		}
	}
	for (unsigned i = start; i < buffer.size(); ++i) {
		if (buffer.at(i) < '0' || buffer.at(i) > '9') {
			throw exception("The input should be an integer!");
		}
	}
}

void Validators::validateRealNumber(string buffer) {
	unsigned start = 0;
	bool onepoint = false;
	if (buffer.at(start) == '-') {
		start++;
		if (buffer.size() == 1) {
			throw exception("The input should be a real number!");
		}
	}
	for (unsigned i = start; i < buffer.size(); ++i) {
		if (buffer.at(i) < '0' || buffer.at(i) > '9') {
			if (buffer.at(i) == '.' && onepoint == false) {
				onepoint = true;
			}
			else {
				throw exception("The input should be a real number!");
			}
		}
	}
}