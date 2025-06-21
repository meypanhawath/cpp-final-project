#include "AdminUtils.hpp"
#include "FileUtils.hpp"
#include <iostream>

using namespace std;

void updateRoomPrice(vector<Room>& rooms) {
    cout << "\n=== Update Room Price ===\n";
    int roomNumber;
    cout << "Enter room number to update price: ";
    cin >> roomNumber;

    bool found = false;
    for (auto& room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            found = true;
            cout << "Current price: $" << room.getPrice() << "\n";
            cout << "Enter new price: ";
            double newPrice;
            cin >> newPrice;
            if (newPrice >= 0) {
                room.setPrice(newPrice);
                cout << "Room price updated successfully.\n";
                saveRooms(rooms);
            } else {
                cout << "Invalid price. No changes made.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Room number " << roomNumber << " not found.\n";
    }
}

void viewRoomsB(const vector<Room>& rooms) {
    cout << "\n=== Room List ===\n";
    for (const auto& room : rooms) {
        cout << "Room Number: " << room.getRoomNumber()
             << ", Type: " << room.getType()
             << ", Price: $" << room.getPrice()
             << ", Status: " << room.getStatus() << "\n";
    }
}
