#include "PassengerService.h"
#include <iostream>

using namespace std;

PassengerService::PassengerService(Passenger& pa,flightManager& fm,ReservationManager& rm,CheckIn& ci): p(pa),f(fm),r(rm),c(ci){}

 void PassengerService::searchFlights()
{
    f.searchFlightsByCriteria();
}

void PassengerService::viewMyReservations()
{
    bool found =r.displayReservationsForPassenger(p.getId());
    if (!found)
    {
        cout << "No reservations found." << endl;
    }
}

void PassengerService::performCheckIn()
{
    c.checkingIn();
}