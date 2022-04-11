#ifndef BASEPERSON_H
#define BASEPERSON_H

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;

class BasePerson
{
public:
    BasePerson();

private:
    int personID;
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
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
