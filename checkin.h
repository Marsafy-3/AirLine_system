#ifndef CHECKIN_H
#define CHECKIN_H

#include "reservationManagement.h"
#include "flightManagement.h"

class CheckIn
{
private:
    ReservationManager& r;
    flightManager& f;

public:
    CheckIn(ReservationManager& rm,flightManager& fm);

    void checkingIn();
};

#endif