#define __MAIN_RUN__
#include <windows.h>
#include <iostream>
#include "MyQVariant.h"
#include "mingw/include/boost/multi_array.hpp"
#include "first.h"

bool bModal;

void msgbox(QString tstr, QString mstr)
	{
		QMessageBox* msgBox = new QMessageBox();
		msgBox->setWindowTitle(tstr);
		msgBox->setText(mstr);
		msgBox->exec();
	}

int main(int argc, char **argv)
{
	QApplication app(argc,argv);

	QTranslator translator;
	translator.load("qt_de", "./translations");
	app.installTranslator(&translator);

	my_form1 *myform1_obj = new my_form1();
	myform1_obj->my_init_form1();

    typedef boost::multi_array<MyQVariant, 2> ARRAY_ArrayA;
    ARRAY_ArrayA ARRAYTYPE_ArrayA(boost::extents[4][8]);

    typedef boost::multi_array<MyQVariant, 2> ARRAY_ArrayB;
    ARRAY_ArrayB ARRAYTYPE_ArrayB(boost::extents[4][8]);

    ARRAYTYPE_ArrayA[0][0] = 2.000000;
    ARRAYTYPE_ArrayA[1][0] = ARRAYTYPE_ArrayA[0][0];
    ARRAYTYPE_ArrayB[0][0] = QString("Alfonso");

	if (!bModal)
	{
	varA = 42.000000;
	varB += 21.000000 + 9.000000 * 2.000000 - varA;
	varA = varB + 1.000000;
	}

	print_console(QString("Hallo Welt!"));
    print_console(ARRAYTYPE_ArrayA[0][0]);
    print(ARRAYTYPE_ArrayB);

for (int varA = static_cast<int>(ARRAYTYPE_ArrayA[static_cast<int>(1.000000)][static_cast<int>(0.000000)].value_double); varA < static_cast<int>(5.000000); varA++)
{
		msgbox(QString("title"), QString("hallo"));
}

	static struct MyObjectTypes f;

	f.widget = myform1_obj;

	f.widget->show();

	myform1_obj->resize(static_cast<int>(myform1_obj->width), static_cast<int>(myform1_obj->height));
	myform1_obj->move  (static_cast<int>(myform1_obj->left),  static_cast<int>(myform1_obj->top));

	return app.exec();
}

void my_klassea::my_init_klassea(void)
{
	my_init_form();
	height = 500.000000;
	width = 500.000000;
	my_menu_gehaltMENU *my_menu_gehalt= new my_menu_gehaltMENU(this);

	Session1 = new MyQSession();

	QObject::connect(Session1->timer, SIGNAL(timeout()), this, SLOT(Session1_OnTimer()));

	Session1->host = QString("127.0.0.1");
	Session1->user = QString("jens");
	Session1->pass = QString("secret");
	Session1->port = static_cast<int>(7945.000000);
	Session1->timeout = static_cast<int>(((1000.000000 * 60.000000) * 3.000000));
	Session1->start();

	DataBase1 = new MyQDataBase();
	DataBase1->session = Session1;
	DataBase1->databaseName = QString("Beispiel");
	DataBase1->open();

}

void my_formular1::my_init_formular1(void)
{
	my_init_klassea();

	PushButton1 = new MyQPushButton("PushButton",this);
	init_PushButton1();

	QObject::connect(PushButton1, SIGNAL(clicked()), this, SLOT(PushButton1_OnClick()));

	PushButton1_top = 30.000000;
	PushButton1_text = QString("Press ""Me1");
	PushButton1->resize(static_cast<int>(PushButton1_width), static_cast<int>(PushButton1_height));
	PushButton1->move  (static_cast<int>(PushButton1_left) , static_cast<int>(PushButton1_top));

	PushButton1->setText(PushButton1_text);
	PushButton1->setDataField();

	if (PushButton1_visible) PushButton1->show();
	else PushButton1->hide();


}

