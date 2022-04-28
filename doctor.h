#ifndef DOCTOR_H
#define DOCTOR_H

#include "baseuser.h"
#include "appointmentlibrary.h"
#include "patientlibrary.h"

class AppointmentLibrary;

class Doctor: public BaseUser
{
public:
    Doctor();

    //functions doctors can perform on appointments
    friend void AppointmentLibrary::viewAppointment(int id);
    friend void AppointmentLibrary::generateAppointmentReport();

    //functions doctors can perform on patients
    friend Patient* PatientLibrary::findPatient(int id, QString name);
    friend void PatientLibrary::updatePatientMedicalDetails(int id);
};

#endif // DOCTOR_H
