/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/


#ifndef PATIENTLIBRARY_H
#define PATIENTLIBRARY_H

#include "patient.h"
#include <vector>

using namespace std;

class PatientLibrary
{
public:
    PatientLibrary();

private:
    vector<Patient> PatientList;

public:
    void viewPatient(int id); // view patient information by id
    Patient* findPatient(int id, QString name); // finding patient based on id and name
    void createPatient(); // creates patient
    void deletePatient(int id); // deletes a patient based on id
    void updatePatientPersonalDetails(int id); // update info based on id
    void updatePatientMedicalDetails(int id); // update medical info based on id
    void generatePatientReport(); // generate reports of all patient records

};

#endif // PATIENTLIBRARY_H
