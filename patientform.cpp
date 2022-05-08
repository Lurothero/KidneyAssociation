#include "Patientform.h"
#include "ui_Patientform.h"

PatientForm::PatientForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientForm)
{
    ui->setupUi(this);

    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));
}

PatientForm::~PatientForm()
{
    delete ui;
}
