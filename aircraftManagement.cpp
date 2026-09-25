#include <iostream>
#include "aircraftManagement.h"
#include "json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;
using namespace std;

AircraftManager::AircraftManager()
{
    loadData();
}
void AircraftManager::saveData()
{
    json j;

    for (auto it = aircrafts.begin(); it != aircrafts.end(); ++it)
    {
        j["aircrafts"].push_back({
            {"id", it->getId()},
            {"model", it->getModel()},
            {"capacity", it->getCapacity()},
            {"status", it->getStatus()}
        });
    }

    ofstream file("aircrafts.json");

    file << j.dump(4);

    file.close();
}
void AircraftManager::loadData()
{
    ifstream file("aircrafts.json");

    if (!file.is_open())
        return;

    json j;
    file >> j;

    file.close();

    aircrafts.clear();

    for (auto& a : j["aircrafts"])
    {
        Aircraft aircraft(
            a["id"],
            a["model"],
            a["capacity"],
            a["status"]
        );

        aircrafts.push_back(aircraft);
    }
}




void AircraftManager::addAircraft()
{
    int id;
    string model;
    int capacity;
    string status;

    cout << "Enter Aircraft ID: ";
    cin >> id;

    cout << "Enter Aircraft Model: ";
    cin >> model;

    cout << "Enter Capacity: ";
    cin >> capacity;

    cout << "Enter Status: ";
    cin >> status;

    Aircraft a(id, model, capacity, status);

    aircrafts.push_back(a);

    cout << "Aircraft added successfully.\n";

    saveData();
}
void AircraftManager::removeAircraft()
{
    int id;

    cout << "Enter Aircraft ID to remove: ";
    cin >> id;

    for (auto it = aircrafts.begin(); it != aircrafts.end(); ++it)
    {
        if (it->getId() == id)
        {
            aircrafts.erase(it);

            cout << "Aircraft removed successfully.\n";

            saveData();
            return;
        }
    }

    cout << "Aircraft not found.\n";
}
Aircraft* AircraftManager::findAircraft(int id)
{
    for (auto it = aircrafts.begin(); it != aircrafts.end(); ++it)
    {
        if (it->getId() == id)
        {
            return &(*it);
        }
    }

    return nullptr;
}
void AircraftManager::updateAircraft()
{
    int id;

    cout << "Enter Aircraft ID that you want to update: ";
    cin >> id;

    for (auto it = aircrafts.begin(); it != aircrafts.end(); ++it)
    {
        if (it->getId() == id)
        {
            int choice;

            cout << "What do you want to update?\n";
            cout << "1. Model\n";
            cout << "2. Capacity\n";
            cout << "3. Status\n";

            cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    string model;

                    cout << "Enter new model: ";
                    cin >> model;

                    it->setModel(model);
                    break;
                }

                case 2:
                {
                    int capacity;

                    cout << "Enter new capacity: ";
                    cin >> capacity;

                    it->setCapacity(capacity);
                    break;
                }

                case 3:
                {
                    string status;

                    cout << "Enter new status: ";
                    cin >> status;

                    it->setStatus(status);
                    break;
                }

                default:
                    cout << "Invalid choice.\n";
                    return;
            }

            cout << "Aircraft updated successfully.\n";

            saveData();
            return;
        }
    }

    cout << "Aircraft not found.\n";
}
void AircraftManager::displayInfo()
{
    if (aircrafts.empty())
    {
        cout << "No aircrafts found." << endl;
        return;
    }

    for (auto& aircraft : aircrafts)
    {
        aircraft.displayAircraft();

    }
}