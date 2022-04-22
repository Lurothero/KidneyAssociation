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
    friend class HomeMenu;



    ~login();

private:


private slots:

    void validateLoginCredentials();



private:
    Database db;
    Ui::login *ui;
};

#endif // LOGIN_H
