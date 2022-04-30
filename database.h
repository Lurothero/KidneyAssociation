#ifndef DATABASE_H
#define DATABASE_H

#include "userlibrary.h"
#include "appointmentlibrary.h"
#include "patientlibrary.h"
#include <QMessageBox>
#include "ui_doctorcontact.h"
#include <QStringList>
#include <QList>
#include <QDebug>
class Database
{
public:
    Database();


    //Create Database functions here
    int loginUser(QString user, QString pass);//We are not concern about hiding data at this time
    void addDoctorInformation(QString FirstName, QString LastName, QString phoneNumber, QString emailAddress);
    void loadDoctorInformation();
    void loadDoctorIds();
    void loadPatientIds();
    void deleteDoctorInformation(int row);
    void indexingDoctorData();
    void insertingAppointmentData(int appoint_id,int doc_id, int patient_id, QString description, float cost, QString date);
    QList<QString> docRecord;
    QList<QString>docIds;
    QList<QString>patientIds;
    int currentID = 0;

    bool addPatient();


private:
    UserLibrary* UserLib;
    AppointmentLibrary* AppLib;
    PatientLibrary* PatLib;

};

#endif // DATABASE_H
