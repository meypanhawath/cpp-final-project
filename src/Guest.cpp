#include "Guest.hpp"

Guest::Guest(const std::string& name, const std::string& contactNumber, int roomNumber, const std::string& bookingTime)
    : name(name), contactNumber(contactNumber), roomNumber(roomNumber), bookingTime(bookingTime) {}

std::string Guest::getName() const {
    return name;
}

std::string Guest::getContactNumber() const {
    return contactNumber;
}

int Guest::getRoomNumber() const {
    return roomNumber;
}

std::string Guest::getBookingTime() const {
    return bookingTime;
}

void Guest::setRoomNumber(int room) {
    roomNumber = room;
}

void Guest::setBookingTime(const std::string& time) {
    bookingTime = time;
}
