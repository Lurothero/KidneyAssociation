#ifndef PATIENTREPORTS_H
#define PATIENTREPORTS_H

#include <QDialog>

class patientReportsDisplay;

namespace Ui {
class PatientReports;
}

class PatientReports : public QDialog
{
    Q_OBJECT

public:
    explicit PatientReports(QWidget *parent = nullptr);
    ~PatientReports();

public slots:
    void generateDeceasedPatientsReport();
    void generatePatientsOnTreatmentReport();
    void generatePatientsNeedingBloodReport();

private:
    Ui::PatientReports *ui;
};

#endif // PATIENTREPORTS_H
