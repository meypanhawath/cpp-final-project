#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include "Room.hpp"
#include "Guest.hpp"
#include <vector>

void saveRooms(const std::vector<Room>& rooms);
void loadRooms(std::vector<Room>& rooms);

void saveGuests(const std::vector<Guest>& guests);
void loadGuests(std::vector<Guest>& guests);

#endif // FILE_UTILS_HPP
