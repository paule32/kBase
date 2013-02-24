#ifndef __MYCOMPILER_H__
#define __MYCOMPILER_H__

#include <QObject>
#include <QApplication>
#include <QMessageBox>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QScrollArea>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "MySourceEditor.h"
#include "MyDesigner.h"

QT_BEGIN_NAMESPACE

extern void check_compile(SourceEdit *edit, int mode=0);

class MyLabel: public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent=0, class SourceEdit *_edit=0)
        : QLabel(parent) {
        edit = _edit;
    }
    class SourceEdit *edit;
protected:
    virtual void mousePressEvent(QMouseEvent *event)
    {
        check_compile(edit,0);
    }
};

class Ui_MainWindow: public QObject
{
    Q_OBJECT
public:
    SourceEdit *textEdit;
    QListView *Ausgabe;

    QAction *actionBeenden;
    QAction *actionSpeichern;
    QAction *actionHilfe;

    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QMdiArea *mdiArea;
    QWidget *subwindow;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QTabWidget *tabWidget_3;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_7;
    QListWidget *listWidget;
    QWidget *tab_6;
    QWidget *subwindow_2;
    QWidget *subwindow_3;
    QHBoxLayout *horizontalLayout_6;
    QWidget *SourceEditWidget;
    QHBoxLayout *horizontalLayout_5;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuBearbeiten;
    QMenu *menuSpeichern;
    QMenu *menuHilfe;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    MyLabel *RunLabel;
    QDockWidget *dockWidget_9;
    QWidget *dockWidgetContents_9;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    MyTreeWidget *treeWidget;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget;
    QDockWidget *dockWidget_11;
    QWidget *dockWidgetContents_13;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QWidget *tab_2;
    QDockWidget *dockWidget_12;
    QWidget *dockWidgetContents_14;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QListView *listView;
    QButtonGroup *buttongroup;
    QHBoxLayout *horizontalLayout_7;

    QVBoxLayout *verticalLayout_9;


    QScrollArea *scrollArea;
    MyDesigner *scrollAreaWidgetContents;

    QListView *getAusgabe(void) { return Ausgabe; }

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 561);
        actionBeenden = new QAction(MainWindow);
        actionBeenden->setObjectName(QString::fromUtf8("actionBeenden"));
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setShortcut(QKeySequence("CTRL+S"));

        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);


        subwindow_3 = new QWidget();
        subwindow_3->setObjectName(QString::fromUtf8("subwindow_3"));
        subwindow_3->setWindowTitle(QString("Designer"));
        horizontalLayout_7 = new QHBoxLayout(subwindow_3);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        scrollArea = new QScrollArea(subwindow_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setEnabled(true);
        scrollArea->setMinimumSize(QSize(208, 215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new MyDesigner(scrollArea);
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 204, 211));
        scrollArea->setWidget(scrollAreaWidgetContents);
        horizontalLayout_7->addWidget(scrollArea);
        mdiArea->addSubWindow(subwindow_3);


        subwindow = new QWidget();
        subwindow->setObjectName(QString::fromUtf8("subwindow"));
        subwindow->setWindowTitle(QString("Regiezentrum"));
        verticalLayout_6 = new QVBoxLayout(subwindow);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_3 = new QLabel(subwindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_6->addWidget(label_3);

        comboBox_2 = new QComboBox(subwindow);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout_6->addWidget(comboBox_2);

        tabWidget_3 = new QTabWidget(subwindow);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_7 = new QVBoxLayout(tab_5);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));

        // regie listitem
        listWidget = new QListWidget(tab_5);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setProperty("showDropIndicator", QVariant(true));
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setProperty("isWrapping", QVariant(true));
        listWidget->setResizeMode(QListView::Fixed);
        listWidget->setSpacing(5);
        listWidget->setViewMode(QListView::ListMode);
        listWidget->setWordWrap(true);
        verticalLayout_7->addWidget(listWidget);


        QDir dir("./");
        dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
        dir.setSorting(QDir::Size | QDir::Reversed);

        QStringList filters;
        filters << "*.wfm" << "*.mnu" << "*.prg";
        dir.setNameFilters(filters);
        QFileInfoList list = dir.entryInfoList();
        QStringList files;

        for (int i = 0; i < list.size(); ++i)
        {
            QFileInfo fileInfo = list.at(i);
            QString fn = fileInfo.fileName();
            fn.replace("$tmp_","");
            files << fn;
            //listWidget->addItem(fn);
        }

        // remove duplicates
        for (int i=0; i < files.count(); ++i)
        {
            for (;;)
            {
                int p = files.lastIndexOf(files.at(i));
                if (p == i) break;
                files.removeAt(p);
            }
        }

        for (int i = 0; i < files.size(); ++i)
            listWidget->addItem(files.at(i));

        connect(listWidget,
                SIGNAL(itemDoubleClicked(QListWidgetItem*)), this,
                SLOT  (ListItemClicked  (QListWidgetItem*)));

        tabWidget_3->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget_3->addTab(tab_6, QString());

        verticalLayout_6->addWidget(tabWidget_3);

        mdiArea->addSubWindow(subwindow);
        subwindow_2 = new QWidget();
        subwindow_2->setObjectName(QString::fromUtf8("subwindow_2"));
        subwindow_2->setWindowTitle(QString("Editor"));
        horizontalLayout_6 = new QHBoxLayout(subwindow_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        SourceEditWidget = new QWidget(subwindow_2);
        SourceEditWidget->setObjectName(QString::fromUtf8("SourceEditWidget"));
        horizontalLayout_5 = new QHBoxLayout(SourceEditWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));


        textEdit = new SourceEdit(SourceEditWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(10);
        textEdit->setFont(font);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        textEdit->setAcceptRichText(false);
        textEdit->setMinimumSize(QSize(371, 227));
        textEdit->addAction(actionSpeichern);

        horizontalLayout_5->addWidget(textEdit);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->addWidget(SourceEditWidget);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);

        mdiArea->addSubWindow(subwindow_2);

        horizontalLayout->addWidget(mdiArea);




        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 18));
        menuDatei      = new QMenu(menubar);
        menuBearbeiten = new QMenu(menubar);
        menuSpeichern  = new QMenu(menuBearbeiten);
        menuHilfe      = new QMenu(menubar);


        QPixmap SpendenIcon((QString::fromUtf8(":/icons/spenden.png")));
        QPushButton *SpendenButton = new QPushButton(menubar);

        SpendenButton->setObjectName(QString::fromUtf8("SpendenButton"));
        SpendenButton->move(200,0);
        SpendenButton->resize(100,20);
        SpendenButton->setIcon(SpendenIcon);
        SpendenButton->setIconSize(QSize(100,20));
        QObject::connect(SpendenButton, SIGNAL(pressed()), this, SLOT(SpendenClick()));

        MainWindow->setMenuBar(menubar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMinimumSize(QSize(71, 427));
        dockWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(25, 25, 25, 55));\n"
