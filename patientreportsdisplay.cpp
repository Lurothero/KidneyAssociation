#include "patientreportsdisplay.h"
#include "ui_patientreportsdisplay.h"

patientReportsDisplay::patientReportsDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::patientReportsDisplay)
{
    ui->setupUi(this);
}

patientReportsDisplay::~patientReportsDisplay()
{
    delete ui;
}
