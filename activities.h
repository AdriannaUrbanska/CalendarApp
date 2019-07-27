#ifndef ACTIVITIES_H
#define ACTIVITIES_H

#include <QDialog>
#include "addwindow.h"

namespace Ui {
class Activities;
}

class Activities : public QDialog
{
    Q_OBJECT

public:
    explicit Activities(QWidget *parent = 0);
    ~Activities();

private slots:
    void on_add_new_clicked();

    void on_delete__clicked();

private:
    Ui::Activities *ui;
    AddWindow *add_window;
};

#endif // ACTIVITIES_H
