#pragma once

#include "medicine.h"
#include<ctime>
#include<iostream>
#include <string>
#include <iomanip>

using namespace std;


MedList medicine_List;

class record {
private:
	string medicineName;
	int quantity;
	int unitPrice;
	int totalOfRecord;

public:
	record() {
		medicineName = "";
		quantity = 0;
		unitPrice = 0;
		totalOfRecord = 0;

	}

	record(string medName, int qty, int unitP) {
		medicineName = medName;
		quantity = qty;
		unitPrice = unitP;
		totalOfRecord = qty * unitP;
	}

	string getName() { return medicineName; }

	int getQty() { return quantity; }

	int getUnitP() { return unitPrice; }


	int getTotal() { return totalOfRecord; }

};

class record_Node {
public:
	record rec;
	record_Node* next;


	record_Node(string medName, int qty, int unitP) {

		rec = record(medName, qty, unitP);
		next = NULL;
	}

};

class recordList {

	record_Node* head;
	record_Node* tail;
	int size;

public:
	recordList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void insertFirst(string medName, int qty, int unitP) {
		record_Node* temp = new record_Node(medName, qty, unitP);

		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head = temp;
			size++;
		}
	}

	void insertLast(string medName, int qty, int unitP) {
		record_Node* temp = new record_Node(medName, qty, unitP);

		tail->next = temp;
		tail = temp;
		size++;
	}

	void deleteFirst() {
		if (head == NULL) {
			cout << "no records to delete\n";
		}
		else {

			record_Node* temp = head;
			if (size == 1) {
				head = NULL;
				tail = NULL;
				delete temp;
				size--;
			}
			else {
				head = head->next;
				delete temp;
				size--;
			}
		}
	}


	void deleteLast() {

		if (head == NULL) {
			cout << "there is no records\n";
		}
		else {

			record_Node* temp = tail;
			if (size == 1) {
				head = NULL;
				tail = NULL;
				size--;
				delete temp;
			}
			else {

				record_Node* current = head;
				for (int i = 0; i < size - 2; i++) {
					current = current->next;

				}
				tail = current;
				tail->next = NULL;
				delete temp;
				size--;


			}
		}
	}


	void deleteAt(int pos) {
		if (pos<0 || pos>size - 1) {
			cout << "Invalid Record\n";
		}
		else {
			if (pos == 0) { deleteFirst(); }
			else if (pos == size - 1) { deleteLast(); }
			else {


				record_Node* current = head;
				for (int i = 0; i < pos - 2; i++) {
					current = current->next;
				}
				record_Node* temp = current->next;
				current->next = current->next->next;
				delete temp;
				size--;


			}
		}
	}

	int getSize() { return size; }

	int getTotal() {
		record_Node* current = head;
		int total = 0;
		for (int i = 0; i < size; i++) {
			total += current->rec.getTotal();
			current = current->next;
		}return total;
	}

	void printRecords() {

		record_Node* current = head;
		for (int i = 0; i < size; i++) {

			cout << endl << "\t" << current->rec.getName() << " \t     " << current->rec.getQty() << "    \t\t    " << current->rec.getUnitP() << "    \t\t   " << current->rec.getTotal() << endl;
			current = current->next;
		}
		cout << "\t________________________________________________________________________\n";
		cout << "\n\tTotal              \t\t\t\t\t\t = " << getTotal() << "\n\n";
	}

};



class Receipt {
private:

	int receiptNo;
	recordList record;
	string customerName;
	double totalBill;
	char dateTime[26];


public:
	Receipt()
	{
		record = recordList();
		receiptNo = 0;
		customerName = "";
		totalBill = 0;

	}
	Receipt(string name, recordList r)
	{
		customerName = name;
		record = r;
		receiptNo = 0;
		time_t now = time(0);
		ctime_s(dateTime, sizeof(dateTime), &now);// recording time and date as a string;
		setTotal();
	}


	void setName(string name) { this->customerName = name; }
	string getName() { return customerName; }

	void printReceipt() {

		system("CLS");
		cout << "\t\t\t\t   ABC Pharmacy\n";

		cout << "\n\n\t\tDate & Time  : \t" << "\t\t" << dateTime << "\n \t        Recipt Number:\t\t\t" << receiptNo << "\n\n \t        Customer Name:\t" << "\t\t" << customerName << "\n\n \t Item \t\t Quantity \t\t Unit Price \t\t Total \n";

		record.printRecords();



	}

	string getTime() { return dateTime; }


	void setTotal() {
		totalBill = record.getTotal();
	}
	double getTotal() { return totalBill; }
	int getReceiptNo() { return receiptNo; }

	void setReceiptNo(int index) { receiptNo = index; }
};


class receipt_Node {
public:

	Receipt receipt;
	receipt_Node* next;
	receipt_Node* prev;


	receipt_Node(Receipt R) {
		receipt = R;
		prev = NULL;
		next = NULL;
	}

};


class receipt_List {
private:
	int size;
	receipt_Node* head;
	receipt_Node* tail;




public:
	receipt_List() {
		size = 0;
		head = NULL;
		tail = NULL;
	}

	void setReceiptNu() {
		receipt_Node* current = head;
		for (int i = 0; i < size; i++) {
			current->receipt.setReceiptNo(i + 1);
			current = current->next;
		}
	}

	void insertFirst(string name, Receipt R) {

		receipt_Node* temp = new receipt_Node(R);
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
		setReceiptNu();
	}

	void insertLast(string name, Receipt R) {
		receipt_Node* temp = new receipt_Node(R);
		if (head == NULL) {

			head = temp;
			tail = temp;

		}
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;


		}
		size++;
		setReceiptNu();

	}


	void deleteFirst() {
		if (head == NULL) {
			cout << "There is no receipts! \n";

		}
		else {
			receipt_Node* temp = head;

			if (size == 1) {
				head = NULL;
				tail = NULL;
				delete temp;
				size--;
			}
			else {
				head = head->next;
				head->prev = NULL;

				delete temp;
			}
		}
	}


	void deleteLast() {

		if (head == NULL) {
			cout << "There is no receipts";
		}
		else {
			receipt_Node* temp = tail;
			if (size == 1) {
				head = NULL;
				tail = NULL;
				size--;

			}
			else {
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
				size--;
			}
		}
	}


	void deleteAt(int pos) {
		if (pos<0 || pos>size) {
			cout << "Invalid record number \n";
		}
		else {
			if (pos == 0) {
				deleteFirst();
			}
			else if (pos == size - 1) {
				deleteLast();
			}
			else {
				receipt_Node* current = head;
				for (int i = 0; i < pos; i++) {
					current = current->next;

				}

				current->prev->next = current->next;
				current->next->prev = current->prev;
				delete current;
				size--;

			}
		}
	}

	void printPreviousOrders() {

		cout << "\n\n\t\t No.  " << "Customer Name   " << "\t\t\tTotal " << "\t\t   Date & Time   \n\n" << endl;

		receipt_Node* current = head;
		for (int i = 0; i < size; i++) {

			cout << "\t\t " << i + 1 << "\t" << current->receipt.getName() << "\t   " << "\t\t \t" << current->receipt.getTotal() << "\t\t" << current->receipt.getTime() << "\n\n" << endl;
			current = current->next;
		}
		int id;
		cout << "\t\t Enter the Receipt number : ";
		cin >> id;
		current = head;
		if (id <= size || id < 0) {
			for (int i = 0; i + 1 < id; i++) {

				current = current->next;

			}
			system("CLS");
			current->receipt.printReceipt();
		}
		else { cout << "Invalid index" << endl; }



	}

};

receipt_List Rec_list;

