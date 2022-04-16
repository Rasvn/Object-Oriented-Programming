#pragma once
#pragma warning (disable: 26432) //	If you define or delete any default operation in the type 'class UndoAction', define or delete them all.
#pragma warning (disable: 26440) // Function 'UndoAction::doUndo' can be declared 'noexcept' (f.6), it's overrideable, it can throw exceptions.

#include "PharmacyService.h"

class UndoAction {
public:
	virtual void doUndo () {};
	virtual ~UndoAction() {};
};

class UndoAdd : public UndoAction {
private:
	unsigned position;
	MedicineListRepository& medicineListRepository;
public:
	UndoAdd(MedicineListRepository& repository, unsigned position) : medicineListRepository{ repository }, position{ position } {}

	void doUndo() override {
		medicineListRepository.deleteMedicine(position);
	}
};

class UndoRemove : public UndoAction {
private:
	unsigned position;
	Medicine removedMedicine;
	MedicineListRepository& medicineListRepository;
public:
	UndoRemove(MedicineListRepository& repository, Medicine& medicine, unsigned position) 
		: medicineListRepository{ repository }, removedMedicine{ medicine }, position{ position } {}

	void doUndo() override {
		medicineListRepository.addMedicine(removedMedicine, position);
	}
};

class UndoUpdate : public UndoAction {
private:
	unsigned position;
	Medicine oldMedicine;
	MedicineListRepository& medicineListRepository;
public:
	UndoUpdate(MedicineListRepository& repository, Medicine& medicine, unsigned position)
		: medicineListRepository{ repository }, oldMedicine{ medicine }, position{ position } {}

	void doUndo() override {
		medicineListRepository.updateMedicine(oldMedicine, position);
	}
};
