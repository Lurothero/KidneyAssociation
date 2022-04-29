#ifndef HOMEMENU_H
#define HOMEMENU_H

#include <QWidget>
#include <QLCDNumber>
#include <QTime>
#include <ctime>
#include <QTimer>
#include <QLabel>
#include "doctorcontact.h"
#include "database.h"
#include "Patientform.h"
#include "appointment.h"
#include "patientregistration.h"

namespace Ui {
class HomeMenu;
}

class HomeMenu : public QWidget
{
    Q_OBJECT

public:
    explicit HomeMenu(QWidget *parent = nullptr);
    ~HomeMenu();
    friend class DoctorContact;
    friend class Database;
    friend class PatientForm;
    friend class Appointment;
    friend class PatientRegistration;
    void displayDeskMenu();
    void displayDoctorMenu();
    void updateTime(); // updates time from the O.S.
    //void displayDoctorContact();

private slots:
    void on_contactButton_clicked();
    void createPatientRecord();
    void on_AppointmentButton_clicked();

    void on_registrationButton_clicked();

private:
    Ui::HomeMenu *ui;
    QLCDNumber * clock; // private object created for lcd widget
    QLabel * dateLabel;
};

#endif // HOMEMENU_H
