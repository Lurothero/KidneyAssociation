/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef DATABASE_H
#define DATABASE_H

#include "userlibrary.h"
#include "appointmentlibrary.h"
#include "patientlibrary.h"
#include <QMessageBox>
#include "ui_doctorcontact.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QStringList>
#include <QList>
#include <QDebug>
#include <iomanip>
using std::setw;

class Database
{
public:
    Database();

    // Functions created to login user, loading doctor information and so on from the database
    int loginUser(QString user, QString pass);
    void addDoctorInformation(QString FirstName, QString LastName, QString phoneNumber, QString emailAddress);
    void loadDoctorInformation();
    void loadDoctorIds();
    void loadPatientIds();
    void loadAppointmentRecords();
    void loadAppointDescription();
    void deleteDoctorInformation(int row);
    void indexingDoctorData();
    void insertingAppointmentData(int appoint_id, int doc_id, int patient_id, QString description, float cost, QString date);
    void loadSocialSecurityNumbers();
    void loadStatus();
    void loadPatientBloodType();
    void loadDistrictList();
    void EditPatientRecord(int SSN,QString FName, QString LName, QString phoneNumber, QString DOB, QString Address);
    void selectedSSN(int SSN); // selects SSN from combobox
    QString FirstName,LastName,PhoneNumber,DOB,Address;

    // Vectors to store a list of doctor Ids, records, social security and so on
    QList<QString> docRecord;
    QList<QString>docIds;
    QList<QString>patientIds;
    QList<QString>appointRecord;
    QList<QString>AppointDescription;
    QList<QString>patientLocations;
    QList<QString>SocialSecurityNumbers;
    QList<QString>StatusList;
    QList<QString>patientBloodTypes;

    int currentID = 0;



    bool addPatientRecord(QString firstName, QString lastName, QString phoneNumber,
                          QString email, int status, QString socialSecurityNumber,
                          QString dateOfBirth, QString gender, QString address,
                          QString district, QString patientStatus, int bloodPressure,
                          int heartRate, float bloodSugar, float weight,
                          bool diabetesType1, bool diabetesType2, bool eyeDamage,
                          int yearsWithDiabetes, int yearsWithHypertension, bool urinatingProblems,
                          QString urinatingProblem_Description,
                          QString bloodType, QString urineLeukocytes, QString urineNitrite,
                          QString urineProtein, QString urinePH, bool urineBlood, QString urineSG,
                          QString urineKetones, QString urineGlucose, QString urineBilirubin);

private:
    UserLibrary* UserLib;
    AppointmentLibrary* AppLib;
    PatientLibrary* PatLib;

};

#endif // DATABASE_H
