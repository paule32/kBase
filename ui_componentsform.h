/********************************************************************************
** Form generated from reading UI file 'componentsform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPONENTSFORM_H
#define UI_COMPONENTSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComponentsForm
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QWidget *tab_2;

    void setupUi(QWidget *ComponentsForm)
    {
        if (ComponentsForm->objectName().isEmpty())
            ComponentsForm->setObjectName(QStringLiteral("ComponentsForm"));
        ComponentsForm->resize(400, 300);
        tabWidget = new QTabWidget(ComponentsForm);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 371, 271));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(10, 10, 26, 29));
        toolButton_2 = new QToolButton(tab);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(40, 10, 26, 29));
        toolButton_3 = new QToolButton(tab);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(70, 10, 26, 29));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(ComponentsForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ComponentsForm);
    } // setupUi

    void retranslateUi(QWidget *ComponentsForm)
    {
        ComponentsForm->setWindowTitle(QApplication::translate("ComponentsForm", "Components", 0));
        toolButton->setText(QApplication::translate("ComponentsForm", "0", 0));
        toolButton_2->setText(QApplication::translate("ComponentsForm", "1", 0));
        toolButton_3->setText(QApplication::translate("ComponentsForm", "2", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ComponentsForm", "Standard", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ComponentsForm", "Database", 0));
    } // retranslateUi

};

namespace Ui {
    class ComponentsForm: public Ui_ComponentsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPONENTSFORM_H
