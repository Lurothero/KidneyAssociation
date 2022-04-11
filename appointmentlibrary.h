#ifndef APPOINTMENTLIBRARY_H
#define APPOINTMENTLIBRARY_H

//#include "appointment.h" //has been forward declared to allow this class's definitions to be added later
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

class Appointment; //has been forward declared

class AppointmentLibrary
{
public:
    AppointmentLibrary();

private:
    vector<Appointment*> appointmentList;       //list of appointments

public:
    void viewAppointment(int id);
    Appointment* findAppointment(int id, string name);
    void createAppointment();
    void deleteAppointment(int id);
    void updateAppointment(int id);
    void generateAppointmentReport();

};


#endif // APPOINTMENTLIBRARY_H
