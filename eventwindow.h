#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class EventWindow;
}

class EventWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventWindow(QWidget *parent = 0);
    ~EventWindow();

private:
    Ui::EventWindow *ui;
};

#endif // EVENTWINDOW_H
