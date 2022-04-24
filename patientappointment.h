#ifndef PATIENTAPPOINTMENT_H
#define PATIENTAPPOINTMENT_H

#include <QWidget>

namespace Ui {
class PatientAppointment;
}

class PatientAppointment : public QWidget
{
    Q_OBJECT

public:
    explicit PatientAppointment(QWidget *parent = nullptr);
    ~PatientAppointment();

private:
    Ui::PatientAppointment *ui;
};

#endif // PATIENTAPPOINTMENT_H
