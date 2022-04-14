#ifndef BASEUSER_H
#define BASEUSER_H

#include "baseperson.h"

#include <QString>

class BaseUser: public BasePerson
{
public:
    BaseUser();

private:
    QString userName;//These should be replaced with QT Equivalent
    QString password;//These should be replaced with QT Equivalent
    int userLevel;

public:
    //--------------------------getters
    QString getUserName();
    QString getPassword();
    int getUserLevel();

    //--------------------------setters
    void setUserName(QString uname);
    void setPassword(QString pwd);
    void setUserLevel(QString userL);



};

#endif // BASEUSER_H
