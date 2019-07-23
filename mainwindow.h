#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void week_setting();

    void on_calendarWidget_clicked(const QDate &date);

    void on_Date_userDateChanged(const QDate &date);

    void on_Date2_userDateChanged(const QDate &date);

    void on_previous_clicked();

    void on_next_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
