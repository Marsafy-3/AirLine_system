#include "payment.h"
#include <iostream>
using namespace std;

Payment::Payment(){
    paymentId = 0;
    reservationId = 0;
    amount = 0;
    method = "";
    status = "";
}
Payment::Payment(int paymentId, int reservationId, double amount, string method, string status){
    this->paymentId = paymentId;
    this->reservationId = reservationId;
    this->amount = amount;
    this->method = method;
    this->status = status;
}

int Payment::getPaymentId() const{
    return paymentId;
}

int Payment::getReservationId() const{
    return reservationId;
}

double Payment::getAmount() const{
    return amount;
}

string Payment::getMethod() const{
    return method;
}

string Payment::getStatus() const{
    return status;
}

void Payment::setStatus(string status){
    this->status = status;
}

void Payment::displayPayment() const{
    cout << "Payment ID: " << paymentId << endl;
    cout << "Reservation ID: " << reservationId << endl;
    cout << "Amount: " << amount << endl;
    cout << "Payment Method: " << method << endl;
    cout << "Status: " << status << endl;
}