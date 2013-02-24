%{
// ------------------------------------
// kBase (c) 2012 Jens Kallup
// All Rights Reserved.
// ------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <signal.h>

#define run_parse(x) (run_parse_mode == (x))
#define false 0
#define true  1

extern int run_parse_mode;
extern char *strlwr(char *c);
extern char *ConvertMenuString(char *dat);
extern char *ConvertMenuClass (char *dat);

extern FILE* yyin;
extern int lineno;

FILE *file_header = NULL;
FILE *file_main   = NULL;

char temp_with [2048*3];
char temp_with1[2048*3];
char temp_with2[2048*3];
char expr_buffer[2048*3];
char menuFile[2048];

char temp_str[2048*3];
char temp_object[2048];
char  class_temp[2048];
char  ttc_name[2048*3];
char  *tmp_id;

char *class_object;
char *class_methode_code;
char *class_name;
char *class_type;
char *class_local;
char *class_datalink;
char *class_element;

int run_parse_mode;
int no_expr = 0;
int last_token = 0;
int twisted = 0;
int errors = 0;
int lineno = 1;

typedef unsigned short bool;

bool has_object = false;
bool in_methode = false;
bool in_main_function = false;
bool compiler_flag = true;

#define TOK_VARIABLE 1
#define TOK_FUNCTION 2

int check_list(char *name);
void print_code(char* str, ... );
void add_symbol(char* str, int type);
int  get_symbol(char* str);

extern int errors;

%}

%union {
    int type;
    float	val;
    char* 	id;
    char*	text;
    int         trfa;
}

%start program

%token _NUM_ _ID_ _ASSIGN_ _PLUS_ _MINUS_ _DIV_ _MUL_ _MOD_ _POW_ _OBR_ _CBR_
%token _NEW_ _CLASS_ _OF_ _ENDCLASS_ _WITH_ _ENDWITH_ _LOCAL_ _COMMA_ _POINT_
%token  _STRING_ _FUNCTION_ _RETURN_ _DBPOINT_ _MSGBOX_ _EQUAL_ _PARAMETER_
%token _IF_ _ELSE_ _ENDIF_ _NOT_ _TRUE_ _FALSE_ _OBR2_ _CBR2_ _MENUBAR_
%token _FOR_ _ENDFOR_ _TO_ _ARRAY_ _PRINT_TEXT_
%type <val> _NUM_
%type <id> _ID_
%type <trfa> false_true_expr
%type <text> _STRING_ string_expr with_objects function_parameters2 function_parameters

%%

program : {
                if run_parse(2)
                {
                        print_code("s",
                        "#define __MAIN_RUN__\n"

                                   "#include <windows.h>\n"

                        "#include <iostream>\n"
                        "#include \"MyQVariant.h\"\n"
                        "#include \"mingw/include/boost/multi_array.hpp\"\n"

                        "#include \"first.h\"\n\n"
                        );
                }
        } parameter_stmt program_stmts ;

program_stmts
        :
        {
          if run_parse(3)
          {
                //run_parse_mode = 1;
                print_code("s",
                "\n#ifndef __PROGRAM_MENU__\n"
                  "#define __PROGRAM_MENU__\n"
                ""
                );
                //run_parse_mode = 3;
          }
          else if run_parse(1) {
                print_code("s",
                "// ---------------------------------\n"
                "// kbase 1.0 (c) 2012 by Jens Kallup\n"
                "// ---------------------------------\n"
                "#ifndef __PROGRAM_HEADER__\n"
                "#define __PROGRAM_HEADER__\n\n"
                "#include <QApplication>\n"
                "#include <QWidget>\n"
                "#include <QFrame>\n"
                "#include <QString>\n"
                "#include <QPushButton>\n"
                "#include <QLineEdit>\n"
                "#include <QMenuBar>\n"
                "#include <QMessageBox>\n"
                "#include <QTranslator>\n"
                "#include <QVector>\n"
                "#include \"session.h\"\n"
                "#include \"MyQVariant.h\"\n"
                "#include \"MyQLineEdit.h\"\n"
                "#include \"MyQPushButton.h\"\n"
                "\n"
                "class MyObjectTypes {\n"
                "public:\n"
                "  int type;\n"
                "  double value;\n"
                "  QString str;\n"
                "  QWidget *widget;\n"
                "  QVector<MyObjectTypes> next;\n"
                "};\n"
                "\n"
                "#ifdef __MAIN_RUN__\n"
                "QVector<MyObjectTypes> param_struct;\n"
                "QVector<MyQLineEdit>   edit_datasources;\n"
                "#else\n"
                "extern QVector<MyObjectTypes> param_struct;\n"
                "extern QVector<MyQLineEdit>   edit_datasources;\n"
                "#endif\n"
                );
          }
          else if run_parse(2)
          {
                in_main_function = true;


                print_code("s",

                           "static int debug_console = 1;"
                           "void print_console(QString str)\n"
                           "{\n"
                           "\tif (debug_console == 1)\n"
                           "\t{\n"
                           "\t\tDWORD i;\n"
                           "\t\tAllocConsole();\n"
                           "\t\tWriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),str.toStdString().c_str(),str.size(),&i,NULL);\n"
                           "\t}\n"
                           "}\n\n"

                        "void msgbox(QString tstr, QString mstr)\n"
                        "\t{\n"
                        "\t\tQMessageBox* msgBox = new QMessageBox();\n"
                        "\t\tmsgBox->setWindowTitle(tstr);\n"
                        "\t\tmsgBox->setText(mstr);\n"
                        "\t\tmsgBox->exec();\n\t}\n\n");


                print_code("s",
                "int main(int argc, char **argv)\n{\n");

                print_code(
                "s",
                "\tQApplication app(argc,argv);\n\n"
                "\tQTranslator translator;\n"
                "\ttranslator.load(\"qt_de\", \"./translations\");\n"
                "\tapp.installTranslator(&translator);\n\n");

                //if (!strcmp(class_type,"QWidget"))
                {
                        char buffer0[2048*3];
                        sprintf(buffer0,"my_%s *my%s_obj = new my_%s();\n",
                        class_name,class_name,class_name);
                        strcat(buffer0,"\tmy");
                        strcat(buffer0,class_name);
                        strcat(buffer0,"_obj->my_init_");
                        strcat(buffer0,class_name);
                        strcat(buffer0,"();\n");

                        print_code("sss","\t",buffer0,"\n");
                }
          }
        } stmt_seq {
          if (run_parse(1) || run_parse(3))
          {
                print_code("s","#endif\n");
          }
        }
        ;

