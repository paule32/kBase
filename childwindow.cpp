#include "childwindow.h"
#include <QMdiSubWindow>

#include "designerform.h"

ChildWindow::ChildWindow(QWidget *parent) :
    QMdiSubWindow(parent)
{
    designerWindow = new DesignerForm(this);
    this->setWidget(designerWindow);
}

ChildWindow::~ChildWindow()
{
    designerWindow->~DesignerForm();
}
