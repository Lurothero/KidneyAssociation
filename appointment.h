#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QDialog>
#include "doctor.h"
#include "patient.h"
#include "appointmentlibrary.h"

namespace Ui {
class Appointment;
}

class Appointment : public QDialog
{
    Q_OBJECT

public:
    explicit Appointment(QWidget *parent = nullptr);
    ~Appointment();
    int appointmentId;
    //    int doctorId; //IF Friend then you can directly access it, if not then just use a getter!
    //    int patientId;
    Doctor* doctor;
    Patient* patient;
    QString treatmentDescription;
    QString AppointmentDate;

private:
    Ui::Appointment *ui;
};

#endif // APPOINTMENT_H
