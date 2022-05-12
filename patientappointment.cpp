/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#include "patientappointment.h"
#include "ui_patientappointment.h"

PatientAppointment::PatientAppointment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientAppointment)
{
    ui->setupUi(this);


    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));
}

PatientAppointment::~PatientAppointment()
{
    delete ui;
}
