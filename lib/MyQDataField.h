#ifndef __MYQDATAFIELD_H__
#define __MYQDATAFIELD_H__

#include "pch.h"

class MyQDataField: public QObject
{
    Q_OBJECT
public:
    MyQDataField(QObject *_parent) { parent = _parent; }
    QObject *parent;

    QString field;
    QString value;

    void bind(class MyQLineEdit   *w);
    void bind(class MyQPushButton *w);
};

#endif
