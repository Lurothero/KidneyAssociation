#include "appointment.h"
#include "ui_appointment.h"

Appointment::Appointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Appointment)
{
    ui->setupUi(this);
    loadDoctorIds();
    loadPatientIds();
}

Appointment::~Appointment()
{
    delete ui;
}

int Appointment::getAppointmentID()
{
    return appointmentId;
}

void Appointment::loadDoctorIds()
{
    Database db;
    db.loadDoctorIds();
    ui->DocIDCombo->addItems(db.docIds);
}

void Appointment::loadPatientIds()
{
    Database db;
    db.loadPatientIds();
    ui->PatientIDCombo->addItems(db.patientIds);
}

void Appointment::on_AddRecord_BTN_clicked()
{
    Database db;
    stringstream intConverter;
    stringstream floatConverter;
    int id;
    float cost;

//    floatConverter << ui->AppointCostEdit;
//    floatConverter >> cost;

//    intConverter << ui->AppointIDEdit;
//    intConverter >> id;

    id = ui->AppointIDEdit->text().toInt();
    cost = ui->AppointCostEdit->text().toFloat();
    db.insertingAppointmentData(id,ui->DocIDCombo->currentText().toInt(),ui->PatientIDCombo->currentText().toInt(),
                                 ui->DescriptEdit->toPlainText(),cost,ui->AppointDateEdit->text());

    QMessageBox::information(this,tr("Appointment"),tr("Appointment was added successfully"));

    ui->AppointIDEdit->clear();
    ui->AppointCostEdit->clear();
    ui->AppointDateEdit->clear();
}

