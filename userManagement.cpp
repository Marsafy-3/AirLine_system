#include "userManagement.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;


// Constructor
UserManager::UserManager()
{
    loadData();
}


// Save Users
void UserManager::saveData()
{
    json data;

    data["users"] = json::array();

    for (User& user : users)
    {
        json userData;

        userData["name"] = user.getname();
        userData["id"] = user.getId();
        userData["password"] = user.getpass();
        userData["role"] = user.getrole();

        data["users"].push_back(userData);
    }

    ofstream file("users.json");

    if (!file.is_open())
    {
        cout << "Error opening users.json!" << endl;
        return;
    }

    file << data.dump(4);

    file.close();
}


// Load Users
void UserManager::loadData()
{
    ifstream file("users.json");

    if (!file.is_open())
    {
        return;
    }

    json data;

    file >> data;

    file.close();

    users.clear();

    if (!data.contains("users"))
    {
        return;
    }

    for (auto& userData : data["users"])
    {
        string name = userData["name"];
        int id = userData["id"];
        string password = userData["password"];
        string role = userData["role"];

        User user(
            name,
            id,
            password,
            role
        );

        users.push_back(user);
    }
}


// Add User
void UserManager::addUser()
{
    string name;
    int id;
    string password;
    string role;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter ID: ";
    cin >> id;

    // Prevent duplicate ID
    if (findUser(id) != nullptr)
    {
        cout << "User ID already exists!" << endl;
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    cout << "Enter Role (Admin/BookingAgent/Passenger): ";
    cin >> role;

    User user(
        name,
        id,
        password,
        role
    );

    users.push_back(user);

    saveData();

    cout << "User added successfully." << endl;
}


// Remove User
void UserManager::removeUser()
{
    int id;

    cout << "Enter User ID to remove: ";
    cin >> id;

    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (it->getId() == id)
        {
            users.erase(it);

            saveData();

            cout << "User removed successfully." << endl;
            return;
        }
    }

    cout << "User not found." << endl;
}


// Update User
void UserManager::updateUser()
{
    int id;

    cout << "Enter User ID that you want to update: ";
    cin >> id;

    User* user = findUser(id);

    if (user == nullptr)
    {
        cout << "User not found." << endl;
        return;
    }

    int choice;

    cout << "What do you want to update?" << endl;
    cout << "1. Name" << endl;
    cout << "2. ID" << endl;
    cout << "3. Password" << endl;
    cout << "4. Role" << endl;

    cout << "Enter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        string name;

        cout << "Enter new name: ";
        cin >> name;

        user->setname(name);

        break;
    }

    case 2:
    {
        int newId;

        cout << "Enter new ID: ";
        cin >> newId;

        User* existingUser = findUser(newId);

        if (existingUser != nullptr &&
            existingUser != user)
        {
            cout << "ID already in use." << endl;
            return;
        }

        user->setId(newId);

        break;
    }

    case 3:
    {
        string password;

        cout << "Enter new Password: ";
        cin >> password;

        user->setpass(password);

        break;
    }

    case 4:
    {
        string role;

        cout << "Enter new Role: ";
        cin >> role;

        user->setrole(role);

        break;
    }

    default:
        cout << "Invalid choice." << endl;
        return;
    }

    saveData();

    cout << "User updated successfully." << endl;
}


// Find User
User* UserManager::findUser(int id)
{
    for (auto& user : users)
    {
        if (user.getId() == id)
        {
            return &user;
        }
    }

    return nullptr;
}


// Display Users
void UserManager::displayUsers()
{

    if (users.empty())
    {
        cout << "No users found." << endl;
        return;
    }

    for (auto& user : users)
    {
        cout << "Name: " << user.getname()
             << " | ID: " << user.getId()
             << " | Role: " << user.getrole()
             << endl;
    }
}