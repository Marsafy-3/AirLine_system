#ifndef FLIGHTMANAGEMENT_H
#define FLIGHTMANAGEMENT_H
#include"flight.h"
#include<vector>
class flightManager{
private:
vector<Flight>flights;
void saveData();
void loadData();
public:
flightManager();
void addFlight();
void updateFlight();
void removeFlight();
void updateFlightStatus();
void searchFlightsByCriteria();
Flight*findFlight(int flight_no);
bool decreaseAvailableSeats(int flightNumber);
void increaseAvailableSeats(int flightNumber);
void displayinfo();



};
#endif