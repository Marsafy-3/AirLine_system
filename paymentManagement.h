#ifndef PAYMENTMANAGEMENT_H
#define PAYMENTMANAGEMENT_H
#include "payment.h"
#include <vector>

using namespace std;

class PaymentManager{
private:
    vector<Payment> payments;

    void saveData();
    void loadData();

public:
PaymentManager();
void processPayment(int paymentId,int reservationId,double amount,string method);
void processPayment();
void refundPayment();
bool refundPaymentByReservationId(int reservationId);
Payment* findPayment(int paymentId);
void displayPayments();
};
#endif