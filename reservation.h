#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>

using namespace std;

class Reservation
{
private:
    int reservationId;
    int passengerId;
    int flightNumber;
    int seatNumber;
    string status;

public:
    Reservation(
        int id = 0,
        int passenger = 0,
        int flight = 0,
        int seat = 0,
        string s = "Confirmed"
    );

    int getReservationId();
    int getPassengerId();
    int getFlightNumber();
    int getSeatNumber();
    string getStatus();

    void setPassengerId(int id);
    void setFlightNumber(int flight);
    void setSeatNumber(int seat);
    void setStatus(string s);

    void displayReservation();
};
#endif