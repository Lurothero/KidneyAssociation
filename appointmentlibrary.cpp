#include "appointmentlibrary.h"

AppointmentLibrary::AppointmentLibrary()
{

}

void AppointmentLibrary::viewAppointment(int id)
{
    QSqlQuery qry;
    qry.prepare( "SELECT FROM appointment WHERE Appointment_id =:id" );
    qry.bindValue(":id",id);
    if( !qry.exec() )
         qDebug() << qry.lastError();
    else
         qDebug( "Opended!" );
}

Appointment *AppointmentLibrary::findAppointment(int id, QString name)
{
    QSqlQuery query;
    query.prepare("SELECT FROM appointment WHERE Appointment_id =:id");
    query.exec();


   while (query.next())
   {
     id = query.value(0).toInt();
     qDebug() << "found" << id;

     QSqlRecord rec = query.record();

     qDebug() << "Number of columns: " << rec.count();

     int idIndex = rec.indexOf("id");
     qDebug() << query.value(idIndex).toInt();
  }
}

void AppointmentLibrary::createAppointment()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO `appointment` (`Appointment_id`,`DoctorID`, `PatientID`, `Treatment_Description`, `Appointment_Cost`,'Appointment_Date') VALUES (DEFAULT, :DoctorID, :PatientID, :Treatment_Description, :Appointment_Cost, :Appointment_Date)");
    qry.bindValue(":DoctorID",doctorId);
    qry.bindValue(":PatientID",patientId);
    qry.bindValue(":Treatment_Description",treatmentDescription);
    qry.bindValue(":Appointment_Cost",appCost);
    qry.bindValue(":Appointment_Date",appDate);
    qry.exec();
}

void AppointmentLibrary::deleteAppointment(int id)
{
    QSqlQuery qry;
    qry.prepare( "DELETE FROM appointment WHERE Appointment_id =:id" );
    qry.bindValue(":id",id);
   if( !qry.exec() )
       qDebug() << qry.lastError();
    else
       qDebug( "Deleted!" );
}

void AppointmentLibrary::updateAppointment(int id)
{
    QSqlQuery qry;
    qry.prepare("UPDATE appointment SET Appointment_ID=:ID WHERE id = :id ");
    qry.bindValue(":id",id );
    if( !qry.exec() )
            qDebug() << qry.lastError();
    else
            qDebug( "Updated!" );

}

void AppointmentLibrary::generateAppointmentReport()
{

}
