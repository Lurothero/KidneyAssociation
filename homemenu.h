#ifndef HOMEMENU_H
#define HOMEMENU_H

#include <QWidget>

namespace Ui {
class HomeMenu;
}

class HomeMenu : public QWidget
{
    Q_OBJECT

public:
    explicit HomeMenu(QWidget *parent = nullptr);
    ~HomeMenu();

private:
    Ui::HomeMenu *ui;
};

#endif // HOMEMENU_H
