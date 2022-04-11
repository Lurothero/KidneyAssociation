#ifndef BASEUSER_H
#define BASEUSER_H

#include "baseperson.h"

class BaseUser: public BasePerson
{
public:
    BaseUser();

private:
    string userName;
    string password;
    int userLevel;

public:
    //--------------------------getters
    string getUserName();
    string getPassword();
    int getUserLevel();

    //--------------------------setters
    void setUserName(string uname);
    void setPassword(string pwd);
    void setUserLevel(string userL);



};

#endif // BASEUSER_H
