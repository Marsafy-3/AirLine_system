#include <iostream>
#include "BookingAgent.h"

using namespace std;

BookingAgent::BookingAgent(
    ReservationManager& rm,
    PaymentManager& pm,
    Passenger& pa
)
    : r(rm),
      p(pm),
      passenger(pa)
{
}

void BookingAgent::bookFlight()
{
    int paymentId;
    int reservationId;
    int passengerId;
    int flightNumber;
    int seatNumber;

    double amount;
    string method;

    passengerId = passenger.getId();

    cout << "Enter reservation ID: ";
    cin >> reservationId;

    cout << "Enter flight number: ";
    cin >> flightNumber;

    cout << "Enter seat number: ";
    cin >> seatNumber;

    bool bookingsucc = r.addReservation(
        reservationId,
        passengerId,
        flightNumber,
        seatNumber
    );

    if (!bookingsucc)
    {
        cout << "Booking failed!" << endl;
        return;
    }

    cout << "Enter payment ID: ";
    cin >> paymentId;

    cout << "Enter payment amount: ";
    cin >> amount;

    cout << "Enter payment method: ";
    cin >> method;

    p.processPayment(
        paymentId,
        reservationId,
        amount,
        method
    );

    passenger.addReservation(reservationId);

    cout << "Booking completed successfully!" << endl;
}


void BookingAgent::cancelReservation()
{
    int reservationId;

    cout << "Enter reservation ID: ";
    cin >> reservationId;

    bool cancelled = r.removeReservation(reservationId);

    if (!cancelled)
    {
        cout << "Cancellation failed!" << endl;
        return;
    }

    bool refunded = p.refundPaymentByReservationId(reservationId);

    if (!refunded)
    {
        cout << "Reservation cancelled, but refund failed!" << endl;
        return;
    }

    cout << "Cancellation completed successfully!" << endl;
}