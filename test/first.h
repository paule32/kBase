// ---------------------------------
// kbase 1.0 (c) 2012 by Jens Kallup
// ---------------------------------
#ifndef __PROGRAM_HEADER__
#define __PROGRAM_HEADER__

#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QMenuBar>
#include <QMessageBox>
#include <QTranslator>
#include <QVector>
#include "session.h"
#include "MyQVariant.h"
#include "MyQLineEdit.h"
#include "MyQPushButton.h"

class MyObjectTypes {
public:
  int type;
  double value;
  QString str;
  QWidget *widget;
  QVector<MyObjectTypes> next;
};

#ifdef __MAIN_RUN__
QVector<MyObjectTypes> param_struct;
QVector<MyQLineEdit>   edit_datasources;
#else
extern QVector<MyObjectTypes> param_struct;
extern QVector<MyQLineEdit>   edit_datasources;
#endif
#ifdef __MAIN_RUN__
MyQVariant varA = 0.00;
#endif
#ifdef __MAIN_RUN__
MyQVariant varB = 0.00;
#endif

class my_klassea : public QWidget
{
	Q_OBJECT
public:
	void my_init_klassea(void);
	void my_init_form(void) { };
	my_klassea(void) {
		top = 100.00;
		left = 100.00;
		width = 100.00;
		height = 100.00;
	}
	void msgbox(QString tstr, QString mstr)
	{
		QMessageBox* msgBox = new QMessageBox();
		msgBox->setWindowTitle(tstr);
		msgBox->setText(mstr);
		msgBox->exec();
	}
public:
	double top, left, width, height;
	MyQSession *Session1;
public slots:
	void Session1_OnTimer()
	{
		myklassea_func_Session1_OnTimer();
	}
public:
	MyQDataBase *DataBase1;

	MyQVariant myklassea_func_zuzu()
	{
		MyQVariant qv;
		qv = 32.000000;
		return qv;
	}

	MyQVariant myklassea_func_Session1_OnTimer()
	{
		MyQVariant qv;
		msgbox(QString("GuGU"), QString("Alfonso"));
		return myklassea_func_zuzu();
	}

};

class my_formular1 : public my_klassea
{
	Q_OBJECT
public:
	void my_init_formular1(void);
	my_formular1(void) {
		top = 100.00;
		left = 100.00;
		width = 100.00;
		height = 100.00;
	}
	void msgbox(QString tstr, QString mstr)
	{
		QMessageBox* msgBox = new QMessageBox();
		msgBox->setWindowTitle(tstr);
		msgBox->setText(mstr);
		msgBox->exec();
	}
	MyQPushButton *PushButton1;
	void init_PushButton1(void)
	{
		PushButton1_top = 0.00;
		PushButton1_left = 0.00;
		PushButton1_height = 35.00;
		PushButton1_width = 90.00;
		PushButton1_visible = true;
		PushButton1_text = QString("");
	}
	QString PushButton1_text;
	double PushButton1_top;
	double PushButton1_left;
	double PushButton1_width;
	double PushButton1_height;
	bool PushButton1_visible;
public slots:
	void PushButton1_OnClick()
	{
		myformular1_func_PushButton1_OnClick();
	}
public:

	MyQVariant myformular1_func_PushButton1_OnClick()
	{
		MyQVariant qv;
		msgbox(QString("Hallo"), QString("DUDU"));
		qv = (2.000000 * 3.000000);
		return qv;
	}

};

