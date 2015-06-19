#include "editorform.h"
#include "ui_editorform.h"

#include "childwindoweditor.h"

EditorForm::EditorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Editor");
    this->editWidget = new CodeEditor(this);
}

EditorForm::~EditorForm()
{
    delete this->editWidget;
    delete ui;
}


void EditorForm::resizeEvent(QResizeEvent *evt)
{
    this->editWidget->move(0,0);
    this->editWidget->resize(width(),height());
}
