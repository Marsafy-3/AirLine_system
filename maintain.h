#ifndef MAINT_H
#define MAINT_H

#include <iostream>
#include <string>

using namespace std;


class Maintenance
{

private:

    int maintenanceId;
    int aircraftId;

    string date;
    string issue;
    string status;


public:

    Maintenance(
        int id = 0,
        int aircraft = 0,
        string d = "",
        string i = "",
        string s = "Scheduled"
    );


    int getMaintenanceId();

    int getAircraftId();

    string getDate();

    string getIssue();

    string getStatus();



    void setStatus(string s);


    void displayMaintenance();

};

#endif