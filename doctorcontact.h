#ifndef DOCTORCONTACT_H
#define DOCTORCONTACT_H

#include <QDialog>
#include "database.h"
#include <QStringList>

namespace Ui {
class DoctorContact;
}

class DoctorContact : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorContact(QWidget *parent = nullptr);
    ~DoctorContact();
    friend class Database;

private slots:
    //void listDoctorRecord();
    void on_AddRecord_BTN_clicked();

private:
    Ui::DoctorContact *ui;
    QStringList doctorData;
};

#endif // DOCTORCONTACT_H
