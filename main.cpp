#include <iostream>
#include <string>
#include "Reports.h"
#include "maintainManagment.h"
#include "flightManagement.h"
#include "reservationManagement.h"
#include "paymentManagement.h"
#include "BookingAgent.h"
#include "checkin.h"
#include "Passenger.h"
#include "passengerservice.h"
#include "maintainManagment.h"

#include "aircraftManagement.h"

#include "crewManagement.h"
#include "crewAssignment.h"

#include "userManagement.h"
#include "authentication.h"

using namespace std;


// ================= PASSENGER MENU =================

void passengerMenu(
    PassengerService& passengerService,
    BookingAgent& bookingAgent
)
{
    int choice;

    do
    {
        cout << "\n==============================" << endl;
        cout << "       PASSENGER MENU          " << endl;
        cout << "==============================" << endl;

        cout << "1. Search Flight" << endl;
        cout << "2. View My Reservations" << endl;
        cout << "3. Check-In" << endl;
        cout << "4. Book Flight" << endl;
        cout << "5. Cancel Reservation" << endl;
        cout << "6. Logout" << endl;

        cout << "\nEnter choice: ";
        cin >> choice;


        switch(choice)
        {
        case 1:
            passengerService.searchFlights();
            break;


        case 2:
            passengerService.viewMyReservations();
            break;


        case 3:
            passengerService.performCheckIn();
            break;


        case 4:
            bookingAgent.bookFlight();
            break;


        case 5:
            bookingAgent.cancelReservation();
            break;


        case 6:
            cout << "Logging out..." << endl;
            break;


        default:
            cout << "Invalid choice!" << endl;
        }


    }while(choice != 6);
}



// ================= BOOKING AGENT MENU =================

void bookingAgentMenu(
    BookingAgent& bookingAgent,
    PassengerService& passengerService
)
{
    int choice;


    do
    {
        cout << "\n==============================" << endl;
        cout << "     BOOKING AGENT MENU        " << endl;
        cout << "==============================" << endl;


        cout << "1. Search Flight" << endl;
        cout << "2. Book Flight" << endl;
        cout << "3. Cancel Reservation" << endl;
        cout << "4. Logout" << endl;


        cout << "\nEnter choice: ";
        cin >> choice;


        switch(choice)
        {

        case 1:
            passengerService.searchFlights();
            break;


        case 2:
            bookingAgent.bookFlight();
            break;


        case 3:
            bookingAgent.cancelReservation();
            break;


        case 4:
            cout << "Logging out..." << endl;
            break;


        default:
            cout << "Invalid choice!" << endl;

        }


    }while(choice != 4);

}



// ================= ADMIN MENU =================

