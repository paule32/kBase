/********************************************************************************
** Form generated from reading UI file 'propertyform.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTYFORM_H
#define UI_PROPERTYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PropertyForm
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QPushButton *pushButton;

    void setupUi(QWidget *PropertyForm)
    {
        if (PropertyForm->objectName().isEmpty())
            PropertyForm->setObjectName(QStringLiteral("PropertyForm"));
        PropertyForm->resize(443, 296);
        tabWidget = new QTabWidget(PropertyForm);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(9, 9, 391, 271));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        tableWidget = new QTableWidget(tab_1);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 0, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 301, 231));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->horizontalHeader()->setDefaultSectionSize(130);
        tableWidget->verticalHeader()->setVisible(false);
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(-10, 30, 97, 31));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(PropertyForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PropertyForm);
    } // setupUi

    void retranslateUi(QWidget *PropertyForm)
    {
        PropertyForm->setWindowTitle(QApplication::translate("PropertyForm", "Form", 0));
#ifndef QT_NO_ACCESSIBILITY
        tab_1->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PropertyForm", "Property", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PropertyForm", "Value", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("PropertyForm", "New line", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("PropertyForm", "Top", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("PropertyForm", "Properties", 0));
        pushButton->setText(QApplication::translate("PropertyForm", "PushButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PropertyForm", "Events", 0));
    } // retranslateUi

};

namespace Ui {
    class PropertyForm: public Ui_PropertyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTYFORM_H
