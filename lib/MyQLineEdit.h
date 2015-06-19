#ifndef __MYQLINEEDIT_H__
#define __MYQLINEEDIT_H__

#include "pch.h"

class MyQLineEdit: public QLineEdit
{
    Q_OBJECT
public:
    MyQLineEdit(QWidget *_parent=0): QLineEdit(_parent)
    {
        parent = _parent;
        init = false;
    }

    MyQLineEdit(QString txt, class MyQDataBrowser *browse);
    MyQDataBrowser *data_browse;

    QWidget *parent;
    class MyQDataField *rowset;
    bool init;
    bool inBrowse;
    void setDataField(void);
    void setDataField(QString field);
    void setDataLink(class MyQQuery *query, QString field);
protected:
    virtual void focusOutEvent(QFocusEvent *event);
};

#endif
