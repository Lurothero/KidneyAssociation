#include "doctorinformation.h"
#include "ui_doctorinformation.h"

doctorInformation::doctorInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doctorInformation)
{
    ui->setupUi(this);
}

doctorInformation::~doctorInformation()
{
    delete ui;
}
