#include "patientregistration.h"
#include "ui_patientregistration.h"

PatientRegistration::PatientRegistration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientRegistration)
{
    ui->setupUi(this);
}

PatientRegistration::~PatientRegistration()
{
    delete ui;
}
