#include "MenuUtils.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Role selectRole() {
    int choice;
    do {
        cout << "\nSelect Role:\n";
        cout << "1. Admin\n";
        cout << "2. Staff\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) exit(0);
    } while (choice < 1 || choice > 2);

    return (choice == 1) ? Role::Admin : Role::Staff;
}

int adminMenu() {
    int choice;
    cout << "\n=== Admin Menu ===\n";
    cout << "1. View Rooms\n";
    cout << "2. Update Room Price\n";
    cout << "0. Logout\n";
    cout << "👉 Enter choice: ";
    cin >> choice;
    return choice;
}

int staffMenu() {
    int choice;
    cout << "\n=== Staff Menu ===\n";
    cout << "1. Check In Guest\n";
    cout << "2. Check Out Guest\n";
    cout << "3. Update Room Status\n";
    cout << "4. View Rooms\n";
    cout << "5. View Current Guests\n";
    cout << "6. Search Guest by Name\n";
    cout << "0. Logout\n";
    cout << "👉 Enter choice: ";
    cin >> choice;
    return choice;
}
