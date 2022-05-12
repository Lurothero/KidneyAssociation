/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

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
  // loads list of districts selected from the patient
  Database db;
  db.loadDistrictList();
  ui->DistrictCombo->addItems(db.patientLocations);
}

void PatientForm::loadPatientStatus()
{
    // loads all patient stutus
  Database db;
  db.loadStatus();
  ui->StatusCombo->addItems(db.StatusList);
}

void PatientForm::loadsBloodTypes()
{
  // loads all blood type from patient selected
  Database db;
  db.loadPatientBloodType();
  ui->BTypeCombo->addItems(db.patientBloodTypes);
}

void PatientForm::loadPatientSSNs()
{
  // loads all SSN from the database
  Database db;
  db.loadSocialSecurityNumbers();
  ui->SSNCombo->addItems(db.SocialSecurityNumbers);
}

void PatientForm::loadSelectedInformation()
{
    Database db;
   if(!ui->SSNCombo->currentText().isNull()) // checks if the current item is selected
   {
       // loads first name, last name, phone number and DOB to the text fields
      db.selectedSSN(ui->SSNCombo->currentText().toInt());
      ui->FNameEdit->setText(db.FirstName);
      ui->LNameEdit->setText(db.LastName);
      ui->PhoneEdit->setText(db.PhoneNumber);
      ui->DOB_Edit->setText(db.DOB);
   }
}

void PatientForm::on_EditRecord_BTN_clicked()
{
   // update the edited information to the database
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

