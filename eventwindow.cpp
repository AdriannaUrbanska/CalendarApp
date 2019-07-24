#include "eventwindow.h"
#include "ui_eventwindow.h"
#include <QCalendarWidget>
#include <QDate>
#include <QDateEdit>

EventWindow::EventWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventWindow)
{
    ui->setupUi(this);

    QCalendarWidget *calendar = parent->findChild<QCalendarWidget *>("calendarWidget");
    QDate date = calendar->selectedDate();

    setWindowTitle(date.toString("dd-MM-yyyy"));
    ui->Date_event->setDate(date);

    connect(ui->Date_event, SIGNAL(userDateChanged(QDate)), parent, SLOT(week_setting(QDate)));
}

EventWindow::~EventWindow()
{
    delete ui;
}

void EventWindow::on_Date_event_userDateChanged(const QDate &date)
{
    setWindowTitle(date.toString("dd-MM-yyyy"));
    QCalendarWidget *calendar = parent()->findChild<QCalendarWidget *>("calendarWidget");
    QDateEdit *Date = parent()->findChild<QDateEdit *>("Date");
    QDateEdit *Date2 = parent()->findChild<QDateEdit *>("Date2");

    calendar->setSelectedDate(date);
    Date->setDate(date);
    Date2->setDate(date);
}
