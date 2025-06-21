#include "AuthUtils.hpp"
#include <iostream>
#include <limits>

using namespace std;

bool login(const Role role)
{
    string username, password;

    cout << "\n=== Login (" << (role == Role::Admin ? "Admin" : "Staff") << ") ===\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (role == Role::Admin && username == "admin" && password == "admin123")
    {
        cout << "Admin login successful.\n";
        return true;
    }
    else if (role == Role::Staff && username == "staff" && password == "staff123")
    {
        cout << "Staff login successful.\n";
        return true;
    }
    cout << "Invalid credentials.\n";
    return false;
}

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
