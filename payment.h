#ifndef PAYMENT_H
#define PAYMENT_H
#include <string>
using namespace std;
class Payment{
private:
    int paymentId;
    int reservationId;
    double amount;
    string method;
    string status;

public:
    Payment();
    Payment(int paymentId, int reservationId, double amount,string method, string status);

    int getPaymentId() const;
    int getReservationId() const;
    double getAmount() const;
    string getMethod() const;
    string getStatus() const;

    void setStatus(string status);

    void displayPayment() const;
};
#endif