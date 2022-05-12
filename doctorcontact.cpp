/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#include "doctorcontact.h"
#include "ui_doctorcontact.h"

DoctorContact::DoctorContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorContact)
{

    Database record;
    ui->setupUi(this);
    connect(this,SIGNAL(clicked()),this,SLOT(AddDoctorRecord())); // connect function to add Doctor record
    loadRecords(); // call function to load doctor records added
    indexConversion(); // call function to ensure that proper index conversion is operating

    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));
}

void DoctorContact::loadRecords()
{
    Database record;
    record.loadDoctorInformation(); // calls functio to prepare all doctor records
    ui->Search_Combo->addItems(record.docRecord); // loads them to the combo box
}

void DoctorContact::indexConversion()
{
    // tokenize selected index so when its time to delete, the appropriate ID and comobox
    // index gets deleted properly
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

    // checks if the all the fields are empty
    if(ui->FirstName_LineEdit->text().isEmpty() && ui->LastName_LineEdit->text().isEmpty()
             && ui->Phone_LineEdit->text().isEmpty() && ui->Email_LineEdit->text().isEmpty())
    {
         // warns the user
         QMessageBox::warning(this,tr("Warning"),tr("All fields can't be empty"));
         return;
    }

    // checks if the first name field is empty
    if(ui->FirstName_LineEdit->text().isEmpty())
      {
            // warns the user
            QMessageBox::warning(this,tr("Warning"),tr("FirstName can't be empty"));
            return;
      }
      else if(ui->LastName_LineEdit->text().isEmpty()) // checks if the last name field is empty
      {
            // warns the user
            QMessageBox::warning(this,tr("Warning"),tr("LastName can't be empty"));
            return;
      }
      else if(ui->Phone_LineEdit->text().isEmpty()) // checks if the phone number field is empty
      {
            // warns the user
            QMessageBox::warning(this,tr("Warning"),tr("Phone Number can't be empty"));
            return;
      }
      else if(ui->Email_LineEdit->text().isEmpty()) // checks if the email address field is empty
      {
            // warns the user
            QMessageBox::warning(this,tr("Warning"),tr("Email Address can't be empty"));
            return;
      }

      else
      {

           // adds the information to the database
           docDatabase.addDoctorInformation(ui->FirstName_LineEdit->text(),ui->LastName_LineEdit->text(),ui->Phone_LineEdit->text(),ui->Email_LineEdit->text());

           // notify the user that the operation was completed
           QMessageBox::information(this,tr("Doctor Record"),tr("Doctor contact was added successfully"));

           docDatabase.loadDoctorInformation(); // loads the updated record that was added

           // adds the record to the combo box
           ui->Search_Combo->addItem(ui->FirstName_LineEdit->text() + " " + ui->LastName_LineEdit->text() + " " + ui->Phone_LineEdit->text() + " " + ui->Email_LineEdit->text());

           // clears all the field after entering a new record
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
    stringstream intConverter; // converts a string to an integer
    QList<QString>tokenizeList;

    qDebug() <<"List of tokenize stuff: "<< tokenizeList;
    if(ui->Search_Combo->currentIndex()) // checks if a record was selected in the search box
    {
      QMessageBox::information(this,tr("Doctor Record"),tr("Selected record was deleted")); // notify the user
      tokenizeList.append(ui->Search_Combo->currentText().split(" ")); // splits the selected record by spaces
      dataRecord.deleteDoctorInformation(tokenizeList.begin()->toInt()); // delets the record based from doctor ID
      ui->Search_Combo->removeItem(ui->Search_Combo->currentIndex()); // remove the proper item from the combo box

      qDebug() << "Current List" << tokenizeList;
    }
    tokenizeList.clear(); // clear vector so it can accept a new one

    // clears all field after deletion of record
    ui->FirstName_LineEdit->clear();
    ui->LastName_LineEdit->clear();
    ui->Phone_LineEdit->clear();
    ui->Email_LineEdit->clear();
    loadRecords();
}
