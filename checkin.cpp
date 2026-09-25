#include "CheckIn.h"
#include <iostream>

using namespace std;

CheckIn::CheckIn(ReservationManager& rm,flightManager& fm): r(rm),f(fm){}

void CheckIn::checkingIn()
{
    int reservationId;

    cout << "\n===== Check-In =====" << endl;

    cout << "Enter Reservation ID: ";
    cin >> reservationId;

    Reservation* reservation = r.findReservation(reservationId);

    if (reservation == nullptr)
    {
        cout << "Reservation not found!" << endl;
        return;
    }

    if (reservation->getStatus() == "Cancelled")
    {
        cout << "Cannot check-in a cancelled reservation!" << endl;
        return;
    }

    int flightNumber = reservation->getFlightNumber();

    Flight* flight = f.findFlight(flightNumber);

    if (flight == nullptr)
    {
        cout << "Flight not found!" << endl;
        return;
    }

    reservation->setStatus("Checked-In");

    r.saveData();

    cout << "\n===== Boarding Pass =====" << endl;
    cout << "Reservation ID: "
         << reservation->getReservationId() << endl;

    cout << "Passenger ID: "
         << reservation->getPassengerId() << endl;

    cout << "Flight Number: "
         << reservation->getFlightNumber() << endl;

    cout << "Seat Number: "
         << reservation->getSeatNumber() << endl;

    cout << "Status: Checked-In" << endl;

    cout << "Check-in successful!" << endl;
}