#include "childwindowcomponents.h"
#include "componentsform.h"

ChildWindowComponents::ChildWindowComponents(QWidget *parent) :
    QMdiSubWindow(parent)
{
    cmpWidget = new ComponentsForm(this);
    this->setWidget(cmpWidget);
}

ChildWindowComponents::~ChildWindowComponents()
{
    cmpWidget->~ComponentsForm();
}
