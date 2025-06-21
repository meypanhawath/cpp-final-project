#include "ExcelUtils.hpp"
#include <xlnt/xlnt.hpp>
#include <iostream>

void saveGuestsToExcel(const std::vector<Guest>& guests, const std::string& filename) {
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    ws.title("Guests");

    // Header
    ws.cell("A1").value("Name");
    ws.cell("B1").value("Contact");
    ws.cell("C1").value("Room Number");
    ws.cell("D1").value("Booking Time");

    int row = 2;
    for (const auto& guest : guests) {
        ws.cell("A" + std::to_string(row)).value(guest.getName());
        ws.cell("B" + std::to_string(row)).value(guest.getContactNumber());
        ws.cell("C" + std::to_string(row)).value(guest.getRoomNumber());
        ws.cell("D" + std::to_string(row)).value(guest.getBookingTime());
        ++row;
    }

    try {
        wb.save(filename);
    } catch (const std::exception& e) {
        std::cerr << "Error saving guests to Excel: " << e.what() << '\n';
    }
}

std::vector<Guest> loadGuestsFromExcel(const std::string& filename) {
    std::vector<Guest> guests;

    xlnt::workbook wb;
    try {
        wb.load(filename);
    } catch (...) {
        std::cerr << "Warning: Guests Excel file not found or invalid, starting empty.\n";
        return guests;
    }

    auto ws = wb.active_sheet();

    bool firstRow = true;
    for (auto row : ws.rows(false)) {
        if (firstRow) { firstRow = false; continue; }  // skip header row

        std::string name = row[0].to_string();
        std::string contact = row[1].to_string();
        int roomNumber = 0;
        try {
            roomNumber = row[2].value<int>();
        } catch (...) {
            roomNumber = 0;
        }
        std::string bookingTime = row[3].to_string();

        guests.emplace_back(name, contact, roomNumber, "");
    }

    return guests;
}

void saveRoomsToExcel(const std::vector<Room>& rooms, const std::string& filename) {
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    ws.title("Rooms");

    // Header
    ws.cell("A1").value("Room Number");
    ws.cell("B1").value("Type");
    ws.cell("C1").value("Price");
    ws.cell("D1").value("Status");

    int row = 2;
    for (const auto& room : rooms) {
        ws.cell("A" + std::to_string(row)).value(room.getRoomNumber());
        ws.cell("B" + std::to_string(row)).value(room.getType());
        ws.cell("C" + std::to_string(row)).value(room.getPrice());
        ws.cell("D" + std::to_string(row)).value(room.getStatus());
        ++row;
    }

    try {
        wb.save(filename);
    } catch (const std::exception& e) {
        std::cerr << "Error saving rooms to Excel: " << e.what() << '\n';
    }
}

std::vector<Room> loadRoomsFromExcel(const std::string& filename) {
    std::vector<Room> rooms;

    xlnt::workbook wb;
    try {
        wb.load(filename);
    } catch (...) {
        std::cerr << "Warning: Rooms Excel file not found or invalid, starting empty.\n";
        return rooms;
    }

    auto ws = wb.active_sheet();

    bool firstRow = true;
    for (auto row : ws.rows(false)) {
        if (firstRow) { firstRow = false; continue; } // skip header

        int roomNumber = 0;
        try {
            roomNumber = row[0].value<int>();
        } catch (...) {
            roomNumber = 0;
        }
        std::string type = row[1].to_string();
        double price = 0.0;
        try {
            price = row[2].value<double>();
        } catch (...) {
            price = 0.0;
        }
        std::string status = row[3].to_string();

        rooms.emplace_back(roomNumber, type, price, status);
    }

    return rooms;
}
