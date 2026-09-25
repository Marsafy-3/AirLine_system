#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>
#include <vector>

using namespace std;

class Passenger
{
private:
    int id;
    string name;
    string email;
    string phone;

    vector<int> reservationIds;

    int loyaltyPoints;

public:
    Passenger();
    Passenger(int id, string name, string email, string phone);

    int getId() const;
    string getName() const;
    string getEmail() const;
    string getPhone() const;

    void setName(string name);
    void setEmail(string email);
    void setPhone(string phone);

    void addReservation(int reservationId);
    vector<int> getReservationIds() const;

    int getLoyaltyPoints() const;
    void addLoyaltyPoints(int points);
    bool useLoyaltyPoints(int points);

    void displayPassenger() const;
};
#endif