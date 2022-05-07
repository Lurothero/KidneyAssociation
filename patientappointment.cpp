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
