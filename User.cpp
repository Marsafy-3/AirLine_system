#include "User.h"

int User::getId()
{
    return id;
}

void User::setId(int i)
{
    id = i;
}

string User::getname()
{
    return name;
}

void User::setname(string n)
{
    name = n;
}

string User::getpass()
{
    return password;
}

void User::setpass(string p)
{
    password = p;
}

string User::getrole()
{
    return role;
}

void User::setrole(string r)
{
    role = r;
}