stmt_seq
        : stmt_seq stmt { }
        | stmt
        ;

stmt	:
        | num_id_stmt
        | id_stmt
        | array_stmt
        | if_stmt
        | for_stmt
        | print_text
        | func_out_stmts
        | local_show
        | local_stmt
        | class_stmt
        ;

print_text
        : _PRINT_TEXT_ {
            if run_parse(2)
            {
                print_code("s","\tprint_console(");
            }
        } texter_print stmt
        ;
texter_print
        : _STRING_ {
            if run_parse(2)
            {
                print_code("sss",
                           "QString(",
                           $1,
                           "));\n"
                           );
            }
        }
        | _ID_ {
            if run_parse(2)
            {
                print_code("ss",
                           "ARRAYTYPE_",
                           $1
                           );
            }
        } array_assign {
            if run_parse(2)
            {
                print_code("s",.value_double");\n");
            }
        }
        | expr2 {
            if run_parse(2)
            {
                print_code("s",");\n");
            }
        }
        ;

array_stmt
        : _ID_ _ASSIGN_ _NEW_ _ARRAY_ {
            if run_parse(2)
            {
                print_code("s",
                "\ttypedef boost::multi_array<MyQVariant, static_cast<int>("
                );
            }
        } _OBR_ {
            strcpy(expr_buffer,"");
        } expr2 {
            if run_parse(2)
            {
                print_code("ssssssss",
                ")> ARRAY_",
                $1,
                ";\n",
                "\tARRAY_",
                $1,
                " ARRAYTYPE_",
                $1,
                "(boost::extents"
                );
            }
        } dimension _CBR_ {
            if run_parse(2)
            {
                print_code("s",");\n\n");
            }
        } stmt
        | array_def expr2 {
            if run_parse(2)
            {
                print_code("s",";\n");
            }
        } stmt
        | array_def _ID_ {
            if run_parse(2)
            {
                print_code("ss","ARRAYTYPE_",$2);
            }
        } array_assign {
            if run_parse(2)
            {
                print_code("s",";\n");
            }
        } stmt
        ;

array_def
        : _ID_ {
            if run_parse(2)
            {
                print_code("ss",
                "\tARRAYTYPE_",
                $1
                );
            }
        } array_assign _ASSIGN_ {
            if run_parse(2)
            {
                print_code("s"," = ");
            }
        }
        ;

array_assign
        : _OBR2_ {
            if run_parse(2)
            {
                print_code("s","[static_cast<int>(");
            }
        } expr2 _CBR2_ {
            if run_parse(2)
            {
                print_code("s",")]");
            }
        }
        | array_assign _OBR2_ {
            if run_parse(2)
            {
                print_code("s","[static_cast<int>(");
            }
        } expr2 _CBR2_ {
            if run_parse(2)
            {
                print_code("s",")]");
            }
        }
        ;

dimension
        :
        | expr2 {
            if run_parse(2)
            {
                print_code("s",
                    "]"
                );
            }
        }
        | _COMMA_ {
            if run_parse(2)
            {
                print_code("s",
                    "[static_cast<int>("
                );
            }
        } expr2 {
            if run_parse(2)
            {
                print_code("s",
                    ")]"
                );
            }
        } dimension
        ;

parameter_stmt
        : _PARAMETER_ stack_parameter_list { }
        ;

stack_parameter_list
        : _ID_ {
                if run_parse(2)
                {
                        print_code("sss","bool ",$1,";\n");
                }
                else if run_parse(3)
                {
                        //print_code("sss","QWidget *",$1,";\n");
                }
        }
        | stack_parameter_list _COMMA_ stack_parameter_list
        ;

for_body
        : _FOR_ _ID_ _ASSIGN_ _ID_ {
            if run_parse(2)
            {
                print_code("ssss",
                    "for (int ",
                    $2,
                    " = static_cast<int>(ARRAYTYPE_",
                    $4
                );
            }
        } array_assign _TO_ {
            if run_parse(2)
            {
                print_code("sss",
                    ".value_double); ",
                    $2,
                    " < static_cast<int>("
                );
            }
        } expr2 {
            if run_parse(2)
            {
                print_code("sss",
                    "); ",
                    $2,
                    "++)\n{\n"
                );
            }
        }
        | _FOR_ _ID_ _ASSIGN_ {
            if run_parse(2)
            {
                print_code("sss",
                    "for (int ",
                    $2,
                    " = static_cast<int>("
                );
            }
        }
        expr2 {
            if run_parse(2)
            {
                print_code("s","); ");
            }
        }
        _TO_ {
            if run_parse(2)
            {
                print_code("ss",
                    $2,
                    " < static_cast<int>("
                );
            }
        }
        expr2 {
            if run_parse(2)
            {
                print_code("sss",
                    "); ",
                    $2,
                    "++)\n{\n"
                );
            }
        }
        ;

for_stmt
        : for_body _ENDFOR_          { if run_parse(2) print_code("s","}\n"); }
        | for_body stmt_seq _ENDFOR_ { if run_parse(2) print_code("s","}\n"); }
        ;

if_stmt : _IF_ { if run_parse(2) print_code("s","\tif ("); } if_stmt2
        ;
if_stmt2
        : expr2 _EQUAL_ expr1 stmt_seq _ENDIF_ { if run_parse(2) print_code("s","\t}\n"); }
        | expr2 _EQUAL_ expr1 stmt_seq _ELSE_  { if run_parse(2) print_code("s","\t} else {\n"); } stmt_seq _ENDIF_ { if run_parse(2) print_code("s","\t}\n"); }
        | _ID_  _EQUAL_ { if run_parse(2) print_code("ss",$1," == "); } if_stmt2_equal
        | _OBR_ if_not_stmt _ID_ _CBR_ {
                char buffer[2048];
                sprintf(buffer,"%s",$3);

                if run_parse(2)
                {
                        print_code("ss",buffer,")\n\t{\n");
                }
        } if_bool_stmt
        ;
