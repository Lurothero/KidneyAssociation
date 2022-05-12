
/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/
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
