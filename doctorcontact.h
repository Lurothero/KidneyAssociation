#ifndef DOCTORCONTACT_H
#define DOCTORCONTACT_H

#include <QDialog>
#include "database.h"

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
    //void AddDoctorRecord();
    void on_AddRecord_BTN_clicked();

private:
    Ui::DoctorContact *ui;
};

#endif // DOCTORCONTACT_H
