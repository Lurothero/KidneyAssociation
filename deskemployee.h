/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef DESKEMPLOYEE_H
#define DESKEMPLOYEE_H

#include "baseuser.h"
#include "appointmentlibrary.h"
#include "patientlibrary.h"

class DeskEmployee: public BaseUser
{
public:
    DeskEmployee();

    //functions deskemployees can perform on appointments
    friend void AppointmentLibrary::viewAppointment(int id);
    friend void AppointmentLibrary::createAppointment();
    friend void AppointmentLibrary::deleteAppointment(int id);
    friend void AppointmentLibrary::updateAppointment(int id);
    friend void AppointmentLibrary::generateAppointmentReport();

    //functions deskemployees can perform on patients
    friend Patient* PatientLibrary::findPatient(int id, QString name);
    friend void PatientLibrary::createPatient();
    friend void PatientLibrary::deletePatient(int id);
    friend void PatientLibrary::updatePatientPersonalDetails(int id);

};

#endif // DESKEMPLOYEE_H
