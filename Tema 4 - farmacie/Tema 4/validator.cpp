#include <string>
#include <exception>
#include "validator.h"

using namespace std;

void Validator::validateMedicineName(string name) {
	if (name.length() < 4) {
		throw exception("Length of the medicine's name is invalid!\n");
	}
}
void Validator::validateMedicinePrice(double price) {
	if (price <= 0) {
		throw exception("Price of the medicine can't be less or equal than 0!\n");
	}
}
void Validator::validateMedicineProducer(string producer) {
	if (producer.length() < 5) {
		throw exception("Length of the medicine's producer is invalid!\n");
	}
}
void Validator::validateMedicineSubstance(string substance) {
	if (substance.length() < 6) {
		throw exception("Length of the medicine's substance is invalid!\n");
	}
}

void Validator::validateInteger(string buffer) {
	unsigned start = 0;
	if (buffer[start] == '-') {
		start++;
		if (buffer.size() == 1) {
			throw exception("The input should be an integer!");
		}
	}
	for (unsigned i = start; i < buffer.size(); ++i) {
		if (buffer[i] < '0' || buffer[i] > '9') {
			throw exception("The input should be an integer!");
		}
	}
}

void Validator::validateRealNumber(string buffer) {
	unsigned start = 0;
	bool onepoint = false;
	if (buffer[start] == '-') {
		start++;
		if (buffer.size() == 1) {
			throw exception("The input should be a real number!");
		}
	}
	for (unsigned i = start; i < buffer.size(); ++i) {
		if (buffer[i] < '0' || buffer[i] > '9') {
			if (buffer[i] == '.' && onepoint == false) {
				onepoint = true;
			}
			else {
				throw exception("The input should be a real number!\n");
			}
		}
	}
}