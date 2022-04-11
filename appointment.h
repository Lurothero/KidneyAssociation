#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "doctor.h"
#include "patient.h"
#include "appointmentlibrary.h"

class Appointment
{
public:
    Appointment();

private:
    int appointmentId;
//    int doctorId;
//    int patientId;
    Doctor* doctor;
    Patient* patient;
    string treatmentDescription;
    string AppointmentDate;

};

#endif // APPOINTMENT_H
