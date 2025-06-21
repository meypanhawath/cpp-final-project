#pragma once

#include "Room.hpp"

enum class Role {
    Admin,
    Staff
};

Role selectRole();

int adminMenu();

int staffMenu();
