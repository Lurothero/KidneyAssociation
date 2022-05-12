#ifndef ADD_USER_H
#define ADD_USER_H

#include <QDialog>

namespace Ui {
class add_user;
}

class add_user : public QDialog
{
    Q_OBJECT

public:
    explicit add_user(QWidget *parent = nullptr);
    ~add_user();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::add_user *ui;
};

#endif // ADD_USER_H