if_not_stmt
        :
        | _NOT_ { if run_parse(2) print_code("s","!"); }
        ;
if_bool_stmt
        : stmt_seq _ENDIF_ { if run_parse(2) print_code("s","\t}\n"); }
        | stmt_seq _ELSE_  { if run_parse(2) print_code("s","\t}\nelse {\n"); } stmt_seq _ENDIF_ { if run_parse(2) print_code("s","\t}\n"); }
        ;
if_stmt2_equal
        : expr2 { if run_parse(2) print_code("s",") {\n"); } stmt_seq _ENDIF_ { if run_parse(2) print_code("s","\t}\n"); }
        | expr2 { if run_parse(2) print_code("s",") {\n"); } stmt_seq _ELSE_  { if run_parse(2) print_code("s","\t} else {\n"); } stmt_seq _ENDIF_ { if run_parse(2) print_code("s","\t}\n"); }
        ;

local_show
        : _ID_ _POINT_ _ID_ _OBR_ _CBR_
        {
                if (last_token == _ENDCLASS_)
                if run_parse(2)
                {
                        print_code("sssss","\t",$1,".widget->",$3,"();\n\n");
                }
        }
        ;

id_stmt
        : _ID_ _ASSIGN_ _NEW_ _ID_ _OBR_ _CBR_
        {
                if run_parse(2)
                {
                        char buffer[2048];
                        sprintf(buffer,"my%s_obj",class_name);

                        print_code("sssss","\t",$1,".widget = ",buffer,";\n\n");
                }
        }
        ;

local_stmt
        : _LOCAL_
        {
                if run_parse(2)
                {
                        print_code("s","\n\tstatic struct MyObjectTypes ");
                        lineno;
                }
        }
        local_stmts {
                if run_parse(2)
                {
                        print_code("s",";\n\n");
                        lineno += 2;
                }
        }
        ;
local_stmts
        : _ID_  	      { if run_parse(2) print_code("s",$1); }
        | local_stmts _COMMA_ { if run_parse(2) print_code("s",", "); } local_stmts
        ;

class_stmt
        : _CLASS_ _ID_ _OF_ _ID_ _ENDCLASS_ { }
        | _CLASS_ _ID_ _OF_ _ID_ {

                if run_parse(2)
                {
                        if (in_main_function)
                        {
                                char buffer[2048];
                                sprintf(buffer,"my%s_obj",class_name);

                                print_code("sssssss","\t",buffer,"->resize(static_cast<int>(",buffer,"->width), static_cast<int>(",buffer,"->height));\n");
                                print_code("sssssss","\t",buffer,"->move  (static_cast<int>(",buffer,"->left),  static_cast<int>(",buffer,"->top));\n");
                                print_code("s","\n\treturn app.exec();\n}\n");

                                in_main_function = false;
                        }

                        print_code("sssss",
                        "\nvoid my_",
                        strlwr($2),
                        "::my_init_",
                        strlwr($2),
                        "(void)\n{\n"
                        );

                        print_code("sss","\tmy_init_",strlwr($4),"();\n");
                }
                else if run_parse(1)
                {
                        strcpy(class_name,strlwr($2));
                        char buf[2048];
                        char puf[2048];


                        if (!strcmp(strlwr($4),"form"))
                                sprintf(puf,"\tvoid my_init_form(void) { };\n");
                        else	sprintf(puf,"");

                        if (!strcmp(strlwr($4),"form"))		sprintf(buf,"%s","QWidget");     else
                        if (!strcmp(strlwr($4),"pushbutton"))	sprintf(buf,"%s","MyQPushButton"); else
                        if (!strcmp(strlwr($4),"query"))	sprintf(buf,"%s","MyQQuery"); else
                        sprintf(buf,"my_%s",strlwr($4));

                        char buffer2[2048];
                        sprintf(buffer2,"\tvoid my_init_%s(void);\n",strlwr($2));

                        print_code("ssssssssss",
                        "\nclass my_",$2," : public ",buf,"\n{\n\tQ_OBJECT\npublic:\n",

                        buffer2,
                        puf,

                        "\tmy_",$2,"(void) {\n"
                        "\t\ttop = 100.00;\n"
                        "\t\tleft = 100.00;\n"
                        "\t\twidth = 100.00;\n"
                        "\t\theight = 100.00;\n"
                        "\t}\n\t"
                        "void msgbox(QString tstr, QString mstr)\n"
                        "\t{\n"
                        "\t\tQMessageBox* msgBox = new QMessageBox();\n"
                        "\t\tmsgBox->setWindowTitle(tstr);\n"
                        "\t\tmsgBox->setText(mstr);\n"
                        "\t\tmsgBox->exec();\n\t}\n");

                        strcpy(class_type,buf);

                        if (!strcmp($4,"form"))
                        {
                                print_code("s","public:\n");
                                print_code("s","\tdouble top, left, width, height;\n");
                        }
                }
        } class_stmts _ENDCLASS_ {
                if (run_parse(1) || run_parse(3))
                print_code("s","\n};\n"); else
                print_code("s","\n}\n");

                last_token = _ENDCLASS_;
        }
        | _CLASS_ _ID_ _OBR_ _ID_ _COMMA_ _ID_ _CBR_ _OF_ _MENUBAR_ _OBR_ _ID_ _COMMA_ _ID_ _CBR_ {
                if (run_parse_mode == 3)
                {
                        print_code("sssss",
                        "class my_menu_",
                        $2,
                        " : public QMenuBar\n{\n\tQ_OBJECT\npublic:\n\tmy_menu_",
                        $2,
                        "(QWidget *parent = 0);\n"
                        );
                }
        } class_stmts _ENDCLASS_ {
                if (run_parse(1) || run_parse(3))
                print_code("s","\n};\n"); else
                print_code("s","\n}\n");
        }
        ;

