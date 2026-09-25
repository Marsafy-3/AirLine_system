#include "Passenger.h"
#include <iostream>

using namespace std;


Passenger::Passenger(){
    id = 0;
    name = "";
    email = "";
    phone = "";
    loyaltyPoints = 0;
}


Passenger::Passenger(int id, string name, string email, string phone){
    this->id = id;
    this->name = name;
    this->email = email;
    this->phone = phone;
    loyaltyPoints = 0;
}

int Passenger::getId() const
{
    return id;
}

string Passenger::getName() const
{
    return name;
}

string Passenger::getEmail() const
{
    return email;
}

string Passenger::getPhone() const
{
    return phone;
}


void Passenger::setName(string name)
{
    this->name = name;
}

void Passenger::setEmail(string email)
{
    this->email = email;
}

void Passenger::setPhone(string phone)
{
    this->phone = phone;
}



void Passenger::addReservation(int reservationId)
{
    reservationIds.push_back(reservationId);
}

vector<int> Passenger::getReservationIds() const
{
    return reservationIds;
}

int Passenger::getLoyaltyPoints() const
{
    return loyaltyPoints;
}

void Passenger::addLoyaltyPoints(int points)
{
    if (points > 0)
    {
        loyaltyPoints += points;
    }
}

bool Passenger::useLoyaltyPoints(int points)
{
    if (points <= 0 || points > loyaltyPoints)
    {
        return false;
    }

    loyaltyPoints -= points;
    return true;
}

void Passenger::displayPassenger() const
{
    cout << "Passenger ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "Loyalty Points: " << loyaltyPoints << endl;
}