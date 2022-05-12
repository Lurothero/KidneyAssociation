/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef PATIENTREGISTRATION_H
#define PATIENTREGISTRATION_H

#include <QDialog>
#include "database.h"

namespace Ui {
class PatientRegistration;
}

class PatientRegistration : public QDialog
{
    Q_OBJECT

public:
    explicit PatientRegistration(QWidget *parent = nullptr);
    ~PatientRegistration();

private slots:
    void addRecord(); // adding patient records
    void toggleHypertention(); // switching to viewing of text box to descripe more details
    void toggleUrineProblemDescription(); // switching to viewing of text box to descripe more details

private:
    Ui::PatientRegistration *ui;
    Database db;
};

#endif // PATIENTREGISTRATION_H