object_stmt
        : _ID_ _POINT_ _ID_ _ASSIGN_ _NEW_ _ID_ _OBR_ _ID_ _CBR_
        {
                strcpy(class_element,$6);
                strcpy(class_temp   ,$3);
                strcpy(class_object ,$6);

                if (run_parse(1) || run_parse(3))
                {

                        char buffer[2038];
                        sprintf(buffer,"%s",$3);
                        strcpy (class_temp ,$3);

                        compiler_flag = true;

                        if (!strcmp(strlwr($6),"menu"))
                        {
                                print_code("sss",
                                "\tQMenu *",
                                $3,
                                ";\n");

                                compiler_flag = false;
                        }
                        else if (!strcmp(strlwr($6),"session"))
                        {
                                print_code("sss",
                                "\tMyQSession *",
                                $3,
                                ";\n");
                                compiler_flag = false;
                        }
                        else if (!strcmp(strlwr($6),"database"))
                        {
                                print_code("sss",
                                "\tMyQDataBase *",
                                $3,
                                ";\n");
                                compiler_flag = false;
                        }

                        // ninit
                        if (compiler_flag == true)
                        {
                                if (!strcmp(strlwr($6),"pushbutton")) print_code("sss","\tMyQPushButton *",$3,";\n"); else
                                if (!strcmp(strlwr($6),"entryfield")) print_code("sss","\tMyQLineEdit *",$3,";\n"); else
                                if (!strcmp(strlwr($6),"query"))      print_code("sss","\tMyQQuery *",$3,";\n"); else
                                if (!strcmp(strlwr($6),"container" )) print_code("sss","\tQFrame *",$3,";\n");

                                print_code("ssssssssssssssssssssssssssssssssssssssss",
                                "\tvoid init_",buffer,"(void)\n\t{\n",
                                        "\t\t",buffer,"_top = 0.00;\n",
                                        "\t\t",buffer,"_left = 0.00;\n",
                                        "\t\t",buffer,"_height = 35.00;\n",
                                        "\t\t",buffer,"_width = 90.00;\n",
                                        "\t\t",buffer,"_visible = true;\n",
                                        "\t\t",buffer,"_text = QString(\"\");\n",
                                        "\t}\n",
                                        "\tQString ",buffer,"_text;\n",
                                        "\tdouble ",buffer,"_top;\n",
                                        "\tdouble ",buffer,"_left;\n",
                                        "\tdouble ",buffer,"_width;\n",
                                        "\tdouble ",buffer,"_height;\n",
                                        "\tbool ",buffer,"_visible;\n"
                                );
                        }
                }
                else if (run_parse(2) || run_parse(4))
                {
                        //if (!strcmp($8,"this"))
                        {
                                if (!strcmp(strlwr($6),"menu"))
                                {
                                print_code("sss",
                                        "\n\t",
                                        $3,
                                        " = new QMenu(this);\n"
                                );} else
                                if (!strcmp(strlwr($6),"session"))
                                print_code("sss",
                                        "\n\t",
                                        $3,
                                        " = new MyQSession();\n"
                                ); else
                                if (!strcmp(strlwr($6),"database"))
                                print_code("sss",
                                        "\n\t",
                                        $3,
                                        " = new MyQDataBase();\n"
                                ); else
                                if (!strcmp(strlwr($6),"pushbutton"))
                                print_code("sssssss",
                                        "\n\t",
                                        $3,
                                        " = new MyQPushButton(\"PushButton\",this",
                                        ");\n",
                                        "\tinit_",
                                        class_temp,
                                        "();\n"
                                ); else
                                if (!strcmp(strlwr($6),"entryfield"))
                                print_code("ssssss",
                                        "\n\t",
                                        $3,
                                        " = new MyQLineEdit(this);\n",
                                        "\tinit_",
                                        class_temp,
                                        "();\n"
                                ); else
                                if (!strcmp(strlwr($6),"query"))
                                print_code("ssssss",
                                        "\n\t",
                                        $3,
                                        " = new MyQQuery(this);\n",
                                        "\tinit_",
                                        class_temp,
                                        "();\n"
                                ); else
                                if (!strcmp(strlwr($6),"container"))
                                print_code("ssssssssssss",
                                        "\n\t",$3," = new QFrame(this);\n",
                                        "\t"  ,$3,"->setFrameStyle(QFrame::Box | QFrame::Sunken);\n",
                                        "\t"  ,$3,"->setLineWidth(2);\n",
                                        "\tinit_",
                                        class_temp,
                                        "();\n"
                                );
                        }
                }
        }
        | with_objects_col _ASSIGN_ _NEW_ _ID_ _OBR_ with_objects { strcpy(temp_with2,temp_with); } _CBR_ {

                if (run_parse(1) || run_parse(3))
                {
                        if (!strcmp(strlwr($4),"pushbutton")) print_code("sss","\tMyQPushButton *", temp_with1, ";\n"); else
                        if (!strcmp(strlwr($4),"entryfield")) print_code("sss","\tMyQLineEdit *"  , temp_with1, ";\n"); else
                        if (!strcmp(strlwr($4),"query"))      print_code("sss","\tMyQQuery *"     , temp_with1, ";\n"); else
                        if (!strcmp(strlwr($4),"container" )) print_code("sss","\tQFrame *"       , temp_with1, ";\n"); else
                        if (!strcmp(strlwr($4),"menu" ))      print_code("sss","\tQMenu *"        , temp_with1, ";\n");

                        print_code("ssssssssssssssssssssssssssssssssssssssss",
                        "\tvoid init_",temp_with1,"(void)\n\t{\n",
                                "\t\t",temp_with1,"_top = 0.00;\n",
                                "\t\t",temp_with1,"_left = 0.00;\n",
                                "\t\t",temp_with1,"_height = 35.00;\n",
                                "\t\t",temp_with1,"_width = 90.00;\n",
                                "\t\t",temp_with1,"_visible = true;\n",
                                "\t\t",temp_with1,"_text = QString(\"\");\n",
                                "\t}\n",
                                "\tQString ",temp_with1,"_text;\n",
                                "\tdouble " ,temp_with1,"_top;\n",
                                "\tdouble " ,temp_with1,"_left;\n",
                                "\tdouble " ,temp_with1,"_width;\n",
                                "\tdouble " ,temp_with1,"_height;\n",
                                "\tbool "   ,temp_with1,"_visible;\n"
                        );

                        strcpy(class_element,$4);
                }
                else if (run_parse(2) || run_parse(4))
                {
                        //if (!strcmp(,"this"))
                        {
                                strcpy(class_object,$4);

                                if (!strcmp(strlwr($4),"menu"))
                                {
                                DisplayErrorMessage(1,"Sorry 1111");

                                print_code("ssssssss",
                                        "\n\t",
                                        temp_with1,
                                        " = new QMenu(",
                                        temp_with2,
                                        ");\n",
                                        "\tinit_",
                                        temp_with1,
                                        "();\n"
                                );} else
                                if (!strcmp(strlwr($4),"pushbutton"))
                                print_code("ssssssss",
                                        "\n\t",
                                        temp_with1,
                                        " = new MyQPushButton(\"PushButton\",",
                                        temp_with2,
                                        ");\n",
                                        "\tinit_",
                                        temp_with1,
                                        "();\n"
                                ); else
                                if (!strcmp(strlwr($4),"entryfield"))
                                print_code("ssssssss",
                                        "\n\t",
                                        temp_with1,
                                        " = new MyQLineEdit(",
                                        temp_with2,
                                        ");\n",
                                        "\tinit_",
                                        temp_with1,
                                        "();\n"
                                ); else
                                if (!strcmp(strlwr($4),"query"))
                                print_code("ssssssss",
                                        "\n\t",
                                        temp_with1,
                                        " = new MyQQuery(",
                                        temp_with2,
                                        ");\n",
                                        "\tinit_",
                                        temp_with1,
                                        "();\n"
                                ); else
                                if (!strcmp(strlwr($4),"container"))
                                print_code("sssssssssss",
                                        "\n\t",
                                        temp_with1,
                                        " = new QFrame(",
                                        temp_with2,
                                        ");\n\t",
                                        temp_with1,
                                        "->setFrameStyle(QFrame::Box | QFrame::Sunken);\n\t",
                                        temp_with1,
                                        "->setLineWidth(1);\n\tinit_",
                                        temp_with1,
                                        "();\n"
                                );
                        }
                }

                strcpy(temp_str,temp_with1);
                strcpy(temp_with1,"");
                strcpy(temp_with2,"");
        }
        ;

