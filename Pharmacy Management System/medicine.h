#pragma once
#include<fstream>
#include<iostream>
#include<cstddef>



using namespace std;

class Medicine {
private:
	string name;
	int stocks;
	int id;
	double unitPrice;

public:
	Medicine()
	{
		name = "";
		stocks = 0;
		id = 0;
		unitPrice = 0;

	}
	Medicine(string mname, int stock, int ids, double price)
	{
		name = mname;
		stocks = stock;
		id = ids;
		unitPrice = price;

	}
	string getName() { return name; }
	int getStocks() { return stocks; }
	int getId() { return id; }
	void setId(int val) { id = val; }
	double getPrice() { return unitPrice; }
	void updateStocksAfterTransaction(int number) {
		stocks = stocks - number;

	}
	void addStocks(int number) {
		stocks = stocks + number;
	}
	void setName(string nm) {
		name = nm;
	}
	void setUnitP(int p) { unitPrice = p; }

};


class MedNode {
public:
	Medicine med;

	MedNode* prev;
	MedNode* next;

	MedNode(string name, int stocks, int id, double price) {
		med = Medicine(name, stocks, id, price);
		prev = NULL;
		next = NULL;

	}

};

class MedList {// Definition of the Linked List which contains the information of Medicine

	MedNode* head = NULL;
	MedNode* tail = NULL;
	int size = 0;

	void setId() {
		MedNode* current = head;
		for (int i = 1; i <= size; i++) {
			current->med.setId(i);
			current = current->next;
		}
	}

public:
	void print() {

		system("CLS");
		cout << "  _____________________________________________________________________________________________________________________ \n";
		cout << " |\t\t\t\t\t\t\t                 \t\t\t\t\t\t\t| " << endl;
		cout << " |\t\t\t\t\t\t\tMedicine List\t\t\t\t\t\t\t| " << endl;
		cout << " |\t\t\t\t\t\t\t                 \t\t\t\t\t\t\t| " << endl;
		cout << " | \t\tMed.Id\t\tMedicine Name \t\tAvailable stocks\t\t       Unit Price\t\t\t\t| \n";
		cout << " |\t\t\t\t\t\t\t                 \t\t\t\t\t\t\t| " << endl;
		MedNode* current = head;


		while (current != NULL) {

			cout << " |\t\t  " << current->med.getId() << "\t\t " << current->med.getName() << " \t\t\t " << current->med.getStocks() << "\t\t\t\t" << current->med.getPrice() << "\t\t\t\t\t| " << endl;
			if (current->next != NULL) cout << " |\t\t\t\t\t\t\t                 \t\t\t\t\t\t\t| " << endl;
			current = current->next;

		}
		cout << " |\t\t\t\t\t\t\t                 \t\t\t\t\t\t\t| " << endl;
		cout << " ______________________________________________________________________________________________________________________ \n";
	}

	void insertFirst(string name, int stocks, int id, double price) {
		MedNode* temp = new MedNode(name, stocks, id, price);
		if (head == NULL) {

			head = temp;
			tail = temp;

		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;

		}
		size++;
		setId();
	}

	void insertLast(string name, int stocks, int id, double price) {

		MedNode* temp = new MedNode(name, stocks, id, price);

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;

		}
		size++;

		setId();

	}


	void deleteFirst() {

		if (head == NULL) {
			cout << "The List is Empty.\n";
		}
		else {
			MedNode* temp = head;
			if (size == 1) {

				head = NULL;
				tail = NULL;
				delete temp;
			}
			else {
				head = head->next;
				head->prev = NULL;
				delete temp;


			}
			size--;
		}
		setId();
	}

	void deleteLast() {
		if (head == NULL) {
			cout << "The List is Empty\n";
		}
		else {
			MedNode* temp = tail;
			if (size == 1) {
				head = NULL;
				tail = NULL;
				delete temp;
			}
			else {

				tail = tail->prev;
				tail->next = NULL;
				delete temp;

			}
			size--;
			setId();

		}







	};

	void deleteAt(int pos) {

		if (pos < 0 || pos >= size) {
			cout << "Invalid index\n";

		}
		else if (pos == 0) { deleteFirst(); }
		else if (pos == size - 1) { deleteLast(); }
		else {
			MedNode* current = head;

			for (int i = 0; i < pos; i++) {
				current = current->next;
			}
			MedNode* temp = current;
			current->prev->next = current->next;
			current->next->prev = current->prev;

			delete temp;
			size--;
			setId();
		}

	}


	void printAt(int pos) {
		MedNode* current = head;
		for (int i = 0; i < pos; i++) { current = current->next; }

		cout << current->med.getName();
	}

	MedNode* getAt(int pos) {
		if (pos < size) {
			MedNode* current = head;
			for (int i = 0; i < pos; i++) { current = current->next; }
			return current;
		}
		else { cout << "inavlid input "; }

		system("PAUSE");
	}

	int getSize() {
		return size;
	}

};

MedList generateInitialMedcineList() {

	MedList medicineList;
	int no;
	ifstream fin("Medicine.txt");
	fin >> no;
	for (int i = 0; i < no; i++) {
		string name;
		fin >> name;
		int stocks;
		fin >> stocks;
		int price;
		fin >> price;
		medicineList.insertLast(name, stocks, i, price);


	}

	return medicineList;
}
