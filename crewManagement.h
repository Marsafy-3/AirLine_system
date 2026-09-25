#ifndef CREW_MANAGEMENT_H
#define CREW_MANAGEMENT_H

#include "Crew.h"
#include <vector>
using namespace std;
class CrewManager {
private:
    vector<Crew> crews;
    void saveData();
    void loadData();

public:
    CrewManager();
    void addCrew();
    void removeCrew();
    void updateCrew();
    Crew* findCrew(int id);

    void displayCrews();
};
#endif