#ifndef __MYQDOUBLESPINBOX_H
#define __MYQDOUBLESPINBOX_H

#include "pch.h"

class MyQDoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit MyQDoubleSpinBox(QWidget *parent = 0);
private:
    class MyQDataBrowser *table;
private slots:
    void valueModified(double);
};

#endif // MYQDOUBLESPINBOX_H
