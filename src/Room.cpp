#include "Room.hpp"

Room::Room(int roomNumber, const std::string &type, double price, const std::string &status)
    : roomNumber(roomNumber), type(type), price(price), status(status) {}

int Room::getRoomNumber() const {
    return roomNumber;
}

std::string Room::getType() const {
    return type;
}

double Room::getPrice() const {
    return price;
}

std::string Room::getStatus() const {
    return status;
}

void Room::setPrice(double price) {
    this->price = price;
}

void Room::setStatus(const std::string &status) {
    this->status = status;
}