void adminMenu(

    flightManager& fm,
    AircraftManager& am,
    CrewManager& cm,
    CrewAssignment& ca,
    UserManager& um,
    MaintenanceManager& mm,
    Reports reports

)
{
    int choice;


    do
    {

        cout << "\n==============================" << endl;
        cout << "          ADMIN MENU           " << endl;
        cout << "==============================" << endl;



        cout << "\n--- Flight Management ---" << endl;

        cout << "1. Add Flight" << endl;
        cout << "2. Update Flight" << endl;
        cout << "3. Remove Flight" << endl;
        cout << "4. Display Flights" << endl;
        


        cout << "\n--- Aircraft Management ---" << endl;

        cout << "5. Add Aircraft" << endl;
        cout << "6. Update Aircraft" << endl;
        cout << "7. Remove Aircraft" << endl;
        cout << "8. Display Aircrafts" << endl;



        cout << "\n--- Crew Management ---" << endl;

        cout << "9. Add Crew" << endl;
        cout << "10. Update Crew" << endl;
        cout << "11. Remove Crew" << endl;
        cout << "12. Display Crews" << endl;



        cout << "\n--- Crew Assignment ---" << endl;

        cout << "13. Assign Crew" << endl;
        cout << "14. Remove Assignment" << endl;
        cout << "15. Display Assignments" << endl;
        
        
        
        cout << "\n--- User Management ---" << endl;
        
        cout << "16. Add User" << endl;
        cout << "17. Update User" << endl;
        cout << "18. Remove User" << endl;
        cout << "19. Display Users" << endl;
        cout << "20. Update Flight Status" << endl;
        cout << "\n21. Logout" << endl;
        cout << "\n--- Maintenance Management ---" << endl;

        cout << "22. Add Maintenance" << endl;
        cout << "23. Update Maintenance" << endl;
        cout << "24. Remove Maintenance" << endl;
        cout << "25. Display Maintenance" << endl;
        cout << "26. Logout" << endl;



        cout << "\nEnter choice: ";
        cin >> choice;



        switch(choice)
        {

        case 1:
            fm.addFlight();
            break;


        case 2:
            fm.updateFlight();
            break;


        case 3:
            fm.removeFlight();
            break;


        case 4:
            fm.displayinfo();
            break;



        case 5:
            am.addAircraft();
            break;


        case 6:
            am.updateAircraft();
            break;


        case 7:
            am.removeAircraft();
            break;


        case 8:
            am.displayInfo();
            break;



        case 9:
            cm.addCrew();
            break;


        case 10:
            cm.updateCrew();
            break;


        case 11:
            cm.removeCrew();
            break;


        case 12:
            cm.displayCrews();
            break;



        case 13:
            ca.assignCrew();
            break;


        case 14:
            ca.removeAssignment();
            break;


        case 15:
            ca.displayAssignments();
            break;



        case 16:
            um.addUser();
            break;


        case 17:
            um.updateUser();
            break;


        case 18:
            um.removeUser();
            break;


        case 19:
            um.displayUsers();
            break;



        case 20:
        fm.updateFlightStatus();
            break;
        case 21:
        cout << "Logging out..." << endl;
        case 22:
    mm.addMaintenance();
    break;

case 23:
    mm.updateMaintenance();
    break;

case 24:
    mm.removeMaintenance();
    break;

case 25:
    mm.displayMaintenance();
    break;
case 26:
reports.displayFinancialReport();

case 27:
    cout << "Logging out..." << endl;
    break;

        default:
            cout << "Invalid choice!" << endl;

        }


    }while(choice != 27);

}




// ================= MAIN =================


int main()
{
    flightManager fm;
    ReservationManager rm(fm);
    PaymentManager pm;
    AircraftManager am;
    UserManager um;
MaintenanceManager mm(am);
Reports reports(fm,rm,pm,mm,um);
CrewManager cm;
CrewAssignment ca(fm,cm);
Authentication auth(um);
Passenger passenger(

        1,

        "Ahmed",

        "ahmed@email.com",

        "01000000000"

    );




    // Services


    CheckIn checkIn(

        rm,

        fm

    );



    BookingAgent bookingAgent(

        rm,

        pm,

        passenger

    );



    PassengerService passengerService(

        passenger,

        fm,

        rm,

        checkIn

    );






    int choice;



    do
    {


        cout << "\n==============================" << endl;
        cout << "     AIRLINE MANAGEMENT        " << endl;
        cout << "==============================" << endl;


        cout << "1. Login" << endl;
        cout << "2. Exit" << endl;



        cout << "\nEnter choice: ";

        cin >> choice;



        switch(choice)

        {


        case 1:
        {

            User* currentUser = auth.login();



            if(currentUser == nullptr)

            {

                break;

            }



            cout << "\nWelcome "
                 << currentUser->getname()
                 << endl;



            cout << "Role: "
                 << currentUser->getrole()
                 << endl;




            if(currentUser->getrole() == "Admin")

            {

                adminMenu(fm,am,cm,ca,um,mm,reports);

            }



            else if(currentUser->getrole() == "Passenger")

            {

                passengerMenu(

                    passengerService,

                    bookingAgent

                );

            }



            else if(currentUser->getrole() == "BookingAgent")

            {

                bookingAgentMenu(

                    bookingAgent,

                    passengerService

                );

            }



            else

            {

                cout << "Unknown role!" << endl;

            }



            break;

        }




        case 2:

            cout << "Goodbye!" << endl;

            break;




        default:

            cout << "Invalid choice!" << endl;


        }



    }while(choice != 2);



    return 0;

}