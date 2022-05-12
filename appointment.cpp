/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#include "appointment.h"
#include "ui_appointment.h"

Appointment::Appointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Appointment)
{
    ui->setupUi(this);
    loadDoctorIds();
    loadPatientIds();

    ui->AppointDate->setDisplayFormat(QString("dd-MMMM-yyyy")); // sets the display format to day-month-year


    // connect function to print all appointment records
    connect(ui->PrintRecord_BTN, SIGNAL(clicked()),this,SLOT(printAppointment));
    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));
}

Appointment::~Appointment()
{
    delete ui;
}

int Appointment::getAppointmentID()
{
    return appointmentId;
}

void Appointment::loadDoctorIds()
{
    Database db;
    db.loadDoctorIds(); // call function to prepare doctor IDs
    ui->DocIDCombo->addItems(db.docIds); // adds vector to the combo box
}

void Appointment::loadPatientIds()
{
    Database db;
    db.loadPatientIds(); // call function to prepare patient IDs
    ui->PatientIDCombo->addItems(db.patientIds); // adds vector to the combo box
}

void Appointment::on_AddRecord_BTN_clicked()
{
    Database db;
    stringstream intConverter; // converting a string to an integer
    stringstream floatConverter; // converting a string to a float
    int id;
    float cost;

    id = ui->AppointIDEdit->text().toInt(); // stores appointment ID
    cost = ui->AppointCostEdit->text().toFloat(); // stores appointment cost
    db.insertingAppointmentData(id,ui->DocIDCombo->currentText().toInt(),ui->PatientIDCombo->currentText().toInt(),
                                 ui->DescriptEdit->toPlainText(),cost,ui->AppointDate->date().toString("yyyy-dd-MM"));

    QMessageBox::information(this,tr("Appointment"),tr("Appointment was added successfully")); // display message that appointment was added

    // clear text Edits after the records were added
    ui->AppointIDEdit->clear();
    ui->AppointCostEdit->clear();
}


void Appointment::on_GenerateReport_BTN_clicked()
{
   Database database;
   QSqlQuery q;

   QFile file("Report.txt");
   if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
       return;

   QTextStream out(&file);

   qDebug() << "list of records" << database.appointRecord;

   if(q.exec("SELECT * FROM appointment"))
   {
       while(q.next())
       {
         out << "Appointment ID: " << q.value(0).toString() << "\n";
         out << "Doctor ID: " << q.value(1).toString() << "\n";
         out << "Patient ID: " << q.value(2).toString() << "\n";
         out << "Treatment Description: " << q.value(3).toString() << "\n";
         out << "Appointment Cost:" << q.value(4).toString() << "\n";
         out << "Appointment Date:" << q.value(5).toString() << "\n";
         out << "\n";
         out << "====================================================================================" << "\n";
         out << "\n";
       }

   }

   QMessageBox::information(this,tr("Report"),tr("Appointment report(s) has been generated"));
}


void Appointment::on_PrintRecord_BTN_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desired printer");
    QPrintDialog dialog(&printer,this);

    if(dialog.exec() == QDialog::Rejected)
        return;
}



