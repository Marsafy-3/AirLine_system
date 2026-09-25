#include "flightManagement.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
using namespace std;
using json = nlohmann::json;
flightManager::flightManager()
{
    loadData();
}
void flightManager::saveData()
{
    json j = json::array();

    for (Flight& flight : flights)
    {
        json flightData;

        flightData["flightNumber"] = flight.getFlightNumber();
        flightData["departure"] = flight.getDeparture();
        flightData["destination"] = flight.getDestination();
        flightData["departureTime"] = flight.getDepartureTime();
        flightData["arrivalTime"] = flight.getArrivalTime();
        flightData["status"] = flight.getStatus();
        flightData["availableSeats"] = flight.getAvailableSeats();

        j.push_back(flightData);
        
    }

    ofstream file("flights.json");

    if (!file)
    {
        cout << "Error opening flights.json\n";
        return;
    }

    file << j.dump(4);

    file.close();
}
void flightManager::loadData()
{
    ifstream file("flights.json");

    if (!file)
    {
        cout << "No flight data found.\n";
        return;
    }

    json j;
    file >> j;

    flights.clear();

    for (auto& flightData : j)
    {
        Flight flight(
            flightData["flightNumber"],
            flightData["departure"],
            flightData["destination"],
            flightData["departureTime"],
            flightData["arrivalTime"],
            flightData["status"],
            flightData["availableSeats"]
        );

        flights.push_back(flight);
    }

    file.close();
}
void flightManager:: addFlight(){
int f;
string dep;
string des;
string dt;
string at;
string s;
int seats;
cout<<"Enter flight #: "<<endl;
cin>>f;
cout<<"Enter departure: "<<endl;
cin>>dep;
cout<<"Enter destination: "<<endl;
cin>>des;
cout<<"Enter departure time: "<<endl;
cin>>dt;
cout<<"Enter arrival time: "<<endl;
cin>>at;
cout<<"Enter status: "<<endl;
cin>>s;
cout<<"Enter Available seats: "<<endl;
cin>>seats;
Flight f1 (f,dep,des,dt,at,s,seats);
flights.push_back(f1);
saveData();
}
void flightManager::updateFlight()
{
    int flight_no;

    cout << "Enter Flight # that you want to update: ";
    cin >> flight_no;

    for (auto it = flights.begin(); it != flights.end(); ++it)
    {
        if (it->getFlightNumber() == flight_no)
        {
            int choice;

            cout << "What do you want to update?\n";
            cout << "1. Flight #\n";
            cout << "2. Departure\n";
            cout << "3. Destination\n";
            cout << "4. Departure Time\n";
            cout << "5. Arrival Time\n";
            cout << "6. Status\n";
            cout << "7. Available Seats\n";

            cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    int f;
                    cout << "Enter new Flight #: ";
                    cin >> f;
                    it->setFlightNumber(f);
                    break;
                }

                case 2:
                {
                    string dep;
                    cout << "Enter new departure: ";
                    cin >> dep;
                    it->setDeparture(dep);
                    break;
                }

                case 3:
                {
                    string des;
                    cout << "Enter new destination: ";
                    cin >> des;
                    it->setDestination(des);
                    break;
                }

                case 4:
                {
                    string dt;
                    cout << "Enter new departure time: ";
                    cin >> dt;
                    it->setDepartureTime(dt);
                    break;
                }

                case 5:
                {
                    string at;
                    cout << "Enter new arrival time: ";
                    cin >> at;
                    it->setArrivalTime(at);
                    break;
                }

                case 6:
                {
                    string s;
                    cout << "Enter new status: ";
                    cin >> s;
                    it->setStatus(s);
                    break;
                }

                case 7:
                {
                    int seats;
                    cout << "Enter new available seats: ";
                    cin >> seats;
                    it->setAvailableSeats(seats);
                    break;
                }

                default:
                    cout << "Invalid choice.\n";
                    return;
            }
            saveData();
            cout << "Flight updated successfully.\n";
            return;
        }
        
    }

    cout << "Flight not found.\n";
}
void flightManager::removeFlight(){
int fn;
cout<<"Enter flight nubmer you want to erase: ";
cin>>fn;
for(auto it=flights.begin();it!=flights.end();++it){

if(it->getFlightNumber()==fn){
    flights.erase(it);
    saveData();
    cout << "Flight removed successfully.\n";
    
            return;
        }
        
}
cout<<"Flight not found"<<endl;
}
Flight* flightManager::findFlight(int flight_no){

for (auto it=flights.begin();it!=flights.end();++it){
if (it->getFlightNumber()==flight_no){
    cout<<"Flight found!"<<"\n";
    return &(*it);//&
}
}
return nullptr;
}
void flightManager::displayinfo(){
for (auto it=flights.begin();it!=flights.end();++it){   
    it->displayFlight();
}
}
bool flightManager::decreaseAvailableSeats(int flightNumber)
{
    for (auto& flight : flights)
    {
        if (flight.getFlightNumber() == flightNumber)
        {
            if (flight.getAvailableSeats() <= 0)
            {
                cout << "No available seats on this flight!" << endl;
                return false;
            }

            flight.setAvailableSeats(
                flight.getAvailableSeats() - 1
            );

            saveData();

            return true;
        }
    }

    cout << "Flight not found!" << endl;
    return false;
}
void flightManager::increaseAvailableSeats(int flightNumber)
{
    for (auto& flight : flights)
    {
        if (flight.getFlightNumber() == flightNumber)
        {
            flight.setAvailableSeats(
                flight.getAvailableSeats() + 1
            );

            saveData();
            return;
        }
    }
}

