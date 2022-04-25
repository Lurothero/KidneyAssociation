#include "database.h"
#include "homemenu.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
Database::Database()
{


    // start a connection to a MYSQL database suig corresponding driver
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    //setting connection credentials
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("mysql");
    db.setDatabaseName("guiproject");

    if(db.open()){
        qDebug() << "Success connection";

    }else{

         qDebug() << "Database connection refused, please check your credentials...";

    }

}

int Database::loginUser(QString user, QString pass)
{

    QSqlQuery q;
    q.prepare("SELECT userlevel_id FROM user WHERE User_name = :user AND Password = :pass ;");
    q.bindValue(":user",user);
    q.bindValue(":pass",pass);

    q.exec();
    q.first();
    if(q.lastError().text().isEmpty()){//Success

        //return the user permission id

        int idReturn = q.value("UserLevel_id").toInt();

        return idReturn;

    }
    else
    {
        return -1;
    }


}

void Database::addDoctorInformation(QString FirstName, QString LastName, QString phoneNumber, QString emailAddress)
{
  QSqlQuery q;
  q.prepare("INSERT INTO `doctor` (`First Name`, `Last Name`, `Phone Number`, `Email Address`) VALUES (:FName, :LName, :PhoneNum, :Email)");
  q.bindValue(":FName",FirstName);
  q.bindValue(":LName",LastName);
  q.bindValue(":PhoneNum",phoneNumber);
  q.bindValue(":Email",emailAddress);

  q.exec();
  //q.first();
}
