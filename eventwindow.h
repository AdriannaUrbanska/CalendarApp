#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include <QDialog>

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

private:
    Ui::EventWindow *ui;
};

#endif // EVENTWINDOW_H
