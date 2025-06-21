#include "FileUtils.hpp"
#include <fstream>
#include <iostream>

using namespace std;

const string ROOMS_FILE = "rooms.txt";
const string GUESTS_FILE = "guests.txt";

// Save rooms to file
void saveRooms(const vector<Room>& rooms) {
    ofstream ofs(ROOMS_FILE);
    if (!ofs) {
        cerr << "Error opening file for saving rooms.\n";
        return;
    }

    for (const auto& room : rooms) {
        ofs << room.getRoomNumber() << ','
            << room.getType() << ','
            << room.getPrice() << ','
            << room.getStatus() << '\n';
    }

    ofs.close();
}

// Load rooms from file
void loadRooms(vector<Room>& rooms) {
    ifstream ifs(ROOMS_FILE);
    if (!ifs) {
        rooms.clear();

        // Default fallback rooms
        rooms.emplace_back(101, "Single", 50.0, "Available");
        rooms.emplace_back(102, "Single", 50.0, "Available");
        rooms.emplace_back(103, "Single", 50.0, "Available");
        rooms.emplace_back(201, "Double", 75.0, "Available");
        rooms.emplace_back(202, "Double", 75.0, "Available");
        rooms.emplace_back(203, "Double", 75.0, "Available");
        rooms.emplace_back(204, "Double", 75.0, "Available");
        rooms.emplace_back(205, "Double", 75.0, "Available");
        rooms.emplace_back(301, "Premium", 120.0, "Available");
        rooms.emplace_back(302, "Premium", 120.0, "Available");

        saveRooms(rooms);
        return;
    }

    rooms.clear();
    string line;
    while (getline(ifs, line)) {
        if (line.empty()) continue;

        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) continue;

        int roomNumber = stoi(line.substr(0, pos1));
        string type = line.substr(pos1 + 1, pos2 - pos1 - 1);
        double price = stod(line.substr(pos2 + 1, pos3 - pos2 - 1));
        string status = line.substr(pos3 + 1);

        rooms.emplace_back(roomNumber, type, price, status);
    }

    ifs.close();
}

// Save guests to file
void saveGuests(const vector<Guest>& guests) {
    ofstream ofs(GUESTS_FILE);
    if (!ofs) {
        cerr << "Error opening file for saving guests.\n";
        return;
    }

    for (const auto& guest : guests) {
        ofs << guest.getName() << ','
            << guest.getContactNumber() << ','
            << guest.getRoomNumber() << ','
            << guest.getBookingTime() << '\n';
    }

    ofs.close();
}

// Load guests from file
void loadGuests(vector<Guest>& guests) {
    ifstream ifs(GUESTS_FILE);
    if (!ifs) {
        guests.clear();
        return;
    }

    guests.clear();
    string line;
    while (getline(ifs, line)) {
        if (line.empty()) continue;

        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) continue;

        string name = line.substr(0, pos1);
        string contactNumber = line.substr(pos1 + 1, pos2 - pos1 - 1);
        int roomNumber = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        string bookingTime = line.substr(pos3 + 1);

        guests.emplace_back(name, contactNumber, roomNumber, bookingTime);
    }

    ifs.close();
}
