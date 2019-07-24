#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCalendarWidget>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QDateEdit>
#include <QPalette>
#include <QTime>

void MainWindow::on_Date2_userDateChanged(const QDate &date)
{
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    week_setting(date);
}
