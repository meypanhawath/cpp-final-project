#pragma once
#include <string>

class Room {
private:
    int roomNumber;
    std::string type;     // Fixed type (Single, Double, Premium)
    double price;
    std::string status;   // "Available" or "Unavailable"

public:
    Room() = default;
    Room(int roomNumber, const std::string &type, double price, const std::string &status);

    int getRoomNumber() const;
    std::string getType() const;
    double getPrice() const;
    std::string getStatus() const;

    void setPrice(double price);
    void setStatus(const std::string &status);
};
