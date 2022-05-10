#ifndef PATIENTFORM_H
#define PATIENTFORM_H

#include <QDialog>

namespace Ui {
class PatientForm;
}

class PatientForm : public QDialog
{
    Q_OBJECT

public:
    explicit PatientForm(QWidget *parent = nullptr);
    ~PatientForm();
    void loadDistrictList();
    void loadPatientStatus();


private:
    Ui::PatientForm *ui;
};

#endif // PATIENTFORM_H
