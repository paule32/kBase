#include "pch.h"
#include "mainwindow.h"

#ifndef WIN32
using namespace boost;
namespace po = boost::program_options;
#endif
extern bool create_assembler;
extern void msgbox(QString,QString);

void DisplayErrorMessage(int line,char *msg)
{
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Programmfehler!");
    msgBox->setText(QString("Error: %1: %2").arg(line).arg(msg));
    msgBox->exec();
}

void DisplayFileError(char *msg)
{
    QMessageBox* msgBox = new QMessageBox();
    msgBox->setWindowTitle("Systemfehler!");
    msgBox->setText(QString("Datei \"%1\" kann nicht geöffnet werden.").arg(msg));
    msgBox->exec();
}


#ifndef WIN32
void write_settings(const char* key, const char *value)
{
    std::ofstream settings_file("dbase.ini");
    settings_file << key << " = "<< value ;
}
void read_settings(boost::program_options::options_description& desc,
                   boost::program_options::variables_map& vm)
{
    std::ifstream settings_file("dbase.ini");

    // Clear the map.
    vm = po::variables_map();

    po::store(po::parse_config_file(settings_file , desc), vm);
    po::notify(vm);
}
#endif

void prepare_compile_file(const char *argv);
void prepare_compile(int argc, char **argv)
{
    #ifndef WIN32
    try {
        std::string name;
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce this help message")
            ("version,v", "display version of compiler")
            ("assemble,S",   po::value< std::vector<std::string> >(), "create assebler code")
            ("input-file,c", po::value< std::vector<std::string> >(), "translate files");

        po::positional_options_description p;
        p.add("input-file", -1);
        p.add("assemble",   -1);
        p.add("version",    -1);

        po::variables_map vm;
        po::store(po::command_line_parser(argc, argv).
                  options(desc).positional(p).run(), vm);
        po::notify(vm);

        std::cout
          << "kBase version: " __DATE__ " - " __TIME__ << std::endl
          << "Copyright by Jens Kallup"       << std::endl
          << std::endl;

        // Write help message
        if (vm.count("help")) {
            std::cout << desc << std::endl;
            exit(1);
        }
        else if (vm.count("version")) {
            std::cout << "version: " __DATE__ " - " __TIME__ " (Linux Debian:7 64 bit)" << std::endl;
            exit(1);
        }
        else if (vm.count("assemble")) {
            create_assembler = true;
            std::cout << "Input files are: " << std::endl;
            FILE *chkf = NULL;
            for (size_t i = 0; i < vm["assemble"].as< std::vector<std::string> >().size(); ++i) {
                chkf = fopen(vm["assemble"].as< std::vector<std::string> >()[i].c_str(),"r");
                std::cout << vm["assemble"].as< std::vector<std::string> >()[i] << ":  "; if (!chkf)
                std::cout << "can't be open.";else
                std::cout << "mark to translate" ;
                std::cout << std::endl;

                if (chkf) fclose(chkf);
                prepare_compile_file(vm["assemble"].as< std::vector<std::string> >()[i].c_str());
            }
            exit(0);
        }
        else if (vm.count("input-file")) {
            std::cout << "Input files are: " << std::endl;
            FILE *chkf = NULL;
            for (size_t i = 0; i < vm["input-file"].as< std::vector<std::string> >().size(); ++i) {
                chkf = fopen(vm["input-file"].as< std::vector<std::string> >()[i].c_str(),"r");
                std::cout << vm["input-file"].as< std::vector<std::string> >()[i] << ":  "; if (!chkf)
                std::cout << "can't be open.";else
                std::cout << "mark to translate" ;
                std::cout << std::endl;

                if (chkf) fclose(chkf);
                prepare_compile_file(vm["input-file"].as< std::vector<std::string> >()[i].c_str());
            }

            exit(0);
        }

        std::cout
            << "no program options/source given. --help for more informations."
            << std::endl
            << std::endl;

        QApplication app(argc,argv);
        MainWindow w;
        w.show();

        exit(app.exec());
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    catch (...) {
        std::cout << "unknown error." << std::endl;
        exit(1);
    }
    #else
        QApplication app(argc,argv);
        MainWindow w;      w.show();
	exit(app.exec());
    #endif
}

extern void print_code(char*,...);
extern void reset_values();
extern void start_parser();

extern int run_parse_mode;

extern FILE *file_header;
extern FILE *file_main;
extern FILE *file_classes;
extern FILE *file_classes_header;
extern FILE *file_assembler;

extern FILE *yyin;
extern int line_num;

void close_all_compiler_files(void)
{
    fclose(file_header);
    fclose(file_main);
    fclose(file_classes);
    fclose(file_classes_header);

    if (create_assembler == true)
    fclose(file_assembler);
    fclose(yyin);

    // reset
    file_header = NULL;
    file_main = NULL;
    file_classes = NULL;
    file_classes_header = NULL;

    if (create_assembler == true)
    file_assembler = NULL;
    yyin = NULL;
}

// -------------------------------------
// the problem with the slash / path ...
// -------------------------------------
char *stray_remove(char *str)
{
    char *filebuffer = new char[strlen(str)+1];
    QString path;
#ifdef WIN32
    path = QString(str).replace("/","\\");
    #else
    path = QString(str);
#endif
    strcpy(filebuffer,path.toStdString().c_str());
    return (char*)filebuffer;
}

void create_pro_file(QString pwd)
{
    QString fileName = QString(pwd + "app.pro");
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly))
    return;

    QTextStream out(&file);
    out << "#---------------------------------------------------" << endl;
    out << "# Project created by kBase: " << __DATE__ << endl;
    out << "#---------------------------------------------------" << endl;
    out << "QT += core gui widgets help" << endl;
    out << "TARGET = app" << endl;
    out << "TEMPLATE = app" << endl;
    out << "SOURCES += app.cc app.classes.cc" << endl;
    out << "HEADERS += app.h app.classes.h" << endl;
    out << "QMAKE_CXXFLAGS += \\" << endl;
    out << "\t-Wno-unused-parameter \\" << endl;
    out << "\t-Wno-unused-local-typedefs \\" << endl;
    out << "\t-Wno-unused-variable \\" << endl;
    out << "\t-Wno-unused-function \\" << endl;
    out << "\t-Wno-write-strings \\" << endl;
    out << "\t-Wno-extra \\" << endl;
    out << "\t-frtti -fexceptions -fpermissive -std=gnu++11 \\" << endl;
    out << "\t\\" << endl;
    out << "\t-DQT_COMPILING_QSTRING_COMPAT_CPP" << endl << endl;
    out << "win32:LIBS += -L. -lkbase -lhelper -ly -lfl" << endl;

    file.close();
}

