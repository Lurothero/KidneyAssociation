#ifndef PATIENTFORM_H
#define PATIENTFORM_H

#include <QWidget>

namespace Ui {
class PatientForm;
}

class PatientForm : public QWidget
{
    Q_OBJECT

public:
    explicit PatientForm(QWidget *parent = nullptr);
    ~PatientForm();



private:
    Ui::PatientForm *ui;
};

#endif // PATIENTFORM_H
