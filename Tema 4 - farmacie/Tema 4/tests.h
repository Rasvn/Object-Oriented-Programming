#pragma once

class Tests {
public:
	void runAllTests();
private:
	void runMedicineTests();
	void runDynamicVectorTests();
	void runRepositoryTests();
	void runValidatorsTests();
	void runServiceTests();
};
