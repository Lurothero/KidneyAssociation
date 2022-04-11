#ifndef PATIENT_H
#define PATIENT_H

#include "baseperson.h"

class Patient : public BasePerson
{
public:
    Patient();

private:
    string socialSecurityNumber;
    string dateOfBirth;
    string gender;
    string address;
    string district;
    string patientStatus;
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
    string bloodType;
//    string urineSampleInfoID;
    string urineLeukocytes;
    string urineNitrite;
    string urineProtein;
    string urinePH;
    string urineBlood;
    string urineSG;
    string urineKetones;
    string urineGlucose;
    string urineBilirubin;

};

#endif // PATIENT_H
