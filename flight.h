#ifndef FLIGHT_H
#define FLIGHT_H
#include <string>
using namespace std;
class Flight{
private:
int flightNumber;
string departure;
string destination;
string departureTime;
string arrivalTime;
string status;
int availableSeats;

public:
Flight(int flightNumber = 0,
           string departure = "",
           string destination = "",
           string departureTime = "",
           string arrivalTime = "",
           string status = "Scheduled",
           int availableSeats = 0);

    int getFlightNumber();
    string getDeparture();
    string getDestination();
    string getDepartureTime();
    string getArrivalTime();
    string getStatus();
    int getAvailableSeats();

    void setFlightNumber(int flightNumber);
    void setDeparture(string departure);
    void setDestination(string destination);
    void setDepartureTime(string departureTime);
    void setArrivalTime(string arrivalTime);
    void setStatus(string status);
    void setAvailableSeats(int availableSeats);
    void displayFlight();
};
#endif