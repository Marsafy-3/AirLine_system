#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>

using namespace std;


class Aircraft
{
private:

    int id;
    string model;
    int capacity;
    string status;


public:

    Aircraft(
        int i=0,
        string m="",
        int c=0,
        string s=""
    )
    : id(i), model(m), capacity(c), status(s)
    {

    }


    int getId()
    {
        return id;
    }


    void setId(int i)
    {
        id=i;
    }


    string getModel()
    {
        return model;
    }


    void setModel(string m)
    {
        model=m;
    }


    int getCapacity()
    {
        return capacity;
    }


    void setCapacity(int c)
    {
        capacity=c;
    }


    string getStatus()
    {
        return status;
    }


    void setStatus(string s)
    {
        status=s;
    }


    void displayAircraft()
    {
        cout<<"Aircraft ID: "<<id<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Capacity: "<<capacity<<endl;
        cout<<"Status: "<<status<<endl;
    }

};

#endif