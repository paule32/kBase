#include "session.h"

void MyQDataField::bind(class MyQLineEdit *w)
{
    if (w) w->setText(w->rowset->value);

    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Database");
    msgBox->setText("field ok");
    msgBox->exec();
}

void MyQLineEdit::setDataField(QString field)
{
    if (parent)
    {
        rowset = new MyQDataField(this);
        rowset->value = "Edit1";
        rowset->bind(this);
    }
}

void MyQLineEdit::setDataField(void)
{
    if (init && parent && rowset)
    {
        rowset->bind(this);
    }
}

void MyQLineEdit::setDataLink(class MyQQuery *query, QString field)
{
    if (parent)
    {
        init = true;
        rowset = new MyQDataField(this);
        rowset->value = field;
    }
}


// MyQPushButton
MyQPushButton::MyQPushButton(QString txt, QWidget *_parent): QPushButton(txt,_parent)
{
    parent = _parent;
    init = false;
}

void MyQDataField::bind(class MyQPushButton *w)
{
    if (w) w->setText(w->rowset->value);

    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Database");
    msgBox->setText("field ok push");
    msgBox->exec();
}

void MyQPushButton::setDataField(QString field)
{
    if (parent)
    {
        rowset = new MyQDataField(parent);
        rowset->value = "Edit1";
    }
}

void MyQPushButton::setDataField(void)
{
/*
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Database");
    msgBox->setText("---------------------");
    msgBox->exec();
*/
}

void MyQPushButton::setDataLink(class MyQQuery *query, QString field)
{
    if (parent && rowset)
    {
        rowset->bind(this);
    }
}
