/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#include "add_user.h"
#include "ui_add_user.h"
#include <QSqlQuery>
#include <QMessageBox>

add_user::add_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_user)
{
    ui->setupUi(this);
}

add_user::~add_user()
{
    delete ui;
}

void add_user::on_okButton_clicked()
{
    if(ui->firstname->text().trimmed() == "") // checks if the first name field is empty
    {
        QMessageBox msgBox;
        msgBox.setText("First name field is empty"); // pre load message in the message box
        msgBox.exec(); // executes its function
        return;
    }

    if(ui->lastname->text().trimmed() == "") // checks if the first name field is empty
    {
        QMessageBox msgBox;
        msgBox.setText("Last name field is empty"); // pre load message in the message box
        msgBox.exec(); // executes its function
        return;
    }

    QString username = (ui->firstname->text()[0] + ui->lastname->text()); // combines FName and LName as a user name

    if(ui->email->text().trimmed() == "") // checks if email field is empty
    {
        QMessageBox msgBox;
        msgBox.setText("Email field is empty"); // pre load message in the message box
        msgBox.exec(); // executes its function
        return;
    }

    if(ui->phoneNumber->text().trimmed() == "") // checks if phone number field is empty
    {
        QMessageBox msgBox;
        msgBox.setText("Phone number field is empty"); // pre load message in the message box
        msgBox.exec(); // executes its function
        return;
    }

    if(ui->password->text().trimmed() == "") // checks if password field is empty
    {
        QMessageBox msgBox;
        msgBox.setText("Password field is empty"); // pre load message in the message box
        msgBox.exec(); // executes its function
        return;
    }

    if(ui->rpt_password->text().trimmed() == "") // checks if the repeated password field is empty
    {
        QMessageBox msgBox;
        msgBox.setText("Repeat password field is empty"); // pre load message in the message box
        msgBox.exec(); // executes its function
        return;
    }

    int userlevel = ui->userlevel->currentIndex() + 1; // sets userlevel at either 1,2 or 3


    // QSqlQuery object created to insert user names to the database
    QSqlQuery query;
    query.prepare("INSERT INTO user (User_id, UserLevel_id, User_name, First_name, Last_name, Phone_number, Email, Password, Status) VALUES (DEFAULT, :levelid, :username, :firstname, :lastname, :phoneNumber, :email, :password, :status)");
    query.bindValue(":levelid", userlevel); // binds value from variable
    query.bindValue(":username", username); // binds value from variable
    query.bindValue(":firstname", ui->firstname->text()); // binds value from the user interface
    query.bindValue(":lastname", ui->lastname->text()); // binds value from the user interface
    query.bindValue(":phoneNumber", ui->phoneNumber->text()); //binds value from the user interface
    query.bindValue(":email", ui->email->text()); // binds value from the user interface
    query.bindValue(":password", ui->password->text()); // binds value from the user interface
    query.bindValue(":status", 1); // binds value from variable
    if(query.exec()) // checks if the query executed properly
    {
        QMessageBox msgBox;
        msgBox.setText("User has been added."); // preload message
        msgBox.exec();

        ui->firstname->setText(""); // sets field to be empty
        ui->lastname->setText(""); // sets field to be empty
        username = ""; // sets field to be empty
        ui->userlevel->setCurrentIndex(1); // sets field to be empty
        ui->email->setText(""); // sets field to be empty
        ui->phoneNumber->setText(""); // sets field to be empty
        ui->password->setText(""); // sets field to be empty
        ui->rpt_password->setText(""); // sets field to be empty
        return;
    }

}


void add_user::on_cancelButton_clicked()
{
    close(); // closes the form
}

