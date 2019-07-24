#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCalendarWidget>
#include <QString>
#include <QDate>
#include <QDebug>
#include <QDateEdit>
#include <QPalette>
#include <QTime>
#include <QMessageBox>
#include <QWidget>
#include <QMouseEvent>

void MainWindow::week_setting(const QDate &date1)
{
    int day_number = date1.dayOfWeek();

    ui->day->setText(date1.toString("dd"));
    ui->day_of_week->setText(date1.toString("dddd"));

    QDate date = date1.addDays(1-day_number);

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
    QDate date = QDate::currentDate();

    week_setting(date);
    setWindowTitle("CalendarApp " + date.toString("dd-MM-yyyy"));
    ui->tab->setCurrentIndex(0);

    ui->Date->setDate(date);
    ui->Date2->setDate(date);

    QString time_string = QTime::currentTime().toString("hh:mm:ss");
    QString date_string = QDate::currentDate().toString("dd MMMM yyyy ");
    ui->hour->setText(date_string + time_string);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_function()));
    timer->start(1000);

    connect(ui->calendarWidget, SIGNAL(activated(QDate)), this, SLOT(add_event(QDate)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timer_function()
{
    QTime timer = QTime::currentTime();

    QString time_string = timer.toString("hh:mm:ss");
    QString date_string = QDate::currentDate().toString("dd MMMM yyyy ");
    ui->hour->setText(date_string + time_string);
}

void MainWindow::on_actionExit_triggered()
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, "Exit", "Are you sure?", QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::Yes)
        QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About",
                       "Qt Calendar Application \n"
                       "Author: Adrianna Urbańska \n"
                       "Date: " + QDate::currentDate().toString("dd-MM-yyyy"));
}

void MainWindow::add_event(const QDate &date)
{
    event_window = new EventWindow(this);
    event_window->show();
}


void MainWindow::on_actionAdd_new_event_triggered()
{
    QDate date = ui->calendarWidget->selectedDate();
    add_event(date);
}
