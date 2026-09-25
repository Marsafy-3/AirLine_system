#include "User.h"
#include "userManagement.h"
#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
class Authentication
{
private:
    UserManager& userManager;

public:
    Authentication(UserManager& manager);

    User* login();
};
#endif