#include"maintain.h"
Maintenance::Maintenance(
    int id,
    int aircraft,
    string d,
    string i,
    string s
)
{
    maintenanceId = id;
    aircraftId = aircraft;
    date = d;
    issue = i;
    status = s;
}



int Maintenance::getMaintenanceId()
{
    return maintenanceId;
}


int Maintenance::getAircraftId()
{
    return aircraftId;
}


string Maintenance::getDate()
{
    return date;
}


string Maintenance::getIssue()
{
    return issue;
}
string Maintenance::getStatus()
{
    return status;
}

void Maintenance::setStatus(string s)
{
    status = s;
}

void Maintenance::displayMaintenance()
{
    cout << "\nMaintenance ID: "
         << maintenanceId << endl;


    cout << "Aircraft ID: "
         << aircraftId << endl;


    cout << "Date: "
         << date << endl;


    cout << "Issue: "
         << issue << endl;


    cout << "Status: "
         << status << endl;
}