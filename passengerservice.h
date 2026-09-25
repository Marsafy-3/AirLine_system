#ifndef PASSENGERSERVICE_H
#define PASSENGERSERVICE_H

#include "Passenger.h"
#include "flightManagement.h"
#include "reservationManagement.h"
#include "checkin.h"

class PassengerService
{
private:
    Passenger& p;
    flightManager& f;
    ReservationManager& r;
    CheckIn& c;

public:
    PassengerService(
        Passenger& p,
        flightManager& fm,
        ReservationManager& rm,
        CheckIn& ci
    );

    void searchFlights();
    void viewMyReservations();
    void performCheckIn();
};

#endif