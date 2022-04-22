#include "homemenu.h"
#include "ui_homemenu.h"

HomeMenu::HomeMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeMenu)
{
    ui->setupUi(this);

    QTimer * timer = new QTimer(this);
    timer->start(1000);
    updateTime();
    connect(timer, &QTimer::timeout,this,&HomeMenu::updateTime);

    time_t currTime;
    tm* currTm;
    char dateString[100];

    time(&currTime);
    currTm = localtime(&currTime);

    strftime(dateString, 50, "Current Date: %d/%m/%Y", currTm);

    ui->dateLabel->setText(dateString);
}

HomeMenu::~HomeMenu()
{
    delete ui;
}

void HomeMenu::displayDeskMenu()
{
    ui->adminButton->setEnabled(false);
}

void HomeMenu::displayDoctorMenu()
{
  ui->adminButton->setEnabled(false);
  ui->patientButton->setEnabled(false);
  ui->reportButton->setEnabled(false);
  ui->registrationButton->setEnabled(false);
}

void HomeMenu::updateTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
        if ((time.second() % 2) == 0)
        {
            text[2] = ' ';
        }

        ui->clock->display(text);
}
