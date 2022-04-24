#include "patientappointment.h"
#include "ui_patientappointment.h"

PatientAppointment::PatientAppointment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientAppointment)
{
    ui->setupUi(this);
}

PatientAppointment::~PatientAppointment()
{
    delete ui;
}
