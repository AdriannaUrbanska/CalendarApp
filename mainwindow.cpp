#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCalendarWidget>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QDateEdit>
#include <QPalette>

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
    ui->my_date->setText(date.toString("dd MMMM yyyy"));
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
    ui->my_date->setText(date.toString("dd MMMM yyyy"));
    week_setting();
}


void MainWindow::on_Date2_userDateChanged(const QDate &date)
{
    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->my_date->setText(date.toString("dd MMMM yyyy"));
    week_setting();

}

void MainWindow::on_previous_clicked()
{
    QDate date = ui->calendarWidget->selectedDate();
    date = date.addDays(-1);

    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    ui->my_date->setText(date.toString("dd MMMM yyyy"));
    week_setting();
}

void MainWindow::on_next_clicked()
{
    QDate date = ui->calendarWidget->selectedDate();
    date = date.addDays(1);

    ui->calendarWidget->setSelectedDate(date);
    ui->Date->setDate(date);
    ui->Date2->setDate(date);
    ui->my_date->setText(date.toString("dd MMMM yyyy"));
    week_setting();
}
