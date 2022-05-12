/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#include "homemenu.h"
#include "ui_homemenu.h"


#include "patientregistration.h"

HomeMenu::HomeMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeMenu)
{
    ui->setupUi(this);


    //Connects the functionality of opening the patient record and patient form
    connect(ui->patientAddButton,SIGNAL(clicked()),this,SLOT(createPatientRecord()));
    connect(ui->AppointmentButton,SIGNAL(clicked()),this,SLOT(opentPatientForm()));

    QTimer * timer = new QTimer(this); // QTimer object created
    timer->start(1000); // let it start at 1000 miliseconds
    updateTime(); // update time to the main menu based on the O.S
    connect(timer, &QTimer::timeout,this,&HomeMenu::updateTime); // connect function to always update current time

    time_t currTime;
    tm* currTm;
    char dateString[100];

    time(&currTime);
    currTm = localtime(&currTime);

    strftime(dateString, 50, "Current Date: %d/%m/%Y", currTm); // formats the current date

    ui->dateLabel->setText(dateString); // display the current date to the screen

    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));


}

HomeMenu::~HomeMenu()
{
    delete ui;
}

void HomeMenu::displayDeskMenu()
{
    ui->adminButton->setEnabled(false); // disable admin button once a desk employee is logged in
}

void HomeMenu::displayDoctorMenu()
{
  // disables admin, adding a patient and generating reports if a doctor is logged in
  ui->adminButton->setEnabled(false);
  ui->patientAddButton->setEnabled(false);
  ui->reportButton->setEnabled(false);
}

void HomeMenu::updateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm"); // formats the time
        if ((time.second() % 2) == 0) // the colon will flash
        {
            text[2] = ' ';
        }

        ui->clock->display(text); // display current time on the home menu
}


void HomeMenu::on_contactButton_clicked()
{
    // opens form to enter doctor information
    DoctorContact * docInfo = new DoctorContact(this);
    docInfo->show();
}


void HomeMenu::createPatientRecord()
{
    // opens form to add patients
    PatientRegistration *addPatient = new PatientRegistration;
    addPatient->show();
}


void HomeMenu::on_AppointmentButton_clicked()
{
    // opens form to make appointments
    Appointment * appointForm = new Appointment(this);
    appointForm->show();
}

void HomeMenu::on_registrationButton_clicked()
{
    PatientRegistration * registerForm = new PatientRegistration(this);
    registerForm->show();
}

void HomeMenu::on_reportButton_clicked()
{
    // opens form to display patient records
  PatientReports * pRecords = new PatientReports(this);
  pRecords->show();
}


void HomeMenu::on_patientRecButton_clicked()
{
    // opens form to edit/ delete patient records
    PatientForm * pForm = new PatientForm(this);
    pForm->show();
}


void HomeMenu::on_LogOutButton_clicked()
{
    // logs out from home screen to login page
   login * loginScreen = new login(this);
   loginScreen->show();
   this->hide();
}


void HomeMenu::on_translateButton_clicked()
{
    QStringList languages; // stores languages to be switched
    languages << "English" << "Spanish";


    // stores the selected option into a QString
    QString lang = QInputDialog::getItem(this,"Select Language", "Language",languages);

    if(lang == "English") // checks if the language was selected
    {
       // loads translation and notify the user
       appTranslator.load(":/kidney_association_en.qm");
       QMessageBox::information(this,tr("Translation"),tr("Translated to english"));
    }
    else if(lang == "Spanish") // checks if the language was selected
    {
        // loads translation and notify the user
        appTranslator.load(":/kidney_association_es.qm");
        QMessageBox::information(this,tr("Translation"),tr("Translated to spanish"));
    }
    else
    {
       // do nothing
    }

    if(lang != "English") // checks if its not the selected language
    {
      qApp->installTranslator(&appTranslator);
    }
    else if(lang != "Spanish") // checks if its not the selected language
    {
        qApp->installTranslator(&appTranslator);
    }

    ui->retranslateUi(this); // translate the user inferface
}

