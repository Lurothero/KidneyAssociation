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
    friend Patient* PatientLibrary::findPatient(int id, string name);
    friend void PatientLibrary::createPatient();
    friend void PatientLibrary::deletePatient(int id);
    friend void PatientLibrary::updatePatientPersonalDetails(int id);

};

#endif // DESKEMPLOYEE_H
