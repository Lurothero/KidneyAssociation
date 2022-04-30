#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QDialog>
#include "doctor.h"
#include "patient.h"
#include "appointmentlibrary.h"
#include "database.h"
#include "sstream"

namespace Ui {
class Appointment;
}

class Appointment : public QDialog
{
    Q_OBJECT

public:
    explicit Appointment(QWidget *parent = nullptr);
    ~Appointment();
    friend class Database;
    int appointmentId;
    //    int doctorId; //IF Friend then you can directly access it, if not then just use a getter!
    //    int patientId;
    Doctor* doctor;
    Patient* patient;
    QString treatmentDescription;
    QString AppointmentDate;
    //Database * db;
    int getAppointmentID();
    void loadDoctorIds();
    void loadPatientIds();
    double appCost;
    QString appDate;


private slots:
    void on_AddRecord_BTN_clicked();

private:
    Ui::Appointment *ui;
    QString description;
};

#endif // APPOINTMENT_H