with_objects_col
        : with_objects { strcpy(temp_with1,temp_with); }
        ;

function_parameters
        : { $$ = ""; }
        | _OBR_ _CBR_ { $$ = ""; }
        | _OBR_ function_parameters2 _CBR_ { $$ = $2; }
        ;

function_parameters2
        : _ID_ _ID_ {
                if run_parse(1)
                {
                        if (!strcmp($1,"int"))
                        $1 = "double";

                        strcat($$," ");
                        strcat($$, $2);
                }
        }
        | function_parameters2 _COMMA_ function_parameters2 {
                if run_parse(1)
                {
                        strcat($$,", ");
                        strcat($$,$3);
                }
        }
        ;

class_stmts
        :
        | _WITH_ _OBR_ _ID_ _CBR_
        {
                if run_parse(2)
                {
                        if (!strcmp($3,"this"))
                        {
                                //strcpy(class_object,$3);
                        }
                        else {
                                char buffer[50];
                                errors++;
                                sprintf(buffer,"ID %s unbekannt.",$3);
                                yyerror(buffer);
                        }
                }
        } with_stmts _ENDWITH_ class_stmts
        | _WITH_ _OBR_ with_objects_col _CBR_
        {
                strcpy(class_temp,temp_with1);
                has_object = true;

        } with_stmts _ENDWITH_
        {
                has_object = false;

                if run_parse(4)
                {
                    if (!strcmp(strlwr(class_element),"menu"))
                    print_code("sss",
                    "\taddMenu(",
                    class_temp,
                    ");\n"
                    );
                }
                else if run_parse(2)
                {
                        char buffer2[2056];
                        sprintf(buffer2,"static_cast<int>(%s",class_temp);

                        compiler_flag = true;

                        if (!strcmp(strlwr(class_object),"session" )) compiler_flag = false; else
                        if (!strcmp(strlwr(class_object),"database")) compiler_flag = false; else
                        if (!strcmp(strlwr(class_object),"query"))    compiler_flag = false;

                        if (compiler_flag == true)
                        {
                                print_code("sssssss","\t",class_temp,"->resize(",buffer2,"_width), ",buffer2,"_height));\n");
                                print_code("sssssss","\t",class_temp,"->move  (",buffer2,"_left) , ",buffer2,"_top));\n\n" );

                                if (!strcmp(strlwr(class_object),"container")) compiler_flag = false;
                                if (!strcmp(strlwr(class_object),"query"))     compiler_flag = false;

                                if (compiler_flag == true)
                                {
                                        print_code("sssss","\t",class_temp,"->setText(",class_temp,"_text);\n");
                                        print_code("sssss","\t",class_temp,"->setDataField(",class_datalink,");\n\n");
                                }

                                print_code("sssssss",
                                        "\tif (",
                                        class_temp,
                                        "_visible) ",
                                        class_temp,
                                        "->show();\n\telse ",
                                        class_temp,
                                        "->hide();\n\n"
                                );
                        }
                }
                strcpy(temp_str,temp_with1);
                strcpy(temp_with1,"");
                strcpy(temp_with2,"");
        } class_stmts
        | object_stmt class_stmts
	| function_decl _RETURN_ { if run_parse(1) print_code("s","\t\tqv = "); } expr1 {
		if run_parse(1)
                {
                        print_code("s",";\n\t\treturn qv;\n\t}\n");
                }
	} class_stmts
	| function_decl function_stmts _RETURN_ _ID_ {
		if run_parse(1)
		{
			strcat(ttc_name, $4);

                        if (get_symbol($4) == TOK_FUNCTION)
                        strcat(ttc_name,"()");

                        print_code("sss","\t\treturn ", ttc_name, ";\n\t}\n");
		}
	} class_stmts
	| function_decl function_stmts _RETURN_ {
                if run_parse(1)
                print_code("s","\t\tqv = ");
	} _STRING_ {
		if run_parse(1)
		{
			print_code("s","\t\treturn qv.toString();\n\t}\n");
		}
	} class_stmts
        | function_decl function_stmts _RETURN_ {
                if run_parse(1)
                print_code("s","\t\tqv = ");
	} expr1 {
                if run_parse(1)
                {
                        print_code("s",";\n\t\treturn qv;\n\t}\n");
                }
        } class_stmts
        ;

