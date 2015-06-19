#ifndef CHILDWINDOWCOMPONENTS_H
#define CHILDWINDOWCOMPONENTS_H

#include <QMdiSubWindow>
#include "componentsform.h"

class ChildWindowComponents : public QMdiSubWindow
{
    Q_OBJECT
public:
    explicit ChildWindowComponents(QWidget *parent = 0);
    ~ChildWindowComponents();

signals:

public slots:

private:
    ComponentsForm *cmpWidget;
};

#endif // CHILDWINDOWCOMPONENTS_H
