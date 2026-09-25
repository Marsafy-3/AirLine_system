build:
	g++ main.cpp flight.cpp Reports.cpp maintain.cpp maintainManagement.cpp flightManagement.cpp reservation.cpp reservationManagement.cpp payment.cpp paymentManagement.cpp Passenger.cpp BookingAgent.cpp checkin.cpp passengerservice.cpp aircraft.cpp aircraftManagement.cpp crew.cpp crewManagement.cpp crewAssignment.cpp User.cpp userManagement.cpp authentication.cpp -o airline_system

run:
	./airline_system.exe