#include "activities.h"
#include "ui_activities.h"
#include <QListWidget>

Activities::Activities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Activities)
{
    ui->setupUi(this);
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
