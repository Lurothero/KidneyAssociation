#ifndef DOCTORINFORMATION_H
#define DOCTORINFORMATION_H

#include <QWidget>

namespace Ui {
class doctorInformation;
}

class doctorInformation : public QWidget
{
    Q_OBJECT

public:
    explicit doctorInformation(QWidget *parent = nullptr);
    ~doctorInformation();

private:
    Ui::doctorInformation *ui;
};

#endif // DOCTORINFORMATION_H
