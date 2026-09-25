#ifndef BOOKINGAGENT_H
#define BOOKINGAGENT_H
#include "reservationManagement.h"
#include "paymentManagement.h"
#include "Passenger.h"

class BookingAgent
{
private:
    ReservationManager& r;
    PaymentManager& p;
    Passenger& passenger;

public:
    BookingAgent(
        ReservationManager& rm,
        PaymentManager& pm,
        Passenger& pa
    );

    void bookFlight();
    void cancelReservation();
};
#endif