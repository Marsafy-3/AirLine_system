#include "Flight.h"
#include <iostream>

using namespace std;

Flight::Flight(int flightNumber,string departure,string destination,string departureTime,string arrivalTime,string status,int availableSeats){
    this->flightNumber = flightNumber;
    this->departure = departure;
    this->destination = destination;
    this->departureTime = departureTime;
    this->arrivalTime = arrivalTime;
    this->status = status;
    this->availableSeats = availableSeats;
}

int Flight::getFlightNumber(){
    return flightNumber;
}

string Flight::getDeparture(){
    return departure;
}

string Flight::getDestination(){
    return destination;
}

string Flight::getDepartureTime(){
    return departureTime;
}

string Flight::getArrivalTime(){
    return arrivalTime;
}

string Flight::getStatus(){
    return status;
}

int Flight::getAvailableSeats(){
    return availableSeats;
}

void Flight::setFlightNumber(int flightNumber){
    this->flightNumber = flightNumber;
}

void Flight::setDeparture(string departure){
    this->departure = departure;
}

void Flight::setDestination(string destination){
    this->destination = destination;
}

void Flight::setDepartureTime(string departureTime){
    this->departureTime = departureTime;
}

void Flight::setArrivalTime(string arrivalTime){
    this->arrivalTime = arrivalTime;
}

void Flight::setStatus(string status){
    this->status = status;
}

void Flight::setAvailableSeats(int availableSeats){
    this->availableSeats = availableSeats;
}

void Flight::displayFlight(){
    cout << "\nFlight Number: " << flightNumber << endl;
    cout << "Departure: " << departure << endl;
    cout << "Destination: " << destination << endl;
    cout << "Departure Time: " << departureTime << endl;
    cout << "Arrival Time: " << arrivalTime << endl;
    cout << "Status: " << status << endl;
    cout << "Available Seats: " << availableSeats << endl;
}