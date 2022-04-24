#ifndef PATIENTREGISTRATION_H
#define PATIENTREGISTRATION_H

#include <QWidget>

namespace Ui {
class PatientRegistration;
}

class PatientRegistration : public QWidget
{
    Q_OBJECT

public:
    explicit PatientRegistration(QWidget *parent = nullptr);
    ~PatientRegistration();

private:
    Ui::PatientRegistration *ui;
};

#endif // PATIENTREGISTRATION_H
