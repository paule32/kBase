#include "propertyform.h"
#include "ui_propertyform.h"

PropertyForm::PropertyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertyForm)
{
    ui->setupUi(this);
    setWindowTitle("Properties");
}

PropertyForm::~PropertyForm()
{
    delete ui;
}


void PropertyForm::resizeEvent(QResizeEvent *evt)
{
    ui->tabWidget->move(4,4);
    ui->tabWidget->resize(width()-4,height()-4);

    ui->tableWidget->move(2,2);
    ui->tableWidget->resize(
                ui->tabWidget->width() -8,
                ui->tabWidget->height()-42);
}
