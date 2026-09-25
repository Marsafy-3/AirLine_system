#include "crewManagement.h"
#include <iostream>
#include "json.hpp"
#include <fstream>
using namespace std;
using json = nlohmann::json;
CrewManager::CrewManager(){
    loadData();
}
void CrewManager::saveData()
{
    json data;
    data["crews"] = json::array();

    for (const auto& crew : crews)
    {
        json c;

        c["id"] = crew.getId();
        c["name"] = crew.getName();
        c["role"] = crew.getRole();

        data["crews"].push_back(c);
    }

    ofstream file("crews.json");

    if (!file.is_open())
    {
        cout << "Error opening crews.json for saving.\n";
        return;
    }

    file << data.dump(4);
    file.close();
}
void CrewManager::loadData()
{
    ifstream file("crews.json");

    if (!file.is_open())
    {
        return;
    }

    json data;
    file >> data;
    file.close();

    crews.clear();

    if (!data.contains("crews"))
    {
        return;
    }

    for (const auto& c : data["crews"])
    {
        int id = c["id"];
        string name = c["name"];
        string role = c["role"];

        Crew crew(name, id, role);

        crews.push_back(crew);
    }
}

void CrewManager::addCrew(){
    string name;
    string role;
    int id;

    cout << "Enter Crew ID: ";
    cin >> id;

    cout << "Enter Crew Name: ";
    cin >> name;

    cout << "Enter Crew Role: ";
    cin >> role;

    Crew c(name, id, role);

    crews.push_back(c);

    saveData();

cout << "Crew added successfully.\n";
}

void CrewManager::removeCrew()
{
    int id;

    cout << "Enter Crew ID to remove: ";
    cin >> id;

    for (auto it = crews.begin(); it != crews.end(); ++it)
    {
        if (it->getId() == id)
        {
            crews.erase(it);

            saveData();

            cout << "Crew removed successfully.\n";
            return;
        }
    }

    cout << "Crew not found.\n";
}

void CrewManager::updateCrew()
{
    int id;

    cout << "Enter Crew ID to update: ";
    cin >> id;

    for (auto it = crews.begin(); it != crews.end(); ++it)
    {
        if (it->getId() == id)
        {
            int choice;

            cout << "What do you want to update?\n";
            cout << "1. Name\n";
            cout << "2. ID\n";
            cout << "3. Role\n";
            cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    string name;
                    cout << "Enter new name: ";
                    cin >> name;
                    it->setName(name);
                    break;
                }

                case 2:
                {
                    int newId;
                    cout << "Enter new ID: ";
                    cin >> newId;
                    it->setId(newId);
                    break;
                }

                case 3:
                {
                    string role;
                    cout << "Enter new role: ";
                    cin >> role;
                    it->setRole(role);
                    break;
                }

                default:
                    cout << "Invalid choice.\n";
                    return;
            }

            saveData();

            cout << "Crew updated successfully.\n";
            return;
        }
    }

    cout << "Crew not found.\n";
}

Crew* CrewManager::findCrew(int id)
{
    for (auto it = crews.begin(); it != crews.end(); ++it)
    {
        if (it->getId() == id)
        {
            return &(*it);
        }
    }

    return nullptr;
}

void CrewManager::displayCrews()
{
    for (auto it = crews.begin(); it != crews.end(); ++it)
    {
        it->displayInfo();
    }
}