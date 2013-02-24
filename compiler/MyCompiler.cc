#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <QAxObject>
#include <QMessageBox>
#include <QResource>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTranslator>
#include "MyCompiler.h"
#include "MyProcess.h"

QString mingw_path;
dBase::MainWindow *win;

extern "C" void displayEnvError(void)
{
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Allgemeiner Fehler");
    msgBox->setText("MinGW Umgebungsvariable nicht gesetzt.");
    msgBox->exec();
}

void test_excel(void)
{
    QAxObject* excel = new QAxObject("Excel.Application");
    excel->setProperty("Visible", true);

    QAxObject* workbooks = NULL;
    try
    {
        workbooks = excel->querySubObject("Workbooks");
        if (!workbooks)
        {
            QMessageBox* msgBox = new QMessageBox();
            msgBox->setWindowTitle("Error");
            msgBox->setText("workbooks = NULL");
            msgBox->exec();
            //return;
        }
        workbooks->dynamicCall("Open (const QString&)", QString("d:\\ant\\2.xls"));
    }
    catch (...)
    {
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setWindowTitle("Exception");
        msgBox->setText("found exception");
        msgBox->exec();
    }

    /*
    QAxObject* workbook = excel->querySubObject("ActiveWorkBook");
    QAxObject* worksheets = workbook->querySubObject("WorkSheets");
    QAxObject* worksheet = workbook->querySubObject("Worksheets(int)", 1); //worksheet number
    QAxObject* usedrange = worksheet->querySubObject("UsedRange");
    QAxObject* rows = usedrange->querySubObject("Rows");
    QAxObject* columns = usedrange->querySubObject("Columns");
    int intRowStart = usedrange->property("Row").toInt();
    int intColStart = usedrange->property("Column").toInt();
    int intCols = columns->property("Count").toInt();
    int intRows = rows->property("Count").toInt();
    QAxObject * cell;
    QString ct;
    for (int i = intRowStart; i < intRowStart + intRows; i++)
    {
       for (int j = intColStart; j < intColStart + intCols; j++)
       {
        cell = excel->querySubObject("Cells(Int, Int)", i, j );
        QVariant cellValue = cell->dynamicCall("value");
        ct += "val: " + cellValue.toString() + "\n";

        //cout << "Content " << cellValue.toString().toStdString() << endl; //value of the cell
       }
    }

    */
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Allgemein");
    msgBox->setText("----");
    msgBox->exec();

    excel->setProperty("DisplayAlerts", 0);
    //workbook->dynamicCall("Save(void)");
    //workbook->dynamicCall("Close (Boolean)", false);
    excel->setProperty("DisplayAlerts",1);

    delete excel;
}

extern "C" int create_main_window(int argc, char **argv)
{
    QApplication app(argc,argv);

    QTranslator translator;
    translator.load("qt_de", "./translations");
    app.installTranslator(&translator);

    mingw_path = QString(QDir::currentPath()+"/mingw/bin");  //getenv("MinGW"));

    // test_excel();
    /*
    char *pPath;
    pPath = getenv("MinGW");
    if ((pPath == NULL) || (strlen(getenv("MinGW")) < 1))
    {
        displayEnvError();
        exit(1);
    }*/

    QMainWindow *main__win = new QMainWindow;
    win = new dBase::MainWindow();
    win->setupUi(main__win);
    main__win->show();

    return app.exec();
}

extern "C" void start_parser(void);
extern "C" void restart_parser(FILE*);
extern "C" void reset_values();

extern FILE *file_header;
extern FILE *file_main;
extern FILE *yyin;

extern char *class_object;
extern char *class_methode_code;
extern char *class_name;
extern char *class_type;
extern char *class_local;
extern char *class_datalink;
extern char *class_element;

extern char menuFile[];

extern int run_parse_mode;
extern int errors;

extern "C" void DisplayErrorMessage(int line,char *msg)
{
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Programmfehler!");
    msgBox->setText(QString("Error: %1: %2").arg(line).arg(msg));
    msgBox->exec();
}

extern "C" void DisplayFileError(char *msg)
{
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Systemfehler!");
    msgBox->setText(QString("Datei \"%1\" kann nicht geöffnet werden.").arg(msg));
    msgBox->exec();
}

extern "C" char *ConvertMenuString(char *dat)
{
    QString filename;
    filename = dat;
    filename.replace("\"","");
    return (char*) filename.toStdString().c_str();
}

extern "C" char *ConvertMenuClass(char *dat)
{
    QString filename;
    filename = dat;
    filename.replace("\"","");
    filename.replace(".mnu","");
    return (char*) filename.toStdString().c_str();
}

