/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

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

    // creates query to selected a specific user from the user table in the database

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
  // Sql query to load all doctor IDs from the doctor table in the database
  QSqlQuery q;

  if(q.exec("SELECT * FROM doctor"))
  {
     while(q.next()) // looping through each record
     {
         docIds.append(q.value(0).toString()); // adds record to vector
     }
  }
}

void Database::loadPatientIds()
{
    // Sql query to load all patient IDs from the doctor table in the database
    QSqlQuery q;
    if(q.exec("SELECT * FROM patient"))
    {
        while(q.next()) // looping through each record
        {
           patientIds.append(q.value(0).toString()); // adds record to vector
        }
    }
}

void Database::loadAppointmentRecords()
{
    // Sql query to load all appointment records from the doctor table in the database
  QSqlQuery q;
  if(q.exec("SELECT * FROM appointment"))
  {
      while(q.next()) // looping through each record
      {
          appointRecord.append(q.value(0).toString() + " " + q.value(1).toString() + " " + q.value(2).toString() + " " + q.value(3).toString() + " "
                               + q.value(4).toString() + " "+ q.value(5).toString()); // adds record to vector
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
            SocialSecurityNumbers.append(q.value(6).toString());
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
            StatusList.append(q.value(5).toString());
        }
    }
}

void Database::loadPatientBloodType()
{
    QSqlQuery q;
    if(q.exec("SELECT * FROM patient"))
    {
        while(q.next())
        {
            patientBloodTypes.append(q.value(24).toString());
        }
    }
}

void Database::loadDistrictList()
{
    QSqlQuery q;
    if(q.exec("SELECT * FROM patient"))
    {
        while(q.next())
        {
            patientLocations.append(q.value(10).toString());
        }
    }
}

void Database::EditPatientRecord(int SSN, QString FName, QString LName, QString phoneNumber, QString DOB, QString Address)
{
  QSqlQuery q;
  q.prepare("UPDATE patient SET First_name = ':FName', Last_name = ':LName', Phone_number = ':phoneNumber', Date_of_birth = ':DOB', Address = ':address'"
            "WHERE SocialSecurityNumber = ':SSN'");
  q.bindValue(":FName",FName);
  q.bindValue(":LName",LName);
  q.bindValue(":phoneNumber",phoneNumber);
  q.bindValue(":DOB",DOB);
  q.bindValue(":address",Address);
  q.bindValue(":SSN",SSN);
  q.exec();

  if(!q.exec())
      qDebug() << "Nothing was edited in patient database";
}

void Database::selectedSSN(int SSN)
{
  QSqlQuery q;
  q.prepare("SELECT First_name, Last_name, Phone_number,Date_of_birth, Address FROM patient WHERE SocialSecurityNumber = :SSN");
  q.bindValue(":SSN",SSN);
  q.exec();

  q.next();
  FirstName = q.value(0).toString();
  LastName = q.value(1).toString();
  PhoneNumber = q.value(2).toString();
  DOB = q.value(3).toString();
  Address = q.value(4).toString();


//  if(q.exec("SELECT First_name, Last_name, Phone_number,Date_of_birth FROM patient WHERE SocialSecurityNumber = :SSN"))
//  {
//      q.bindValue(":SSN",SSN);
//      q.first();
//     while(q.next())
//     {
//         FirstName = q.value(1).toString();
//         LastName = q.value(2).toString();
//         PhoneNumber = q.value(3).toString();
//         DOB = q.value(6).toString();
//     }
//  }

  if(!q.exec())
      qDebug() << "Social Security row wasn't selected";


  qDebug() << FirstName << "\n";
  qDebug() << LastName << "\n";
  qDebug() << PhoneNumber << "\n";
  qDebug() << DOB << "\n";
}

bool Database::addPatientRecord(QString firstName, QString lastName, QString phoneNumber, QString email, int status, QString socialSecurityNumber, QString dateOfBirth, QString gender, QString address, QString district, QString patientStatus, int bloodPressure, int heartRate, float bloodSugar, float weight, bool diabetesType1, bool diabetesType2, bool eyeDamage, int yearsWithDiabetes, int yearsWithHypertension, bool urinatingProblems, QString urinatingProblem_Description, QString bloodType, QString urineLeukocytes, QString urineNitrite, QString urineProtein, QString urinePH, bool urineBlood, QString urineSG, QString urineKetones, QString urineGlucose, QString urineBilirubin)

