#include "patientregistration.h"
#include "ui_patientregistration.h"

PatientRegistration::PatientRegistration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientRegistration)
{
    ui->setupUi(this);
    connect(ui->patient_add_record_btn,SIGNAL(clicked()),this,SLOT(addRecord()));
}

PatientRegistration::~PatientRegistration()
{
    delete ui;
}

void PatientRegistration::addRecord()
{
    //Call the database to add record!

   // db.addPatientRecord();
    //What records do we need?
            QString firstName = ui->FNameEdit->text();
            QString lastName = ui->LNameEdit->text();
            QString phoneNumber = ui->PhoneEdit->text();
            QString email = ui->Email_Edit->text();
            int status  = -1;//WARNING WHERE STATUS COMES FROM???
            QString socialSecurityNumber  =  "BLANK";//Doesnt Exist
            QString dateOfBirth  = ui->DOBEdit->text();
            QString gender  = ui->GenderCombo->currentText();
            QString address  = ui->Address_Text_Box->toPlainText();
            QString district  = ui->DistrictCombo->currentText();
            QString patientStatus  =  ui->PatientStatus_Combo->currentText();
            int bloodPressure  = ui->BloodPressureEdit->text().toInt();
            int heartRate  = ui->HeartRateEdit->text().toInt();
            int pulse  = ui->PulseEdit->text().toInt();
            float bloodSugar  = ui->SugarEdit->text().toFloat();
            float weight  = ui->weigthEdit->text().toFloat();
            bool diabetesType1  = ui->DiabetesType1Box->isChecked();
            bool diabetesType2  = ui->DiabetesType2Box->isChecked();
            bool eyeDamage  = ui->eyeDamageBox->isChecked();
            int yearsWithDiabetes  = ui->DiabetesYearsEdit->text().toInt();
            int yearsWithHypertension  = ui->HyperYears_Edit->text().toInt();
            bool urinatingProblems  = ui->UrineProblemCheck->isChecked();
            QString bloodType  = ui->bloodtypeCombo->currentText();
            QString urineLeukocytes  = ui->Urine_LeukocytesEdit->text();
            QString urineNitrite  = ui->UrineNitriteEdit->text();
            QString urineProtein  = ui->UrineProteinEdit->text();
            QString urinePH  = ui->Urine_PH_Edit->text();
            bool urineBlood  = ui->UrineBloodCheck->isChecked();
            QString urineSG  = ui->Urine_SG_Edit->text();
            QString urineKetones  = ui->Urine_KeytonesEdit->text();
            QString urineGlucose  = ui->UrineGlucoseEdit->text();
            QString urineBilirubin  = ui->UrineBilEdit->text();


    //Return a bool to indicate success or failure
}
