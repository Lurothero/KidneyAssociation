#include "database.h"
#include "homemenu.h"

Database::Database()
{


    // start a connection to a MYSQL database suig corresponding driver
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    //setting connection credentials
    db.setHostName("127.0.0.1");
    db.setUserName("jahmur");
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

void Database::loadDoctorIds()
{
  QSqlQuery q;

  if(q.exec("SELECT * FROM doctor"))
  {
     while(q.next())
     {
         docIds.append(q.value(0).toString());
     }
  }
}

void Database::loadPatientIds()
{
    QSqlQuery q;
    if(q.exec("SELECT * FROM patient"))
    {
        while(q.next())
        {
           patientIds.append(q.value(0).toString());
        }
    }
}

void Database::loadAppointmentRecords()
{
  QSqlQuery q;
  if(q.exec("SELECT * FROM appointment"))
  {
      while(q.next())
      {
          appointRecord.append(q.value(0).toString() + " " + q.value(1).toString() + " " + q.value(2).toString() + " " + q.value(3).toString() + " "
                               + q.value(4).toString() + " "+ q.value(5).toString());
      }
  }
}

void Database::loadAppointDescription()
{
    QSqlQuery q;
    if(q.exec("SELECT * FROM appointment"))
    {
        while(q.next())
        {
            AppointDescription.append(q.value(3).toString());
        }
    }
}

void Database::deleteDoctorInformation(int row)
{
  QSqlQuery q; // declare query object

  q.prepare("DELETE FROM doctor WHERE doctor_id = :id");
  q.bindValue(":id",row);
  q.exec();

  qDebug() << "Current row deleted: " << row;
}

void Database::insertingAppointmentData(int appoint_id, int doc_id, int patient_id, QString description, float cost, QString date)
{
  QSqlQuery q;
  // prepares to insert data from doctor contact form and updates the database
  q.prepare("INSERT INTO appointment (Appointment_id,Doctor_id, Patient_id, Treatment_description, Appointment_cost,Appointment_date) VALUES (:ID, :docID, :patID, :description, :cost, :date)");
  q.bindValue(":ID",appoint_id);
  q.bindValue(":docID",doc_id);
  q.bindValue(":patID",patient_id);
  q.bindValue(":description",description);
  q.bindValue(":cost",cost);
  q.bindValue(":date",date);
  q.exec();

}

void Database::loadSocialSecurityNumbers()
{
    QSqlQuery q;
    if(q.exec("SELECT * FROM patient"))
    {
        while(q.next())
        {
            SocialSecurityNumbers.append(q.value(6).toString().toInt());
        }
    }
}

void Database::loadStatus()
{
    QSqlQuery q;
    if(q.exec("SELECT * FROM patient"))
    {
        while(q.next())
        {
            StatusList.append(q.value(5).toString().toInt());
        }
    }
}

void Database::EditPatientRecord()
{

}

bool Database::addPatientRecord(QString firstName, QString lastName, QString phoneNumber, QString email, int status, QString socialSecurityNumber, QString dateOfBirth, QString gender, QString address, QString district, QString patientStatus, int bloodPressure, int heartRate, int pulse, float bloodSugar, float weight, bool diabetesType1, bool diabetesType2, bool eyeDamage, int yearsWithDiabetes, int yearsWithHypertension, bool urinatingProblems, QString bloodType, QString urineLeukocytes, QString urineNitrite, QString urineProtein, QString urinePH, bool urineBlood, QString urineSG, QString urineKetones, QString urineGlucose, QString urineBilirubin)
{
    /*

            firstName
            lastName
            phoneNumber

            email
            status
            socialSecurityNumber

            dateOfBirth
            gender
            address

            district
            patientStatus
            bloodPressure

            heartRate
            pulse,  bloodSugar
            weight

            diabetesType1
            diabetesType2
            eyeDamage,
            yearsWithDiabetes
            yearsWithHypertension
            urinatingProblems
            bloodType
            urineLeukocytes
            urineNitrite
            urineProtein
            urinePH
            urineBlood
            urineSG
            urineKetones
            urineGlucose
            urineBilirubin


*/
}



