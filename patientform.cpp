#include "Patientform.h"
#include "ui_Patientform.h"

PatientForm::PatientForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientForm)
{
    ui->setupUi(this);
    connect(ui->SSNCombo, SIGNAL(currentText()),this,SLOT(loadSelectedInformation()));

    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));
    loadDistrictList();
    loadPatientStatus();
    loadsBloodTypes();
    loadPatientSSNs();
}

PatientForm::~PatientForm()
{
    delete ui;
}

void PatientForm::loadDistrictList()
{
  Database db;
  db.loadDistrictList();
  ui->DistrictCombo->addItems(db.patientLocations);
}

void PatientForm::loadPatientStatus()
{
  Database db;
  db.loadStatus();
  ui->StatusCombo->addItems(db.StatusList);
}

void PatientForm::loadsBloodTypes()
{
  Database db;
  db.loadPatientBloodType();
  ui->BTypeCombo->addItems(db.patientBloodTypes);
}

void PatientForm::loadPatientSSNs()
{
  Database db;
  db.loadSocialSecurityNumbers();
  ui->SSNCombo->addItems(db.SocialSecurityNumbers);
}

void PatientForm::loadSelectedInformation()
{
    Database db;
   if(!ui->SSNCombo->currentText().isNull())
   {
      db.selectedSSN(ui->SSNCombo->currentText().toInt());
      ui->FNameEdit->setText(db.FirstName);
      ui->LNameEdit->setText(db.LastName);
      ui->PhoneEdit->setText(db.PhoneNumber);
      ui->DOB_Edit->setText(db.DOB);
   }
}

void PatientForm::on_EditRecord_BTN_clicked()
{
   Database db;
   db.EditPatientRecord(ui->SSNCombo->currentText().toInt(),ui->FNameEdit->text(), ui->LNameEdit->text(), ui->PhoneEdit->text(),ui->DOB_Edit->text(),ui->AddressEdit->text());

   QMessageBox::information(this,tr("Record Edited"),tr("The Record was edited"));
}


void PatientForm::on_SSNCombo_activated(int index)
{
    Database db;
   if(!ui->SSNCombo->currentText().isNull())
   {
      db.selectedSSN(ui->SSNCombo->currentText().toInt());
      ui->FNameEdit->setText(db.FirstName);
      ui->LNameEdit->setText(db.LastName);
      ui->PhoneEdit->setText(db.PhoneNumber);
      ui->DOB_Edit->setText(db.DOB);
      ui->PhoneEdit->setText(db.PhoneNumber);
      ui->AddressEdit->setText(db.Address);
   }
}

