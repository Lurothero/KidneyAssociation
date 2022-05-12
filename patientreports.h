/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef PATIENTREPORTS_H
#define PATIENTREPORTS_H

#include <QDialog>

class patientReportsDisplay;

namespace Ui {
class PatientReports;
}

class PatientReports : public QDialog
{
    Q_OBJECT

public:
    explicit PatientReports(QWidget *parent = nullptr);
    ~PatientReports();

public slots:
    void generateDeceasedPatientsReport(); // generate charts on how many patients are deceased
    void generatePatientsOnTreatmentReport(); // generate charts based on how many patient are on treatment
    void generatePatientsNeedingBloodReport(); // generate charts based on patients needing blood

private:
    Ui::PatientReports *ui;
};

#endif // PATIENTREPORTS_H
