#include "reservationManagement.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
using namespace std;
using json = nlohmann::json;


ReservationManager::ReservationManager(flightManager& manager)
    : f(manager)
{
    loadData();
}

bool ReservationManager::addReservation(
    int reservationId,
    int passengerId,
    int flightNumber,
    int seatNumber
)
{    if (findReservation(reservationId) != nullptr)
    {
        cout << "Reservation ID already exists!" << endl;
        return false;
    }

    // Check flight exists
    if (f.findFlight(flightNumber) == nullptr)
    {
        cout << "Flight not found!" << endl;
        return false;
    }
    for ( auto& reservation : reservations)
    {
        if (reservation.getFlightNumber() == flightNumber && reservation.getSeatNumber() == seatNumber &&reservation.getStatus() != "Cancelled"
        )
        {
            cout << "Seat is already booked on this flight!" << endl;
            return false;
        }
    }
    f.decreaseAvailableSeats(flightNumber);

    Reservation r(
        reservationId,
        passengerId,
        flightNumber,
        seatNumber,
        "Confirmed"
    );

    reservations.push_back(r);

    saveData();

    cout << "Reservation created successfully!" << endl;

    return true;
}
Reservation* ReservationManager::findReservation(int reservationId)
{
    for (auto& r : reservations)
    {
        if (r.getReservationId() == reservationId)
        {
            return &r;
        }
    }

    return nullptr;
}


void ReservationManager::updateReservation()
{
    int reservationId;

    cout << "Enter reservation ID: ";
    cin >> reservationId;

    Reservation* r = findReservation(reservationId);

    if (r == nullptr)
    {
        cout << "Reservation not found!" << endl;
        return;
    }

    int newFlight;
    int newSeat;

    cout << "Enter new flight number: ";
    cin >> newFlight;

    
    if (f.findFlight(newFlight) == nullptr)
    {
        cout << "Flight not found!" << endl;
        return;
    }

    cout << "Enter new seat number: ";
    cin >> newSeat;

    r->setFlightNumber(newFlight);
    r->setSeatNumber(newSeat);

    saveData();

    cout << "Reservation updated successfully!" << endl;
}

bool ReservationManager::removeReservation(int reservationId){
    Reservation* r = findReservation(reservationId);

    if (r == nullptr)
    {
        cout << "Reservation not found!" << endl;
        return false;
    }

    if (r->getStatus() == "Cancelled")
    {
        cout << "Reservation is already cancelled!" << endl;
        return false;
    }

    f.increaseAvailableSeats(r->getFlightNumber());

    r->setStatus("Cancelled");

    saveData();

    cout << "Reservation cancelled successfully!" << endl;

    return true;
}


// Display All Reservations
void ReservationManager::displayReservations()
{
    if (reservations.empty())
    {
        cout << "No reservations found." << endl;
        return;
    }

    for (auto& r : reservations)
    {
        r.displayReservation();

        cout << "------------------------" << endl;
    }
}


// Search Reservations
void ReservationManager::searchReservations()
{
    int choice;

    cout << "1. Search by Passenger ID" << endl;
    cout << "2. Search by Flight Number" << endl;

    cout << "Enter choice: ";
    cin >> choice;


    // Search by Passenger ID
    if (choice == 1)
    {
        int passengerId;

        cout << "Enter passenger ID: ";
        cin >> passengerId;

        bool found = false;

        for (auto& r : reservations)
        {
            if (r.getPassengerId() == passengerId)
            {
                r.displayReservation();

                cout << "------------------------" << endl;

                found = true;
            }
        }

        if (!found)
        {
            cout << "No reservations found." << endl;
        }
    }


    // Search by Flight Number
    else if (choice == 2)
    {
        int flightNumber;

        cout << "Enter flight number: ";
        cin >> flightNumber;

        bool found = false;

        for (auto& r : reservations)
        {
            if (r.getFlightNumber() == flightNumber)
            {
                r.displayReservation();

                cout << "------------------------" << endl;

                found = true;
            }
        }

        if (!found)
        {
            cout << "No reservations found." << endl;
        }
    }

    else
    {
        cout << "Invalid choice!" << endl;
    }
}


// Save Data
void ReservationManager::saveData()
{
    json data = json::array();

    for (auto& r : reservations)
    {
        data.push_back({
            {"reservationId", r.getReservationId()},
            {"passengerId", r.getPassengerId()},
            {"flightNumber", r.getFlightNumber()},
            {"seatNumber", r.getSeatNumber()},
            {"status", r.getStatus()}
        });
    }

    ofstream file("reservations.json");

    if (!file)
    {
        cout << "Error opening reservations.json!" << endl;
        return;
    }

    file << data.dump(4);

    file.close();
}


// Load Data
void ReservationManager::loadData()
{
    ifstream file("reservations.json");

    // File does not exist yet
    if (!file)
    {
        return;
    }

    json data;

    file >> data;

    file.close();

    reservations.clear();

    for (auto& item : data)
    {
        Reservation r(
            item["reservationId"],
            item["passengerId"],
            item["flightNumber"],
            item["seatNumber"],
            item["status"]
        );

        reservations.push_back(r);
    }
}
bool ReservationManager::displayReservationsForPassenger(int passengerId)
{
    bool found = false;

    for (auto& reservation : reservations)
    {
        if (reservation.getPassengerId() == passengerId)
        {
            reservation.displayReservation();
            cout << "------------------------" << endl;

            found = true;
        }
    }

    return found;
}