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
    void insertingAppointmentData(int appoint_id, int doc_id, int patient_id, QString description, float cost, QString date);
    QList<QString> docRecord;
    QList<QString>docIds;
    QList<QString>patientIds;
    int currentID = 0;

    bool addPatientRecord(QString firstName, QString lastName, QString phoneNumber,
                          QString email, int status, QString socialSecurityNumber,
                          QString dateOfBirth, QString gender, QString address,
                          QString district, QString patientStatus, int bloodPressure,
                          int heartRate, int pulse, float bloodSugar, float weight,
                          bool diabetesType1, bool diabetesType2, bool eyeDamage,
                          int yearsWithDiabetes, int yearsWithHypertension, bool urinatingProblems,
                          QString bloodType, QString urineLeukocytes, QString urineNitrite,
                          QString urineProtein, QString urinePH, bool urineBlood, QString urineSG,
                          QString urineKetones, QString urineGlucose, QString urineBilirubin);


private:
    UserLibrary* UserLib;
    AppointmentLibrary* AppLib;
    PatientLibrary* PatLib;

};

#endif // DATABASE_H
