#pragma once
#include <string>

class User {
private:
    std::string username;
    std::string password; // store as plain for now (simple)
    std::string role;     // "Admin" or "Staff"

public:
    User() = default;
    User(const std::string& username, const std::string& password, const std::string& role);

    std::string getUsername() const;
    std::string getPassword() const;
    std::string getRole() const;

    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setRole(const std::string& role);
};
