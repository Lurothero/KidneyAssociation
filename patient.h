#ifndef PATIENT_H
#define PATIENT_H

#include "baseperson.h"

class Patient : public BasePerson
{
public:
    Patient();

private:
    //Better separation? to resemble the database table instead
    QString socialSecurityNumber;
    QString dateOfBirth;
    QString gender;
    QString address;
    QString district;
    QString patientStatus;

    int bloodPressure;
    int heartRate;
    int pulse;
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
