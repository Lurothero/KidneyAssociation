#include "appointment.h"
#include "ui_appointment.h"

Appointment::Appointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Appointment)
{
    ui->setupUi(this);
    loadDoctorIds();
    loadPatientIds();

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
    db.loadDoctorIds();
    ui->DocIDCombo->addItems(db.docIds);
}

void Appointment::loadPatientIds()
{
    Database db;
    db.loadPatientIds();
    ui->PatientIDCombo->addItems(db.patientIds);
}

void Appointment::on_AddRecord_BTN_clicked()
{
    Database db;
    stringstream intConverter;
    stringstream floatConverter;
    int id;
    float cost;

    id = ui->AppointIDEdit->text().toInt();
    cost = ui->AppointCostEdit->text().toFloat();
    db.insertingAppointmentData(id,ui->DocIDCombo->currentText().toInt(),ui->PatientIDCombo->currentText().toInt(),
                                 ui->DescriptEdit->toPlainText(),cost,ui->AppointDateEdit->text());

    QMessageBox::information(this,tr("Appointment"),tr("Appointment was added successfully"));

    ui->AppointIDEdit->clear();
    ui->AppointCostEdit->clear();
    ui->AppointDateEdit->clear();
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



