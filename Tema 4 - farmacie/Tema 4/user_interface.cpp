#pragma warning (disable: 26823)
#include "user_interface.h"
#include "validators.h"
#include "repository.h"
#include "service.h"
#include "medicine.h"
#include <iostream>
#include <cstring>

const string twoLines = "=================================================================================================================\n";

using namespace std;

void UserInterface::begin() {
	populateMedicineList();
	while (true) {
		switch (globalMenu()) {
		case 0:
			cout << "\t\tArrivederci!!\n\n";
			return;

		case 1:
			displayMedicineList(repo);
			break;

		case 2:
			addMedicine();
			break;

		case 3:
			removeMedicine();
			break;

		case 4:
			updateMedicine();
			break;

		case 5:
			findMedicineList();
			break;

		case 6:
			filterMedicineList();
			break;

		case 7:
			sortMedicineList();
			break;

		default:
			cout << twoLines << "\n";
			cout << "\t\tInvalid option!\n\n";
		}
	}
}

int UserInterface::readInteger() {
	string buffer;
	rewind(stdin);
	getline(cin, buffer);
	validator.validateInteger(buffer);
	return stoi(buffer);
}
double UserInterface::readDouble() {
	string buffer;
	rewind(stdin);
	getline(cin, buffer);
	validator.validateRealNumber(buffer);
	return stod(buffer);
}
string UserInterface::readString() {
	string buffer;
	rewind(stdin);
	getline(cin, buffer);
	return buffer;
}

void UserInterface::populateMedicineList() {
	serv.addMedicine("Atorvastatin", 18.43, "Viatris", "atorvastatin calcium trihydrate");
	serv.addMedicine("Augmentin", 12.44, "GSK", "amoxicillin");
	serv.addMedicine("Lisinopril", 34.74, "Almus", "torasemide");
	serv.addMedicine("Levothyroxine", 14.99, "Wockhardt", "levothyroxine sodium");
	serv.addMedicine("Albuterol", 19.05, "Prahem", "albuterol sulfate");
	serv.addMedicine("Metformin", 89.99, "Bristol-Myers Squibb", "metformin hydrochloride");
	serv.addMedicine("Amlodipine", 17.86, "Synthon Pharmaceuticals", "amlodipine maleate");
	serv.addMedicine("Metoprolol", 13.59, "Taj Pharma", "metoprolol tartrate");
	serv.addMedicine("Paracetamol", 0.63, "Zentiva", "paracetamol");
	serv.addMedicine("Omeprazole", 69.96, "Astra Zeneca", "disodium hydrogen phosphate");
}

int UserInterface::globalMenu() {
	cout << twoLines;
	cout << "\n\tManagement of a list of medicine\n";
	cout << "\t\t1. Display the list of medicine\n";
	cout << "\t\t2. Add a medicine\n";
	cout << "\t\t3. Remove a medicine\n";
	cout << "\t\t4. Update a medicine\n";
	cout << "\t\t5. Find a medicine (substring in the name)\n";
	cout << "\t\t6. Filter the list of medicine (in a price range)\n";
	cout << "\t\t7. Sort the list of medicine\n";
	cout << "\t\t0. Leave the application\n";
	cout << "\tChoose an option: ";
	try {
		const int cmd = readInteger();
		system("cls");
		return cmd;
	}
	catch (exception&) {
		system("cls");
		return -1;
	}
}

void UserInterface::displayMedicineList(Repository repo) {
	if (repo.getLength() == 0) {
		cout << "\t\tThere are no medicines!\n\n";
		return;
	}
	cout << twoLines;
	for (unsigned i = 0; i < repo.getLength(); ++i) {
		cout << " " <<  i << ") Name: " << repo.getMedicineAt(i).getName() << " / Price: $";
		cout << repo.getMedicineAt(i).getPrice() << " / Producer: " << repo.getMedicineAt(i).getProducer();
		cout << " / Active substance: " << repo.getMedicineAt(i).getSubstance() << "\n";
	}
	cout << twoLines;
	cout << "\n";
}

