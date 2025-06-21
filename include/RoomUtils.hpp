#pragma once
#include <vector>
#include "Room.hpp"

// Add a new room to the list (admin only)
void addRoom(std::vector<Room> &rooms);

// Display all rooms in a simple table
void displayRooms(const std::vector<Room> &rooms);

// Update room status by room number (staff only)
void updateRoomStatusB(std::vector<Room> &rooms);

// Find a room by room number, return pointer or nullptr if not found
Room* findRoom(std::vector<Room> &rooms, int roomNumber);
