#ifndef PATIENT_H
#define PATIENT_H

#include "baseperson.h"

class Patient : public BasePerson
{
public:
    Patient();
    Patient(QString firstName,QString lastName,QString phoneNumber,QString email,int status,QString socialSecurityNumber,QString dateOfBirth, QString gender, QString address,QString district, QString patientStatus,  int bloodPressure, int heartRate,int pulse,float bloodSugar,float weight,bool diabetesType1,bool diabetesType2,bool eyeDamage,int yearsWithDiabetes,int yearsWithHypertension, bool urinatingProblems,QString bloodType,   QString urineLeukocytes, QString urineNitrite,QString urineProtein, QString urinePH, QString urineBlood, QString urineSG,QString urineKetones,QString urineGlucose, QString urineBilirubin);

private:

    //Get all of the patient details

    //ALL EXIST IN BASEPERSON

    //QString firstName;
    //QString lastName;
    //QString telephoneNumber;
    //QString email;
    //int status;



    QString socialSecurityNumber;
    QString dateOfBirth;
    QString gender;
    QString address;
    QString district;
    QString patientStatus;



    int bloodPressure;
    int heartRate;
    int pulse;//Doesnt Exist in table
    float bloodSugar;
    float weight;
    bool diabetesType1;
    bool diabetesType2;
    bool eyeDamage;
    int yearsWithDiabetes;
    int yearsWithHypertension;
    bool urinatingProblems;
    QString bloodType;





//    string urineSampleInfoID;
    QString urineLeukocytes;
    QString urineNitrite;
    QString urineProtein;
    QString urinePH;
    QString urineBlood;
    QString urineSG;
    QString urineKetones;
    QString urineGlucose;
    QString urineBilirubin;

};

#endif // PATIENT_H
