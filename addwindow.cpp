#include "addwindow.h"
#include "ui_addwindow.h"
#include <QComboBox>
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
    QComboBox *combo = parent()->findChild<QComboBox *>("kind_of_activity");
    combo->addItem(ui->name->toPlainText());

   //if(ui->add_to_all->isChecked())
        //list->addItem(ui->name->toPlainText());

    close();
}
