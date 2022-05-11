#include "doctorcontact.h"
#include "ui_doctorcontact.h"

DoctorContact::DoctorContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorContact)
{

    Database record;
    ui->setupUi(this);
    connect(this,SIGNAL(clicked()),this,SLOT(AddDoctorRecord()));
    //connect(this,SIGNAL(clicked()),this,SLOT(refreshButton()));
    loadRecords();
    indexConversion();

    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));
}

void DoctorContact::loadRecords()
{
    Database record;
    record.loadDoctorInformation();
    ui->Search_Combo->addItems(record.docRecord);
}

void DoctorContact::indexConversion()
{
    QList<QString>tokenizeList;

    if(ui->Search_Combo->currentText().isSimpleText())
    {
        tokenizeList.append(ui->Search_Combo->currentText().split(" "));

        qDebug() <<"List of tokenize stuff: "<< tokenizeList;
    }

}

DoctorContact::~DoctorContact()
{
    delete ui;
}

void DoctorContact::on_AddRecord_BTN_clicked()
{
    Database docDatabase;

    if(ui->FirstName_LineEdit->text().isEmpty() && ui->LastName_LineEdit->text().isEmpty()
             && ui->Phone_LineEdit->text().isEmpty() && ui->Email_LineEdit->text().isEmpty())
    {
         QMessageBox::warning(this,tr("Warning"),tr("All fields can't be empty"));
         return;
    }

    if(ui->FirstName_LineEdit->text().isEmpty())
      {
            QMessageBox::warning(this,tr("Warning"),tr("FirstName can't be empty"));
            return;
      }
      else if(ui->LastName_LineEdit->text().isEmpty())
      {
            QMessageBox::warning(this,tr("Warning"),tr("LastName can't be empty"));
            return;
      }
      else if(ui->Phone_LineEdit->text().isEmpty())
      {
            QMessageBox::warning(this,tr("Warning"),tr("Phone Number can't be empty"));
            return;
      }
      else if(ui->Email_LineEdit->text().isEmpty())
      {
            QMessageBox::warning(this,tr("Warning"),tr("Email Address can't be empty"));
            return;
      }

      else
      {

           docDatabase.addDoctorInformation(ui->FirstName_LineEdit->text(),ui->LastName_LineEdit->text(),ui->Phone_LineEdit->text(),ui->Email_LineEdit->text());

           QMessageBox::information(this,tr("Doctor Record"),tr("Doctor contact was added successfully"));

           docDatabase.loadDoctorInformation();
           ui->Search_Combo->addItem(ui->FirstName_LineEdit->text() + " " + ui->LastName_LineEdit->text() + " " + ui->Phone_LineEdit->text() + " " + ui->Email_LineEdit->text());

           ui->FirstName_LineEdit->clear();
           ui->LastName_LineEdit->clear();
           ui->Phone_LineEdit->clear();
           ui->Email_LineEdit->clear();

            //Reload records after inserting
           loadRecords();
       }





    qDebug() << "Button Clicked";
}


void DoctorContact::on_DeleteRecord_BTN_clicked()
{
    Database dataRecord;
    stringstream intConverter;
    QList<QString>tokenizeList;

    qDebug() <<"List of tokenize stuff: "<< tokenizeList;
    if(ui->Search_Combo->currentIndex())
    {
      QMessageBox::information(this,tr("Doctor Record"),tr("Selected record was deleted"));
      tokenizeList.append(ui->Search_Combo->currentText().split(" "));
      dataRecord.deleteDoctorInformation(tokenizeList.begin()->toInt());
      ui->Search_Combo->removeItem(ui->Search_Combo->currentIndex());

      qDebug() << "Current List" << tokenizeList;
    }
    tokenizeList.clear();

    //Reload records
     loadRecords();
}

//May become obsolete
void DoctorContact::on_Refresh_BTN_clicked()
{
    DoctorContact * docForm = new DoctorContact();
    this->close();
    docForm->show();

    qDebug() << "Refresh Button";

    //int id = ui->AddRecord_BTN.;
}

