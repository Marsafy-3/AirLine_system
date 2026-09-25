#ifndef RESERVATIONMANAGEMENT_H
#define RESERVATIONMANAGEMENT_H
#include "reservation.h"
#include "flightManagement.h"

#include <vector>

using namespace std;

class ReservationManager
{
private:
    vector<Reservation> reservations;

    flightManager& f;

    
    public:
    void saveData();
    void loadData();
    ReservationManager(flightManager& fm);

    bool addReservation(int reservationId,int passengerId,int flightNumber,int seatNumber);
    void updateReservation();
    bool removeReservation(int reservationId);
    bool displayReservationsForPassenger(int passengerId);
  Reservation* findReservation(int reservationId);
    void displayReservations();
    void searchReservations();
};
#endif