void UserInterface::addMedicine() {
	try {
		cout << twoLines << "\n";
		cout << "\tThe name of the new medicine: ";
		string name = readString();
		validator.validateMedicineName(name);

		cout << "\tThe price of the new medicine: ";
		const double price = readDouble();
		validator.validateMedicinePrice(price);

		cout << "\tThe producer of the new medicine: ";
		string producer = readString();
		validator.validateMedicineProducer(producer);

		cout << "\tThe active substance of the new medicine: ";
		string substance = readString();
		validator.validateMedicineSubstance(substance);

		serv.addMedicine(name, price, producer, substance);
		Medicine newMedicine(name, price, producer, substance);

		cout << "\n" << twoLines;
		cout << "\n\tThe medicine was added successfully, the new medicine:\n";
		cout << "\t\tName: " << newMedicine.getName() << "\n\t\tPrice: " << newMedicine.getPrice();
		cout << "\n\t\tProducer: " << newMedicine.getProducer() << "\n\t\tActive substance: ";
		cout << newMedicine.getSubstance() << "\n\n";
	}
	catch (const exception& e) {
		cout << "\t\t" << e.what() << "\n\n";
	}
}

void UserInterface::removeMedicine() {
	try {
		displayMedicineList(repo);
		cout << "\tChoose the position of the medicine you want to delete from the list: ";
		const int position = readInteger();
		Medicine oldMedicine = repo.getMedicineAt(position);
		serv.deleteMedicine(position);
		cout << "\n" << twoLines;
		cout << "\n\tThe deletion was successful, the deleted medicine:\n";
		cout << "\t\tName: " << oldMedicine.getName() <<"\n\t\tPrice: " << oldMedicine.getPrice();
		cout << "\n\t\tProducer: " << oldMedicine.getProducer() << "\n\t\tActive substance: ";
		cout << oldMedicine.getSubstance() << "\n\n";
	}
	catch (const exception& e) {
		cout << "\t\t" << e.what() << "\n\n";
	}
}

void UserInterface::updateMedicine() {
	try {
		displayMedicineList(repo);
		cout << "\tChoose the position of the medicine you want to update from the list: ";
		const int position = readInteger();
		Medicine oldMedicine = repo.getMedicineAt(position);

		cout << "\tThe new name of the medicine: ";
		string name = readString();
		validator.validateMedicineName(name);

		cout << "\tThe new price of the medicine: ";
		const double price = readDouble();
		validator.validateMedicinePrice(price);

		cout << "\tThe new producer of the medicine: ";
		string producer = readString();
		validator.validateMedicineProducer(producer);

		cout << "\tThe new active substance of the medicine: ";
		string substance = readString();
		validator.validateMedicineSubstance(substance);

		serv.updateMedicine(position, name, price, producer, substance);
		cout << "\n" << twoLines;
		cout << "\n\tThe update was successful, the modified medicine:\n";
		cout << "\t\tName: " << oldMedicine.getName() << "\n\t\tPrice: " << oldMedicine.getPrice();
		cout << "\n\t\tProducer: " << oldMedicine.getProducer() << "\n\t\tActive substance: ";
		cout << oldMedicine.getSubstance() << "\n\n";
	}
	catch (const exception& e) {
		cout << "\t\t" << e.what() << "\n\n";
	}
}

void UserInterface::findMedicineList() {
	try {
		cout << twoLines << "\n";
		cout << "\tThe pattern of the name of the searched medicine: ";
		string namePattern = readString();

		cout << "\n" << twoLines;
		cout << "\n\tThe medicines that match your input:\n\n";
		displayMedicineList(serv.findMedicineList(namePattern));

	}
	catch (const exception& e) {
		cout << "\t\t" << e.what() << "\n\n";
	}
}

void UserInterface::filterMedicineList() {
	try {
		cout << twoLines << "\n";
		cout << "\tThe minimum price: ";
		const int minPrice = readInteger();
		cout << "\tThe maximum price: ";
		const int maxPrice = readInteger();
		cout << "\n\tThe medicines that match your range:\n";
		displayMedicineList(serv.filterMedicinePriceRange(minPrice, maxPrice));
	}
	catch (const exception& e) {
		cout << "\t\t" << e.what() << "\n\n";
	}
}

