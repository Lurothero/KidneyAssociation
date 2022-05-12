/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef PATIENTAPPOINTMENT_H
#define PATIENTAPPOINTMENT_H

#include <QWidget>

namespace Ui {
class PatientAppointment;
}

class PatientAppointment : public QWidget
{
    Q_OBJECT

public:
    explicit PatientAppointment(QWidget *parent = nullptr);
    ~PatientAppointment();

private:
    Ui::PatientAppointment *ui;
};

#endif // PATIENTAPPOINTMENT_H
