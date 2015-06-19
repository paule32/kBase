#ifndef __MYQPUSHBUTTON_H__
#define __MYQPUSHBUTTON_H__

#include "pch.h"

class MyQPushButton: public QPushButton
{
    Q_OBJECT
public:
    MyQPushButton(QString txt, QWidget *_parent=0);
    QWidget *parent;
    class MyQDataField *rowset;
    bool init;
    void setDataField(void);
    void setDataField(QString field);
    void setDataLink(class MyQQuery *query, QString field);
};

#endif
