#include "patientregistration.h"
#include "ui_patientregistration.h"

PatientRegistration::PatientRegistration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientRegistration)
{
    ui->setupUi(this);

    //Setting format for string
    ui->DOB_Date_Edit->setDisplayFormat(QString("dd-MMMM-yyyy"));

    //Hidding areas
    ui->UrineProblemEdit->hide();
    ui->UrineProblemLabel->hide();

    ui->Hypertention_Splitter->hide();

    connect(ui->patient_add_record_btn,SIGNAL(clicked()),this,SLOT(addRecord()));
    connect(ui->hyper_CheckBox,SIGNAL(clicked()),this,SLOT(toggleHypertention()));
    connect (ui->UrineProblemCheck,SIGNAL(clicked()),this,SLOT(toggleUrineProblemDescription()));



    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));
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
            int status  = ui->PatientStatus_Combo->currentIndex();
            QString socialSecurityNumber  =  ui->patient_ssn_Box->text();
            QString dateOfBirth  = ui->DOB_Date_Edit->date().toString("yyyy-dd-MM");

            qDebug() << dateOfBirth;

            QString gender  = ui->GenderCombo->currentText();
            QString address  = ui->Address_Text_Box->toPlainText();
            QString district  = ui->DistrictCombo->currentText();
            QString patientStatus  =  ui->PatientStatus_Combo->currentText();
            int bloodPressure  = ui->BloodPressureEdit->text().toInt();
            int heartRate  = ui->HeartRateEdit->text().toInt();
            float bloodSugar  = ui->SugarEdit->text().toFloat();
            float weight  = ui->weigthEdit->text().toFloat();
            bool diabetesType1  = ui->DiabetesType1Box->isChecked();
            bool diabetesType2  = ui->DiabetesType2Box->isChecked();
            bool eyeDamage  = ui->eyeDamageBox->isChecked();
            int yearsWithDiabetes  = ui->DiabetesYearsEdit->text().toInt();
            int yearsWithHypertension  = ui->HyperYears_Edit->text().toInt();
            bool urinatingProblems  = ui->UrineProblemCheck->isChecked();
            QString urineProblemDescription = ui->UrineProblemEdit->toPlainText();
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

            qDebug() << "Called add patient";

            db.addPatientRecord(firstName,
                                lastName,
                                phoneNumber,
                                email,
                                status,
                                socialSecurityNumber,
                                dateOfBirth,
                                gender,
                                address,
                                district,
                                patientStatus,
                                bloodPressure,
                                heartRate,
                                bloodSugar,
                                weight,
                                diabetesType1,
                                diabetesType2,
                                eyeDamage,
                                yearsWithDiabetes,
                                yearsWithHypertension,
                                urinatingProblems,
                                urineProblemDescription,
                                bloodType,
                                urineLeukocytes,
                                urineNitrite,
                                urineProtein,
                                urinePH,
                                urineBlood,
                                urineSG,
                                urineKetones,
                                urineGlucose,
                                urineBilirubin
                                );

            //Return a bool to indicate success or failure
}

void PatientRegistration::toggleHypertention()
{

    if (ui->hyper_CheckBox->isChecked()){

           ui->Hypertention_Splitter->show();

    }else{
            ui->Hypertention_Splitter->hide();
    }



}

void PatientRegistration::toggleUrineProblemDescription()
{

    if (ui->UrineProblemCheck->isChecked()){

        ui->UrineProblemEdit->show();
        ui->UrineProblemLabel-> show();

    }else{
        ui->UrineProblemEdit->hide();
        ui->UrineProblemLabel->hide();
    }

}
