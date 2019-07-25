#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include <QDialog>
#include "addwindow.h"

namespace Ui {
class EventWindow;
}

class EventWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventWindow(QWidget *parent = 0);
    ~EventWindow();

private slots:
    void on_Date_event_userDateChanged(const QDate &date);

    void on_add_clicked();

    void on_start_dateTimeChanged(const QDateTime &dateTime);

    void on_add_new_clicked();

private:
    Ui::EventWindow *ui;
    AddWindow *add_window;
};

#endif // EVENTWINDOW_H
