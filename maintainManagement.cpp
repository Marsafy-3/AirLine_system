#include "maintainManagment.h"
#include "json.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;



// Constructor

MaintenanceManager::MaintenanceManager(AircraftManager& manager)
    : am(manager)
{
    loadData();
}



// Save Data

void MaintenanceManager::saveData()
{
    json data = json::array();


    for(auto& m : records)
    {
        data.push_back({

            {"maintenanceId", m.getMaintenanceId()},
            {"aircraftId", m.getAircraftId()},
            {"date", m.getDate()},
            {"issue", m.getIssue()},
            {"status", m.getStatus()}

        });
    }


    ofstream file("maintenance.json");


    if(!file)
    {
        cout << "Error opening maintenance.json!" << endl;
        return;
    }


    file << data.dump(4);

    file.close();
}



// Load Data

void MaintenanceManager::loadData()
{
    ifstream file("maintenance.json");


    if(!file)
    {
        return;
    }


    json data;

    file >> data;

    file.close();



    records.clear();


    for(auto& item : data)
    {

        Maintenance m(

            item["maintenanceId"],
            item["aircraftId"],
            item["date"],
            item["issue"],
            item["status"]

        );


        records.push_back(m);
    }
}



// Add Maintenance

void MaintenanceManager::addMaintenance()
{
    int maintenanceId;
    int aircraftId;

    string date;
    string issue;


    cout << "Enter Maintenance ID: ";
    cin >> maintenanceId;


    cout << "Enter Aircraft ID: ";
    cin >> aircraftId;



    if(am.findAircraft(aircraftId) == nullptr)
    {
        cout << "Aircraft not found!" << endl;
        return;
    }



    cout << "Enter Maintenance Date: ";
    cin >> date;


    cout << "Enter Issue: ";
    cin >> issue;



    Maintenance m(

        maintenanceId,
        aircraftId,
        date,
        issue,
        "Scheduled"

    );



    records.push_back(m);


    saveData();


    cout << "Maintenance record added successfully!" << endl;
}



// Update Maintenance

void MaintenanceManager::updateMaintenance()
{
    int id;


    cout << "Enter Maintenance ID: ";
    cin >> id;



    for(auto& m : records)
    {

        if(m.getMaintenanceId() == id)
        {

            int choice;


            cout << "\n1. Mark In Progress" << endl;
            cout << "2. Mark Completed" << endl;


            cout << "Enter choice: ";
            cin >> choice;



            if(choice == 1)
            {
                m.setStatus("In Progress");
            }

            else if(choice == 2)
            {
                m.setStatus("Completed");
            }

            else
            {
                cout << "Invalid choice!" << endl;
                return;
            }



            saveData();


            cout << "Maintenance updated successfully!" << endl;

            return;

        }

    }


    cout << "Maintenance record not found!" << endl;
}



// Remove Maintenance

void MaintenanceManager::removeMaintenance()
{
    int id;


    cout << "Enter Maintenance ID: ";
    cin >> id;



    for(auto it = records.begin(); it != records.end(); ++it)
    {

        if(it->getMaintenanceId() == id)
        {

            records.erase(it);


            saveData();


            cout << "Maintenance removed successfully!" << endl;

            return;
        }

    }


    cout << "Maintenance record not found!" << endl;
}



// Display Maintenance

void MaintenanceManager::displayMaintenance()
{

    if(records.empty())
    {
        cout << "No maintenance records found." << endl;
        return;
    }



    for(auto& m : records)
    {

        m.displayMaintenance();

        cout << "----------------------" << endl;

    }

}