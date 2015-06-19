#include "MyQTimeEdit.h"

MyQTimeEdit::MyQTimeEdit(QWidget *parent) : QTimeEdit(parent)
{
    setDisplayFormat("hh:mm:ss");
}