class my_form1 : public my_formular1
{
	Q_OBJECT
public:
	void my_init_form1(void);
	my_form1(void) {
		top = 100.00;
		left = 100.00;
		width = 100.00;
		height = 100.00;
	}
	void msgbox(QString tstr, QString mstr)
	{
		QMessageBox* msgBox = new QMessageBox();
		msgBox->setWindowTitle(tstr);
		msgBox->setText(mstr);
		msgBox->exec();
	}
	MyQQuery *Query1;
	void init_Query1(void)
	{
		Query1_top = 0.00;
		Query1_left = 0.00;
		Query1_height = 35.00;
		Query1_width = 90.00;
		Query1_visible = true;
		Query1_text = QString("");
	}
	QString Query1_text;
	double Query1_top;
	double Query1_left;
	double Query1_width;
	double Query1_height;
	bool Query1_visible;
	MyQPushButton *PushButton2;
	void init_PushButton2(void)
	{
		PushButton2_top = 0.00;
		PushButton2_left = 0.00;
		PushButton2_height = 35.00;
		PushButton2_width = 90.00;
		PushButton2_visible = true;
		PushButton2_text = QString("");
	}
	QString PushButton2_text;
	double PushButton2_top;
	double PushButton2_left;
	double PushButton2_width;
	double PushButton2_height;
	bool PushButton2_visible;
	MyQLineEdit *Entryfield1;
	void init_Entryfield1(void)
	{
		Entryfield1_top = 0.00;
		Entryfield1_left = 0.00;
		Entryfield1_height = 35.00;
		Entryfield1_width = 90.00;
		Entryfield1_visible = true;
		Entryfield1_text = QString("");
	}
	QString Entryfield1_text;
	double Entryfield1_top;
	double Entryfield1_left;
	double Entryfield1_width;
	double Entryfield1_height;
	bool Entryfield1_visible;
	QFrame *Container1;
	void init_Container1(void)
	{
		Container1_top = 0.00;
		Container1_left = 0.00;
		Container1_height = 35.00;
		Container1_width = 90.00;
		Container1_visible = true;
		Container1_text = QString("");
	}
	QString Container1_text;
	double Container1_top;
	double Container1_left;
	double Container1_width;
	double Container1_height;
	bool Container1_visible;
	MyQPushButton *Container1_PushButton1;
	void init_Container1_PushButton1(void)
	{
		Container1_PushButton1_top = 0.00;
		Container1_PushButton1_left = 0.00;
		Container1_PushButton1_height = 35.00;
		Container1_PushButton1_width = 90.00;
		Container1_PushButton1_visible = true;
		Container1_PushButton1_text = QString("");
	}
	QString Container1_PushButton1_text;
	double Container1_PushButton1_top;
	double Container1_PushButton1_left;
	double Container1_PushButton1_width;
	double Container1_PushButton1_height;
	bool Container1_PushButton1_visible;
	QFrame *Container1_Container1;
	void init_Container1_Container1(void)
	{
		Container1_Container1_top = 0.00;
		Container1_Container1_left = 0.00;
		Container1_Container1_height = 35.00;
		Container1_Container1_width = 90.00;
		Container1_Container1_visible = true;
		Container1_Container1_text = QString("");
	}
	QString Container1_Container1_text;
	double Container1_Container1_top;
	double Container1_Container1_left;
	double Container1_Container1_width;
	double Container1_Container1_height;
	bool Container1_Container1_visible;
	MyQLineEdit *Container1_Container1_Entryfield1;
	void init_Container1_Container1_Entryfield1(void)
	{
		Container1_Container1_Entryfield1_top = 0.00;
		Container1_Container1_Entryfield1_left = 0.00;
		Container1_Container1_Entryfield1_height = 35.00;
		Container1_Container1_Entryfield1_width = 90.00;
		Container1_Container1_Entryfield1_visible = true;
		Container1_Container1_Entryfield1_text = QString("");
	}
	QString Container1_Container1_Entryfield1_text;
	double Container1_Container1_Entryfield1_top;
	double Container1_Container1_Entryfield1_left;
	double Container1_Container1_Entryfield1_width;
	double Container1_Container1_Entryfield1_height;
	bool Container1_Container1_Entryfield1_visible;

};
#endif

#ifndef __PROGRAM_MENU__
#define __PROGRAM_MENU__
class my_menu_gehaltMENU : public QMenuBar
{
	Q_OBJECT
public:
	my_menu_gehaltMENU(QWidget *parent = 0);
	QMenu *Datei;
	QMenu *Hilfe;

};
#endif
