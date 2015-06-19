#ifndef MYQDATABROWSER_H
#define MYQDATABROWSER_H

#include "pch.h"

class MyQDataBrowser : public QTableWidget
{
    Q_OBJECT
public:
    explicit MyQDataBrowser(QWidget *parent = 0, QString v = "");
    void set_header(void);

private slots:
    void itemClick(QTableWidgetItem *);
    void cellPress(int, int);
    void openEditLine(int,int);
    
public:
    class MyQWorkArea *workArea;
    class MyQLineEdit *editor;
    class MyQCheckBox *checkBox;
    class MyQDateEdit *datebox;
    class MyQTimeEdit *timebox;
    class MyQDoubleSpinBox *dspinbox;

    QString alias;
    QString view;

    int old_row;
    int old_col;

    void setAlias(QString);
};

extern void save_all_browsers(QList<MyQDataBrowser*>);
#endif // MYQDATABROWSER_H
