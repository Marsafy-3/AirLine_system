#include "crew.h"
Crew::Crew(string n, int i, string r): name(n), id(i), role(r){}
int Crew::getId()const{
    return id;
}

void Crew::setId(int i){
    id = i;
}
string Crew::getName()const{
    return name;
}
void Crew::setName(string n){
    name = n;
}

string Crew::getRole()const{
    return role;
}

void Crew::setRole(string r){
    role = r;
}

void Crew::displayInfo(){
    cout << "Crew ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Role: " << role << endl;
}