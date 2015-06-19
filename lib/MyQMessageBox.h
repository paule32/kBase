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
#ifndef MYQMESSAGEBOX_H
#define MYQMESSAGEBOX_H

#include "pch.h"

namespace kBaseDebug {
class MyQMessageBox : public QObject
{
    Q_OBJECT
public:
    MyQMessageBox(QWidget *parent=0);
    ~MyQMessageBox();

    void appendText(const ::std::string);
    void appendText(const QString);
    void appendText(const double );
    void insertNL(void);

private:
    QPlainTextEdit *memo;
    QPushButton    *okButton;

public slots:
    void cls();
};
}
#endif
