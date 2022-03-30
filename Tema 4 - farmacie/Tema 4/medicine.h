#pragma once
#include <string>

using namespace std;

class Medicine {
private:
	string name;
	double price;
	string producer;
	string substance;
public:
	///	Medicine Class Constructor.
	Medicine(string, double, string, string);
	/// Returns the name of the medicine
	string getName() const;
	/// Returns the price of the medicine
	double getPrice() const;
	/// Returns the producer of the medicine
	string getProducer() const;
	/// Returns the active substance used in the medicine
	string getSubstance() const;
	bool equal(Medicine);
	/// Medicine Class Destructor
	~Medicine();
};