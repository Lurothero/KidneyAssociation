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
  QSqlQuery q; // QSqlQuery object created

  int id = int();

  // prepares to insert data from doctor contact form and updates the database
  q.prepare("INSERT INTO `doctor` (`doctor_id`,`First Name`, `Last Name`, `Phone Number`, `Email Address`) VALUES (:ID, :FName, :LName, :PhoneNum, :Email)");
  q.bindValue(":ID",id);
  q.bindValue(":FName",FirstName);
  q.bindValue(":LName",LastName);
  q.bindValue(":PhoneNum",phoneNumber);
  q.bindValue(":Email",emailAddress);
  q.exec();

}

void Database::loadDoctorInformation()
{
 QSqlQuery q; // declare query object

 if(q.exec("SELECT * FROM doctor")) // checks if query is selecting all records
 {
     while(q.next()) // cycling through each row
     {
         // adds each record to the QList vector
         docRecord.append(q.value(0).toString() + " " + q.value(1).toString() + " " + q.value(2).toString() + " " + q.value(3).toString() + " " + q.value(4).toString());
     }
 }
 else
 {
     qDebug() << "The query didnt work";
 }

   //docRecord.removeDuplicates();

 qDebug() << "List of items" << docRecord << "\n"; // outputs to the console
}

void Database::deleteDoctorInformation(int row)
{
  QSqlQuery q; // declare query object

  q.prepare("DELETE FROM doctor WHERE doctor_id = :id");
  q.bindValue(":id",row);
  q.exec();

  qDebug() << "Current row deleted: " << row;
}


