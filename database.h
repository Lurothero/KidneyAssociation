#ifndef DATABASE_H
#define DATABASE_H

#include "userlibrary.h"
#include "appointmentlibrary.h"
#include "patientlibrary.h"

class Database
{
public:
    Database();

private:
    UserLibrary* UserLib;
    AppointmentLibrary* AppLib;
    PatientLibrary* PatLib;

};

#endif // DATABASE_H