function_decl
	: _FUNCTION_ _ID_ function_parameters {
                if run_parse(1)
		{
			strcpy(ttc_name,"my");
			strcat(ttc_name,class_name);
			strcat(ttc_name,"_func_");

                        if (get_symbol($2) == TOK_VARIABLE) strcpy(ttc_name,"");
                        else
                        add_symbol($2,TOK_FUNCTION);

                        print_code(
                        "sssssss",
                        "\n\tMyQVariant my",class_name,"_func_",$2,"(",$3,")\n\t{\n\t"
                        "\tMyQVariant qv;\n"
			);
                }
        }
	;

func_out_stmts
        : { /* empty */ }
        | _MSGBOX_ _OBR_ _STRING_ _COMMA_ _STRING_ _CBR_ {
            if run_parse(2)
            {
                print_code("sssss",
                    "\t\tmsgbox(QString(",$3,"), QString(",$5,"));\n"
                );
            }
        }
        ;

function_stmts
        : { /* empty */ }
        | _MSGBOX_ _OBR_ _STRING_ _COMMA_ _STRING_ _CBR_ {
                if run_parse(1)
                {
                        print_code("sssss",
                        "\t\tmsgbox(QString(",$3,"), QString(",$5,"));\n"
                        );
                }
        }
        ;

with_objects
        : _ID_ _POINT_ _ID_ {
                strcpy(temp_with,$3);
        }
        | _ID_ _POINT_ _ID_ _POINT_ _ID_ {
                strcpy(temp_with,$3); strcat(temp_with,"_");
                strcat(temp_with,$5);
        }
        | _ID_ _POINT_ _ID_ _POINT_ _ID_ _POINT_ _ID_ {
                strcpy(temp_with,$3); strcat(temp_with,"_");
                strcat(temp_with,$5); strcat(temp_with,"_");
                strcat(temp_with,$7);
        }
        | _ID_ _POINT_ _ID_ _POINT_ _ID_ _POINT_ _ID_ _POINT_ _ID_ {
                strcpy(temp_with,$3); strcat(temp_with,"_");
                strcat(temp_with,$5); strcat(temp_with,"_");
                strcat(temp_with,$7); strcat(temp_with,"_");
                strcat(temp_with,$9 );
        }
        | _ID_ _POINT_ _ID_ _POINT_ _ID_ _POINT_ _ID_ _POINT_ _ID_ _POINT_ _ID_ {
                strcpy(temp_with,$3); strcat(temp_with,"_");
                strcat(temp_with,$5); strcat(temp_with,"_");
                strcat(temp_with,$7); strcat(temp_with,"_");
                strcat(temp_with,$9); strcat(temp_with,"_");
                strcat(temp_with,$11);
        }
        ;

with_stmts
        :
        | _ID_ _ASSIGN_ _ID_ _POINT_ _ID_ _POINT_ _ID_ _POINT_ _ID_ _OBR2_ _STRING_ _CBR2_ {
            if run_parse(2)
            {
                if (!strcmp(strlwr($1),"datalink"))
                {
                    print_code("sssssss",
                        "\t",
                        class_temp,
                        "->setDataLink(",
                        $5,
                        ",",
                        $11,
                        ");\n"
                    );
                }
            }
        } with_stmts
        | _ID_ _ASSIGN_ _CLASS_ _DBPOINT_ _ID_ {
                if run_parse(1)
                {
                        if (!strcmp(strlwr($1),"onclick"))
                        print_code("ssssssssss",
                                "public slots:\n\t",
                                "void ",class_temp,"_OnClick()\n\t{\n\t\t",
                                "my",class_name,"_func_",class_temp,"_OnClick();\n\t}\n",
                                "public:\n"
                        ); else
                        if (!strcmp(strlwr($1),"ontimer"))
                        print_code("ssssssssss",
                                "public slots:\n\t",
                                "void ",
                                class_temp,
                                "_OnTimer()\n\t{\n\t\t",
                                "my",
                                class_name,
                                "_func_",
                                class_temp,
                                "_OnTimer();\n\t}\n",
                                "public:\n"
                        );
                } else
                if run_parse(2)
                {
// todo: ...
                        if (!strcmp(strlwr($1),"onclick"))
                        print_code("sssss",
                            "\n\tQObject::connect(",
                            class_temp ,
                            ", SIGNAL(clicked()), this, SLOT(",
                            class_temp,
                            "_OnClick()));\n\n"
                        ); else
                        if (!strcmp(strlwr($1),"ontimer"))
                        print_code("sssss",
                            "\n\tQObject::connect(",
                            class_temp,
                            "->timer, SIGNAL(timeout()), this, SLOT(",
                            class_temp,
                            "_OnTimer()));\n\n"
                        );
                }
        } with_stmts
        | _ID_ _ASSIGN_ _ID_ _POINT_ _ID_ {
                if run_parse(2)
                {
                        if (!strcmp(strlwr(class_element),"database"))
                        {
                                if (!strcmp(strlwr($1),"session"))
                                print_code("sssss",
                                        "\t",
                                        class_temp,
                                        "->session = ",
                                        $5,
                                        ";\n"
                                );
                        }
                }
        } with_stmts
        | _ID_ _ASSIGN_ {
                if run_parse(2)
                {
                        strcpy(temp_object,"");
                        if (has_object == true)
                        {
                                if (!strcmp(strlwr(class_element),"session"))
                                {
                                        if (!strcmp(strlwr($1),"timeout"))
                                        print_code("sss","\t",class_temp,"->timeout = static_cast<int>(");

                                        else if (!strcmp(strlwr($1),"port"))
                                        print_code("sss","\t",class_temp,"->port = static_cast<int>(");
                                }
                                else
                                print_code("sssss","\t",class_temp,"_",$1," = ");
                        }
                        else {
                            print_code("sss"  ,"\t",$1," = ");
                            add_symbol($1,TOK_VARIABLE);
                        }
                }
        } expr2 {
                if run_parse(2)
                {
                    if (!strcmp(strlwr($1),"timeout")) print_code("s",")"); else
                    if (!strcmp(strlwr($1),"port"))    print_code("s",")");

                    print_code("s",";\n");
                }
        } with_stmts
        | _ID_ _ASSIGN_ false_true_expr {
                if run_parse(2)
                {
                        if (!strcmp(strlwr(class_element),"session"))
                        {
                                if (!strcmp(strlwr($1),"active"))
                                {
                                    if ($3 == 0) print_code("sss","\t",class_temp,"->stop();\n"); else
                                    if ($3 == 1) print_code("sss","\t",class_temp,"->start();\n");
                                }
                        }
                        else if (!strcmp(strlwr(class_element),"database"))
                        {
                                if (!strcmp(strlwr($1),"active"))
                                {
                                    if ($3 == 0) print_code("sss","\t",class_temp,"->close();\n"); else
                                    if ($3 == 1) print_code("sss","\t",class_temp,"->open();\n" );
                                }
                        }
                }
        } with_stmts
        | _ID_ _ASSIGN_ string_expr
        {
                if run_parse(4)
                {
                    if (!strcmp(strlwr(class_element),"menu"))
                    {
                        if (!strcmp(strlwr($1),"text")) print_code("sssss","\t",class_temp,"->setTitle(QString(",$3,"));\n");
                    }
                }
                else if run_parse(2)
                {
                    compiler_flag = true;
                    if (!strcmp(strlwr($1),"menufile"))
                    {
                        strcpy(menuFile,$3);
                        print_code("sssssss",
                        "\tmy_menu_",
                        ConvertMenuClass(menuFile),
                        "MENU *my_menu_",
                        ConvertMenuClass(menuFile),
                        "= new my_menu_",
                        ConvertMenuClass(menuFile),
                        "MENU(this);\n"
                        );

                        compiler_flag = false;
                    }

                        if (!strcmp(strlwr(class_element),"session"))
                        {
                            if (!strcmp(strlwr($1),"host")) print_code("sssss","\t",class_temp,"->host = QString(",$3,");\n"); else
                            if (!strcmp(strlwr($1),"user")) print_code("sssss","\t",class_temp,"->user = QString(",$3,");\n"); else
                            if (!strcmp(strlwr($1),"pass")) print_code("sssss","\t",class_temp,"->pass = QString(",$3,");\n");
                        }
                        else if (!strcmp(strlwr(class_element),"database"))
                        {
                            if (!strcmp(strlwr($1),"databasename")) print_code("sssss","\t",class_temp,"->databaseName = QString(",$3,");\n");
                        }
                        else
                        if (compiler_flag == true)
                        print_code("sssss","\t",class_temp,"_text = QString(",$3,");\n");
                }
        } with_stmts
        ;

