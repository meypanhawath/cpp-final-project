#pragma once

#include <vector>
#include <string>
#include "Guest.hpp"
#include "Room.hpp"

void saveGuestsToExcel(const std::vector<Guest>& guests, const std::string& filename);
std::vector<Guest> loadGuestsFromExcel(const std::string& filename);

void saveRoomsToExcel(const std::vector<Room>& rooms, const std::string& filename);
std::vector<Room> loadRoomsFromExcel(const std::string& filename);
