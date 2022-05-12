/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

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



    QString firstName = ui->FNameEdit->text();
    QString lastName = ui->LNameEdit->text();


    QString phoneNumber = ui->PhoneEdit->text();
    bool isPhoneValid = ui->PhoneEdit->hasAcceptableInput();

    QString email = ui->Email_Edit->text();


    int status  = ui->PatientStatus_Combo->currentIndex();


    QString socialSecurityNumber  =  ui->patient_ssn_Box->text();
    bool isSSNValid = ui->patient_ssn_Box->hasAcceptableInput();


    QString dateOfBirth  = ui->DOB_Date_Edit->date().toString("yyyy-dd-MM");

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

    //TRY FIRST NAME
    try {

        int sizeLimit = 20; // limits the size of character
        QRegularExpression re("[a-zA-Z]");
        QRegularExpressionMatch match = re.match(firstName); // stores the first name



        if (firstName.isEmpty()){
            throw(QString(tr("First name field is blank!"))); // throws an exception handing
        }

        if(!match.hasMatch()){
            // throws an exception handing
            throw(QString(tr("First name contains invalid characters! Please only use Letters!")));

        }

        if(firstName.length() > sizeLimit){
            // throws an exception handing
            throw(QString(tr("First name field has too many characters! Contains %1 characters, limit %2 ").arg(firstName.length()).arg(sizeLimit)));


        }

    }  catch (QString invalidString) { // catches an exception handling

        // notify the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY LAST NAME
    try {

        int sizeLimit = 20; // limits the size of character
        QRegularExpression re("[a-zA-Z]");
        QRegularExpressionMatch match = re.match(lastName); // stores the last name



        if (lastName.isEmpty()){ // throws an expection handling
            throw(QString(tr("Last name field is blank!")));
        }

        if(!match.hasMatch()){

            // throws an expection handling
            throw(QString(tr("Last name contains invalid characters! Please only use Letters!")));

        }

        if(lastName.length() > sizeLimit){

            // throws an expection handling
            throw(QString(tr("Last name field has too many characters! Contains %1 characters, limit %2 ").arg(lastName.length()).arg(sizeLimit)));


        }

    }  catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }

    //TRY PHONE
    try {
        if (phoneNumber.isEmpty()){
            // throws an expection handling
            throw(QString(tr("Telephone number field is blank!")));
        }

        if (!isPhoneValid){
            // throws an expection handling
            throw(QString(tr("Telephone number is invalid!")));
        }

    }  catch (QString invalidString) { // catches exception handling

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }

    //TRY EMAIL
    try {

        int sizeLimit = 60; // size limit for the email address
        QRegularExpression re("^([a-zA-Z][\\w\\_\\.]{6,15})\\@([a-zA-Z0-9.-]+)\\.([a-zA-Z]{2,4})$");
        QRegularExpressionMatch match = re.match(email); // stores the email

        if (email.isEmpty()){
            // throws an expection handling
            throw(QString(tr("Email field is blank!")));
        }

        if(!match.hasMatch()){

            // throws an expection handling
            throw(QString(tr("Email contains invalid characters!")));

        }

        if(email.length() > sizeLimit){

            // throws an expection handling
            throw(QString(tr("Email field has too many characters! Contains %1 characters, limit %2 ").arg(email.length()).arg(sizeLimit)))

        }

    }  catch (QString invalidString) {

        // throws an expection handling
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY DOB
    try {

        if(ui->DOB_Date_Edit->date() > QDate::currentDate()){
            // throws an expection handling
            throw(QString(tr("This patient cannot be born in the future!")))

        }



    }  catch (QString invalidString) { // catches an exception handling

        // throws an expection handling
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }

    //TRY WEIGHT
    try {


        if (ui->weigthEdit->text().isEmpty()){ // throws an expection handling
            throw(QString(tr("Weight field is empty!")));
        }

        if(weight < 0){
            // throws an expection handling
            throw(QString(tr("Weight cannot be less than 0!")));
        }

        if(weight >= 1000){
            // throws an expection handling
            throw(QString(tr("Weight is out of bounds!")));
        }




    }  catch (QString invalidString) { // catches exception handling

        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY SOCIAL
    try {

        if (socialSecurityNumber.isEmpty()){
            // throws an expection handling
            throw(QString(tr("Social Security Number field empty!")));
        }

        if (!isSSNValid){
            // throws an expection handling
            throw(QString(tr("Social Security Number field has invalid inputs!")));

        }

    }  catch (QString invalidString) {
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }

    //TRY ADDRESS
    try {

        int sizeLimit = 50; // sets a limit for an address
        QRegularExpression re("[a-zA-Z0-9]");
        QRegularExpressionMatch match = re.match(address); // stores the address



        if (address.isEmpty()){
            // throws an expection handling
            throw(QString(tr("Address field is blank!")));
        }

        if(!match.hasMatch()){
            // throws an expection handling
            throw(QString(tr("Address contains invalid characters! Please only use Letters!")));

        }

        if(address.length() > sizeLimit){
             // throws an expection handling
            throw(QString(tr("Address field has too many characters! Contains %1 characters, limit %2 ").arg(address.length()).arg(sizeLimit)));

        }

    }  catch (QString invalidString) {
        // notify the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY BLOODPRESSURE
    try {


        if (ui->BloodPressureEdit->text().isEmpty()){
            // throws an expection handling
            throw(QString(tr("Blood Pressure field is blank!")));
        }

        if(bloodPressure < 0){

            // throws an expection handling
            throw(QString(tr("Blood pressure cannot be less than 0!")));
        }

        if(bloodPressure >= 500){

            // throws an expection handling
            throw(QString(tr("Blood pressure is out of bounds!")));
        }




    }  catch (QString invalidString) {
        // notify the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY HEARTRATE
    try {


        if (ui->HeartRateEdit->text().isEmpty()){
            // throws an expection handling
            throw(QString(tr("Heart rate field is blank!")));
        }

        if(heartRate < 0){

            // throws an expection handling
            throw(QString(tr("Heart rate cannot be less than 0!")));
        }

        if(heartRate >= 500){

            // throws an expection handling
            throw(QString(tr("Heart rate is out of bounds!")));
        }




    }  catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY BLOODSUGAR
    try {


        if (ui->SugarEdit->text().isEmpty()){
            // throws an expection handling
            throw(QString(tr("Blood sugar field is blank!")));
        }

        if(bloodSugar < 0){
            // throws an expection handling
            throw(QString(tr("Blood sugar cannot be less than 0!")));
        }

        if(bloodSugar >= 3000){
            // throws an expection handling
            throw(QString(tr("Blood sugar is out of bounds!")));
        }




    }  catch (QString invalidString) {

        // notify the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY YEARS_HYPERTENSION
    try {

        if(ui->hyper_CheckBox->isChecked() && ui->HyperYears_Edit->text().isEmpty()){
            // throws an expection handling
            throw(QString(tr("Years with hypertension field cannot be empty!")));
        }


        if(yearsWithHypertension < 0){
            // throws an expection handling
            throw(QString(tr("Years with hypertension cannot be less than 0!")));
        }

        if(yearsWithHypertension >= 150){
            // throws an expection handling
            throw(QString(tr("Years with hypertension is out of bounds!")));
        }

    }  catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY YEARS_DIABET
    try {


        if (ui->DiabetesYearsEdit->text().isEmpty()){
            // throws an expection handling
            throw(QString(tr("Years with Diabetes field is empty!")));
        }



        if(yearsWithDiabetes < 0){
            // throws an expection handling
            throw(QString(tr("Years with Diabetes cannot be less than 0!")));
        }

        if(yearsWithDiabetes >= 150){
            // throws an expection handling
            throw(QString(tr("Years with Diabetes is out of bounds! Limit is 150")));
        }




    }  catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY SG
    try {


        if( ui->Urine_SG_Edit->text().remove(".").isEmpty()){
            // throws an expection handling
            throw(QString(tr("Urine Specific Gravity field is empty!")));
        }

        if (urineSG.toFloat() < 0.0){
            // throws an expection handling
            throw(QString(tr("Urine Specific Gravity field cannot be less than 0!")));
        }



    }   catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY Bilirubin
    try {

        if(ui->UrineBilEdit->text().remove(".").isEmpty()){
            // throws an expection handling
            throw(QString(tr("Urine Bilirubin field is empty!")));
        }

        if (urineBilirubin.toFloat() < 0.0){
            // throws an expection handling
            throw(QString(tr("Urine Bilirubin field cannot be less than 0!")));
        }

    }   catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }




    //TRY URINEPROBLEMDESC
    try {

        int sizeLimit = 50;
        QRegularExpression re("[a-zA-Z0-9]");
        QRegularExpressionMatch match = re.match(urineProblemDescription);


        if(ui->UrineProblemCheck->isChecked() && urineProblemDescription.length() == 0){
            // throws an expection handling
            throw(QString(tr("Urine problem description is empty!")));
        }

        if(!match.hasMatch() && urineProblemDescription.length()!= 0){
            // throws an expection handling
            throw(QString(tr("Urine problem description contains invalid characters! Please only use Letters!")));

        }

        if(urineProblemDescription.length() > sizeLimit){
            // throws an expection handling
            throw(QString(tr("Urine problem description field has too many characters! Contains %1 characters, limit %2 ").arg(urineProblemDescription.length()).arg(sizeLimit)));

        }

    }  catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY PROTEIN
    try {

        if(ui->UrineProteinEdit->text().isEmpty()){
            // throws an expection handling
            throw(QString(tr("Urine Protein field is empty!")));
        }

        if (urineProtein.toInt() < 0){
            // throws an expection handling
            throw(QString(tr("Urine Protein field cannot be less than 0!")));
        }

    }   catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }



    //TRY PH
    try {

        if(ui->Urine_PH_Edit->text().remove(".").isEmpty()){
            // throws an expection handling
            throw(QString(tr("Urine Ph field is empty!")));
        }

        if (urinePH.toFloat() < 0.0){
            // throws an expection handling
            throw(QString(tr("Urine pH field cannot be less than 0!")));
        }

        if (urinePH.toFloat() > 14.0){
            // throws an expection handling
            throw(QString(tr("Urine pH field cannot be greater than 14!")));
        }


    }   catch (QString invalidString) {
        // throws an expection handling
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }

    //TRY Ketones
    try {
        // throws an expection handling
        if(ui->Urine_KeytonesEdit->text().remove(".").isEmpty()){
            throw(QString(tr("Urine Ketones field is empty!")));
        }

        if (urineSG.toFloat() < 0.0){
            // throws an expection handling
            throw(QString(tr("Urine Ketones field cannot be less than 0!")));
        }



    }   catch (QString invalidString) {
        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    //TRY URINELEUKOCYTES
    try {

        QRegularExpression re("[0-9.]");
        QRegularExpressionMatch match = re.match(urineLeukocytes);


        if(!match.hasMatch()){

            // throws an expection handling
            throw(QString(tr("Leukocytes field contains invalid characters! Please only use numbers!")));

        }

        if(urineLeukocytes.toInt() < 0){

            // throws an expection handling
            throw(QString(tr("Leukocytes cannot be less that 0!")));


        }

    }  catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }



    //TRY Glucose
    try {

        // throws an expection handling
        if(ui->UrineGlucoseEdit->text().remove(".").isEmpty()){
            throw(QString(tr("Urine Glucose field is empty!")));
        }

        if (urineGlucose.toFloat() < 0.0){

            // throws an expection handling
            throw(QString(tr("Urine Glucose field cannot be less than 0!")));
        }



    }   catch (QString invalidString) {

        // throws an expection handling
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }



    //TRY Nitrite
    try {

        // throws an expection handling
        if (ui->UrineNitriteEdit->text().remove(".").isEmpty()){

            throw(QString(tr("Urine Nitrite field is empty!")));
        }


    }  catch (QString invalidString) {

        // notifies the user
        QMessageBox::warning(this,tr("Error while performing request"),invalidString,QMessageBox::Ok);
        return;
    }


    qDebug() << "Called add patient";
    bool success = db.addPatientRecord(firstName, // adds the patient record
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

    if (success){
        QMessageBox::information(this,tr("Operation Success"),tr("The record has successfully been inserted."),QMessageBox::Ok);
    }else{
        QMessageBox::critical(this,tr("Operation Failure"),tr("Internal error had occured, failed to insert record."),QMessageBox::Ok);
    }

}

void PatientRegistration::toggleHypertention()
{

    if (ui->hyper_CheckBox->isChecked()){

        // display description
        ui->Hypertention_Splitter->show();

    }else{
        ui->Hypertention_Splitter->hide();
        ui->HyperYears_Edit->clear();
    }



}

void PatientRegistration::toggleUrineProblemDescription()
{

    if (ui->UrineProblemCheck->isChecked()){

        // display description box
        ui->UrineProblemEdit->show();
        ui->UrineProblemLabel-> show();

    }else{
        ui->UrineProblemEdit->hide();
        ui->UrineProblemEdit->clear();
        ui->UrineProblemLabel->hide();
    }

}
