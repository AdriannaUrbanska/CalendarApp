#include "addwindow.h"
#include "ui_addwindow.h"
#include <QTextEdit>
#include <QListWidget>
#include <QDebug>
#include <QLabel>

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
    setWindowTitle("Add activity");
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_add_activity_button_clicked()
{
    QListWidget *list = parent()->findChild<QListWidget *>("list");
    list->addItem(ui->name->toPlainText());

    close();
}
