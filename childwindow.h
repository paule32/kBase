#ifndef CHILDWINDOW_H
#define CHILDWINDOW_H

#include <QtGui>
#include <QWidget>
#include <QMdiSubWindow>

#include "designerform.h"
#include "editorform.h"

class ChildWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    explicit ChildWindow(QWidget *parent = 0);
    ~ChildWindow();

signals:

public slots:

public:
    DesignerForm *designerWindow;
};

#endif // CHILDWINDOW_H
