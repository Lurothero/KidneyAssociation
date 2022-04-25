#include "baseperson.h"

BasePerson::BasePerson()
{

}

BasePerson::BasePerson( QString fname, QString lname, QString phone, QString email, int status)
{

    //setPersonID(id);//Set the id via a database on creation?
    setFirstName(fname);
    setLastName(lname);
    setPhoneNumber(phone);
    setEmail(email);
    setStatus(status);
}




int BasePerson::getPersonID()
{
    return personID;
}

QString BasePerson::getFirstName()
{

    return firstName;
}

QString BasePerson::getLastName()
{
    return lastName;
}

QString BasePerson::getPhoneNumber()
{
    return phoneNumber;
}

QString BasePerson::getEmail()
{

    return email;
}

int BasePerson::getStatus()
{
    return status;
}

void BasePerson::setPersonID(int id)
{
    personID = id;
}

void BasePerson::setFirstName(QString fname)
{
    firstName = fname;
}

void BasePerson::setLastName(QString lname)
{
    lastName =lname;
}

void BasePerson::setPhoneNumber(QString pnumber)
{
    phoneNumber = pnumber;
}

void BasePerson::setEmail(QString em)
{
    email = em;
}

void BasePerson::setStatus(int flag)
{
    status = flag;
}
