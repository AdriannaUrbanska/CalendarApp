#include "addwindow.h"
#include "ui_addwindow.h"

AddWindow::AddWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_add_activity_button_clicked()
{
    close();
}
