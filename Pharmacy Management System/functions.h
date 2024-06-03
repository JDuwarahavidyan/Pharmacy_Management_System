#pragma once
#include "Receipt.h"
#include<sstream>

void mainMenu() {
	cout << " \t\t\t _______________________________________________________\n";
	cout << " \t\t\t|\t\t\t\t\t\t\t| " << endl;
	cout << " \t\t\t|\t\t\tWelcome !!      \t\t| " << endl;
	cout << " \t\t\t|\t\t\t\t\t\t\t| " << endl;
	cout << " \t\t\t|\t1. Take a new order     \t\t\t| " << endl;
	cout << " \t\t\t|\t\t\t\t\t\t\t| " << endl;
	cout << " \t\t\t|\t2. View previous orders\t\t\t\t| " << endl;
	cout << " \t\t\t|\t\t\t\t\t\t\t| " << endl;
	cout << " \t\t\t|\t3. View Medicine List  \t\t\t\t| " << endl;
	cout << " \t\t\t|\t\t\t\t\t\t\t| " << endl;
	cout << " \t\t\t|\t4. Login as Administrator \t\t\t| " << endl;
	cout << " \t\t\t|\t\t\t\t\t\t\t| " << endl;
	cout << " \t\t\t|\t5. Exit         \t\t\t\t| " << endl;
	cout << " \t\t\t|\t\t\t\t\t\t\t| " << endl;
	cout << " \t\t\t -------------------------------------------------------\n";

}

void TakeOrder() {

	string customerName;

	int medIndex;
	int medAmount;
	system("CLS");

	cout << "  ----------------------------------------------------------------\n";


	cout << " | \t Enter Customer name : \t\t\t\t\t  | " << endl;
	cout << " | \t                          \t\t\t\t  | " << endl;
	cout << " |\t\t ";
	getline(cin >> ws, customerName);
	recordList Record_List;
	Receipt Receipti;
	int secondChoice = 1;

	do {
		medicine_List.print();

		cout << "\n\n  \t Enter Medicine ID:  ";

		cin >> medIndex;
		system("CLS");


		MedNode* current = medicine_List.getAt(medIndex - 1);


		cout << "\n\t\t" << current->med.getName() << endl;
		cout << "\n\t\tEnter medicine quantity: ";


		cin >> medAmount;


		if (medAmount > current->med.getStocks()) {

			cout << "\n\n\n\n\tSorry, insufficient stocks \n";

			system("PAUSE");

		}
		else {
			Record_List.insertFirst(current->med.getName(), medAmount, current->med.getPrice());


			current->med.updateStocksAfterTransaction(medAmount);



			system("CLS");
			cout << "\n\tItems added successfully!\n\n\tWould you like to:\n";
			cout << "\t\t 1. Add another medicine\n";
			cout << "\t\t 2. Print recipt\n\n";
			cout << "\tEnter your choice: ";
			cin >> secondChoice;
		}
	} while (secondChoice == 1);
	if (secondChoice == 2) {

		Receipti = Receipt(customerName, Record_List);
		Receipti.printReceipt();
		Rec_list.insertLast(customerName, Receipti);

		cout << endl;
		system("PAUSE");


	}
	else { cout << "\nInvlid input\n"; }



}