{

    //Inserting everything

    QSqlQuery q;
    //Binding all 31 arguments


    q.prepare("INSERT INTO patient( `First_name`, `Last_name`, `Phone_number`, `Email`, `Status`, `SocialSecurityNumber`, `Date_of_birth`, `Gender`, `Address`, `District`, `Patient_status`, `Blood_pressure`, `Heart_rate`, `Blood_sugar`, `Weight`, `Diabetes_type1`, `Diabetes_type2`, `Eye_damage`, `Years_with_diabetes`, `Years_with_hypertension`, `Urinating_problems`, `Urinating_problems_description`, `BloodType_id`) "
              "VALUES"
               "(:firstName,:lastName,:phoneNumber,:email,:status,:ssn,:dob,:gender,:addr,:district,:patientStatus,:pressure,:rate,:sugar,:weight,:diabetesType1,:diabetesType2,:eyeDamage,:yearsWithDiabetes,:yearsWithHypertension,:UrineProblem,:UrineProblemDescription,:bloodTypeID)"
                );

    q.bindValue(":firstName",firstName);
    q.bindValue(":lastName",lastName);
    q.bindValue(":phoneNumber",phoneNumber);
    q.bindValue(":email",email);
    q.bindValue(":status",status);
    q.bindValue(":ssn",socialSecurityNumber);
    q.bindValue(":dob",dateOfBirth);
    q.bindValue(":gender",gender);
    q.bindValue(":addr",address);
    q.bindValue(":district",district);
    q.bindValue(":patientStatus",patientStatus);
    q.bindValue(":pressure",bloodPressure);
    q.bindValue(":rate",heartRate);
    q.bindValue(":sugar",bloodSugar);
    q.bindValue(":weight",weight);
    q.bindValue(":diabetesType1",diabetesType1);
    q.bindValue(":diabetesType2",diabetesType2);
    q.bindValue(":eyeDamage",eyeDamage);
    q.bindValue(":yearsWithDiabetes",yearsWithDiabetes);
    q.bindValue(":yearsWithHypertension",yearsWithHypertension);
    q.bindValue(":UrineProblem",urinatingProblems);
    q.bindValue(":UrineProblemDescription",urinatingProblem_Description);
    q.bindValue(":bloodTypeID",bloodType);


    q.exec();


    if(!q.lastError().text().isEmpty()){

        qDebug() << "An error had occured during patient insert!";

        qDebug() << q.lastError().text();
        return false;

    }

    q.prepare("SELECT LAST_INSERT_ID()");

    q.exec();

    if(!q.lastError().text().isEmpty()){

        qDebug() << "An error had occured during LAST_INSERT_RETURN!";

        qDebug() << q.lastError().text();
        return false;

    }
    q.next();

    int id_patient = q.value(0).toInt();

    qDebug() << id_patient;


    q.prepare("INSERT INTO urinesampleinfo (`Urine_leukocytes`, `Urine_nitrite`, `Urine_protein`, `Urine_ph`, `Urine_blood`, `Urine_sg`, `Urine_ketones`, `Glucose`, `Urine_bilirubin`)"
              "VALUES"
              "(:urineLeukocytes,:urineNitrite,:urineProtein,:urinePH,:urineBlood,:urineSG,:urineKetones,:urineGlucose,:urineBilirubin)");



    q.bindValue(":urineLeukocytes",urineLeukocytes);
    q.bindValue(":urineNitrite",urineNitrite);
    q.bindValue(":urineProtein",urineProtein);
    q.bindValue(":urinePH",urinePH);
    q.bindValue(":urineBlood",urineBlood);
    q.bindValue(":urineSG",urineSG);
    q.bindValue(":urineKetones",urineKetones);
    q.bindValue(":urineGlucose",urineGlucose);
    q.bindValue(":urineBilirubin",urineBilirubin);

    q.exec();

    if(!q.lastError().text().isEmpty()){

        qDebug() << "An error had occured during urinesampleinfo insert!";

        qDebug() << q.lastError().text();
        return false;

    }

    q.prepare("SELECT LAST_INSERT_ID()");

    q.exec();

    if(!q.lastError().text().isEmpty()){

        qDebug() << "An error had occured during LAST_INSERT_RETURN!";

        qDebug() << q.lastError().text();
        return false;

    }
    q.next();

    int id_urineSampleInfo = q.value(0).toInt();

    qDebug() << id_urineSampleInfo;


        //Now that we have the last saved ID, we can add it to
        q.prepare("UPDATE patient SET UrineSampleInfo_id = :sampleID  WHERE Patient_id = :patientID");
        q.bindValue(":sampleID",id_urineSampleInfo);
        q.bindValue(":patientID",id_patient);


        q.exec();


        if(!q.lastError().text().isEmpty()){

            qDebug() << "An error had occured during Patient UPDATE!";

            qDebug() << q.lastError().text();
            return false;

        }


        //Update Urine table
        q.prepare("UPDATE urinesampleinfo SET PatientID = :patientID WHERE UrineSampleInfo_id = :sampleID");
        q.bindValue(":sampleID",id_urineSampleInfo);
        q.bindValue(":patientID",id_patient);


        q.exec();


        if(!q.lastError().text().isEmpty()){

            qDebug() << "An error had occured during Patient UPDATE!";

            qDebug() << q.lastError().text();
            return false;

        }






return true;

}



