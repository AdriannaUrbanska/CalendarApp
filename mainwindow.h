#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "eventwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void week_setting(const QDate &date);

    void on_calendarWidget_clicked(const QDate &date);

    void on_Date_userDateChanged(const QDate &date);

    void on_Date2_userDateChanged(const QDate &date);

    void timer_function();

    void on_day1_clicked();

    void on_day2_clicked();

    void on_day3_clicked();

    void on_day4_clicked();

    void on_day5_clicked();

    void on_day6_clicked();

    void on_day7_clicked();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void add_event(const QDate &date);

    void on_actionAdd_new_event_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    EventWindow *event_window;
};

#endif // MAINWINDOW_H
