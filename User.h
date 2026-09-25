#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
protected:
    int id;
    string name;
    string password;
    string role;

public:
    User(
        string n = "",
        int i = 0,
        string p = "",
        string r = ""
    )
        : name(n),
          id(i),
          password(p),
          role(r)
    {
    }

    virtual void displayMenu()
    {
        cout << "Hello, " << name << ", Welcome!" << endl;
    }

    int getId();
    void setId(int i);

    string getname();
    void setname(string n);

    string getpass();
    void setpass(string p);

    string getrole();
    void setrole(string r);
};

#endif