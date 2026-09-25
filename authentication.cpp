#include <iostream>
#include"authentication.h"
using namespace std;
Authentication::Authentication(UserManager& manager)
    : userManager(manager){}

User* Authentication::login()
{
    int id;
    string password;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Password: ";
    cin >> password;

    User* user = userManager.findUser(id);

    if (user == nullptr)
    {
        cout << "User not found.\n";
        return nullptr;
    }

    if (user->getpass() != password)
    {
        cout << "Incorrect password.\n";
        return nullptr;
    }

    cout << "Login successful.\n";

    return user;
}