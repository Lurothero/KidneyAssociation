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
    void loadRecords();
    ~DoctorContact();
    friend class Database;

private slots:
    //void listDoctorRecord();
    void on_AddRecord_BTN_clicked();
    void indexConversion();
    void on_DeleteRecord_BTN_clicked();
    void on_Refresh_BTN_clicked();

private:
    Ui::DoctorContact *ui;
    QStringList doctorData;
    int currentIndex;
};

#endif // DOCTORCONTACT_H
