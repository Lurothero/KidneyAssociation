#include "login.h"
#include "ui_login.h"
#include "homemenu.h"

#include <QMessageBox>
#include <QSqlDatabase>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    //Validate what is currently entered!
    connect(ui->loginButton,SIGNAL(clicked()),this,SLOT(validateLoginCredentials()));

    setWindowTitle("Kidney's Association");
    this->setWindowIcon(QIcon(":/kidneyIcon.png"));

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


    qDebug() << "User: " << ui->UsernameEdit->text();
    qDebug() <<  "Pass: " << ui->PasswordEdit->text();

    QString username = ui->UsernameEdit->text();
    QString password = ui->PasswordEdit->text();



    switch ( db.loginUser(username,password)){

    case -1:
    {
        //AN Internal Error has occured!
        QMessageBox::critical(this,tr("Internal Server Error"),tr("An Internal Error occured, Please contact the administrators!"),QMessageBox::Ok);
        //Close the application
        break;

    }//Case -1

    case 0:{
    //The user credential was incorrect

     QMessageBox::warning(this,tr("Invalid Login!"),tr("The information is incorrect, please try again!"),QMessageBox::Ok);

    break;
    }

    case 1:{

        //User logged in as ADMIN
        QMessageBox::information(this,tr("Welcome ADMIN"),tr("Successfully logged in as %1").arg(username),QMessageBox::Ok);


        //Create a main menu
        HomeMenu * mainMenu = new HomeMenu();
        mainMenu->show();
        this->close();

        break;
    }

    case 2:{
        //User logged in as DESK
        QMessageBox::information(this,tr("Welcome DESK"),tr("Successfully logged in as %1").arg(username),QMessageBox::Ok);

        //Create a main menu with restricted features
        HomeMenu * mainMenu = new HomeMenu();
        mainMenu->show();
        mainMenu->displayDeskMenu();

        //this->close();
        break;
    }

    case 3:{
        //User logged in as DOCTOR
        QMessageBox::information(this,tr("Welcome DOCTOR"),tr("Successfully logged in as %1").arg(username),QMessageBox::Ok);

        //Create a main menu with restricted features
        HomeMenu * mainMenu = new HomeMenu();
        mainMenu->show();
        mainMenu->displayDoctorMenu();
        break;
    }

    }//switch end statement



}//validateLoginCredentials()