void my_form1::my_init_form1(void)
{
	my_init_formular1();

	Query1 = new MyQQuery(this);
	init_Query1();

	PushButton2 = new MyQPushButton("PushButton",this);
	init_PushButton2();
	PushButton2_top = 30.000000;
	PushButton2_left = 30.000000;
	PushButton2_text = QString("Press");
	PushButton2->resize(static_cast<int>(PushButton2_width), static_cast<int>(PushButton2_height));
	PushButton2->move  (static_cast<int>(PushButton2_left) , static_cast<int>(PushButton2_top));

	PushButton2->setText(PushButton2_text);
	PushButton2->setDataField();

	if (PushButton2_visible) PushButton2->show();
	else PushButton2->hide();


	Entryfield1 = new MyQLineEdit(this);
	init_Entryfield1();
	Entryfield1->setDataLink(Query1,"name");
	Entryfield1_top = 20.000000;
	Entryfield1_left = 100.000000;
	Entryfield1_width = 100.000000;
	Entryfield1_height = 25.000000;
	Entryfield1->resize(static_cast<int>(Entryfield1_width), static_cast<int>(Entryfield1_height));
	Entryfield1->move  (static_cast<int>(Entryfield1_left) , static_cast<int>(Entryfield1_top));

	Entryfield1->setText(Entryfield1_text);
	Entryfield1->setDataField();

	if (Entryfield1_visible) Entryfield1->show();
	else Entryfield1->hide();


	Container1 = new QFrame(this);
	Container1->setFrameStyle(QFrame::Box | QFrame::Sunken);
	Container1->setLineWidth(2);
	init_Container1();
	Container1_top = 60.000000;
	Container1_left = 100.000000;
	Container1_width = 300.000000;
	Container1_height = 300.000000;
	Container1->resize(static_cast<int>(Container1_width), static_cast<int>(Container1_height));
	Container1->move  (static_cast<int>(Container1_left) , static_cast<int>(Container1_top));

	if (Container1_visible) Container1->show();
	else Container1->hide();


	Container1_PushButton1 = new MyQPushButton("PushButton",Container1);
	init_Container1_PushButton1();
	Container1_PushButton1->resize(static_cast<int>(Container1_PushButton1_width), static_cast<int>(Container1_PushButton1_height));
	Container1_PushButton1->move  (static_cast<int>(Container1_PushButton1_left) , static_cast<int>(Container1_PushButton1_top));

	Container1_PushButton1->setText(Container1_PushButton1_text);
	Container1_PushButton1->setDataField();

	if (Container1_PushButton1_visible) Container1_PushButton1->show();
	else Container1_PushButton1->hide();


	Container1_Container1 = new QFrame(Container1);
	Container1_Container1->setFrameStyle(QFrame::Box | QFrame::Sunken);
	Container1_Container1->setLineWidth(1);
	init_Container1_Container1();
	Container1_Container1_top = 50.000000;
	Container1_Container1_left = 100.000000;
	Container1_Container1_width = 200.000000;
	Container1_Container1_height = 200.000000;
	Container1_Container1->resize(static_cast<int>(Container1_Container1_width), static_cast<int>(Container1_Container1_height));
	Container1_Container1->move  (static_cast<int>(Container1_Container1_left) , static_cast<int>(Container1_Container1_top));

	if (Container1_Container1_visible) Container1_Container1->show();
	else Container1_Container1->hide();


	Container1_Container1_Entryfield1 = new MyQLineEdit(Container1_Container1);
	init_Container1_Container1_Entryfield1();
	Container1_Container1_Entryfield1_top = 20.000000;
	Container1_Container1_Entryfield1_left = 20.000000;
	Container1_Container1_Entryfield1_width = 100.000000;
	Container1_Container1_Entryfield1_height = 25.000000;
	Container1_Container1_Entryfield1->resize(static_cast<int>(Container1_Container1_Entryfield1_width), static_cast<int>(Container1_Container1_Entryfield1_height));
	Container1_Container1_Entryfield1->move  (static_cast<int>(Container1_Container1_Entryfield1_left) , static_cast<int>(Container1_Container1_Entryfield1_top));

	Container1_Container1_Entryfield1->setText(Container1_Container1_Entryfield1_text);
	Container1_Container1_Entryfield1->setDataField();

	if (Container1_Container1_Entryfield1_visible) Container1_Container1_Entryfield1->show();
	else Container1_Container1_Entryfield1->hide();


}
my_menu_gehaltMENU::my_menu_gehaltMENU(QWidget *parent) : QMenuBar(parent)
{

	Datei = new QMenu(this);
	Datei->setTitle(QString("&Datei"));
	addMenu(Datei);

	Hilfe = new QMenu(this);
	Hilfe->setTitle(QString("&Hilfe"));
	addMenu(Hilfe);

}
