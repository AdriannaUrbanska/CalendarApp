#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCalendarWidget>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QDateEdit>
#include <QPalette>
#include <QTime>

void MainWindow::week_setting()
{
    QDate date = ui->calendarWidget->selectedDate();
    int day_number = date.dayOfWeek();

    ui->day->setText(date.toString("dd"));
    ui->day_of_week->setText(date.toString("dddd"));

    date = date.addDays(1-day_number);

    ui->day1->setText(date.toString("dd"));
    ui->day2->setText(date.addDays(1).toString("dd"));
    ui->day3->setText(date.addDays(2).toString("dd"));
    ui->day4->setText(date.addDays(3).toString("dd"));
    ui->day5->setText(date.addDays(4).toString("dd"));
    ui->day6->setText(date.addDays(5).toString("dd"));
    ui->day7->setText(date.addDays(6).toString("dd"));

    ui->day1->setStyleSheet("background-color: normal;");
    ui->day2->setStyleSheet("background-color: normal;");
    ui->day3->setStyleSheet("background-color: normal;");
    ui->day4->setStyleSheet("background-color: normal;");
    ui->day5->setStyleSheet("background-color: normal;");
    ui->day6->setStyleSheet("background-color: normal;");
    ui->day7->setStyleSheet("background-color: normal;");

    switch(day_number)
    {
        case 1:
            ui->day1->setStyleSheet("background-color: rgb(85, 170, 255);");
            break;
        case 2:
            ui->day2->setStyleSheet("background-color: rgb(85, 170, 255);");
            break;
        case 3:
            ui->day3->setStyleSheet("background-color: rgb(85, 170, 255);");
            break;
        case 4:
            ui->day4->setStyleSheet("background-color: rgb(85, 170, 255);");
            break;
        case 5:
            ui->day5->setStyleSheet("background-color: rgb(85, 170, 255);");
            break;
        case 6:
            ui->day6->setStyleSheet("background-color: rgb(85, 170, 255);");
            break;
        case 7:
            ui->day7->setStyleSheet("background-color: rgb(85, 170, 255);");
            break;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    week_setting();
    ui->tab->setCurrentIndex(0);
    QDate date = ui->calendarWidget->selectedDate();
    ui->Date->setDate(date);
    ui->Date2->setDate(date);

    QString time_string = QTime::currentTime().toString("hh:mm:ss");
    QString date_string = QDate::currentDate().toString("dd MMMM yyyy ");
    ui->hour->setText(date_string + time_string);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_function()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting();
}

void MainWindow::on_Date_userDateChanged(const QDate &date)
{
    ui->calendarWidget->setSelectedDate(date);
    ui->Date2->setDate(date);
    week_setting();
}


void MainWindow::on_Date2_userDateChanged(const QDate &date)
{
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    week_setting();

}

void MainWindow::timer_function()
{
    QTime timer = QTime::currentTime();

    QString time_string = timer.toString("hh:mm:ss");
    QString date_string = QDate::currentDate().toString("dd MMMM yyyy ");
    ui->hour->setText(date_string + time_string);
}

void MainWindow::on_day1_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();

    date = date.addDays(1-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting();
}

void MainWindow::on_day2_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();

    date = date.addDays(2-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting();
}

void MainWindow::on_day3_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();

    date = date.addDays(3-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting();
}

void MainWindow::on_day4_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();

    date = date.addDays(4-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting();
}

void MainWindow::on_day5_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();

    date = date.addDays(5-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting();
}

void MainWindow::on_day6_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();

    date = date.addDays(6-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting();
}

void MainWindow::on_day7_clicked()
{
    QDate date = ui->Date->date();
    int day_of_week = date.dayOfWeek();

    date = date.addDays(7-day_of_week);
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    week_setting();
}
