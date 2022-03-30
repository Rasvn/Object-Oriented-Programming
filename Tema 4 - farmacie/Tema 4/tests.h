#pragma once
#include "medicine.h"
#include "validator.h"
#include "repository.h"
#include "service.h"

class Tests {
private:
	void testMedicine();
	void testValidator();
	void testRepository();
public:
	void testAll();
};