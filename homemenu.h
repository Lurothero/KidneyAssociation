/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

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
#include "patientreports.h"
#include "Patientform.h"
#include "login.h"
#include <QTranslator>
#include <QInputDialog>


namespace Ui {
class HomeMenu;
}

class HomeMenu : public QWidget
{
    Q_OBJECT

public:
    // added friend classes so memory can be allocated to create new buttons for the main menu
    explicit HomeMenu(QWidget *parent = nullptr);
    ~HomeMenu();
    friend class DoctorContact;
    friend class Database;
    friend class PatientForm;
    friend class Appointment;
    friend class PatientRegistration;
    friend class PatientReports;
    friend class PatientForm;
    friend class login;
    void displayDeskMenu(); // display home menu but with certain restrictions
    void displayDoctorMenu(); // displays home menu but with certain restrictions
    void updateTime(); // updates time from the O.S.


private slots:

    void on_contactButton_clicked();
    void createPatientRecord(); // a button to create patient record
    void on_AppointmentButton_clicked(); // a button to create appointment for patients
    void on_registrationButton_clicked();
    void on_reportButton_clicked(); // a button to open reports button to display an overview report of patients
    void on_patientRecButton_clicked();
    void on_LogOutButton_clicked(); // logs out from home menu and returns back to the login page

    void on_translateButton_clicked(); // created a button to swtich translation from english to spanish

private:
    Ui::HomeMenu *ui;
    QLCDNumber * clock; // private LCD object created for lcd widget
    QLabel * dateLabel; // private QLabel object created to display current time
    QTranslator appTranslator; // Private QTranslator object
};

#endif // HOMEMENU_H