void adminMenu() {
	bool running = true;
	do {

		int choice;
		system("CLS");
		cout << "\n\n \t 1. Add new medicine item\n\n";
		cout << " \t 2. Add stocks\n\n";
		cout << "\t 3. Modify medicine item\n\n";
		cout << "\t 4. Delete medicine item\n\n";
		cout << "\t 5. Back to Main Menu\n\n\t";
		cin >> choice;
		if (choice == 1) {
			system("CLS");
			string medName;
			int UnitP;
			int stocksAv;
			int confirm;

			cout << "\n \t ADD NEW MEDICINE ..\n\n";
			cout << " Enter Medicine Name     : ";
			getline(cin >> ws, medName);

			cout << "\n\n Enter Unit Price        : ";
			cin >> UnitP;
			cout << "\n\n Enter Available Stocks  : ";
			cin >> stocksAv;

			system("CLS");
			cout << "\n\n\tMedicine Name    : " << medName;
			cout << "\n\tUnit Price       : " << UnitP;
			cout << "\n\tAvailable stocks : " << stocksAv;
			cout << "\n\n \t Do you wish to add this item? \n";

			cout << "\t\t 1. Yes\n";
			cout << "\t\t 2. No\n\n\t ";
			cin >> confirm;
			if (confirm == 1) {
				medicine_List.insertLast(medName, UnitP, 10, stocksAv);
				cout << "\n\n\t New Medicine Item added successfully!\n";
				system("PAUSE");
			}
			else if (confirm == 2) {
				system("PAUSE");
			}
			else {

				cout << "Invalid Input \n\n";
				system("PAUSE");
			}


		}
		else if (choice == 2) {
			int id;
			int stocks;
			medicine_List.print();
			cout << "\n\n\t Enter the Med.Id of the item you want to add stocks to: ";
			cin >> id;
			system("CLS");

			MedNode* current = medicine_List.getAt(id - 1);
			cout << "\n\t" << current->med.getName();
			cout << "\n\n \tEnter the amount of stocks to add: ";
			cin >> stocks;
			current->med.addStocks(abs(stocks));
			cout << "\n \tStocks added successfully! \n";
			system("PAUSE");
		}
		else if (choice == 3) {
			int id;
			int selection;
			medicine_List.print();
			cout << "\n\n\t Enter the Med.Id of the item you want to modify: ";
			cin >> id;
			MedNode* current = medicine_List.getAt(id - 1);
			system("CLS");
			cout << "\n\n\t" << current->med.getName();
			cout << "\n\n\t 1. Change Item Name  \n";
			cout << "\n\t 2. Remove Stocks \n";
			cout << "\n\t 3. Change Unit Price \n\n\t";
			cin >> selection;

			if (selection == 1) {
				system("CLS");
				string newName;

				cout << "\n\n\t" << current->med.getName();

				cout << "\n\n\n\tEnter New Name: ";
				getline(cin >> ws, newName);
				current->med.setName(newName);
				cout << "\n\n\tItem Name changed successfully!\n";

			}
			else if (selection == 2) {

				system("CLS");
				int stocks;
				cout << "\n\n\t" << current->med.getName();
				cout << "\n\n\n\tEnter the amount of stocks to remove: ";
				cin >> stocks;
				if (stocks > current->med.getStocks()) {
					current->med.addStocks(-1 * (current->med.getStocks()));
				}
				else {
					current->med.addStocks(-1 * (abs(stocks)));
				}
				cout << "\n\tStocks removed successfully!\n";
			}
			else if (selection == 3) {
				system("CLS");
				int newPrice;
				cout << "\n\n\t" << current->med.getName();
				cout << "\n\n\n\tEnter The New Unit Price: ";
				cin >> newPrice;
				current->med.setUnitP(abs(newPrice));
				cout << "\n\n\tUnit Price changed successfully!\n";

			}

			system("PAUSE");

		}
		else if (choice == 4) {

			int id;

			medicine_List.print();
			cout << "\n\n\t Enter the Med.Id of the item you want to Delete : ";
			cin >> id;
			medicine_List.deleteAt(id - 1);
			cout << "Successful !\n";
			system("PAUSE");


		}
		else if (choice == 5) {
			running = false;
			system("PAUSE");
		}
	} while (running);

}

void adminLogin() {

	system("CLS");
	const string password = "password";

	int attempts = 3;

	do {
		system("CLS");
		string pass;
		cout << "\n\t-Login as Administrator-\n";
		cout << "\n\tEnter the password: ";
		cin >> pass;

		bool match = true;

		if (!pass.compare(password)) {
			cout << "\n\n\tLogin successful!\n";
			system("PAUSE");
			adminMenu();
			break;
		}
		else {
			cout << "\n\n\tIncorrect Password. ";
			attempts--;
			cout << "You have " << attempts << " attempts remaining...\n\n";
			system("PAUSE");
		}


	} while (attempts > 0);


}












