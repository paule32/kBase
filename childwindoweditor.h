#ifndef CHILDWINDOWEDITOR_H
#define CHILDWINDOWEDITOR_H

#include <QMdiSubWindow>

#include "editorform.h"

class ChildWindowEditor : public QMdiSubWindow
{
    Q_OBJECT
public:
    explicit ChildWindowEditor(QWidget *parent = 0);
    ~ChildWindowEditor();

signals:

public slots:

public:
    EditorForm *editWidget;
};

#endif // CHILDWINDOWEDITOR_H
