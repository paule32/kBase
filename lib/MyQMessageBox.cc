/*
   (c) Copyright 2013-2014  Kallup Software.
   All rights reserved.

   Written by Jens Kallup <jkallup@web.de>,

   This file is subject to the terms and conditions of the MIT License:

   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without restriction,
   including without limitation the rights to use, copy, modify, merge,
   publish, distribute, sublicense, and/or sell copies of the Software,
   and to permit persons to whom the Software is furnished to do so,
   subject to the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "MyQMessageBox.h"

namespace kBaseDebug {
static QWidget *MessageBox = NULL;
MyQMessageBox::MyQMessageBox(QWidget *parent)
{
    if (!MessageBox)
    {
	MessageBox = new QWidget(parent);
	MessageBox->setFixedSize(250,150);

	memo = new QPlainTextEdit(MessageBox);
        memo->setFixedSize(250,100);

	okButton = new QPushButton("Ok",MessageBox);
        okButton->setGeometry(155,100,100,20);
	okButton->show();

	QObject::connect(okButton,SIGNAL(clicked()),this,SLOT(cls()));

	MessageBox->show();
    }
}

void MyQMessageBox::cls(){
    delete this;
}

MyQMessageBox::~MyQMessageBox(){
    delete MessageBox;
    QCoreApplication::quit();
}

void MyQMessageBox::appendText(const double value) {
  appendText(QString("%1").arg(value));
}

void MyQMessageBox::appendText(const QString text)
{
   QScrollBar *p_scroll_bar = memo->verticalScrollBar();
   bool bool_at_bottom = (p_scroll_bar->value() == p_scroll_bar->maximum());
   memo->appendPlainText(text);

   QTextCursor text_cursor = QTextCursor(memo->document());
   text_cursor.movePosition(QTextCursor::End);

   if (bool_at_bottom){
      p_scroll_bar->setValue(p_scroll_bar->maximum());
   }
}

void MyQMessageBox::appendText(const std::string text)
{
   QScrollBar *p_scroll_bar = memo->verticalScrollBar();
   bool bool_at_bottom = (p_scroll_bar->value() == p_scroll_bar->maximum());
   memo->appendPlainText(QString(text.c_str()));

   QTextCursor text_cursor = QTextCursor(memo->document());
   text_cursor.movePosition(QTextCursor::End);

   if (bool_at_bottom){
      p_scroll_bar->setValue(p_scroll_bar->maximum());
   }
}

/**
 * Just insert new QTextBlock to the text.
 * (in fact, adds new paragraph)
 */
void MyQMessageBox::insertNL(void)
{
   QScrollBar *p_scroll_bar = memo->verticalScrollBar();
   bool bool_at_bottom = (p_scroll_bar->value() == p_scroll_bar->maximum());

   QTextCursor text_cursor = QTextCursor(memo->document());
   text_cursor.movePosition(QTextCursor::End);
   text_cursor.insertBlock();

   if (bool_at_bottom){
      p_scroll_bar->setValue(p_scroll_bar->maximum());
   }
}
}
