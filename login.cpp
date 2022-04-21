#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    //Validate what is currently entered!
    connect(ui->loginButton,SIGNAL(clicked()),this,SLOT(validateLoginCredentials()));

}


login::~login()
{
    delete ui;
}

void login::validateLoginCredentials()
{
    //Create a database connection? Or let it be handled by a database class system?
    //Pass in the password and user
    //Send this data to the database


    qDebug() <<  "Pass: " << ui->PasswordEdit->text();
    qDebug() << "User: " << ui->UsernameEdit->text();


}
