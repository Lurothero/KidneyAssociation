#include "patientrecords.h"
#include "ui_patientrecords.h"

PatientRecords::PatientRecords(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientRecords)
{
    ui->setupUi(this);
}

PatientRecords::~PatientRecords()
{
    delete ui;
}
