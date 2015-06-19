#include "componentsform.h"
#include "ui_componentsform.h"

#include "designerform.h"
#include "ui_designerform.h"

#include "mainwindow.h"

#include <QDebug>

newObject_onDesigner current_DegignerObject;

ComponentsForm::ComponentsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComponentsForm)
{
    ui->setupUi(this);
}

ComponentsForm::~ComponentsForm()
{
    delete ui;
}

void ComponentsForm::resizeEvent(QResizeEvent *evt)
{
    ui->tabWidget->move(4,4);
    ui->tabWidget->resize(width()-8,height()-8);
}

void ComponentsForm::on_toolButton_2_clicked()
{
    qDebug() << "PushButton prepare add";
    this->setCursor(QCursor(Qt::PointingHandCursor));

    current_DegignerObject = odPushButton;
}

void ComponentsForm::on_toolButton_clicked()
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    current_DegignerObject = odNone;
}
