#ifndef LOGIN_H
#define LOGIN_H

#include <ctime>
#include <iostream>
#include "UserDB.h"

class Login{
private:
    int user_;
    int passwd_;
public:
    Login(int user_ = 0, int passwd_ = 0);
    void authenticate(UserDB *userDB);
    int getUser();
    int getPasswd();
    void setUser(int user);
    void setPasswd(int passwd);
};

#endif