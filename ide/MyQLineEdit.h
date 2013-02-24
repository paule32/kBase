#ifndef __MYQLINEEDIT_H__
#define __MYQLINEEDIT_H__

#include <QObject>
#include <QLineEdit>
#include "session.h"

class MyQLineEdit: public QLineEdit
{
    Q_OBJECT
public:
    MyQLineEdit(QWidget *_parent=0): QLineEdit(_parent)
    {
        parent = _parent;
        init = false;
    }
    QWidget *parent;
    class MyQDataField *rowset;
    bool init;
    void setDataField(void);
    void setDataField(QString field);
    void setDataLink(class MyQQuery *query, QString field);
};

#endif
