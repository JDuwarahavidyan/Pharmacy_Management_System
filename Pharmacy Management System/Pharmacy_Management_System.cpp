// Pharmacy Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"
#include<Windows.h>


void managementSystem() {

    bool running = TRUE;

    while (running) {

        system("CLS");
        mainMenu();

        int choice;
        cout << "\n\n\t\tPlease select an option from the menu: ";
        cin >> choice;
        switch (choice) {
        case 1:
            TakeOrder();
            break;

        case 2:
            system("CLS");
            Rec_list.printPreviousOrders();
            system("PAUSE");
            break;
        case 3:
            system("CLS");
            medicine_List.print();


            system("PAUSE");
            break;

        case 4:
            adminLogin();
            break;
        case 5:
            running = FALSE;
            break;
        default:
            cout << "\t\tPlease select a valid option" << endl;
            system("PAUSE");
        }
    }
}

int main()
{
    medicine_List = generateInitialMedcineList();
    managementSystem();

}
