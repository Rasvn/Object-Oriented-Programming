#include "medicine.h"

Medicine::Medicine(string name, double price, string producer, string substance) {
	this->name = name;
	this->price = price;
	this->producer = producer;
	this->substance = substance;
}
string Medicine::getName() const {
	return this->name;
}
double Medicine::getPrice() const {
	return this->price;
}
string Medicine::getProducer() const {
	return this->producer;
}
string Medicine::getSubstance() const {
	return this->substance;
}

bool Medicine::equal(Medicine med) {
	return this->name.compare(med.name) == 0 && this->producer.compare(med.producer) == 0;
}

Medicine::~Medicine() {
	name.erase();
	price = NULL;
	producer.erase();
	substance.erase();
}