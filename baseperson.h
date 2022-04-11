#ifndef BASEPERSON_H
#define BASEPERSON_H

#include <iostream>
#include <string>//These should be replaced with QT Equivalent
using std::string;//These should be replaced with QT Equivalent
using std::cout;
using std::endl;
using std::cin;

class BasePerson
{
public:
    BasePerson();

private:
    int personID;
    string firstName;//These should be replaced with QT Equivalent
    string lastName;//These should be replaced with QT Equivalent
    string phoneNumber;//These should be replaced with QT Equivalent
    string email;//These should be replaced with QT Equivalent
    int status;

public:
    //--------------------------getters
    int getPersonID();
    string getFirstName();
    string getLastName();
    string getPhoneNumber();
    string getEmail();
    int getStatus();

    //--------------------------setters
    void setPersonID(int id);
    void setFirstName(string fname);
    void setLastName(string lname);
    void setPhoneNumber(string pnumber);
    void setEmail(string em);
    void setStatus(int flag);


};

#endif // BASEPERSON_H
