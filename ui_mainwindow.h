/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNeu;
    QAction *actionDatei_oder_Projekt_ffnen;
    QAction *actionSpeichern;
    QAction *actionSpeichern_unter;
    QAction *actionDrucken;
    QAction *actionBeenden;
    QAction *actionAlles_erstellen;
    QAction *actionProjektAusfuehren;
    QAction *actionProjekt_erstellen;
    QAction *actionProjekt_bereinigen;
    QAction *actionEinstellungen;
    QWidget *centralwidget;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuBearbeiten;
    QMenu *menuErstellen;
    QMenu *menuDebuggen;
    QMenu *menuAnalyse;
    QMenu *menuExtras;
    QMenu *menuFenster;
    QMenu *menuHilfe;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(851, 621);
        actionNeu = new QAction(MainWindow);
        actionNeu->setObjectName(QStringLiteral("actionNeu"));
        actionDatei_oder_Projekt_ffnen = new QAction(MainWindow);
        actionDatei_oder_Projekt_ffnen->setObjectName(QStringLiteral("actionDatei_oder_Projekt_ffnen"));
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName(QStringLiteral("actionSpeichern"));
        actionSpeichern_unter = new QAction(MainWindow);
        actionSpeichern_unter->setObjectName(QStringLiteral("actionSpeichern_unter"));
        actionDrucken = new QAction(MainWindow);
        actionDrucken->setObjectName(QStringLiteral("actionDrucken"));
        actionBeenden = new QAction(MainWindow);
        actionBeenden->setObjectName(QStringLiteral("actionBeenden"));
        actionAlles_erstellen = new QAction(MainWindow);
        actionAlles_erstellen->setObjectName(QStringLiteral("actionAlles_erstellen"));
        actionProjektAusfuehren = new QAction(MainWindow);
        actionProjektAusfuehren->setObjectName(QStringLiteral("actionProjektAusfuehren"));
        actionProjekt_erstellen = new QAction(MainWindow);
        actionProjekt_erstellen->setObjectName(QStringLiteral("actionProjekt_erstellen"));
        actionProjekt_bereinigen = new QAction(MainWindow);
        actionProjekt_bereinigen->setObjectName(QStringLiteral("actionProjekt_bereinigen"));
        actionEinstellungen = new QAction(MainWindow);
        actionEinstellungen->setObjectName(QStringLiteral("actionEinstellungen"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(0, 0, 853, 682));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mdiArea->sizePolicy().hasHeightForWidth());
        mdiArea->setSizePolicy(sizePolicy);
        mdiArea->setMinimumSize(QSize(200, 200));
        mdiArea->setFocusPolicy(Qt::ClickFocus);
        mdiArea->setAutoFillBackground(false);
        mdiArea->setFrameShape(QFrame::Box);
        mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        mdiArea->setActivationOrder(QMdiArea::CreationOrder);
        mdiArea->setViewMode(QMdiArea::SubWindowView);
        mdiArea->setDocumentMode(true);
        mdiArea->setTabsMovable(true);
        mdiArea->setTabPosition(QTabWidget::East);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 851, 21));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName(QStringLiteral("menuDatei"));
        menuBearbeiten = new QMenu(menubar);
        menuBearbeiten->setObjectName(QStringLiteral("menuBearbeiten"));
        menuErstellen = new QMenu(menubar);
        menuErstellen->setObjectName(QStringLiteral("menuErstellen"));
        menuDebuggen = new QMenu(menubar);
        menuDebuggen->setObjectName(QStringLiteral("menuDebuggen"));
        menuAnalyse = new QMenu(menubar);
        menuAnalyse->setObjectName(QStringLiteral("menuAnalyse"));
        menuExtras = new QMenu(menubar);
        menuExtras->setObjectName(QStringLiteral("menuExtras"));
        menuFenster = new QMenu(menubar);
        menuFenster->setObjectName(QStringLiteral("menuFenster"));
        menuHilfe = new QMenu(menubar);
        menuHilfe->setObjectName(QStringLiteral("menuHilfe"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuBearbeiten->menuAction());
        menubar->addAction(menuErstellen->menuAction());
        menubar->addAction(menuDebuggen->menuAction());
        menubar->addAction(menuAnalyse->menuAction());
        menubar->addAction(menuExtras->menuAction());
        menubar->addAction(menuFenster->menuAction());
        menubar->addAction(menuHilfe->menuAction());
        menuDatei->addAction(actionNeu);
        menuDatei->addAction(actionDatei_oder_Projekt_ffnen);
        menuDatei->addSeparator();
        menuDatei->addAction(actionSpeichern);
        menuDatei->addAction(actionSpeichern_unter);
        menuDatei->addSeparator();
        menuDatei->addAction(actionDrucken);
        menuDatei->addSeparator();
        menuDatei->addAction(actionBeenden);
        menuErstellen->addAction(actionAlles_erstellen);
        menuErstellen->addAction(actionProjekt_erstellen);
        menuErstellen->addAction(actionProjekt_bereinigen);
        menuErstellen->addSeparator();
        menuErstellen->addAction(actionProjektAusfuehren);
        menuExtras->addAction(actionEinstellungen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNeu->setText(QApplication::translate("MainWindow", "Neu ..", 0));
        actionNeu->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionDatei_oder_Projekt_ffnen->setText(QApplication::translate("MainWindow", "Datei oder Projekt \303\266ffnen", 0));
        actionSpeichern->setText(QApplication::translate("MainWindow", "Speichern", 0));
        actionSpeichern_unter->setText(QApplication::translate("MainWindow", "Speichern unter..", 0));
#ifndef QT_NO_TOOLTIP
        actionSpeichern_unter->setToolTip(QApplication::translate("MainWindow", "speichert eine Datei unter einen angegebenen Namen", 0));
#endif // QT_NO_TOOLTIP
        actionDrucken->setText(QApplication::translate("MainWindow", "Drucken", 0));
        actionBeenden->setText(QApplication::translate("MainWindow", "Beenden", 0));
        actionBeenden->setShortcut(QApplication::translate("MainWindow", "Alt+X", 0));
        actionAlles_erstellen->setText(QApplication::translate("MainWindow", "Alles erstellen", 0));
        actionProjektAusfuehren->setText(QApplication::translate("MainWindow", "Ausf\303\274hren", 0));
        actionProjekt_erstellen->setText(QApplication::translate("MainWindow", "Projekt erstellen", 0));
        actionProjekt_bereinigen->setText(QApplication::translate("MainWindow", "Projekt bereinigen", 0));
        actionEinstellungen->setText(QApplication::translate("MainWindow", "Einstellungen", 0));
#ifndef QT_NO_ACCESSIBILITY
        mdiArea->setAccessibleName(QApplication::translate("MainWindow", "<html><head/><body><p>hallo</p></body></html>", 0));
#endif // QT_NO_ACCESSIBILITY
        menuDatei->setTitle(QApplication::translate("MainWindow", "Datei", 0));
        menuBearbeiten->setTitle(QApplication::translate("MainWindow", "Bearbeiten", 0));
        menuErstellen->setTitle(QApplication::translate("MainWindow", "Erstellen", 0));
        menuDebuggen->setTitle(QApplication::translate("MainWindow", "Debuggen", 0));
        menuAnalyse->setTitle(QApplication::translate("MainWindow", "Analyse", 0));
        menuExtras->setTitle(QApplication::translate("MainWindow", "Extras", 0));
        menuFenster->setTitle(QApplication::translate("MainWindow", "Fenster", 0));
        menuHilfe->setTitle(QApplication::translate("MainWindow", "Hilfe", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
