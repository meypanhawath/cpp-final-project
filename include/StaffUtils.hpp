#pragma once
#include <vector>
#include "Room.hpp"
#include "Guest.hpp"

void checkInGuest(std::vector<Room>& rooms, std::vector<Guest>& guests);
void checkOutGuest(std::vector<Room>& rooms, std::vector<Guest>& guests);
void updateRoomStatusA(std::vector<Room>& rooms);
void viewRoomsA(const std::vector<Room>& rooms);
void viewCurrentGuests(const std::vector<Guest>& guests);
void searchGuestByName(const std::vector<Guest>& guests);
