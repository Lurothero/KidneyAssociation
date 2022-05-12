/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef BASEUSER_H
#define BASEUSER_H

#include "baseperson.h"

#include <QString>

class BaseUser: public BasePerson
{
public:
    BaseUser();

private:
    QString userName; // data member to store userName
    QString password; // data member to store password
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
