#ifndef DATABASE_H
#define DATABASE_H

#include "userlibrary.h"
#include "appointmentlibrary.h"
#include "patientlibrary.h"


class Database
{
public:
    Database();


    //Create Database functions here
    int loginUser(QString user, QString pass);//We are not concern about hiding data at this time


private:
    UserLibrary* UserLib;
    AppointmentLibrary* AppLib;
    PatientLibrary* PatLib;





};

#endif // DATABASE_H
