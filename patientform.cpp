#include "Patientform.h"
#include "ui_Patientform.h"

PatientForm::PatientForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientForm)
{
    ui->setupUi(this);
}

PatientForm::~PatientForm()
{
    delete ui;
}