false_true_expr
        : _ID_ {
                if run_parse(2)
                {
                        if (!strcmp(strlwr($1),"false")) $$ = 0;
                        if (!strcmp(strlwr($1),"true"))  $$ = 1;
                }
        }
        | _FALSE_ { if run_parse(2) $$ = 0; }
        | _TRUE_  { if run_parse(2) $$ = 1; }
        ;

string_expr
        : _STRING_
        {
                if (!$$)
                $$ = (char*) malloc(strlen($1)+1);
                $$ = $1;
        }
        | string_expr _PLUS_ string_expr
        {
                char *buffer = (char*) malloc(4096);

                if (!$$)
                $$ = (char*) malloc(strlen($1)+strlen($3)+5);

                strcpy(buffer,$1);
                strcat(buffer,$3);

                $$ = buffer;
        }
        ;

num_id_stmt
        : _ID_ _ASSIGN_         {  check_list($1); if run_parse(2) print_code("sss","\t",$1," = " ); } expr2 { if run_parse(2) print_code("s",";\n"); }
        | _ID_ _PLUS_  _ASSIGN_ {  check_list($1); if run_parse(2) print_code("sss","\t",$1," += "); } expr2 { if run_parse(2) print_code("s",";\n"); }
        | _ID_ _MINUS_ _ASSIGN_ {  check_list($1); if run_parse(2) print_code("sss","\t",$1," -= "); } expr2 { if run_parse(2) print_code("s",";\n"); }
        | _ID_ _DIV_   _ASSIGN_ {  check_list($1); if run_parse(2) print_code("sss","\t",$1," /= "); } expr2 { if run_parse(2) print_code("s",";\n"); }
        | _ID_ _MUL_   _ASSIGN_ {  check_list($1); if run_parse(2) print_code("sss","\t",$1," *= "); } expr2 { if run_parse(2) print_code("s",";\n"); }
        | _ID_ _POW_   _ASSIGN_ {  check_list($1); if run_parse(2) print_code("sss","\t",$1," ^= "); } expr2 { if run_parse(2) print_code("s",";\n"); }
        | _ID_ { errors++; }
        ;

expr2	: expr3 _PLUS_  { if run_parse(2) { strcat(expr_buffer," + "); print_code("s"," + "); } } expr2
        | expr3 _MINUS_ { if run_parse(2) { strcat(expr_buffer," - "); print_code("s"," - "); } } expr2
        | expr3 _MUL_   { if run_parse(2) { strcat(expr_buffer," * "); print_code("s"," * "); } } expr2
        | expr3 _DIV_   { if run_parse(2) { strcat(expr_buffer," / "); print_code("s"," / "); } } expr2
        | expr3 _MOD_   { if run_parse(2) { strcat(expr_buffer," & "); print_code("s"," % "); } } expr2
        | expr3 _POW_   { if run_parse(2) { strcat(expr_buffer," ^ "); print_code("s"," ^ "); } } expr2
        | expr3
        ;

expr3:    _NUM_ { if run_parse(2) {
        {
            char buffer[2048];
            sprintf(buffer,"%f",$1);
            strcat(expr_buffer,buffer);
            print_code("f",$1);
        } } }
        | _ID_  { if run_parse(2) { strcat(expr_buffer,$1);  print_code("s",$1);  } }
        | _OBR_ { if run_parse(2) { strcat(expr_buffer,"("); print_code("s","("); } } expr2 _CBR_ { if run_parse(2) { strcat(expr_buffer,")"); print_code("s",")"); } }
        | math_ops2
        ;


