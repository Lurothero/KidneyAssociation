#ifndef HOMEMENU_H
#define HOMEMENU_H

#include <QWidget>
#include <QLCDNumber>
#include <QTime>
#include <ctime>
#include <QTimer>
#include <QLabel>

namespace Ui {
class HomeMenu;
}

class HomeMenu : public QWidget
{
    Q_OBJECT

public:
    explicit HomeMenu(QWidget *parent = nullptr);
    ~HomeMenu();
    void displayDeskMenu();
    void displayDoctorMenu();
    void updateTime(); // updates time from the O.S.

private:
    Ui::HomeMenu *ui;
    QLCDNumber * clock; // private object created for lcd widget
    QLabel * dateLabel;
};

#endif // HOMEMENU_H
