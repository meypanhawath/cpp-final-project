#include "RoomUtils.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void addRoom(vector<Room> &rooms) {
    int number;
    string type;
    double price;

    cout << "Enter room number: ";
    cin >> number;

    // Check if room number already exists
    for (const auto &r : rooms) {
        if (r.getRoomNumber() == number) {
            cout << "Room number already exists.\n";
            return;
        }
    }

    cout << "Enter room type (Single/Double/Suite): ";
    cin.ignore();
    getline(cin, type);

    cout << "Enter room price: ";
    cin >> price;

    rooms.emplace_back(number, type, price, "Available");
    cout << "Room added successfully!\n";
}

void displayRooms(const vector<Room> &rooms) {
    cout << left << setw(12) << "Room No" 
         << setw(12) << "Type" 
         << setw(12) << "Price" 
         << setw(12) << "Status" << endl;
    cout << "--------------------------------------------\n";

    for (const auto &room : rooms) {
        cout << left << setw(12) << room.getRoomNumber()
             << setw(12) << room.getType()
             << setw(12) << room.getPrice()
             << setw(12) << room.getStatus()
             << endl;
    }
}

Room* findRoom(vector<Room> &rooms, int roomNumber) {
    for (auto &room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            return &room;
        }
    }
    return nullptr;
}

void updateRoomStatusB(vector<Room> &rooms) {
    int roomNumber;
    cout << "Enter room number to update status: ";
    cin >> roomNumber;

    Room* room = findRoom(rooms, roomNumber);
    if (!room) {
        cout << "Room not found.\n";
        return;
    }

    cout << "Current status: " << room->getStatus() << endl;
    cout << "Enter new status (Available/Unavailable): ";
    string newStatus;
    cin.ignore();
    getline(cin, newStatus);

    if (newStatus != "Available" && newStatus != "Unavailable") {
        cout << "Invalid status.\n";
        return;
    }

    room->setStatus(newStatus);
    cout << "Room status updated successfully!\n";
}
