/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef DOCTORCONTACT_H
#define DOCTORCONTACT_H

#include <QDialog>
#include "database.h"
#include <QStringList>
#include <QSqlQuery>
#include <QStringTokenizer>
#include <sstream>

namespace Ui {
class DoctorContact;
}

class DoctorContact : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorContact(QWidget *parent = nullptr);
    void loadRecords(); // loads all doctor records upon start up of the program
    ~DoctorContact();
    friend class Database; // declared database a friend class to access other functions & data members

private slots:

    void on_AddRecord_BTN_clicked(); // add records to the database
    void indexConversion(); // converts to the proper index number for the database
    void on_DeleteRecord_BTN_clicked(); // deletes selected record

private:
    Ui::DoctorContact *ui;
    QStringList doctorData;
    int currentIndex;
};

#endif // DOCTORCONTACT_H
