/*
 * Name: Jahmur Lopez, Tadeo Bennett, Rene Allen, Carolee Saunders
 * Class: Graphical User Interface
 * Title: Kidney Association
 * Due Date: 12/05/2022
 * Due Time: 7:30 am for deliverables and 12:30 to 1:00 for presentation
 * Lectures: Thiana Vasquez, Jason Reyes & Vernelle Sylvester
 * Class Section: 1
*/

#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "homemenu.h"
#include <database.h>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    friend class HomeMenu; // declared home menu as a friend class to access its functions
    ~login();

private:


private slots:

    void validateLoginCredentials(); // checking login info before giving access to the main menu



private:
    Database db;
    Ui::login *ui;
};

#endif // LOGIN_H
