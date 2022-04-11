#ifndef BASEUSER_H
#define BASEUSER_H

#include "baseperson.h"

class BaseUser: public BasePerson
{
public:
    BaseUser();

private:
    string userName;//These should be replaced with QT Equivalent
    string password;//These should be replaced with QT Equivalent
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
