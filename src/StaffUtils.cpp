#include "StaffUtils.hpp"
#include "ExcelUtils.hpp" // ADD THIS
#include "FileUtils.hpp"
#include <iostream>
#include <limits>
#include <algorithm>
#include <ctime> // for std::time, std::strftime

using namespace std;

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

void checkInGuest(vector<Room>& rooms, vector<Guest>& guests) {
    cout << "\n🟢 === Guest Check-In ===\n";
    string name, contact;
    int roomNumber;

    cout << "Guest name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Contact number (10 digits): ";
    getline(cin, contact);

    if (contact.length() >= 10 || !all_of(contact.begin(), contact.end(), ::isdigit)) {
        cout << "❌ Invalid contact number. Check-in failed.\n";
        return;
    }

    cout << "Enter room number: ";
    cin >> roomNumber;

    bool found = false;
    for (auto& room : rooms) {
        if (room.getRoomNumber() == roomNumber && room.getStatus() == "Available") {
            room.setStatus("Unavailable");
            found = true;

            // Get current time in DD-MM-YY HH:MN
            time_t now = time(nullptr);
            tm* local = localtime(&now);
            char timeBuffer[20];
            strftime(timeBuffer, sizeof(timeBuffer), "%d-%m-%y %H:%M", local);

            guests.emplace_back(name, contact, roomNumber, timeBuffer);
            saveGuestsToExcel(guests, "data/guests.xlsx");
            saveRoomsToExcel(rooms, "data/rooms.xlsx");
            cout << "✅ Check-in successful.\n";
            return;
        }
    }

    if (!found) {
        cout << " ❌ Room not found or not available.\n";
    }
}

void checkOutGuest(vector<Room>& rooms, vector<Guest>& guests) {
    cout << "\n🔴 === Check Out Guest ===\n";

    int roomNumber;
    cout << "Enter room number to check out: ";
    cin >> roomNumber;

    auto guestIt = find_if(guests.begin(), guests.end(),
        [roomNumber](const Guest& g) { return g.getRoomNumber() == roomNumber; });

    if (guestIt == guests.end()) {
        cout << " No guest found in room " << roomNumber << ".\n";
        return;
    }

    guests.erase(guestIt);

    bool roomFound = false;
    for (auto& room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            room.setStatus("Available");
            roomFound = true;
            break;
        }
    }

    if (!roomFound) {
        cout << "Room number " << roomNumber << " not found.\n";
        return;
    }

    cout << "Guest checked out from room " << roomNumber << " successfully.\n";

    saveRoomsToExcel(rooms, "data/rooms.xlsx");
    saveGuestsToExcel(guests, "data/guests.xlsx");
}

void updateRoomStatusA(vector<Room>& rooms) {
    cout << "\n=== Update Room Status ===\n";
    int roomNumber;
    cout << "Enter room number to update status: ";
    cin >> roomNumber;

    bool found = false;
    for (auto& room : rooms) {
        if (room.getRoomNumber() == roomNumber) {
            found = true;
            cout << "Current status: " << room.getStatus() << "\n";
            cout << "Enter new status (Available / Unavailable): ";
            string status;
            cin >> status;
            if (status == "Available" || status == "Unavailable") {
                room.setStatus(status);
                cout << "Room status updated successfully.\n";
                saveRooms(rooms);
            } else {
                cout << "Invalid status. No changes made.\n";
            }
            break;
        }
    }

    if (!found) {
        cout << "Room number " << roomNumber << " not found.\n";
    }
}

void viewRoomsA(const vector<Room>& rooms) {
    cout << "\n👀 === Room List ===\n";
    for (const auto& room : rooms) {
        cout << "Room Number: " << room.getRoomNumber()
             << ", Type: " << room.getType()
             << ", Price: $" << room.getPrice()
             << ", Status: " << room.getStatus() << "\n";
    }
}

void viewCurrentGuests(const vector<Guest>& guests) {
    cout << "\n❕ === Current Guests ===\n";
    if (guests.empty()) {
        cout << "No guests currently checked in.\n";
        return;
    }
    for (const auto& guest : guests) {
        cout << "Name: " << guest.getName()
             << ", Contact: " << guest.getContactNumber()
             << ", Room Number: " << guest.getRoomNumber()
             << ", Booking Time: " << guest.getBookingTime() << "\n";
    }
}

void searchGuestByName(const vector<Guest>& guests) {
    cout << "\n🔍 === Search Guest By Name ===\n";
    cout << "Enter guest name to search: ";
    string name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    bool found = false;
    for (const auto& guest : guests) {
        if (guest.getName().find(name) != string::npos) {
            found = true;
            cout << "Name: " << guest.getName()
                 << ", Contact: " << guest.getContactNumber()
                 << ", Room Number: " << guest.getRoomNumber() << "\n";
        }
    }

    if (!found) {
        cout << "No guests found with name containing '" << name << "'.\n";
    }
}
