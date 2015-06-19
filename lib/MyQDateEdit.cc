#include "MyQDateEdit.h"

MyQDateEdit::MyQDateEdit(QWidget *parent) : QDateEdit(parent)
{
    setDisplayFormat(QString("dd.MM.yyyy"));
}