extern "C" void compile_program(void)
{
    QString cp;
    cp = QString(
    "#--------------------------------------------\n"
    "# Makefile - Installationsscript für test.prg\n"
    "# (c) 2013 J. Kallup\n"
    "#--------------------------------------------\n"
    "LAUFWERK_PFAD = %1\n"
    "\n"
    "CC  = $(LAUFWERK_PFAD)/mingw/bin/g++ -mwindows\n"
    "MOC = $(LAUFWERK_PFAD)/Qt/bin/moc.exe\n"
    "\n"
    "DEFINES  = -DUNICODE -DQT_LARGEFILE_SUPPORT -DQT_DLL -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_HAVE_MMX -DQT_HAVE_3DNOW -DQT_HAVE_SSE -DQT_HAVE_MMXEXT -DQT_HAVE_SSE2 -DQT_THREAD_SUPPORT -DQT_NEEDS_QMAIN\n"
    "INCLUDES = \\\n"
    "\t-I\"$(LAUFWERK_PFAD)/Qt/include/Qt\" \\\n"
    "\t-I\"$(LAUFWERK_PFAD)/Qt/include/QtCore\" \\\n"
    "\t-I\"$(LAUFWERK_PFAD)/Qt/include/QtNetwork\" \\\n"
    "\t-I\"$(LAUFWERK_PFAD)/Qt/include/QtGui\" \\\n"
    "\t-I\"$(LAUFWERK_PFAD)/Qt/include/\" \\\n"
    "\t-I\"$(LAUFWERK_PFAD)/Qt/include/ActiveQt\"\n"
    "LIBS  = \\\n"
    "\t-L\"$(LAUFWERK_PFAD)/Qt/lib\" -lmingw32 -lqtmain -lQtGui4 -lQtNetwork4 -lQtCore4\n"
    "\n"
    "all: first.exe\n"
    "\n"
    "first.exe: first.cc first.h session.h session.cc\n"
    "\t$(MOC) $(DEFINES) $(INCLUDES) -D__GNUC__ -DWIN32 -D__MOC_RUN__ first.h -o moc_first.cc\n"
    "\t$(MOC) $(DEFINES) $(INCLUDES) -D__GNUC__ -DWIN32 -D__MOC_RUN__ session.h -o moc_session.cc\n"
    "\t$(MOC) $(DEFINES) $(INCLUDES) -D__GNUC__ -DWIN32 -D__MOC_RUN__ MyQLineEdit.h -o moc_qlineedit.cc\n"
    "\t$(MOC) $(DEFINES) $(INCLUDES) -D__GNUC__ -DWIN32 -D__MOC_RUN__ MyQPushButton.h -o moc_qpushbutton.cc\n"
    "\t$(CC) $(DEFINES) $(INCLUDES) -o moc_first.o   -c moc_first.cc 2> m1\n"
    "\t$(CC) $(DEFINES) $(INCLUDES) -o moc_session.o -c moc_session.cc\n"
    "\t$(CC) $(DEFINES) $(INCLUDES) -o moc_qlineedit.o -c moc_qlineedit.cc\n"
    "\t$(CC) $(DEFINES) $(INCLUDES) -o moc_qpushbutton.o -c moc_qpushbutton.cc\n"
    "\t$(CC) $(DEFINES) $(INCLUDES) -c MyDebugFuncs.cc -o MyDebugFuncs.o\n"
    "\t$(CC) $(DEFINES) $(INCLUDES) -c session.cc -o session.o\n"
    "\t$(CC) $(DEFINES) $(INCLUDES) -c first.cc -o first.o\n"
    "\t$(CC) -o first.exe first.o session.o \\\n"
    "\tMyDebugFuncs.o \\\n"
    "\tmoc_first.o \\\n"
    "\tmoc_session.o \\\n"
    "\tmoc_qlineedit.o \\\n"
    "\tmoc_qpushbutton.o \\\n"
    "\t$(LIBS)\n"
    )
    .arg(QDir::currentPath());

    QString mkf;
    FILE *fh;
    mkf = QString("%1/Makefile").arg(QDir::currentPath());

    fh = fopen(mkf.toStdString().c_str(),"w");
    if (!fh)
    {
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setWindowTitle("Systemfehler");
        msgBox->setText("kann Makefile nicht speichern.");
        msgBox->exec();

        return;
    }

    fprintf(fh,"%s",cp.toStdString().c_str());
    fclose(fh);

    cp = QString("%1/mingw/bin/mingw32-make.exe -f %1/Makefile")
            .arg(QDir::currentPath());

    fh = fopen("build.bat","w");
    fprintf(fh,"%s\n",cp.toStdString().c_str());
    fprintf(fh,"pause\n");
    fclose(fh);

    QStringList args;
    args << "-f"
         << QString(QDir::currentPath() + "/Makefile");
    MyProcess *mp = new MyProcess(win,QString("%1/mingw/bin/mingw32-make.exe").arg(QDir::currentPath()),args);
    //system("build.bat");
}

void prepare_compile(const char *argv)
{
    QStringList args;
    args << "-o"
         << QString("%1/$tmp_%2")
            .arg(QDir::currentPath())
            .arg(argv)
         << QString("%1/%2")
            .arg(QDir::currentPath())
            .arg(argv);

    MyProcess *mp = new MyProcess(win,
                                  QString("%1/cpp.exe").arg(mingw_path),
                                  args);

    char buffer[2048];    
    sprintf(buffer,"$tmp_%s",argv);
    yyin = fopen(buffer,"r");

    if (!yyin)
    {
        QMessageBox* msgBox = new QMessageBox();
        msgBox->setWindowTitle("Systemfehler!");
        msgBox->setText(QString("Datei \"%1\" kann nicht geöffnet werden.").arg(buffer));
        msgBox->exec();
        return;
    }

    file_header = fopen("first.h" ,"w");
    file_main   = fopen("first.cc","w");

    class_object       = new char[2048];
    class_methode_code = new char[2048];
    class_datalink     = new char[2048];

    class_name    = new char[2048];
    class_type    = new char[2048];
    class_element = new char[2048];

    strcpy(class_methode_code,"");
    strcpy(class_datalink,"");
    strcpy(menuFile,"");

    fseek(yyin,0,0);
    run_parse_mode = 1; reset_values(); start_parser();

    fseek(yyin,0,0); restart_parser(yyin);

    run_parse_mode = 2; reset_values(); start_parser();
    run_parse_mode = 3; reset_values(); start_parser();

    free(class_object);
    free(class_name);
    free(class_type);
    free(class_element);
    free(class_datalink);
    free(class_methode_code);

    fclose(file_header);
    fclose(file_main);

    fclose(yyin);

    if (errors < 1)
    compile_program();
}