void UserInterface::sortMedicineList() {
	try {
		cout << twoLines << "\n";
		cout << "\tSelect the sorting type:\n";
		cout << "\t\t1. By name\n";
		cout << "\t\t2. By price\n";
		cout << "\t\t3. By producer\n";
		cout << "\t\t4. By active substance\n";
		cout << "\tChoose an option: ";
		Repository sortedMedicineList;
		switch (readInteger()) {
		case 1: {
			cout << "\n" << twoLines;
			cout << "\n\tSelect the ordering of the sort:\n";
			cout << "\t\t1. Ascending\n";
			cout << "\t\t2. Descending\n";
			cout << "\tChoose an option: ";
			const int option = readInteger();
			if (option == 1) {
				cout << "\n\tThe medicine list sorted ascending, by name:\n";
				displayMedicineList(serv.sortMedicineList([](const Medicine& m1, const Medicine& m2) {
					return m1.getName() < m2.getName(); }));
				break;
			}
			else if (option == 2) {
				cout << "\n\tThe medicine list sorted descending, by name:\n";
				displayMedicineList(serv.sortMedicineList([](const Medicine& m1, const Medicine& m2) { 
					return m1.getName() > m2.getName(); }));
				break;
			}
			else {
				cout << "\t\tInvalid option!";
				break;
			}
		}

		case 2: {
			cout << "\n" << twoLines;
			cout << "\n\tSelect the ordering of the sort:\n";
			cout << "\t\t1. Ascending\n";
			cout << "\t\t2. Descending\n";
			cout << "\tChoose an option: ";
			const int option = readInteger();
			if (option == 1) {
				cout << "\n\tThe medicine list sorted ascending, by price:\n";
				displayMedicineList(serv.sortMedicineList([](const Medicine& m1, const Medicine& m2) noexcept {
					return m1.getPrice() < m2.getPrice(); }));
				break;
			}
			else if (option == 2) {
				cout << "\n\tThe medicine list sorted descending, by price:\n";
				displayMedicineList(serv.sortMedicineList([](const Medicine& m1, const Medicine& m2) noexcept {
					return m1.getPrice() > m2.getPrice(); }));
				break;
			}
			else {
				cout << "\t\tInvalid option!";
				break;
			}
		}

		case 3: {
			cout << "\n" << twoLines;
			cout << "\n\tSelect the ordering of the sort:\n";
			cout << "\t\t1. Ascending\n";
			cout << "\t\t2. Descending\n";
			cout << "\tChoose an option: ";
			const int option = readInteger();
			if (option == 1) {
				cout << "\n\tThe medicine list sorted ascending, by producer:\n";
				displayMedicineList(serv.sortMedicineList([](const Medicine& m1, const Medicine& m2) { return m1.getProducer() < m2.getProducer(); }));
				break;
			}
			else if (option == 2) {
				cout << "\n\tThe medicine list sorted descending, by producer:\n";
				displayMedicineList(serv.sortMedicineList([](const Medicine& m1, const Medicine& m2) { return m1.getProducer() > m2.getProducer(); }));
				break;
			}
			else {
				cout << "\t\tInvalid option!";
				break;
			}
		}

		case 4: {
			cout << "\n" << twoLines;
			cout << "\n\tSelect the ordering of the sort:\n";
			cout << "\t\t1. Ascending\n";
			cout << "\t\t2. Descending\n";
			cout << "\tChoose an option: ";
			const int option = readInteger();
			if (option == 1) {
				cout << "\n\tThe medicine list sorted ascending, by active substance:\n";
				displayMedicineList(serv.sortMedicineList([](const Medicine& m1, const Medicine& m2) { return m1.getSubstance() < m2.getSubstance(); }));
				break;
			}
			else if (option == 2) {
				cout << "\n\tThe medicine list sorted descending, by active substance:\n";
				displayMedicineList(serv.sortMedicineList([](const Medicine& m1, const Medicine& m2) { return m1.getSubstance() > m2.getSubstance(); }));
				break;
			}
			else {
				cout << "\t\tInvalid option!";
				break;
			}
		}
		default:
			cout << "\t\tInvalid option!";
		}
	}
	catch (const exception& e) {
		cout << "\t\t" << e.what() << "\n\n";
	}
}
