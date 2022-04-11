#ifndef USERLIBRARY_H
#define USERLIBRARY_H

//#include "administrator.h" //has been forward declared to allow this class's definitions to be added later in administrator class
#include "doctor.h"
#include "deskemployee.h"

#include <vector>
using std::vector;

class Administrator; //forward declaration

class UserLibrary
{
public:
    UserLibrary();

private:
    vector <Doctor*> doctorList;                // list of doctors
    vector <Administrator*> adminList;          // list of admins
    vector <DeskEmployee*> deskemployeeList;    // list of desk employees

public:

    void viewDeskEmployee(int id);                    // functions to perform on desk employees(only admins can use these)
    DeskEmployee* findDeskEmployee(int id, string name);
    void createDeskEmployee();
    void deleteDeskEmployee(int id);
    void updateDeskEmployee(int id);

    void viewAdministrator (int id);                  // functions to perform on admins
    Administrator* findAdministrator(int id, string name);
    void createAdministrator ();
    void deleteAdministrator (int id);
    void updateAdministrator (int id);

    void viewDoctor(int id);                          // functions to perform on doctors
    Doctor* findDoctor (int id, string name);
    void createDoctor();
    void deleteDoctor (int id);
    void updateDoctor(int id);

};

#endif // USERLIBRARY_H
