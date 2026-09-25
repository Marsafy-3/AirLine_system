#ifndef CREW_ASSIGNMENT_H
#define CREW_ASSIGNMENT_H
#include <vector>
using namespace std;

class flightManager;
class CrewManager;

struct Assignment
{
    int flightNumber;
    int crewId;
};

class CrewAssignment
{
private:
    vector<Assignment> assignments;

    flightManager& fm;
    CrewManager& cm;

    void saveData();
    void loadData();

public:
    CrewAssignment(flightManager& fm, CrewManager& cm);

    void assignCrew();
    void removeAssignment();
    void displayAssignments();
};
#endif