"border: 1px"));
        dockWidget->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(20, -1, 0, -1);
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0)"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icons/help.png")));

        verticalLayout_3->addWidget(label);

        RunLabel = new MyLabel(dockWidgetContents,textEdit);
        RunLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0)"));
        RunLabel->setPixmap(QPixmap(QString::fromUtf8(":/icons/run.png")));
        verticalLayout_3->addWidget(RunLabel);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidget_9 = new QDockWidget(MainWindow);
        dockWidget_9->setObjectName(QString::fromUtf8("dockWidget_9"));
        dockWidget_9->setMinimumSize(QSize(220, 178));
        dockWidgetContents_9 = new QWidget();
        dockWidgetContents_9->setObjectName(QString::fromUtf8("dockWidgetContents_9"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_9);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(dockWidgetContents_9);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 30));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(9, 0, -1, -1);
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);


        verticalLayout_2->addWidget(widget);

        tabWidget_2 = new QTabWidget(dockWidgetContents_9);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        treeWidget = new MyTreeWidget(tab_3);

        verticalLayout_4->addWidget(treeWidget);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_5 = new QVBoxLayout(tab_4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tableWidget = new QTableWidget(tab_4);
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
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QBrush brush1(QColor(85, 255, 127, 255));
        brush1.setStyle(Qt::SolidPattern);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setBackground(brush1);
        __qtablewidgetitem3->setForeground(brush);
        tableWidget->setItem(0, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 1, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(20);

        verticalLayout_5->addWidget(tableWidget);

        tabWidget_2->addTab(tab_4, QString());

        verticalLayout_2->addWidget(tabWidget_2);

        dockWidget_9->setWidget(dockWidgetContents_9);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_9);
        dockWidget_11 = new QDockWidget(MainWindow);
        dockWidget_11->setObjectName(QString::fromUtf8("dockWidget_11"));
        dockWidget_11->setMinimumSize(QSize(223, 179));
        dockWidgetContents_13 = new QWidget();
        dockWidgetContents_13->setObjectName(QString::fromUtf8("dockWidgetContents_13"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_13);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(dockWidgetContents_13);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::South);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_4 = new QHBoxLayout(tab);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(10, 10, 31, 31));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setInputMethodHints(Qt::ImhHiddenText);
        QIcon icon(QPixmap(QString::fromUtf8(":/icons/entryfield.png")));
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(40, 40));
        toolButton->setCheckable(true);
        toolButton->setAutoRaise(true);
        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(40, 10, 31, 31));
        QIcon icon1(QPixmap(QString::fromUtf8(":/icons/pushbutton.png")));
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(38, 38));
        toolButton_2->setCheckable(true);
        toolButton_2->setChecked(false);
        toolButton_2->setAutoRaise(true);
        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(90, 10, 25, 19));
        //toolButton_3->setIcon(icon);
        //toolButton_3->setIconSize(QSize(38, 38));
        toolButton_3->setCheckable(true);
        toolButton_3->setChecked(false);
        toolButton_3->setAutoRaise(true);

        buttongroup = new QButtonGroup(frame);
        buttongroup->addButton(toolButton);
        buttongroup->addButton(toolButton_2);
        buttongroup->addButton(toolButton_3);

        QObject::connect(toolButton  , SIGNAL(clicked()), this, SLOT(EntryFieldOnCreate()));
        QObject::connect(toolButton_2, SIGNAL(clicked()), this, SLOT(PushButtonOnCreate()));

        horizontalLayout_4->addWidget(frame);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        dockWidget_11->setWidget(dockWidgetContents_13);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_11);
        dockWidget_12 = new QDockWidget(MainWindow);
        dockWidget_12->setObjectName(QString::fromUtf8("dockWidget_12"));
        //dockWidget_12->setMinimumSize(QSize(800, 110));
        dockWidgetContents_14 = new QWidget();
        dockWidgetContents_14->setObjectName(QString::fromUtf8("dockWidgetContents_14"));
        verticalLayout_8 = new QVBoxLayout(dockWidgetContents_14);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));

        Ausgabe = new QListView(dockWidgetContents_14);
        Ausgabe->setObjectName(QString::fromUtf8("AusgabeListe"));
        Ausgabe->setMinimumSize(QSize(799, 89));
        Ausgabe->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);



        verticalLayout_9->addWidget(Ausgabe);
        verticalLayout_8->addLayout(verticalLayout_9);



        dockWidget_12->setWidget(dockWidgetContents_14);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_12);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuBearbeiten->menuAction());
        menubar->addAction(menuHilfe->menuAction());

        //SpendenButton->addAction(actionSpenden);
        menuDatei->addAction(actionBeenden);
        menuBearbeiten->addAction(actionSpeichern);
        menuHilfe->addAction(actionHilfe);

        retranslateUi(MainWindow);

        QObject::connect(actionBeenden, SIGNAL(triggered()), actionBeenden, SLOT(trigger()));
        QObject::connect(actionSpeichern, SIGNAL(triggered()), actionSpeichern, SLOT(EditSpeichern()));

        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        //QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "kBase Compiler 1.0 (c) 2012 J. Kallup", 0, QApplication::UnicodeUTF8));
        actionBeenden->setText(QApplication::translate("MainWindow", "Beenden", 0, QApplication::UnicodeUTF8));
        //subwindow->setWindowTitle(QApplication::translate("MainWindow", "Subwindow", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Aktuelles Verzeichnis:", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);



        /*
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "New Item", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);
        */



        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_5), QApplication::translate("MainWindow", "Alle", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("MainWindow", "Formulare", 0, QApplication::UnicodeUTF8));
        //subwindow_2->setWindowTitle(QApplication::translate("MainWindow", "Subwindow", 0, QApplication::UnicodeUTF8));
        menuDatei->setTitle("Datei");
        menuBearbeiten->setTitle("Bearbeiten");
        menuHilfe->setTitle("Hilfe");
        label->setText(QString());
        RunLabel->setText(QString());

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Eigenschaften", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Ereignis", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Funktion", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "New Row", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled2 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->item(0, 0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "onClick", 0, QApplication::UnicodeUTF8));
        tableWidget->setSortingEnabled(__sortingEnabled2);

        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Events", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Standard", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Datenbank", 0, QApplication::UnicodeUTF8));


        mdiArea->cascadeSubWindows();
    } // retranslateUi

public slots:
    void SpendenClick()
    {
        QDesktopServices::openUrl(QUrl("https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=ZM2EFHA53Q4RS", QUrl::TolerantMode));
    }

    void EditSpeichern()
    {
        check_compile(textEdit,1);
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setWindowTitle("Information");
        msgBox->setText("Datei wurde gespeichert.");
        msgBox->exec();
    }

    void ListItemClicked(QListWidgetItem *item)
    {
        if (item->text().contains(".prg"))
        {
            textEdit->insertTextByFile(item->text());
        }
        else if(item->text().contains(".mnu"))
        {
            textEdit->insertTextByFile(item->text());
        }
        else {
            textEdit->setText("");
        }
    }

    void PushButtonOnCreate() { placeObject = DesignerObject_PushButton; }
    void EntryFieldOnCreate() { placeObject = DesignerObject_EntryField; }
};


namespace dBase {
    class MainWindow: public Ui_MainWindow {};
};

QT_END_NAMESPACE

#endif
