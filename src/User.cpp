#include "User.hpp"

User::User(const std::string& username, const std::string& password, const std::string& role)
    : username(username), password(password), role(role) {}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

std::string User::getRole() const {
    return role;
}

void User::setUsername(const std::string& username) {
    this->username = username;
}

void User::setPassword(const std::string& password) {
    this->password = password;
}

void User::setRole(const std::string& role) {
    this->role = role;
}
