#ifndef CREW_H
#define CREW_H
#include <iostream>
#include <string>
using namespace std;
class Crew {
protected:
    int id;
    string name;
    string role;
public:
    Crew(string n = "", int i = 0, string r = "");
    int getId()const;
    void setId(int i);
    string getName()const;
    void setName(string n);
    string getRole()const;
    void setRole(string r);
    void displayInfo();
};
#endif