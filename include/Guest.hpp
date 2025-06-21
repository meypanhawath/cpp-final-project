#pragma once
#include <string>

class Guest {
private:
    std::string name;
    std::string contactNumber;
    int roomNumber;
    std::string bookingTime;

public:
    Guest(const std::string& name, const std::string& contactNumber, int roomNumber, const std::string& bookingTime);

    std::string getName() const;
    std::string getContactNumber() const;
    int getRoomNumber() const;
    std::string getBookingTime() const;

    void setRoomNumber(int room);
    void setBookingTime(const std::string& time);
};
