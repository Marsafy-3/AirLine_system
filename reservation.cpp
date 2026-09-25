#include "reservation.h"
#include <iostream>

using namespace std;

Reservation::Reservation(
    int id,
    int passenger,
    int flight,
    int seat,
    string s
)
    : reservationId(id),
      passengerId(passenger),
      flightNumber(flight),
      seatNumber(seat),
      status(s)
{
}

int Reservation::getReservationId()
{
    return reservationId;
}

int Reservation::getPassengerId()
{
    return passengerId;
}

int Reservation::getFlightNumber()
{
    return flightNumber;
}

int Reservation::getSeatNumber()
{
    return seatNumber;
}

string Reservation::getStatus()
{
    return status;
}

void Reservation::setPassengerId(int id)
{
    passengerId = id;
}

void Reservation::setFlightNumber(int flight)
{
    flightNumber = flight;
}

void Reservation::setSeatNumber(int seat)
{
    seatNumber = seat;
}

void Reservation::setStatus(string s)
{
    status = s;
}

void Reservation::displayReservation()
{
    cout << "Reservation ID: " << reservationId << endl;
    cout << "Passenger ID: " << passengerId << endl;
    cout << "Flight Number: " << flightNumber << endl;
    cout << "Seat Number: " << seatNumber << endl;
    cout << "Status: " << status << endl;
}