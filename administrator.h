#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "baseuser.h"
#include "userlibrary.h" //contains the include statements for other user classes

#include <QString>

class Administrator: public BaseUser
{
public:
    Administrator();

    //admins can perform all actions
    friend void UserLibrary::viewDeskEmployee(int id);                  //functions to perform on desk employees
    friend DeskEmployee* UserLibrary::findDeskEmployee(int id, QString name);
    friend void UserLibrary::createDeskEmployee();
    friend void UserLibrary::deleteDeskEmployee(int id);
    friend void UserLibrary::updateDeskEmployee(int id);

    friend void UserLibrary::viewAdministrator (int id);                //functions to perform on other admins
    friend Administrator* UserLibrary::findAdministrator(int id, QString name);
    friend void UserLibrary::createAdministrator ();
    friend void UserLibrary::deleteAdministrator (int id);
    friend void UserLibrary::updateAdministrator (int id);

    friend void UserLibrary::viewDoctor(int id);                         //functions to perform on doctors
    friend Doctor* UserLibrary::findDoctor (int id, QString name);
    friend void UserLibrary::createDoctor();
    friend void UserLibrary::deleteDoctor (int id);
    friend void UserLibrary::updateDoctor(int id);

    friend void AppointmentLibrary::viewAppointment(int id);             //functions to perform on appointments
    friend Appointment* AppointmentLibrary::findAppointment(int id, QString name);
    friend void AppointmentLibrary::createAppointment();
    friend void AppointmentLibrary::deleteAppointment(int id);
    friend void AppointmentLibrary::updateAppointment(int id);
    friend void AppointmentLibrary::generateAppointmentReport();

};
#endif // ADMINISTRATOR_H
