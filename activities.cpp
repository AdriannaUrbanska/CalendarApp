#include "activities.h"
#include "ui_activities.h"
#include <QListWidget>
#include <QMessageBox>

Activities::Activities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Activities)
{
    ui->setupUi(this);
    ui->list->addItem("Birthday");
    ui->list->addItem("Party");
    ui->list->addItem("Anniversary");
    ui->list->addItem("Work");
    ui->list->addItem("Sport");
    ui->list->addItem("Study");
    ui->list->addItem("Other");

    setWindowTitle("Activities");
}

Activities::~Activities()
{
    delete ui;
}

void Activities::on_add_new_clicked()
{
    add_window = new AddWindow(this);
    add_window->show();
}

void Activities::on_delete__clicked()
{
    QMessageBox::StandardButton button = QMessageBox::question(this, "Delete item", "Are you sure you want to delete item?",
                                         QMessageBox::Yes | QMessageBox::No);
    if(button == QMessageBox::Yes)
        delete ui->list->currentItem();
}
