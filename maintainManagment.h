#ifndef MAINTENANCEMANAGEMENT_H
#define MAINTENANCEMANAGEMENT_H

#include "maintain.h"
#include "aircraftManagement.h"

#include <vector>


using namespace std;



class MaintenanceManager
{

private:

    vector<Maintenance> records;


    AircraftManager& am;


    void saveData();

    void loadData();



public:


    MaintenanceManager(AircraftManager& manager);



    void addMaintenance();

    void updateMaintenance();

    void removeMaintenance();

    void displayMaintenance();


};

#endif