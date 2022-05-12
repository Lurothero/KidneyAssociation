/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef PATIENTFORM_H
#define PATIENTFORM_H

#include <QDialog>
#include "database.h"

namespace Ui {
class PatientForm;
}

class PatientForm : public QDialog
{
    Q_OBJECT

public:
    friend class Database;
    explicit PatientForm(QWidget *parent = nullptr);
    ~PatientForm();
    void loadDistrictList(); // loads the districts that each patient reside into combo box
    void loadPatientStatus(); // loads the patient status from each patient
    void loadsBloodTypes(); // loads selected blood type from each patient
    void loadPatientSSNs(); // loads all social security numbers for all patients

private slots:
    void loadSelectedInformation();
    void on_EditRecord_BTN_clicked();
    void on_SSNCombo_activated(int index);

private:
    Ui::PatientForm *ui;
};

#endif // PATIENTFORM_H
