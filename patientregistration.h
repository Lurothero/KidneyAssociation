#ifndef PATIENTREGISTRATION_H
#define PATIENTREGISTRATION_H

#include <QWidget>
#include <database.h>
namespace Ui {
class PatientRegistration;
}

class PatientRegistration : public QWidget
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
