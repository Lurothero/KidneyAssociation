#ifndef PATIENTREPORTSDISPLAY_H
#define PATIENTREPORTSDISPLAY_H

#include <QWidget>

namespace Ui {
class patientReportsDisplay;
}

class patientReportsDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit patientReportsDisplay(QWidget *parent = nullptr);
    ~patientReportsDisplay();

public:
    Ui::patientReportsDisplay *ui;
};

#endif // PATIENTREPORTSDISPLAY_H
