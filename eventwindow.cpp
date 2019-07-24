#include "eventwindow.h"
#include "ui_eventwindow.h"
#include <QCalendarWidget>
#include <QDate>

EventWindow::EventWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventWindow)
{
    ui->setupUi(this);

    QCalendarWidget *calendar = parent->findChild<QCalendarWidget *>("calendarWidget");
    QDate date = calendar->selectedDate();

    setWindowTitle(date.toString("dd-MM-yyyy"));

}

EventWindow::~EventWindow()
{
    delete ui;
}
