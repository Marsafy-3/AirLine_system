========================================
Airline Reservation & Management System
========================================
A console-based airline management system written in C++ using object-oriented design. It supports three user roles (Admin, Booking Agent, Passenger) and covers flight scheduling, reservations, payments, check-in, crew assignment, aircraft maintenance, and reporting. All data persists between runs as JSON files.
==========
Features
==========
Admin:

Flights: add, update, remove, display, and update flight status
Aircraft: add, update, remove, display
Crew: add, update, remove, display
Crew assignment: assign crew to flights, remove assignments, display assignments
Users: add, update, remove, display
Maintenance: add, update, remove, and display maintenance records linked to aircraft
Reports: flight, reservation, financial, maintenance, and user reports
========================================================================================
Booking Agent
Search flights
Book a flight (reservation followed by payment)
Cancel a reservation
========================================================================================
Passenger
Search flights by departure, destination, departure time, or status
View own reservations
Check in for a flight
Book a flight and cancel a reservation
System behavior
ID and password login with role-based menu routing
Duplicate seat prevention: a seat already booked on a flight is rejected
Available seats decrease on booking and increase on cancellation
Check-in is rejected for cancelled reservations
Crew assignment and maintenance records are validated against existing flights and aircraft
=========================================================================================
Architecture

Each domain has an entity class and a manager class. Managers receive their dependencies through constructors (dependency injection), which keeps modules decoupled.

Domain	              Entity Manager / Service
Flights	              Flight--flightManager
Reservations	        Reservation--ReservationManager
Payments	            Payment--PaymentManager
Aircraft	            Aircraft--AircraftManager
Maintenance	          Maintenance--MaintenanceManager
Crew	               	CrewManager--CrewAssignment
Users		              UserManager--Authentication
Passenger             workflow--Passenger--PassengerService--BookingAgent--CheckIn
Reporting	           	Reports
=====================================================================================
main.cpp wires the managers together, handles login, and routes each user to the menu for their role.

Project structure
AirLine/
├── main.cpp                  # Entry point, login, role menus
├── flight.*  flightManagement.*
├── reservation.*  reservationManagement.*
├── payment.*  paymentManagement.*
├── aircraft.*  aircraftManagement.*
├── maintain.*  maintainManagement.* / maintainManagment.h
├── crew.*  crewManagement.*  crewAssignment.*
├── User.*  userManagement.*  authentication.*
├── Passenger.*  passengerservice.*  BookingAgent.*  checkin.*
├── Reports.*
├── json.hpp                  # nlohmann/json (single header)
├── *.json                    # Persistent data files
└── Makefile
=====================================================================================
Tech stack
===========
C++ (C++11 or later)
nlohmann/json for JSON serialization
Make and g++ for building
Git / GitHub for version control
=================================
Build and run
===============
Windows (MinGW g++):
make build
./airline_system.exe
