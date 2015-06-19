/********************************************************************************
** Form generated from reading UI file 'editorform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORFORM_H
#define UI_EDITORFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditorForm
{
public:

    void setupUi(QWidget *EditorForm)
    {
        if (EditorForm->objectName().isEmpty())
            EditorForm->setObjectName(QStringLiteral("EditorForm"));
        EditorForm->resize(400, 300);

        retranslateUi(EditorForm);

        QMetaObject::connectSlotsByName(EditorForm);
    } // setupUi

    void retranslateUi(QWidget *EditorForm)
    {
        EditorForm->setWindowTitle(QApplication::translate("EditorForm", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class EditorForm: public Ui_EditorForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORFORM_H