void prepare_compile_file(const char *argv)
{
    QDir output("./release");
    if (!output.exists())
         output.mkdir(QDir::currentPath() + QString("./release"));
    QString pwd = QDir::currentPath() + QString("/release/");

    if (create_assembler == true)
    if (!file_assembler) file_assembler = fopen(stray_remove((char*)QString(QString(pwd) + QString("app.s" )).toStdString().c_str()),"w");
    if (!file_header)    file_header    = fopen(stray_remove((char*)QString(QString(pwd) + QString("app.h" )).toStdString().c_str()),"w");
    if (!file_main)      file_main      = fopen(stray_remove((char*)QString(QString(pwd) + QString("app.cc")).toStdString().c_str()),"w");

    if (!file_classes)        file_classes        = fopen(stray_remove((char*)QString(QString(pwd) + QString("app.classes.cc")).toStdString().c_str()),"w");
    if (!file_classes_header) file_classes_header = fopen(stray_remove((char*)QString(QString(pwd) + QString("app.classes.h" )).toStdString().c_str()),"w");

    yyin = fopen(stray_remove((char*)argv),"rb");
    create_pro_file(pwd);

    // --------------------------------------
    // step through code phase 1 - header ...
    // --------------------------------------
    fseek(yyin,0,0);
    line_num = 1;
    run_parse_mode = 1; reset_values(); start_parser();

    // ----------------------
    // phase 2 - c++ code ...
    // ----------------------
    fseek(yyin,0,0);
    run_parse_mode = 2; reset_values(); start_parser();

    // ------------------------------
    // phase 3 - c++ code classes ...
    // ------------------------------
    fseek(yyin,0,0);
    run_parse_mode = 3; reset_values(); start_parser();

    // ----------------------------
    // phase 4 - header classes ...
    // ----------------------------
    fseek(yyin,0,0);
    run_parse_mode = 4;

    print_code("s",
        "#ifndef __APPCLASSES_H__\n"
        "#define __APPCLASSES_H__\n"
        "#include \"pch.h\"\n"
    );
    reset_values(); start_parser();
    //print_code("s","#endif");

    close_all_compiler_files();
}
