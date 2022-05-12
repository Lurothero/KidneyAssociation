/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#include "baseperson.h"

BasePerson::BasePerson()
{

}

BasePerson::BasePerson( QString fname, QString lname, QString phone, QString email, int status)
{
    // sets all data members
    setFirstName(fname);
    setLastName(lname);
    setPhoneNumber(phone);
    setEmail(email);
    setStatus(status);
}




int BasePerson::getPersonID()
{
    return personID; // returns the person ID
}

QString BasePerson::getFirstName()
{

    return firstName; // returns the first name of the patient
}

QString BasePerson::getLastName()
{
    return lastName; // returns the last name of the patient
}

QString BasePerson::getPhoneNumber()
{
    return phoneNumber; // returns the phone number of the patient
}

QString BasePerson::getEmail()
{

    return email; // returns the email address
}

int BasePerson::getStatus()
{
    return status; // returns the status of the patient
}

void BasePerson::setPersonID(int id)
{
    personID = id; // sets the person ID
}

void BasePerson::setFirstName(QString fname)
{
    firstName = fname; // sets the first name
}

void BasePerson::setLastName(QString lname)
{
    lastName =lname; // sets the last name
}

void BasePerson::setPhoneNumber(QString pnumber)
{
    phoneNumber = pnumber; // sets the phone number
}

void BasePerson::setEmail(QString em)
{
    email = em; // sets the email address
}

void BasePerson::setStatus(int flag)
{
    status = flag; // sets the status
}
