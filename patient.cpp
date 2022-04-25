#include "patient.h"

Patient::Patient()
{

}

Patient::Patient(QString firstName, QString lastName, QString phoneNumber,
                 QString email, int status, QString socialSecurityNumber,
                 QString dateOfBirth, QString gender, QString address,
                 QString district, QString patientStatus, int bloodPressure,
                 int heartRate, int pulse, float bloodSugar, float weight,
                 bool diabetesType1, bool diabetesType2, bool eyeDamage,
                 int yearsWithDiabetes, int yearsWithHypertension, bool urinatingProblems,
                 QString bloodType, QString urineLeukocytes, QString urineNitrite,
                 QString urineProtein, QString urinePH, QString urineBlood, QString urineSG,
                 QString urineKetones, QString urineGlucose, QString urineBilirubin)

                 :BasePerson( firstName,  lastName,  phoneNumber,  email,  status)
{


    //Setting our data
    setFirstName(firstName);
    setLastName(lastName);
    setPhoneNumber(phoneNumber);
    setEmail(email);
    setStatus(status);
    setSSN(socialSecurityNumber);
    setDOB(dateOfBirth);
    setGender(gender);
    setAddress(address);
    setDistrict(district);
    setPatientStatus(patientStatus);
    setBloodPressure(bloodPressure);
    setHeartRate(heartRate);
    setPulse(pulse);
    setBloodSugar(bloodSugar);
    setWeight(weight);
    setDiabetesType1(diabetesType1);
    setDiabetesType2(diabetesType2);
    setEyeDamage(eyeDamage);
    setYearsWithDiabetes(yearsWithDiabetes);
    setYearsWithHypertension(yearsWithHypertension);
    setUrinatingProblems(urinatingProblems);
    setBloodType(bloodType);
    setUrineLeukocytes(urineLeukocytes);
    setUrineNitrite(urineNitrite);
    setUrineProtein(urineProtein);
    setUrinePH(urinePH);
    setUrineBlood(urineBlood);
    setUrineSG(urineSG);
    setUrineKetones(urineKetones);
    setUrineGlucose(urineGlucose);
    setUrineBilirubin(urineBilirubin);


}

QString Patient::getSSN()
{
    return socialSecurityNumber;
}

QString Patient::getDOB()
{

        return dateOfBirth;
}

QString Patient::getGender()
{
return gender;
}

QString Patient::getAddress()
{
return address;
}

QString Patient::getDistrict()
{
    return district;
}

QString Patient::getPatientStatus()
{
    return patientStatus;
}

int Patient::getBloodPressure()
{
return bloodPressure;
}

int Patient::getHeartRate()
{
return heartRate;
}

int Patient::getPulse()
{
return pulse;
}

float Patient::getBloodSugar()
{
return bloodSugar;
}

float Patient::getWeight()
{
return weight;
}

bool Patient::getDiabetesType1()
{
return diabetesType1;
}

bool Patient::getDiabetesType2()
{
return diabetesType2;
}

bool Patient::getEyeDamage()
{
return eyeDamage;
}

int Patient::getYearsWithDiabetes()
{
return yearsWithDiabetes;
}

int Patient::getYearsWithHypertension()
{
return yearsWithHypertension;
}

bool Patient::getUrinatingProblems()
{
return urinatingProblems;
}

QString Patient::getBloodType()
{
return bloodType;
}

QString Patient::getUrineLeukocytes()
{
return urineLeukocytes;
}

QString Patient::getUrineNitrite()
{
return urineNitrite;
}

QString Patient::getUrineProtein()
{
return urineProtein;
}

QString Patient::getUrinePH()
{
return urinePH;
}

QString Patient::getUrineBlood()
{
return urineBlood;
}

QString Patient::getUrineSG()
{
return urineSG;
}

QString Patient::getUrineKetones()
{
return urineKetones;
}

QString Patient::getUrineGlucose()
{
return urineGlucose;
}

QString Patient::getUrineBilirubin()
{
return urineBilirubin;
}

//Error Checking will be implimented later
void Patient::setSSN(QString ssn)
{
socialSecurityNumber = ssn;
}

void Patient::setDOB(QString dob)
{

    dateOfBirth = dob;
}

void Patient::setGender(QString g)
{
gender = g;
}

void Patient::setAddress(QString addr)
{
address = addr;
}

void Patient::setDistrict(QString district)
{
this->district = district;
}

void Patient::setPatientStatus(QString status)
{
patientStatus = status;
}

void Patient::setBloodPressure(int pressure)
{
bloodPressure = pressure;
}

void Patient::setHeartRate(int rate)
{
heartRate = rate;
}

void Patient::setPulse(int pulse)
{
this->pulse = pulse;
}



;

void Patient::setBloodSugar(float sugar)
{
bloodSugar = sugar;
}

void Patient::setWeight(float w)
{
weight  = w;
}

void Patient::setDiabetesType1(bool isDiabetic1)
{
diabetesType1 = isDiabetic1;
}

void Patient::setDiabetesType2(bool isDiabetic2)
{
    diabetesType2 = isDiabetic2;
}

void Patient::setEyeDamage(bool isEyeDmg)
{
       eyeDamage = isEyeDmg;
}

void Patient::setYearsWithDiabetes(int years)
{
 yearsWithDiabetes = years;
}

void Patient::setYearsWithHypertension(int years)
{
yearsWithHypertension = years;
}

void Patient::setUrinatingProblems(bool UP)
{
urinatingProblems = UP;
}

void Patient::setBloodType(QString type)
{
    bloodType = type;
}

void Patient::setUrineLeukocytes(QString L)
{
urineLeukocytes = L;
}

void Patient::setUrineNitrite(QString N)
{
urineNitrite = N;
}

void Patient::setUrineProtein(QString P)
{
urineProtein = P;
}

void Patient::setUrinePH(QString PH)
{
urinePH = PH;
}

void Patient::setUrineBlood(QString B)
{
urineBlood = B;
}

void Patient::setUrineSG(QString SG)
{
urineSG = SG;
}

void Patient::setUrineKetones(QString K)
{
urineKetones = K;
}

void Patient::setUrineGlucose(QString G)
{
urineGlucose = G;
}

void Patient::setUrineBilirubin(QString B)
{
urineBilirubin = B;
}
