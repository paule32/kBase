/********************************************************************************
** Form generated from reading UI file 'designerform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESIGNERFORM_H
#define UI_DESIGNERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <designergraphicsview.h>

QT_BEGIN_NAMESPACE

class Ui_DesignerForm
{
public:
    DesignerGraphicsView *graphicsView;

    void setupUi(QWidget *DesignerForm)
    {
        if (DesignerForm->objectName().isEmpty())
            DesignerForm->setObjectName(QStringLiteral("DesignerForm"));
        DesignerForm->resize(405, 198);
        graphicsView = new DesignerGraphicsView(DesignerForm);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(30, 10, 256, 192));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        retranslateUi(DesignerForm);

        QMetaObject::connectSlotsByName(DesignerForm);
    } // setupUi

    void retranslateUi(QWidget *DesignerForm)
    {
        DesignerForm->setWindowTitle(QApplication::translate("DesignerForm", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class DesignerForm: public Ui_DesignerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESIGNERFORM_H
