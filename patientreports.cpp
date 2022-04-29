#include "patientreports.h"
#include "ui_patientreports.h"

PatientReports::PatientReports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientReports)
{
    ui->setupUi(this);
}

PatientReports::~PatientReports()
{
    delete ui;
}
