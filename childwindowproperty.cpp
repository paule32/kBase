#include "childwindowproperty.h"
#include <QMdiSubWindow>

ChildWindowProperty::ChildWindowProperty(QWidget *parent) :
    QMdiSubWindow(parent)
{
    propWidget = new PropertyForm(this);
    this->setWidget(propWidget);
}

ChildWindowProperty::~ChildWindowProperty()
{
    propWidget->~PropertyForm();
}
