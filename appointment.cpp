#include "appointment.h"
#include "ui_appointment.h"

Appointment::Appointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Appointment)
{
    ui->setupUi(this);
}

Appointment::~Appointment()
{
    delete ui;
}
