#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCalendarWidget>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QDateEdit>
#include <QPalette>
#include <QTime>

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting(date);
}
