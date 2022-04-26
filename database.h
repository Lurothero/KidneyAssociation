#ifndef DATABASE_H
#define DATABASE_H

#include "userlibrary.h"
#include "appointmentlibrary.h"
#include "patientlibrary.h"
#include <QMessageBox>
#include "ui_doctorcontact.h"
class Database
{
public:
    Database();


    //Create Database functions here
    int loginUser(QString user, QString pass);//We are not concern about hiding data at this time
    void addDoctorInformation(QString FirstName, QString LastName, QString phoneNumber, QString emailAddress);
    void loadDoctorInformation(QString FirstName, QString LastName, QString phoneNumber, QString emailAddress);
    friend class Ui_DoctorContact;

    bool addPatient();


private:
    UserLibrary* UserLib;
    AppointmentLibrary* AppLib;
    PatientLibrary* PatLib;





};

#endif // DATABASE_H