expr1	: expr4 _PLUS_  { if run_parse(1) print_code("s"," + "); } expr1
        | expr4 _MINUS_ { if run_parse(1) print_code("s"," - "); } expr1
        | expr4 _MUL_   { if run_parse(1) print_code("s"," * "); } expr1
        | expr4 _DIV_   { if run_parse(1) print_code("s"," / "); } expr1
        | expr4 _MOD_   { if run_parse(1) print_code("s"," % "); } expr1
        | expr4 _POW_   { if run_parse(1) print_code("s"," ^ "); } expr1
        | expr4
        ;

expr4:    _NUM_ { if run_parse(1) print_code("f",$1);
        }
        | _ID_  { if run_parse(1) print_code("s",$1); }
        | _OBR_ { if run_parse(1) print_code("s","("); } expr1 _CBR_ { if run_parse(1) print_code("s",")"); }
        ;

math_ops2
        : _ID_ _OBR_ {
            if (!strcmp(strlwr($1),"sin")
            ||  !strcmp(strlwr($1),"cos")
            ||  !strcmp(strlwr($1),"tan")
            ||  !strcmp(strlwr($1),"asin")
            ||  !strcmp(strlwr($1),"acos")
            ||  !strcmp(strlwr($1),"atan")
            ) {
                if run_parse(2)
                {
                    strcat(expr_buffer,strlwr($1));
                }
            }
        } expr2 _CBR_ {
            if run_parse(2)
            {
                strcat(expr_buffer,$1);
            }
        }
        ;
%%

int symbols_count = 0;
char *ptr_symbols[2048];


int check_list(char *name)
{
    bool found = false;
    int i;

    if run_parse(1)
    {
        if (!symbols_count)
        {
                ptr_symbols[symbols_count] = (char*)malloc(strlen(name)+1);
                strcpy(ptr_symbols[symbols_count],name);
                ++symbols_count;
        }

        for (i = 0; i < symbols_count-1; i++)
        {
                if (!strcmp(ptr_symbols[i],name))
                {
                        found = true;
                        break;
                }
        }
        if (found == false)
        {
                ++symbols_count;
                ptr_symbols[symbols_count] = (char*)malloc(strlen(name)+1);
                strcpy(ptr_symbols[symbols_count],name);
                print_code("s","#ifdef __MAIN_RUN__\n");
                print_code("sss","MyQVariant ",name," = 0.00;\n");
                print_code("s","#endif\n");
        }
    }
}

void print_code(char* str, ... )
{
        va_list vl;
        int i;

        va_start(vl, str);

        // Step through the list.
        for( i = 0; str[i] != '\0'; ++i )
        {
                union Printable_t {
                        int     i;
                        float   f;
                        char    c;
                        char   *s;
                } Printable;

                // Type to expect ...
                switch( str[i] )
                {
                        case 'i':
                                Printable.i = va_arg( vl, int );
                                if run_parse(1)
                                fprintf(file_header,"%i", Printable.i); else
                                fprintf(file_main  ,"%i", Printable.i);
                        break;

                        case 'f':
                                Printable.f = va_arg( vl, double);
                                if run_parse(1)
                                fprintf(file_header,"%f", Printable.f); else
                                fprintf(file_main  ,"%f", Printable.f);
                        break;

                        case 'c':
                                Printable.c = va_arg( vl, int );
                                if run_parse(1)
                                fprintf(file_header,"%c", Printable.c); else
                                fprintf(file_main  ,"%c", Printable.c);
                        break;

                        case 's':
                                Printable.s = va_arg( vl, char *);
                                if (run_parse_mode == 3) fprintf(file_header,"%s", Printable.s); else
                                if (run_parse_mode == 1) fprintf(file_header,"%s", Printable.s); else
                                fprintf(file_main  ,"%s", Printable.s);
                        break;

                        default:
                        break;
                }
        }
        va_end( vl );
}

void reset_values(void)
{
    lineno = 1;
    strcpy(menuFile,"");
}

struct used_symbol_list
{
    char *name;
    int type;
};
struct used_symbol_list symbol_list[4096*10];
static int symbol_list_counter = 0;
void add_symbol(char *str, int type)
{
    int i;
    bool found = false;
    for (i = 0; i < symbol_list_counter; i++)
    {
        if (!strcmp(symbol_list[i].name,str))
        {
            found = true;
            break;
        }
    }

    if (found == false)
    {
        i = symbol_list_counter++;
        symbol_list[i].name = (char*) malloc(strlen(str)+1);
        strcpy(symbol_list[i].name,str);
        symbol_list[i].type = type;
    }
}

int get_symbol(char *str)
{
    int i;
    for (i = 0; i < symbol_list_counter; i++)
    {
        if (!strcmp(symbol_list[i].name,str))
        return symbol_list[i].type;
    }   return 0;
}

extern void create_main_window(int argc, char **argv);
extern void displayEnvError(void);

int main(int argc, char **argv)
{
    create_main_window(argc,argv);
    return 0;
}

extern void DisplayFileError(char *msg);
extern void compile_program(void);

void start_parser(void)
{
    if (run_parse(1) || run_parse(2))
    yyparse();

    if (run_parse(2) && strlen(menuFile) > 2)
    {
        char *mfile = ConvertMenuString(menuFile);
        fclose(yyin);
        yyin = fopen(mfile,"r");

        if (!yyin)
        {
            DisplayFileError(mfile);
            return;
        }

        run_parse_mode = 4;
        print_code("sssss",
        "my_menu_",
        ConvertMenuClass(menuFile),
        "MENU::my_menu_",
        ConvertMenuClass(menuFile),
        "MENU(QWidget *parent) : QMenuBar(parent)\n{\n"
        );
        run_parse_mode = 3;

        fseek(yyin,0,0);
        yyparse();

        run_parse_mode = 4;
        fseek(yyin,0,0);
        reset_values();
        yyrestart(yyin);
        yyparse();
    }
}

void restart_parser(FILE *yf)
{
    yyrestart(yf);
}
