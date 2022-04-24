#ifndef PATIENTRECORDS_H
#define PATIENTRECORDS_H

#include <QWidget>

namespace Ui {
class PatientRecords;
}

class PatientRecords : public QWidget
{
    Q_OBJECT

public:
    explicit PatientRecords(QWidget *parent = nullptr);
    ~PatientRecords();



private:
    Ui::PatientRecords *ui;
};

#endif // PATIENTRECORDS_H
