#ifndef APPOINTMENTLIBRARY_H
#define APPOINTMENTLIBRARY_H

//#include "appointment.h" //has been forward declared to allow this class's definitions to be added later

#include <iostream>//These should be replaced with QT Equivalent
#include <string>//These should be replaced with QT Equivalent
#include <vector>//These should be replaced with QT Equivalent

using std::vector;//These should be replaced with QT Equivalent
using std::string;//These should be replaced with QT Equivalent
using std::cout;//These should be replaced with QT Equivalent
using std::endl;//These should be replaced with QT Equivalent
using std::cin;//These should be replaced with QT Equivalent


#include <QString>

class Appointment; //has been forward declared

class AppointmentLibrary
{
public:
    AppointmentLibrary();

private:
    vector<Appointment*> appointmentList;       //list of appointments //These should be replaced with QT Equivalent

public:
    void viewAppointment(int id);
    Appointment* findAppointment(int id, QString name);
    void createAppointment();
    void deleteAppointment(int id);
    void updateAppointment(int id);
    void generateAppointmentReport();

};


#endif // APPOINTMENTLIBRARY_H
