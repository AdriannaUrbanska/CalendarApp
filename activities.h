#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include <QDialog>

namespace Ui {
class Activities;
}

class Activities : public QDialog
{
    Q_OBJECT

public:
    explicit Activities(QWidget *parent = 0);
    ~Activities();

private:
    Ui::Activities *ui;
};

#endif // ACTIVITIES_H
