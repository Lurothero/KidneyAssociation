#include "homemenu.h"
#include "ui_homemenu.h"

HomeMenu::HomeMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeMenu)
{
    ui->setupUi(this);
}

HomeMenu::~HomeMenu()
{
    delete ui;
}
