#include "childwindoweditor.h"
#include <QMdiSubWindow>

#include <editorform.h>

ChildWindowEditor::ChildWindowEditor(QWidget *parent) :
    QMdiSubWindow(parent)
{
    editWidget = new EditorForm(this);
    this->setWidget(editWidget);
}

ChildWindowEditor::~ChildWindowEditor()
{
    editWidget->~EditorForm();
}
