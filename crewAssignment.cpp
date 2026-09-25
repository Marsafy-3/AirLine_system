#include "crewAssignment.h"
#include "flightManagement.h"
#include "crewManagement.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
using namespace std;
using json = nlohmann::json;
void CrewAssignment::saveData()
{
    json data = json::array();

    for (auto& a : assignments)
    {
        data.push_back({
            {"flightNumber", a.flightNumber},
            {"crewId", a.crewId}
        });
    }

    ofstream file("crewAssignments.json");

    if (!file)
    {
        cout << "Error opening file for saving!" << endl;
        return;
    }

    file << data.dump(4);
    file.close();
}
void CrewAssignment::loadData()
{
    ifstream file("crewAssignments.json");

    if (!file)
    {
        return;
    }

    json data;
    file >> data;
    file.close();

    assignments.clear();

    for (auto& item : data)
    {
        Assignment a;

        a.flightNumber = item["flightNumber"];
        a.crewId = item["crewId"];

        assignments.push_back(a);
    }
}
CrewAssignment::CrewAssignment(flightManager& fm, CrewManager& cm)
    : fm(fm), cm(cm)
{
    loadData();
}

void CrewAssignment::assignCrew()
{
    int flightNumber;
    int crewId;

    cout << "Enter flight number: " << endl;
    cin >> flightNumber;

    cout << "Enter crew ID: " << endl;
    cin >> crewId;

    if (fm.findFlight(flightNumber) == nullptr)
    {
        cout << "Flight not found!" << endl;
        return;
    }

    if (cm.findCrew(crewId) == nullptr)
    {
        cout << "Crew member not found!" << endl;
        return;
    }

    Assignment a;
    a.flightNumber = flightNumber;
    a.crewId = crewId;

    assignments.push_back(a);

    saveData();

    cout << "Crew assigned successfully!" << endl;
}

void CrewAssignment::removeAssignment()
{
    int flightNumber;
    int crewId;

    cout << "Enter flight number: " << endl;
    cin >> flightNumber;

    cout << "Enter crew ID: " << endl;
    cin >> crewId;

    for (auto it = assignments.begin(); it != assignments.end(); ++it)
    {
        if (it->flightNumber == flightNumber &&
            it->crewId == crewId)
        {
            assignments.erase(it);
            saveData();

            cout << "Assignment removed successfully!" << endl;
            return;
        }
    }

    cout << "Assignment not found!" << endl;
}

void CrewAssignment::displayAssignments()
{
    if (assignments.empty())
    {
        cout << "No crew assignments found." << endl;
        return;
    }

    for (auto& a : assignments)
    {
        cout << "Flight: " << a.flightNumber
             << " | Crew ID: " << a.crewId << endl;
    }
}
