#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCalendarWidget>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QDateEdit>
#include <QPalette>
#include <QTime>

void MainWindow::on_Date_userDateChanged(const QDate &date)
{
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));
    ui->calendarWidget->setSelectedDate(date);
    ui->Date2->setDate(date);
    week_setting(date);
}

void MainWindow::on_day1_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));

    date = date.addDays(1-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting(date);
}

void MainWindow::on_day2_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));

    date = date.addDays(2-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting(date);
}

void MainWindow::on_day3_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));

    date = date.addDays(3-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting(date);
}

void MainWindow::on_day4_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));

    date = date.addDays(4-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting(date);
}

void MainWindow::on_day5_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));

    date = date.addDays(5-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting(date);
}

void MainWindow::on_day6_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));

    date = date.addDays(6-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting(date);
}

void MainWindow::on_day7_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));

    date = date.addDays(7-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting(date);
}

