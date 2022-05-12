/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef APPOINTMENTLIBRARY_H
#define APPOINTMENTLIBRARY_H

//#include "appointment.h" //has been forward declared to allow this class's definitions to be added later

#include <iostream>//These should be replaced with QT Equivalent
#include <string>//These should be replaced with QT Equivalent
#include <vector>//These should be replaced with QT Equivalent
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;


#include <QString>

class Appointment; //has been forward declared

class AppointmentLibrary
{
public:
    AppointmentLibrary();

private:
    vector<Appointment*> appointmentList;       //list of appointments

public:
    int doctorId,patientId;
    QString treatmentDescription;
    double appCost;
    QString appDate;
    void viewAppointment(int id); // able to view appointment by id
    Appointment* findAppointment(int id, QString name); // able to locate appointment by name and id
    void createAppointment(); // able to create an appointment from the form
    void deleteAppointment(int id); // removes appointment by id
    void updateAppointment(int id); // updates appointment by id
    void generateAppointmentReport(); // generates report of all appointments made

};


#endif // APPOINTMENTLIBRARY_H
