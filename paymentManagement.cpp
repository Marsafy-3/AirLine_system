#include "paymentManagement.h"
#include "json.hpp"

#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

PaymentManager::PaymentManager()
{
    loadData();
}

void PaymentManager::processPayment(
    int paymentId,
    int reservationId,
    double amount,
    string method
)
{
    if (findPayment(paymentId) != nullptr)
    {
        cout << "Payment ID already exists." << endl;
        return;
    }

    Payment p(
        paymentId,
        reservationId,
        amount,
        method,
        "Paid"
    );

    payments.push_back(p);

    saveData();

    cout << "Payment processed successfully." << endl;
}
void PaymentManager::refundPayment()
{
    int paymentId;

    cout << "Enter payment ID: ";
    cin >> paymentId;

    Payment* payment = findPayment(paymentId);

    if (payment == nullptr)
    {
        cout << "Payment not found." << endl;
        return;
    }

    if (payment->getStatus() == "Refunded")
    {
        cout << "Payment is already refunded." << endl;
        return;
    }

    payment->setStatus("Refunded");

    saveData();

    cout << "Payment refunded successfully." << endl;
}

Payment* PaymentManager::findPayment(int paymentId)
{
    for (auto& payment : payments)
    {
        if (payment.getPaymentId() == paymentId)
        {
            return &payment;
        }
    }

    return nullptr;
}

void PaymentManager::displayPayments()
{
    if (payments.empty())
    {
        cout << "No payments found." << endl;
        return;
    }

    for (auto& payment : payments)
    {
        payment.displayPayment();
        cout << "------------------------" << endl;
    }
}

void PaymentManager::saveData()
{
    json data = json::array();

    for (auto& payment : payments)
    {
        json p;

        p["paymentId"] = payment.getPaymentId();
        p["reservationId"] = payment.getReservationId();
        p["amount"] = payment.getAmount();
        p["method"] = payment.getMethod();
        p["status"] = payment.getStatus();

        data.push_back(p);
    }

    ofstream file("payments.json");

    if (!file.is_open())
    {
        cout << "Error opening payments.json" << endl;
        return;
    }

    file << data.dump(4);

    file.close();
}

void PaymentManager::loadData()
{
    ifstream file("payments.json");

    if (!file.is_open())
    {
        return;
    }

    json data;
    file >> data;

    payments.clear();

for (auto& p : data){
Payment payment(
p["paymentId"],
p["reservationId"],
p["amount"],
p["method"],
p["status"]
);

        payments.push_back(payment);
    }

    file.close();
}
bool PaymentManager::refundPaymentByReservationId(int reservationId)
{
    for (auto& payment : payments)
    {
        if (payment.getReservationId() == reservationId)
        {
            if (payment.getStatus() == "Refunded")
            {
                cout << "Payment is already refunded." << endl;
                return false;
            }

            payment.setStatus("Refunded");

            saveData();

            cout << "Payment refunded successfully." << endl;

            return true;
        }
    }

    cout << "Payment for this reservation not found." << endl;

    return false;
}