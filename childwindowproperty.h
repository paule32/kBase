#ifndef CHILDWINDOWPROPERTY_H
#define CHILDWINDOWPROPERTY_H

#include <QMdiSubWindow>
#include "propertyform.h"

class ChildWindowProperty : public QMdiSubWindow
{
    Q_OBJECT
public:
    explicit ChildWindowProperty(QWidget *parent = 0);
    ~ChildWindowProperty();

signals:

public slots:

private:
    PropertyForm *propWidget;
};

#endif // CHILDWINDOWPROPERTY_H
