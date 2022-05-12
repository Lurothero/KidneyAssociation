#include "homemenu.h"
#include "ui_homemenu.h"


#include "patientregistration.h"

HomeMenu::HomeMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeMenu)
{
    ui->setupUi(this);


    //Connects
    connect(ui->patientAddButton,SIGNAL(clicked()),this,SLOT(createPatientRecord()));
    connect(ui->AppointmentButton,SIGNAL(clicked()),this,SLOT(opentPatientForm()));

    QTimer * timer = new QTimer(this);
    timer->start(1000);
    updateTime();
    connect(timer, &QTimer::timeout,this,&HomeMenu::updateTime);

    time_t currTime;
    tm* currTm;
    char dateString[100];

    time(&currTime);
    currTm = localtime(&currTime);

    strftime(dateString, 50, "Current Date: %d/%m/%Y", currTm);

    ui->dateLabel->setText(dateString);

    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));


}

HomeMenu::~HomeMenu()
{
    delete ui;
}

void HomeMenu::displayDeskMenu()
{
    ui->adminButton->setEnabled(false);
}

void HomeMenu::displayDoctorMenu()
{
  ui->adminButton->setEnabled(false);
  ui->patientAddButton->setEnabled(false);
  ui->reportButton->setEnabled(false);
}

void HomeMenu::updateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
        if ((time.second() % 2) == 0)
        {
            text[2] = ' ';
        }

        ui->clock->display(text);
}


void HomeMenu::on_contactButton_clicked()
{
    DoctorContact * docInfo = new DoctorContact(this);
    docInfo->show();
}


void HomeMenu::createPatientRecord()
{

    //Call the addRecord window

    PatientRegistration *addPatient = new PatientRegistration;

    addPatient->show();

}


void HomeMenu::on_AppointmentButton_clicked()
{
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
  PatientReports * pRecords = new PatientReports(this);
  pRecords->show();
}


void HomeMenu::on_patientRecButton_clicked()
{
    PatientForm * pForm = new PatientForm(this);
    pForm->show();
}


void HomeMenu::on_LogOutButton_clicked()
{
   login * loginScreen = new login(this);
   loginScreen->show();
   this->hide();
}


void HomeMenu::on_translateButton_clicked()
{
    //QTranslator t;
    QStringList languages;
    languages << "English" << "Spanish";


    QString lang = QInputDialog::getItem(this,"Select Language", "Language",languages);

    if(lang == "English")
    {
       appTranslator.load(":/kidney_association_en.qm");
       QMessageBox::information(this,tr("Translation"),tr("Translated to english"));
    }
    else if(lang == "Spanish")
    {
        appTranslator.load(":/kidney_association_es.qm");
        QMessageBox::information(this,tr("Translation"),tr("Translated to spanish"));
    }
    else
    {

    }

    if(lang != "English")
    {
      qApp->installTranslator(&appTranslator);
    }
    else if(lang != "Spanish")
    {
        qApp->installTranslator(&appTranslator);
    }

    ui->retranslateUi(this);
}

