#ifndef PATIENTREPORTS_H
#define PATIENTREPORTS_H

#include <QDialog>

namespace Ui {
class PatientReports;
}

class PatientReports : public QDialog
{
    Q_OBJECT

public:
    explicit PatientReports(QWidget *parent = nullptr);
    ~PatientReports();

private:
    Ui::PatientReports *ui;
};

#endif // PATIENTREPORTS_H
