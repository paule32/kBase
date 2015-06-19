#ifndef __MYQCHECKBOX_H
#define __MYQCHECKBOX_H

#include "pch.h"

class MyQCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    MyQCheckBox(QWidget *parent) : QCheckBox(parent)
    {
    }

    class MyQDataBrowser *browser;

    MyQCheckBox& operator = (MyQDataBrowser *db)
    {
	this->browser = db;
    }

    void check(void); // { this->checkStateSet(); }
protected:
    //virtual void checkStateSet();
};

#endif
