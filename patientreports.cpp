#include "patientreports.h"
#include "ui_patientreports.h"

PatientReports::PatientReports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientReports)
{
    ui->setupUi(this);

    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));
}

PatientReports::~PatientReports()
{
    delete ui;
}
