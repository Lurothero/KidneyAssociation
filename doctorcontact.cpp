#include "doctorcontact.h"
#include "ui_doctorcontact.h"

DoctorContact::DoctorContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorContact)
{
    ui->setupUi(this);
    connect(this,SIGNAL(clicked()),this,SLOT(AddDoctorRecord()));
}

DoctorContact::~DoctorContact()
{
    delete ui;
}

void DoctorContact::on_AddRecord_BTN_clicked()
{
    Database docDatabase;
    if(ui->FirstName_LineEdit->text() == " ")
      {
            QMessageBox::warning(this,tr("Warning"),tr("FirstName can't be empty"));
            return;
      }
      else if(ui->LastName_LineEdit->text() == " ")
      {
            QMessageBox::warning(this,tr("Warning"),tr("LastName can't be empty"));
            return;
      }
      else if(ui->Phone_LineEdit->text() == " ")
      {
            QMessageBox::warning(this,tr("Warning"),tr("Phone Number can't be empty"));
            return;
      }
      else if(ui->Email_LineEdit->text() == " ")
      {
            QMessageBox::warning(this,tr("Warning"),tr("Email Address can't be empty"));
            return;
      }

      else
      {
           docDatabase.addDoctorInformation(ui->FirstName_LineEdit->text(),ui->LastName_LineEdit->text(),ui->Phone_LineEdit->text(),ui->Email_LineEdit->text());

           QMessageBox::information(this,tr("Database Query"),tr("Doctor contact was added successfully"));

           doctorData.append(ui->FirstName_LineEdit->text() + " " + ui->LastName_LineEdit->text() + "-" + ui->Phone_LineEdit->text() + "-" + ui->Email_LineEdit->text());

           ui->Search_Combo->addItem(ui->FirstName_LineEdit->text() + " " + ui->LastName_LineEdit->text() + "-" + ui->Phone_LineEdit->text() + "-" + ui->Email_LineEdit->text());

           //ui->Search_Combo->addItem(docDatabase.loadDoctorInformation(ui->FirstName_LineEdit->text(),ui->LastName_LineEdit->text(),ui->Phone_LineEdit->text(),ui->Email_LineEdit->text()))
           docDatabase.loadDoctorInformation(ui->FirstName_LineEdit->text(),ui->LastName_LineEdit->text(),ui->Phone_LineEdit->text(),ui->Email_LineEdit->text());
           ui->FirstName_LineEdit->clear();
           ui->LastName_LineEdit->clear();
           ui->Phone_LineEdit->clear();
           ui->Email_LineEdit->clear();


           qDebug() << "List of records " <<doctorData << "\n";
           //ui->Search_Combo.

       }


       if(ui->FirstName_LineEdit->text() == " " && ui->LastName_LineEdit->text() == " "
                && ui->Phone_LineEdit->text() == " " && ui->Email_LineEdit->text() == " ")
       {
            QMessageBox::warning(this,tr("Warning"),tr("All fields can't be empty"));
            return;
       }


    qDebug() << "Button Clicked";
}

