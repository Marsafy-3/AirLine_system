#ifndef AIRCRAFTMANAGEMENT_H
#define AIRCRAFTMANAGEMENT_H
#include "aircraft.h"
#include <vector>

using namespace std;

class AircraftManager
{
private:
    vector<Aircraft> aircrafts;

    void saveData();
    void loadData();

public:
    AircraftManager();

    void addAircraft();
    void removeAircraft();
    void updateAircraft();
    Aircraft* findAircraft(int id);
    void displayInfo();
};
#endif