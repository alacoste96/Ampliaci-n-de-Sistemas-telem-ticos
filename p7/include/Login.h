#ifndef LOGIN_H
#define LOGIN_H

#include <ctime>
#include <iostream>
#include "UserDB.h"

/**
 * \file Login.h
 * \brief This file contains the declaration of the Login class.
 */

/**
 * \class Login
 * \brief Represents a login session.
 * 
 * This class represents a login session with functionalities for authentication.
 */
class Login{
private:
    int user_; /**< User NIF. */
    int passwd_; /**< Pasword(ID). */
public:
    /**
     * \brief Constructor for the Login class.
     * \param user_ User NIF.
     * \param passwd_ Password(ID).
     */
    Login(int user_ = 0, int passwd_ = 0);

    /**
     * \brief Authenticates the user.
     * \param userDB Pointer to the UserDB object containing user information.
     */
    void authenticate(UserDB *userDB);
    int getUser();
    int getPasswd();
    void setUser(int user);
    void setPasswd(int passwd);
};

#endif
