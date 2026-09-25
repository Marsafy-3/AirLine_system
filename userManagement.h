#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include "User.h"
#include <vector>

using namespace std;

class UserManager
{
private:
    vector<User> users;

    void saveData();
    void loadData();

public:
    UserManager();

    void addUser();
    void removeUser();
    void updateUser();

    User* findUser(int id);

    void displayUsers();
};

#endif