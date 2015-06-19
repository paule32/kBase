#include "designerform.h"
#include "designergraphicsview.h"
#include "ui_designerform.h"

#include "childwindow.h"

DesignerForm::DesignerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DesignerForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Designer Window");
}

DesignerForm::~DesignerForm()
{
    delete ui;
}


void DesignerForm::resizeEvent(QResizeEvent *evt)
{
    ui->graphicsView->move(0,0);
    ui->graphicsView->resize(width(),height());
}