void flightManager::searchFlightsByCriteria()
{
    int choice;

    cout << "\n===== Search Flight =====" << endl;
    cout << "1. Search by Departure" << endl;
    cout << "2. Search by Destination" << endl;
    cout << "3. Search by Departure Time" << endl;
    cout << "4. Search by Status" << endl;

    cout << "Enter choice: ";
    cin >> choice;


    bool found = false;


    if(choice == 1)
    {
        string departure;

        cout << "Enter departure: ";
        cin >> departure;


        for(auto& flight : flights)
        {
            if(flight.getDeparture() == departure)
            {
                flight.displayFlight();
                cout << "--------------------" << endl;
                found = true;
            }
        }
    }


    else if(choice == 2)
    {
        string destination;

        cout << "Enter destination: ";
        cin >> destination;


        for(auto& flight : flights)
        {
            if(flight.getDestination() == destination)
            {
                flight.displayFlight();
                cout << "--------------------" << endl;
                found = true;
            }
        }
    }


    else if(choice == 3)
    {
        string time;

        cout << "Enter departure time: ";
        cin >> time;


        for(auto& flight : flights)
        {
            if(flight.getDepartureTime() == time)
            {
                flight.displayFlight();
                cout << "--------------------" << endl;
                found = true;
            }
        }
    }


    else if(choice == 4)
    {
        string status;

        cout << "Enter status: ";
        cin >> status;


        for(auto& flight : flights)
        {
            if(flight.getStatus() == status)
            {
                flight.displayFlight();
                cout << "--------------------" << endl;
                found = true;
            }
        }
    }


    else
    {
        cout << "Invalid choice!" << endl;
        return;
    }


    if(!found)
    {
        cout << "No flights found!" << endl;
    }
}
void flightManager::updateFlightStatus()
{
    int flightNumber;

    cout << "Enter flight number: ";
    cin >> flightNumber;


    Flight* flight = findFlight(flightNumber);


    if(flight == nullptr)
    {
        cout << "Flight not found!" << endl;
        return;
    }
    int choice;
    cout << "\nSelect new status:" << endl;
    cout << "1. Scheduled" << endl;
    cout << "2. Delayed" << endl;
    cout << "3. Cancelled" << endl;
    cout << "4. Completed" << endl;

    cout << "Enter choice: ";
    cin >> choice;
    string status;
    switch(choice)
    {
        case 1:
            status = "Scheduled";
            break;

        case 2:
            status = "Delayed";
            break;

        case 3:
            status = "Cancelled";
            break;

        case 4:
            status = "Completed";
            break;

        default:
            cout << "Invalid choice!" << endl;
            return;
    }
    flight->setStatus(status);
    cout << "Flight status updated successfully!" << endl;
    saveData();
}