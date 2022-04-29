#ifndef PATIENTREGISTRATION_H
#define PATIENTREGISTRATION_H

#include <QDialog>
#include "database.h"

namespace Ui {
class PatientRegistration;
}

class PatientRegistration : public QDialog
{
    Q_OBJECT

public:
    explicit PatientRegistration(QWidget *parent = nullptr);
    ~PatientRegistration();

private slots:
    void addRecord();

private:
    Ui::PatientRegistration *ui;
    Database db;
};

#endif // PATIENTREGISTRATION_H
