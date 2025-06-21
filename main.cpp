#include <iostream>
#include <vector>
#include <string>
#include "Room.hpp"
#include "Guest.hpp"
#include "AuthUtils.hpp"
#include "MenuUtils.hpp"
#include "AdminUtils.hpp"
#include "StaffUtils.hpp"
#include "FileUtils.hpp"

using namespace std;

int main() {
    vector<Room> rooms;
    vector<Guest> guests;

    // Load data from files (if any)
    loadRooms(rooms);
    loadGuests(guests);

    // If no rooms loaded, create default fixed rooms
    if (rooms.empty()) {
        // 3 Single rooms
        rooms.emplace_back(101, "Single", 50.0, "Available");
        rooms.emplace_back(102, "Single", 50.0, "Available");
        rooms.emplace_back(103, "Single", 50.0, "Available");

        // 5 Double rooms
        rooms.emplace_back(201, "Double", 75.0, "Available");
        rooms.emplace_back(202, "Double", 75.0, "Available");
        rooms.emplace_back(203, "Double", 75.0, "Available");
        rooms.emplace_back(204, "Double", 75.0, "Available");
        rooms.emplace_back(205, "Double", 75.0, "Available");

        // 2 Premium rooms
        rooms.emplace_back(301, "Premium", 120.0, "Available");
        rooms.emplace_back(302, "Premium", 120.0, "Available");

        saveRooms(rooms);
    }

    while (true) {
    Role role = selectRole();

    // Call login function here before entering menu
    if (!login(role)) {
        cout << "❌ Login failed. Try again\n";
        continue;  // Go back to role selection if login fails
    }

    if (role == Role::Admin) {
        while (true) {
            int choice = adminMenu();
            if (choice == 0) break; // Logout
            switch (choice) {
                case 1:
                    viewRoomsB(rooms);
                    
                    break;
                case 2:
                    updateRoomPrice(rooms);
                    saveRooms(rooms);
                    break;
                default:
                    cout << "❌ Invalid choice. Try again.\n";
            }
        }
    } else if (role == Role::Staff) {
        while (true) {
            int choice = staffMenu();
            if (choice == 0) break; // Logout
            switch (choice) {
                case 1:
                    checkInGuest(rooms, guests);
                    break;
                case 2:
                    checkOutGuest(rooms, guests);
                    break;
                case 3:
                    updateRoomStatusA(rooms);
                    saveRooms(rooms);
                    break;
                case 4:
                    viewRoomsA(rooms);
                    break;
                case 5:
                    viewCurrentGuests(guests);
                    break;
                case 6:
                    searchGuestByName(guests);
                    break;
                default:
                    cout << "⚠️ Option not implemented or invalid.\n";
                    break;
            }
        }
    }
}

    return 0;
}
