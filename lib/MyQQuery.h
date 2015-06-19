#ifndef __MYQQUERY_H__
#define __MYQQUERY_H__

#include "pch.h"

class MyQQuery: public QObject
{
    Q_OBJECT
public:
    MyQQuery(void) { }
    MyQQuery(QObject *_parent=0) { parent = _parent; }
    QObject *parent;
};

#endif
