#include "Reports.h"

#include <iostream>

using namespace std;



Reports::Reports(
    flightManager& fm,
    ReservationManager& rm,
    PaymentManager& pm,
    MaintenanceManager& mm,
    UserManager& um
)
:
fm(fm),
rm(rm),
pm(pm),
mm(mm),
um(um)
{

}



// Flight Report

void Reports::displayFlightReport()
{
    cout << "\n===== Flight Report =====" << endl;

    fm.displayinfo();
}



// Reservation Report

void Reports::displayReservationReport()
{
    cout << "\n===== Reservation Report =====" << endl;

    rm.displayReservations();
}



// Financial Report

void Reports::displayFinancialReport()
{
    cout << "\n===== Financial Report =====" << endl;

    cout << "Payment report module connected." << endl;

    pm.displayPayments();
}



// Maintenance Report

void Reports::displayMaintenanceReport()
{
    cout << "\n===== Maintenance Report =====" << endl;

    mm.displayMaintenance();
}



// User Report

void Reports::displayUserReport()
{
    cout << "\n===== User Report =====" << endl;

    um.displayUsers();
}



// All Reports

void Reports::displayAllReports()
{

    displayFlightReport();

    displayReservationReport();

    displayFinancialReport();

    displayMaintenanceReport();

    displayUserReport();

}