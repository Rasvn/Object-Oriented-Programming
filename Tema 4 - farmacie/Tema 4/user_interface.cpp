#include <iostream>
#include <string>
#include "user_interface.h"

using namespace std;
#define yeet catch

UserInterface::UserInterface(Pharmacy pharmacy)
			  :srv(&repo) {
	repo = pharmacy;
}

void UserInterface::begin() {
	populateMedicineList();
	while (true) {
		switch (globalMenu()) {
		case 1:
			system("cls");
			displayMedicineList();
			break;
		
		case 2:
			system("cls");
			addMedicine();
			break;

		case 3:
			system("cls");
			removeMedicine();
			break;

		case 4:
			system("cls");
			updateMedicine();
			break;

		case 0:
			system("cls");
			cout << "Bye!\n";
			return;
		
		default:
			system("cls");
			cout << "Invalid option!\n\n";
		}
	}
}

UserInterface::~UserInterface() {
	srv.~Service();
}

int UserInterface::globalMenu() {
	Validator validator;
	try {
		string buffer;
		cout << "Management of a list of medicine\n";
		cout << " 1. Display the list of medicine\n";
		cout << " 2. Add a medicine\n";
		cout << " 3. Remove a medicine\n";
		cout << " 4. Update a medicine\n";
		cout << " 5. Find a medicine\n";
		cout << " 6. Filter the list of medicine\n";
		cout << " 7. Sort the list of medicine\n";
		cout << " 0. Leave the application\n";
		cout << "Choose an option: ";
		rewind(stdin);
		getline(cin, buffer);
		validator.validateInteger(buffer);
		return stoi(buffer);
	}
	catch (exception&) {
		return -1;
	}
}

void UserInterface::populateMedicineList() {
	srv.addMedicine("Atorvastatin", 18.43, "Lipitor", "atorvastatin calcium trihydrate");
	srv.addMedicine("Augmentin", 12.44, "Trimox", "amoxicillin");
	srv.addMedicine("Lisinopril", 34.74, "Zestril", "torasemide");
	srv.addMedicine("Levothyroxine", 14.99, "Synthroid", "levothyroxine sodium");
	srv.addMedicine("Albuterol", 19.05, "Ventolin", "albuterol sulfate");
	srv.addMedicine("Metformin", 89.99, "Glucophage", "metformin hydrochloride");
	srv.addMedicine("Amlodipine", 17.86, "Norvasc", "amlodipine maleate");
	srv.addMedicine("Metoprolol", 13.59, "Lopressor", "metoprolol tartrate");
	srv.addMedicine("Paracetamol", 0.63, "Farmson", "paracetamol");
	srv.addMedicine("Omeprazole", 69.96, "Losec", "disodium hydrogen phosphate");
	srv.addMedicine("Losartan", 52.89, "Cozaar", "hydrochlorothiazide");
	srv.addMedicine("Nurofen Plus", 2.89, "Nurofen", "ibuprofen");
}

void UserInterface::displayMedicineList() {
	for (unsigned i = 0; i < repo.getLength(); ++i) {
		cout << " " << i << ") Name: " << repo.getMedicineAt(i).getName() << " / Price: $";
		cout << repo.getMedicineAt(i).getPrice() << " / Producer: " << repo.getMedicineAt(i).getProducer();
		cout << " / Active substance: " << repo.getMedicineAt(i).getSubstance() << "\n";
	}
	cout << "\n";
}

void UserInterface::addMedicine() {
	cout << "Add a new medicine\n";
	try {
		Validator validator;
		string name, producer, substance, buffer;
		double price;
		bool onepoint = false;

		cout << " The name of the new medicine: ";
		rewind(stdin);
		getline(cin, name);
		validator.validateMedicineName(name);

		cout << " The price of the new medicine: ";
		rewind(stdin);
		getline(cin, buffer);
		validator.validateRealNumber(buffer);
		price = stod(buffer);
		validator.validateMedicinePrice(price);

		cout << " The producer of the new medicine: ";
		rewind(stdin);
		getline(cin, producer);
		validator.validateMedicineProducer(producer);

		cout << " The active substance of the new medicine: ";
		rewind(stdin);
		getline(cin, substance);
		validator.validateMedicineSubstance(substance);

		srv.addMedicine(name, price, producer, substance);

		cout << "The new medicine was added in the list successfully!\n";
	}
	yeet (exception& e) {
		cout << e.what();
	}
	cout << "\n";
}

void UserInterface::removeMedicine() {
	cout << "Remove a medicine\n";
	cout << " 1. Remove a medicine by name & producer\n";
	cout << " 2. Remove a medicine by position\n";
	cout << "Choose an option: ";
	Validator validator;
	string buffer;
	rewind(stdin);
	getline(cin, buffer);
	if (buffer.size() != 1 || (buffer[0] != '1' && buffer[0] != '2')) {
		cout << "Invalid option!\n\n";
	}
	else if (buffer[0] == '1') {
		cout << "\n";
		try {
			string name, producer;

			cout << "The name of the medicine: ";
			rewind(stdin);
			getline(cin, name);
			validator.validateMedicineName(name);

			cout << "The producer of the medicine: ";
			rewind(stdin);
			getline(cin, producer);
			validator.validateMedicineProducer(producer);

			Medicine oldMed = srv.removeMedicine(name, producer);
			cout << " Removed medicine:\n\tName: " << oldMed.getName();
			cout << "\n\tPrice: $" << oldMed.getPrice() << "\n\tProducer: ";
			cout << oldMed.getProducer() << "\n\tActive substance: ";
			cout << oldMed.getSubstance() << "\n\n";
		}
		catch (exception& e) {
			cout << " " << e.what() << "\n\n";
		}
	}
	else if (buffer[0] == '2') {
		cout << "\n";
		displayMedicineList();
		cout << "Choose a position: ";
		rewind(stdin);
		getline(cin, buffer);
		try {
			validator.validateInteger(buffer);
			unsigned position = (unsigned)stoi(buffer);
			Medicine oldMed = repo.removeMedicine(position);
			cout << " Removed medicine:\n\tName: " << oldMed.getName();
			cout << "\n\tPrice: $" << oldMed.getPrice() << "\n\tProducer: ";
			cout << oldMed.getProducer() << "\n\tActive substance: ";
			cout << oldMed.getSubstance() << "\n\n";
		}
		catch (exception& e) {
			cout << " " << e.what() << "\n\n";
		}
	}
}

void UserInterface::updateMedicine() {
	Validator validator;
	displayMedicineList();
	try {
		string buffer, name, producer, substance;
		double price;
		unsigned position;

		cout << "Choose a position: ";
		rewind(stdin);
		getline(cin, buffer);
		validator.validateInteger(buffer);
		position = (unsigned)stoi(buffer);

		cout << " The name of the updated medicine: ";
		rewind(stdin);
		getline(cin, name);
		validator.validateMedicineName(name);

		cout << " The price of the updated medicine: ";
		rewind(stdin);
		getline(cin, buffer);
		validator.validateRealNumber(buffer);
		price = stod(buffer);
		validator.validateMedicinePrice(price);

		cout << " The producer of the updated medicine: ";
		rewind(stdin);
		getline(cin, producer);
		validator.validateMedicineProducer(producer);

		cout << " The active substance of the updated medicine: ";
		rewind(stdin);
		getline(cin, substance);
		validator.validateMedicineSubstance(substance);

		srv.updateMedicine(position, name, price, producer, substance);

		cout << "The medicine was updated successfully!\n\n";
	}
	catch (exception& e) {
		cout << " " << e.what() << "\n\n";
	}
}
