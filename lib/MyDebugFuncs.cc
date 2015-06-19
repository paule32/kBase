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
#include "pch.h"

using namespace kBaseDebug;
static class MyQMessageBox *debugMessageBox = NULL;

double floor(MyQVariant &v)
{
	return ::floor((double)boost::get<double>(v.data));
}

void print_console(char *str)  {
    print_console(QString(str));
}

void print_console(MyQVariant v)
{
    if (!debugMessageBox)
    debugMessageBox = new kBaseDebug::MyQMessageBox;

    try {
        QString str = boost::get<QString>(v.data);
        debugMessageBox->appendText(str);
    } catch (...) {
        try {
            std::string str = boost::get<std::string>(v.data);
            debugMessageBox->appendText(str);
	} catch (...) {
	    try {
	        double value = boost::get<double>(v.data);
		debugMessageBox->appendText(QString("-> %1").arg(value));
	    } catch (...) {
		debugMessageBox->appendText(QString("runtime error"));
	    }
	}
    }
}

void print_console(QString str)
{
    if (!debugMessageBox)
    debugMessageBox = new kBaseDebug::MyQMessageBox;
    debugMessageBox->appendText(QString(str).toStdString());
}

void print_console(std::string str)
{
    if (!debugMessageBox)
    debugMessageBox = new kBaseDebug::MyQMessageBox;
    debugMessageBox->appendText(str);
}

void print_console(double val)
{
    if (!debugMessageBox)
    debugMessageBox = new kBaseDebug::MyQMessageBox;
    debugMessageBox->appendText(QString("hallo2"));
    debugMessageBox->appendText(val);
}

void msgbox(QString tstr, QString mstr)
{
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle(tstr);
    msgBox->setText(mstr);
    msgBox->exec();
}


void my_set_time(QString ts)
{
    char buffer[50];
    strcpy(buffer,ts.toLatin1().data());

    int h,m,s;
    if (sscanf(buffer,"%d:%d:%d",&h,&m,&s) == 3) {} else
    if (sscanf(buffer,"%d:%d"   ,&h,&m   ) == 2) { s = 0; } else
    if (sscanf(buffer,"%d"      ,&h      ) == 1) { s = 0; m = 0; }

/*
    #ifdef WIN32
    SYSTEMTIME dat;
    dat.wHour = h;
    dat.wMinute = m;
    dat.wSecond = s;

    if (!SetSystemTime(&dat))
*/
//    #else

        print_console(std::string("Systemzeit konnte nicht gesetzt werden."));
//    #endif
}

QString my_date_now(void)
{
#ifdef PORT_WIN32
    SYSTEMTIME dat;
    GetSystemTime(&dat);

    QString buffer;
    buffer = QString("%1.%2.%3")
    .arg(dat.wDay)
    .arg(dat.wMonth)
    .arg(dat.wYear);
    return buffer;
#else
    return QString("not implemented");
#endif
}

QString my_time_now(void)
{
    QTime time = QTime::currentTime();
    QString timeString = time.toString();
    return  timeString;
/*
    SYSTEMTIME dat;
    GetSystemTime(&dat);

    QString buffer;
    buffer = QString("%1:%2:%3")
    .arg(dat.wHour)
    .arg(dat.wMinute)
    .arg(dat.wSecond);
    return buffer;
*/
}
