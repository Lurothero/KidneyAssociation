#ifndef PATIENT_H
#define PATIENT_H

#include "baseperson.h"

class Patient : public BasePerson
{
public:
    Patient();
    Patient(QString firstName,QString lastName,QString phoneNumber,QString email,int status,QString socialSecurityNumber,QString dateOfBirth, QString gender, QString address,QString district, QString patientStatus,  int bloodPressure, int heartRate,int pulse,float bloodSugar,float weight,bool diabetesType1,bool diabetesType2,bool eyeDamage,int yearsWithDiabetes,int yearsWithHypertension, bool urinatingProblems,QString bloodType,QString urineLeukocytes, QString urineNitrite,QString urineProtein, QString urinePH, QString urineBlood, QString urineSG,QString urineKetones,QString urineGlucose, QString urineBilirubin);




    //setters and getters
    QString getSSN();
    QString getDOB();
    QString getGender();
    QString getAddress();
    QString getDistrict();
    QString getPatientStatus();


    int getBloodPressure();
    int getHeartRate();
    int getPulse();//Doesnt Exist in table
    float getBloodSugar();
    float getWeight();
    bool getDiabetesType1();
    bool getDiabetesType2();
    bool getEyeDamage();
    int getYearsWithDiabetes();
    int getYearsWithHypertension();
    bool getUrinatingProblems();
    QString getBloodType();

    QString getUrineLeukocytes();
    QString getUrineNitrite();
    QString getUrineProtein();
    QString getUrinePH();
    QString getUrineBlood();
    QString getUrineSG();
    QString getUrineKetones();
    QString getUrineGlucose();
    QString getUrineBilirubin();


    //Setters
    void setSSN(QString ssn);
    void setDOB(QString dob);
    void setGender(QString g);
    void setAddress(QString addr);
    void setDistrict(QString district);
    void setPatientStatus(QString status);


    void setBloodPressure(int pressure);
    void setHeartRate(int rate);
    void setPulse(int pulse);
    void setBloodSugar(float sugar);
    void setWeight(float w);
    void setDiabetesType1(bool isDiabetic1);
    void setDiabetesType2(bool isDiabetic2);
    void setEyeDamage(bool isEyeDmg);
    void setYearsWithDiabetes(int years);
    void setYearsWithHypertension(int years);
    void setUrinatingProblems(bool UP);
    void setBloodType(QString type);

    void setUrineLeukocytes(QString L);
    void setUrineNitrite(QString N);
    void setUrineProtein(QString P);
    void setUrinePH(QString PH);
    void setUrineBlood(QString B);
    void setUrineSG(QString SG);
    void setUrineKetones(QString K);
    void setUrineGlucose(QString G);
    void setUrineBilirubin(QString B);


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
