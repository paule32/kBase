#ifndef EDITORFORM_H
#define EDITORFORM_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QMdiSubWindow>

#include "codeeditor.h"

namespace Ui {
class EditorForm;
}

class EditorForm : public QWidget
{
    Q_OBJECT

public:
    explicit EditorForm(QWidget *parent = 0);
    ~EditorForm();

protected:
    void resizeEvent(QResizeEvent *evt);

public:
    CodeEditor *editWidget;

    Ui::EditorForm *ui;
};

#endif // EDITORFORM_H
