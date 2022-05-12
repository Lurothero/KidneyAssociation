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
    if(ui->firstname->text().trimmed() == ""){
        QMessageBox msgBox;
        msgBox.setText("First name field is empty");
        msgBox.exec();
        return;
    }

    if(ui->lastname->text().trimmed() == ""){
        QMessageBox msgBox;
        msgBox.setText("Last name field is empty");
        msgBox.exec();
        return;
    }

    QString username = (ui->firstname->text()[0] + ui->lastname->text());

    if(ui->email->text().trimmed() == ""){
        QMessageBox msgBox;
        msgBox.setText("Email field is empty");
        msgBox.exec();
        return;
    }

    if(ui->phoneNumber->text().trimmed() == ""){
        QMessageBox msgBox;
        msgBox.setText("Phone number field is empty");
        msgBox.exec();
        return;
    }

    if(ui->password->text().trimmed() == ""){
        QMessageBox msgBox;
        msgBox.setText("Password field is empty");
        msgBox.exec();
        return;
    }

    if(ui->rpt_password->text().trimmed() == ""){
        QMessageBox msgBox;
        msgBox.setText("Repeat password field is empty");
        msgBox.exec();
        return;
    }

    int userlevel = ui->userlevel->currentIndex() + 1;


    QSqlQuery query;
    query.prepare("INSERT INTO user (User_id, UserLevel_id, User_name, First_name, Last_name, Phone_number, Email, Password, Status) VALUES (DEFAULT, :levelid, :username, :firstname, :lastname, :phoneNumber, :email, :password, :status)");
    query.bindValue(":levelid", userlevel);
    query.bindValue(":username", username);
    query.bindValue(":firstname", ui->firstname->text());
    query.bindValue(":lastname", ui->lastname->text());
    query.bindValue(":phoneNumber", ui->phoneNumber->text());
    query.bindValue(":email", ui->email->text());
    query.bindValue(":password", ui->password->text());
    query.bindValue(":status", 1);
    if(query.exec()){
        QMessageBox msgBox;
        msgBox.setText("User has been added.");
        msgBox.exec();

        ui->firstname->setText("");
        ui->lastname->setText("");
        username = "";
        ui->userlevel->setCurrentIndex(1);
        ui->email->setText("");
        ui->phoneNumber->setText("");
        ui->password->setText("");
        ui->rpt_password->setText("");


        return;
    }

}


void add_user::on_cancelButton_clicked()
{
    close();
}

