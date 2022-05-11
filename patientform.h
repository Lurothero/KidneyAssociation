#ifndef PATIENTFORM_H
#define PATIENTFORM_H

#include <QDialog>
#include "database.h"

namespace Ui {
class PatientForm;
}

class PatientForm : public QDialog
{
    Q_OBJECT

public:
    friend class Database;
    explicit PatientForm(QWidget *parent = nullptr);
    ~PatientForm();
    void loadDistrictList();
    void loadPatientStatus();
    void loadsBloodTypes();
    void loadPatientSSNs();

private slots:
    void loadSelectedInformation();


    void on_EditRecord_BTN_clicked();

    void on_SSNCombo_activated(int index);

private:
    Ui::PatientForm *ui;
};

#endif // PATIENTFORM_H
