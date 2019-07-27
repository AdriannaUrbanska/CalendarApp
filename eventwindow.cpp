#include "eventwindow.h"
#include "ui_eventwindow.h"
#include <QCalendarWidget>
#include <QDate>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QDateTime>
#include <QTime>
#include <QDebug>
#include <QDialog>
#include <QObject>

EventWindow::EventWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventWindow)
{
    ui->setupUi(this);

    QCalendarWidget *calendar = parent->findChild<QCalendarWidget *>("calendarWidget");
    QDate date = calendar->selectedDate();

    setWindowTitle("Add Event " + date.toString("dd-MM-yyyy"));
    ui->Date_event->setDate(date);
    QDateTime datetime;
    QTime time(0,0);


    datetime.setDate(date);
    datetime.setTime(time);
    ui->start->setDateTime(datetime);
    ui->end->setDateTime(datetime);

    connect(ui->Date_event, SIGNAL(userDateChanged(QDate)), parent, SLOT(week_setting(QDate)));

    //ui->kind_of_activity->addItems();
}

EventWindow::~EventWindow()
{
    delete ui;
}

void EventWindow::on_Date_event_userDateChanged(const QDate &date)
{
    setWindowTitle("Add Event " + date.toString("dd-MM-yyyy"));
    QCalendarWidget *calendar = parent()->findChild<QCalendarWidget *>("calendarWidget");
    QDateEdit *Date = parent()->findChild<QDateEdit *>("Date");
    QDateEdit *Date2 = parent()->findChild<QDateEdit *>("Date2");
    ui->start->setDate(date);

    calendar->setSelectedDate(date);
    Date->setDate(date);
    Date2->setDate(date);
}

void EventWindow::on_add_clicked()
{
    close();
}

void EventWindow::on_start_dateTimeChanged(const QDateTime &dateTime)
{
    if(dateTime.operator >(ui->end->dateTime()))
        ui->end->setDateTime(dateTime);

    ui->end->setMinimumDateTime(dateTime);

    ui->Date_event->setDate(dateTime.date());

    QDate date = dateTime.date();
    QCalendarWidget *calendar = parent()->findChild<QCalendarWidget *>("calendarWidget");
    QDateEdit *Date = parent()->findChild<QDateEdit *>("Date");
    QDateEdit *Date2 = parent()->findChild<QDateEdit *>("Date2");

    calendar->setSelectedDate(date);
    Date->setDate(date);
    Date2->setDate(date);
}
