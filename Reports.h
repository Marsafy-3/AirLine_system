#ifndef REPORTS_H
#define REPORTS_H

#include "flightManagement.h"
#include "reservationManagement.h"
#include "paymentManagement.h"
#include "maintainManagment.h"
#include "userManagement.h"

class Reports
{

private:

    flightManager& fm;
    ReservationManager& rm;
    PaymentManager& pm;
    MaintenanceManager& mm;
    UserManager& um;


public:

    Reports(
        flightManager& fm,
        ReservationManager& rm,
        PaymentManager& pm,
        MaintenanceManager& mm,
        UserManager& um
    );


    void displayFlightReport();

    void displayReservationReport();

    void displayFinancialReport();

    void displayMaintenanceReport();

    void displayUserReport();


    void displayAllReports();

};

#endif