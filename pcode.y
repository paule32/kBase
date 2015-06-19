%{
/*
   (c) Copyright 2013-2015  Kallup Software.
   All rights reserved.

   Written by Jens Kallup <jkallup@web.de>,

   This file is subject to the terms and conditions of the MIT License:

   Permission is hereby granted, free of charge, to any person
   obtaining a copy of this software and associated documentation
   files (the "Software"), to deal in the Software without reiction,
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
#include "QtCore/QDebug"

#define run_parse(x) (run_parse_mode == (x))
#define false 0
#define true  1

extern "C" int yywrap(void) { return 1; } 
extern int yylex();

int run_parse_mode;
extern char *strlwr(char *c);
extern void DisplayMessage(char*);

extern void DisplayErrorMessage(int,char*);
extern msgbox(QString,QString);
extern char* strlwr(char*);
extern void yyerror(char *msg);

extern FILE* yyin;
extern int lineno;
extern int commaCount;

FILE *file_header         = nullptr;
FILE *file_main           = nullptr;
FILE *file_classes        = nullptr;
FILE *file_classes_header = nullptr;
FILE *file_assembler      = nullptr;

bool init_construct   = false;
bool create_assembler = false;

int no_expr = 0;
int app_flag = 0;
int last_token = 0;
int class_counter = 0;
int function_counter = 0;
int in_while_loop = 0;
int in_array_cnt = 0;
int ifop = 0;
int program_exec_mode = 0;
int expr2inc = 2;
int twisted = 0;
int errors = 0;
int lineno = 1;
int do_case_counter = 0;
int do_case_flag = 0;

int array_var_counter = 1;

bool ident_code = false;
bool has_if_flag = false;
bool has_for_flag = false;
bool class_has_subclass = false;
bool has_case_flag = false;
bool no_do_case_flag = true;

#define TOK_VARIABLE 1
#define TOK_FUNCTION 2

char *this_object;

char temp_with [2048*3];
char temp_with1[2048*3];
char temp_with2[2048*3];
char expr_buffer[2048*3];
char printcon_buffer[2048*3];
char menuFile[2048];

char temp_str[2048*3];
char temp_object[2048];
char  class_temp[2048];
char  ttc_name[2048*3];
char  *tmp_id;

enum class_types {
  clInvalid,
  clButton
};

class_types class_type = clInvalid;

char *class_object;
char *class_methode_code;
char class_name[2048];
char *class_local;
char *class_datalink;
char *class_element;
char _buffer[2048];

extern void check_list(char *name);
extern char * stringReplace(char*, char*, char*);

void check_added_symbol(const char*, int);

void add_dll_func(char*,char*,char*);
void write_dll_includes(void);
void write_dll_free(void);

void print_comma(void);

void print_code(char* str, ... );
void add_symbol(char* str, int type);
int  get_symbol(char* str);

extern int errors;

extern void set_dbg_line(int);
extern int line_num;

void print_def(char* sym);
extern int errors;

bool in_print_console = false;
bool in_myqvariant = false;
bool in_upper_case = false;

extern int line_num;

struct class_functions_struct
{
    QString name;
    QStringList parameters;
};

// -----------------------------
// hold functions/parameters ...
// -----------------------------
QMap<QString, QStringList> procedure_parameters;
QMap<QString, QStringList> procedure_members;

QString current_function;
QString class_function_name;

QString tmp_object;
%}

%union {
    int type;
    float	val;
    char* 	id;
    char*       path;
    char*	text;
    char*       trfa;
    char*	object_class_name;
    char*	object_class_name_type;
    char*	object_new_id;
}

%start program


%token _POINT_
%token _DBPOINT_ _MSGBOX_ _EQUAL_ _PARAMETER_
%token _OBR2_ _CBR2_ _MENUBAR_
%token _GETLINE_ _SET_ _PATH_
%token _PATHID_ _WHILE_ _EOF_ _STORE_
%token _COUNT_ _AUSRUF_ _DOLLAR_SIGN_
%token _CLI_PROGRAM_ _DEFINE_ _SHARP_ _EXTERN_ _FROM_ _CSTRING_
%token _CLEAR_ _INT_  _NULLOBJ_


%token _NUM_ _ID_ _ASSIGN_ _PLUS_ _MINUS_ _DIV_ _MUL_ _MOD_ _POW_ _OBR_ _CBR_ _TYPE_ _DATE_ _TIME_
%token _TRUE_ _FALSE_ _STRING_ _COMMA_ _LEN_ _ASC_ _AT_ _SPACE_ _TRIM_ _SUBSTR_ _TEST_ _ARRAY_DIM0_
%token _LOWER_ _UPPER_ _ARRAY_DIM_ _ARRAY_DIM1_ _ARRAY_DIM2_ _ARRAY_ _PRINT_TEXT_ _NOT_ _NEW_
%token _CLASS_ _OF_ _ENDCLASS_ _WITH_ _ENDWITH_ _ARRAY_DIM3_ _ARRAY_DIM4_ _PUSHBUTTON_
%token _FUNCTION_ _FUNCTION_ARRAY_ _RETURN_ _IF_ _ELSE_ _ENDIF_ _FOR_ _ENDFOR_ _TO_ _USE_
%token _OBJECT_ID_ _OBJECT_ID2_ _ARRAY_REMARK0_ _THIS_OBJECT_PUSHBUTTON_ _CLASS_ONCLICK_ _CLASS_ONCLICK2_
%token _FUNCTION_CALL_CLASS_ _DO_ _CASE_ _OTHERWISE_ _ENDDO_ _ENDCASE_ _LOCAL_ _INNER_TEXT_
%token _DATABASE_ _OPEN_ _LOGIN_ _LOGIN_USERPASS_ _SELECT_ _THIS_OBJECT_CONTAINER_

%type <val> _NUM_
%type <id> _ID_ _DATE_ _TIME_
%type <path> _PATHID_
%type <trfa> false_true_expr
%type <text> _FUNCTION_CALL_CLASS_ _LOGIN_USERPASS_ _INNER_TEXT_ _THIS_OBJECT_CONTAINER_
%type <text> _STRING_ string_expr _THIS_OBJECT_PUSHBUTTON_ _CLASS_ONCLICK_ _CLASS_ONCLICK2_
%type <text> _ARRAY_DIM0_ _ARRAY_DIM1_ _ARRAY_DIM_ _SPACE_ _SUBSTR_
%type <object_class_name> _OBJECT_ID_ _OBJECT_ID2_

%%

program : program_stmts ;

program_stmts
    :   {
        if ((run_parse_mode == 1) && (create_assembler == false)) {
            print_code("s",
                "// ---------------------------------\n"
                "// kbase 1.0 (c) " __DATE__ " by Jens Kallup\n"
                "// ---------------------------------\n"
                "#ifndef __PROGRAM_HEADER__\n"
                "#define __PROGRAM_HEADER__\n\n"
                "#include \"pch.h\"\n"
                "#include \"app.classes.h\"\n"
            );
        }
        else if ((run_parse_mode == 1) && (create_assembler == true))
        {
            run_parse_mode = 5;
            static int flag= 0;
            if (flag == 0) {
                print_code("s",
                    ";------------------------------------------\n"
                    "; kbase 1.0 (c) " __DATE__ " by Jens Kallup\n"
                    ";------------------------------------------\n"
                    "bits 64\n"
                    "\torg 0\n"
                    "text:\n"
                    "dq 19790208\n"
                    "dq 10101\n"
                    "dq plugin_name - text\n"
                    "\n"
                    "exports_len:\n"
                    "dq (end_of_table-exports)/24\n"
                    "exports:\n"
                    "\tdq start_symbol - text\n"
                    "\tdq 0\n"
                    "\tdq start_function - text\n"
                    "\n"
                    "\tdq init_application_symbol - text\n"
                    "\tdq 2\n"
                    "\texport_call__init_app:\n"
                    "\tdq 0 \t; relocation function\n"

                    ";.include \"plugin_exports.s\"\n"

                    "end_of_table:\n"
                    "start_symbol:\n"
                    "\tdb \"start\",0\n"
                    "\n"
                    "init_application_symbol:\n"
                    "\tdb \"init_application\",0\n\n"
                    "start_function:\n"
                    "\tmov rax, rdi\n"
                    "\tpush rax\n"
                    "\n"
                    "\tmov rbx, rax\n\n"
                    "\tmov rbx, [rbx + export_call__init_app]\n"
                    "\tcall rbx\n"
                );
                flag++;
            }
        }

        if run_parse(2)
        {
                print_code("s",
                "#define __MAIN_RUN__\n"
                "#include \"app.h\"\n"
                "\n"
                );

                print_code("s",
                "int main(int argc, char **argv)\n{\n");

                print_code(
                "s",
                "\tQApplication app(argc,argv);\n\n"
                //"\tQTranslator translator;\n"
                //"\ttranslator.load(\"qt_de\", \"./translations\");\n"
                //"\tapp.installTranslator(&translator);\n\n"
                );

                write_dll_includes();

                print_code("s","\t// --- start ---\n");
        }
     } stmt_seq {
            if run_parse(5)
            {
                static int flag = 0;
                if (flag == 0)
                {   flag++;
                    print_code("s",
                        "\tleave\n"
                        "\tret\n"
                        "\n"
                        ";----------------------------------------------------\n"
                        "; main label: it holds the base of mmap'ed plugin ...\n"
                        ";----------------------------------------------------\n"
                        "base_addr:\n"
                        "\tdq 0\n"
                        "\n"
                        "plugin_name:\n"
                        "\tdb \"app.plugin\",0\n"
                    );
                }
            }

            if run_parse(1)  {
                print_code("s","#endif\n");
            }
            if run_parse(2) {
                if (app_flag == 0) {
                    print_code("s",
                        "\tint r = app.exec();\n"
                        "\n\treturn r;\n}\n"
                    );
                }
            }
        }
        ;

stmt_seq
    : stmt_seq stmt { }
    | stmt
    ;

stmt
    : { /* empty */ }
    | stmt print_stmt { }
    | stmt array_stmt { }
    | stmt id_stmt { }
    | stmt local_stmt { }
    | stmt open_database_stmt { }
    | stmt select_stmt { }
    | stmt use_stmt { }
    | stmt class_stmt { }
    ;

local_stmt
    : _LOCAL_ _ID_ {
        if run_parse(1)
        print_def($2);
    }
    ;

open_database_stmt
    : open_database_login_id _ID_ { print_comma(); } _DIV_ { print_comma(); } _ID_ {
        if run_parse(2)
        print_code("sssss",
            "QString(\"",
            $2,
            "\"),QString(\"",
            $6,
            "\"));\n"
        );
    }
    | open_database_login_id _ID_ {
        if run_parse(2)
        print_code("ss",$2,",");
    } _DIV_ { print_comma(); } string_expr {
        if run_parse(2)
        print_code("s",");\n");
    }
    | open_database_login_str _ID_ {
        if run_parse(2)
        print_code("s",$2);
        print_comma();
    } _DIV_ { print_comma(); } string_expr {
        if run_parse(2)
        print_code("s",");\n");
    }
    | open_database_login_str string_expr { print_comma(); } _DIV_ _ID_ {
        if run_parse(2)
        print_code("sss",
            "QString(\"",
            $5,
            "\"));\n"
        );
    }
    | open_database_login_str _LOGIN_USERPASS_ {
        if run_parse(2) {
            char *user = (char*)malloc(2048);
            char *pass = (char*)malloc(2048);

            char buffer[4000];

            strcpy(buffer,$2);
            sscanf(buffer,"%s / %s",user,pass);
            print_code("sssss",
                "QString(",
                user,
                "), QString(",
                pass,
                "));\n"
            );
            free(user);
            free(pass);
        }
    }
    ;

open_database_login_str : open_database string_expr _LOGIN_ { print_comma(); }  ;
open_database_login_id  : open_database _ID_        _LOGIN_ {
    if run_parse(2) print_code("ss",$2,",");
    }
    ;

open_database
    : _OPEN_ _DATABASE_ {
        if run_parse(2)
        print_code("s","\txbase_open_database(");
    }
    ;

open_database_expr
    : _STRING_ _DIV_ _STRING_ {
        if run_parse(2)
        print_code("s",$1);
        print_comma();
        print_code("s",$3);
    }
    ;

select_stmt
    : _SELECT_ {
        if run_parse(2)
        {
            has_for_flag = true;
            print_code("s","\txbase_select(");
        }
    } numeric_expr {
        if run_parse(2) {
            print_code("s",");\n");
            has_for_flag = false;
        }
    }
    ;

use_stmt
    : _USE_ string_expr {
        if run_parse(2) {
            print_code("sss",
                "\txbase_open_dbf(",
                $2,
                ");\n"
            );
        }
    }
    | _USE_ _ID_ {
        if run_parse(2) {
            print_code("sss",
                "\txbase_open_dbf(\"",
                $2,
                "\");\n"
            );
        }
    }
    | _USE_ _TEST_ {
        if run_parse(2)
        print_code("s","\txbase_open_dbf(\"test\");\n");
    }
    ;

class_stmt
	: _CLASS_ _ID_ _OF_ _ID_ {

		yylval.object_class_name = (char*) malloc(strlen($2)+1);
		strcpy(yylval.object_class_name,$2);

		yylval.object_class_name_type = (char*) malloc(strlen($4)+1);
		strcpy(yylval.object_class_name_type,$4);
        strcpy(class_name,$2);

		init_construct = true;

		if run_parse(3)
		{
            static int f = 0;
            if (f == 0) {
		        print_code("ss",
		            "#define __APP_HEADER__\n",
		            "#include \"app.classes.h\"\n\n"
		        );
                f = 1;
            }
            QString str = QString($2).toLower();

		    print_code("ssss",
			"void myclass_",
                        str.toStdString().c_str(),
			"::myclass_init",
			"(void)\n{\n"
		    );
		}
		if run_parse(4)
		{
                    QString str = QString($4).toLower();
                    QString obj;

                    if (str == QString("form")) {
                        obj = QString("MyQForm");
                        class_has_subclass = false; } else {
                        class_has_subclass = true;
                        obj = QString("myclass_") + str;
                    }


            /*if (class_has_subclass == false)
            print_code("s",
                "#include \"pch.h\"\n\n"
            );*/

		    print_code("sssssss",
		    	"class myclass_",
                            QString($2).toLower().toStdString().c_str(),
			    ": public ",
                            obj.toStdString().c_str(),
			    "\n{\npublic:\n\tmyclass_",
                            QString($2).toLower().toStdString().c_str(),
			    "(void) { myclass_init(); } \n"
		        );
		        print_code("ss",
			    "\n\tvoid myclass_init",
			    "(void);\n"
		    );
		}
	} in_class_stmts _ENDCLASS_ {
		if run_parse(3)
		{
			if (init_construct)
			print_code("s","}\n");
			init_construct = false;
		}
		else if run_parse(4)
		{
			print_code("s","\n};\n");
		}
	}
	;

in_class_stmts
        : in_class_stmts class_stmts { }
        | class_stmts
        ;

class_stmts
    : /* empty */
    | new_class_ref
    | with_class
    | _FUNCTION_ARRAY_ {
        if run_parse(4)
        {
            QString str1 = QString(yylval.text).toLower();
            QString str2 = str1;
            QString str3 = str2;

            bool flag = false;
            int c;

            str1 = str1.replace("function","MyQVariant& ");

            if (str1.contains(QString("(")) != true) {
            str1.append(QString("(void)")); flag = true; }
            str1.append(QString("\n{\n "));

            str2 = str2.replace("function","");
            str2 = str2.replace(QRegExp("\\(.*\\)"),"");
            str2 = str2.replace(QRegExp("[ \\t\\n\\r]*"),"");

            current_function = str2;

            if (flag == false) {
                str3 = str3.replace("function","");
                str3 = str3.replace(QRegExp("[ \\t\\n]*[a-zA-Z0-9_]*[ \\t\\n]*\\("),"");
                str3 = str3.replace(")","");
            }
            else {
                str3 = QString("");
            }

            QString str_p =
            QString("myclass_")  +
            QString(class_name)  +
            QString("::")        +
            QString(current_function).toLower();

            QString str4 = "void";
            QStringList sl1; sl1 << "@void";

            if (
            procedure_parameters.values(str_p).isEmpty())
            procedure_parameters.insert(str_p,sl1);

            QStringList mlist; mlist = procedure_parameters.values(str_p).at(0);
            if (mlist.at(0) == QString("@init:onMouseClick"))
            str4 = "QMouseEvent *p1";

            run_parse_mode = 4;

            QString str5 =
            QString("\tMyQVariant ") +
            QString(str2) +
            QString("(")  +
            QString(str4) +
            QString(");\n");

            print_code("s",str5.toStdString().c_str());
            run_parse_mode = 3;

            QList <QString> str6; str6
                << QString("MyQVariant myclass_")
                << QString(class_name)
                << QString("::")
                << QString(str2)
                << QString("(")
                << QString(str4)
                << QString(")\n")
                << QString("{\tMyQVariant result;\n");

            if (mlist.at(0) == QString("@init:onMouseClick"))
            str6<< QString("\tp1 = event_OnMouseClick;\n");

            procedure_members[current_function] += str6;
            run_parse_mode = 4;
        }
    } class_func_stmts {
        if run_parse(4) {
            run_parse_mode = 3;
            QList <QString> strlist; strlist << QString("}\n");
            procedure_members[current_function] += strlist;

            QString str ;
            QStringList mlist; mlist = procedure_members.values(current_function).at(0);
            int msize = mlist.size();

            for (int c = 0; c < msize; ++c)
            str += QString(mlist.at(c));

            qDebug() << str;

            print_code("s",str.toStdString().c_str());
            run_parse_mode = 4;
        }
    }
    | _THIS_OBJECT_CONTAINER_ {
        QString str1 = QString($1).toLower();
        QString str2 = str1;
        QString str3;

        if (run_parse_mode == 4 || run_parse_mode == 3)
        {
            str2 = str2.replace(QRegExp(".*container\\("),"");
            str2 = str2.replace(QRegExp("this\\."),"");
            str2 = str2.replace(QRegExp("\\)"),"");

            str2 = QString("\n\tMyQPanel *") +
            str2 + QString(";\n");

            str1 = str1.replace(QRegExp("this\\."),"this->");
            str1 = str1.replace(QRegExp("\\."),"_");
            str1 = str1.replace(QRegExp("container\\("),"MyQPanel(");
            str3 = str1;
            str1 = QString("\t") + str1 + QString(";\n");

            str3 = str3.replace(QRegExp("this->"),"");
            str3 = str3.replace(QRegExp("[ \\t\\n]=[ \\t\\n]new[ \\t\\n]MyQPanel\\(.*"),"");
            str3 = QString("\tMyQPanel *") + str3 + QString(";\n");
        }

        if run_parse(4) { print_code("s",str3.toStdString().c_str()); } else
        if run_parse(3) { print_code("s",str1.toStdString().c_str()); }
    }
    | _THIS_OBJECT_PUSHBUTTON_ {
        QString str1 = QString($1).toLower();
        QString str2 = str1;
        QString str3;
        QString str4;

        if (run_parse_mode == 4 || run_parse_mode == 3)
        {
            str3.clear();
            str4.clear();

            int pos = str2.lastIndexOf(QRegExp(".*\\=[ \\t\\n]new[ \\t\\n]pushbutton\\("));

            for (int i=0;i<pos;i++) str3[i] = str2[pos-i-1];
            for (int i=0;i<pos;i++) str4[i] = str3[pos-i-1];

            str2 = str1;
            str2 = str2.replace(QRegExp(".*pushbutton\\("),"");
            str2 = str2.replace(QRegExp("this\\."),"this->");
            str2 = str2.replace(QRegExp("\\."),"_");
            str2 = str2.replace(QRegExp("\\)"),"");

            str4 = str4.replace(QRegExp("this\\."),"this->");
            str4 = str4.replace(QRegExp("\\."),"_");

            str3 =
            str4 + QString(" = new MyQPushButton(") +
            str2 + QString(", \"pusher\");\n");

			str4 = str4.replace(QRegExp("this\\-\\>"),"");
            str4 = QString("\tMyQPushButton *") + str4 + QString(";\n");
        }

        if run_parse(3) { print_code("s",str3.toStdString().c_str()); } else
        if run_parse(4) { print_code("s",str4.toStdString().c_str()); }
    }
	;

class_func_stmts
    : class_func_stmts class_funcs { }
    | class_funcs
    ;

class_funcs
    :
    | class_local_stmt
    | print_stmt
    | class_if_stmt
    | class_for_stmt
    | class_docase_stmt
    | _RETURN_ {
        if run_parse(4) {
            run_parse_mode = 3;
            procedure_members[current_function] += QString("\treturn result;\n");
            run_parse_mode = 4;
        }
    }
    ;

class_local_stmt
    : _LOCAL_ class_local_multi
    ;

class_local_multi
    : _ID_ {
        if run_parse(4) {
            QString str1 = QString($1).toLower();
            QString str2 = QString("\tMyQVariant %1;\n").arg(str1);
            procedure_members[current_function] += str2;
        }
    }
    | class_local_multi _COMMA_ class_local_multi
    ;

class_if_stmt
    : _IF_ {
        has_if_flag = true;
        if run_parse(4)   {
            QString str = "\tif (";
            procedure_members[current_function] += str;
        }
    } string_expr _EQUAL_ {
        if run_parse(4)   {
            QString str = QString(" == ");
            procedure_members[current_function] += str;
        }
    } string_expr {
        if run_parse(4)   {
            QString str = QString(") {\n");
            procedure_members[current_function] += str;
        }
    } class_func_stmts end_if_stmt {
        has_if_flag = false;
    }
    | _IF_ {
        has_if_flag = true;
        if run_parse(4)   {
            QString str = "\tif (";
            procedure_members[current_function] += str;
        }
    } numeric_expr _EQUAL_ {
        if run_parse(4)   {
            QString str = QString(" == ");
            procedure_members[current_function] += str;
        }
    } numeric_expr {
        if run_parse(4)   {
            QString str = QString(") {\n");
            procedure_members[current_function] += str;
        }
    } class_func_stmts end_if_stmt {
        has_if_flag = false;
    }
    ;

end_if_stmt
    : _ENDIF_ {
        if run_parse(4) {
            QString str = QString("\t}\n");
            procedure_members[current_function] += str;
        }
    }
    | _ELSE_ {
        if run_parse(4) {
            QString str = QString("\t}\n\telse {\n");
            procedure_members[current_function] += str;
        }
    } class_func_stmts _ENDIF_ {
        if run_parse(4) {
            QString str = QString("\t}\n");
            procedure_members[current_function] += str;
        }
    }
    ;

class_for_stmt
    : _FOR_ _ID_ _ASSIGN_ {
        has_for_flag = true;
        if run_parse(4) {
            QString str1 = QString($2).toLower();
            QString str2 = QString("\tfor (int %1 = ").arg(str1);
            procedure_members[current_function] += str2;
        }
    } numeric_expr {
        if run_parse(4) {
            QString str1 = QString($2).toLower();
            QString str2 = QString("; %1 < ").arg(str1);
            procedure_members[current_function] += str2;
        }
    } _TO_ numeric_expr {
        if run_parse(4) {
            QString str1 = QString($2).toLower();
            QString str2 = QString("; ++%1)\n\t{\n").arg(str1);
            procedure_members[current_function] += str2;
        }
    } class_func_stmts _ENDFOR_ {
        has_for_flag = false;
        if run_parse(4) {
            QString str = QString("\t}\n");
            procedure_members[current_function] += str;
        }
    }
    ;


case_expr_stmts
    : case_expr_stmts case_expr { }
    | case_expr
    ;

class_docase_stmt
    : _DO_ _CASE_ _ENDCASE_ {
        if run_parse(4) {
            --do_case_counter;
        }
    }
    | _DO_ _CASE_ {
        if run_parse(3)
        has_if_flag = true;
        else if run_parse(4)
        has_case_flag = true;
    } case_expr_stmts _ENDCASE_ {
        if run_parse(3) {
            has_if_flag = false;
        }
        else if run_parse(4) {
            QString str = QString("\t}\n");
            procedure_members[current_function] += str;

            --do_case_counter;
        }
    }
    ;

case_expr
    : _OTHERWISE_ {
        if run_parse(4) {
            QString str = QString("\t} else {\n");
            procedure_members[current_function] += str;
        }
    }
    | _CASE_ _ID_ _EQUAL_ {
        if run_parse(3) {
            has_if_flag = true;
        }
        else if run_parse(4) {
            if (do_case_counter > 0) {
                QString str = QString("\t}\n\telse ");
                procedure_members[current_function] += str;
            }
            else {
                if (do_case_flag == 1) {
                    QString str = QString("\tMyQVariant %1;\n").arg($2);
                    procedure_members[current_function] += str;
                }
            }

            QString str1 = QString($2).toLower();
            QString str2 = QString("\tif (%1 == ").arg(str1);
            procedure_members[current_function] += str2;

            ++do_case_counter;
        }
    } case_expr_case
    ;

case_expr_case
    :
    | numeric_expr {
        if run_parse(4) {
            QString str = QString(")\n\t{\n");
            procedure_members[current_function] += str;
        }
    }
    ;

new_class_ref
	: _OBJECT_ID_ _ASSIGN_ _NEW_ _PUSHBUTTON_ {
		printf(" pusher\n");
	} _OBJECT_ID2_ {
		printf("objid: %s\n",yylval.object_class_name);
	}
	;

with_class
    : with_class with_event_stmts { }
    | with_event_stmts
    ;

with_event_stmts
    :
    | _CLASS_ONCLICK2_ {
        if run_parse(3)
        {
            QString str1 = QString($1);
            str1 = str1.replace(QRegExp("[ \t\n\r]*onclick[ \t\n\r]*\\=[ \t\n\r]*\\{"),"");
            str1 = str1.replace(QRegExp("\\}"),"");
            str1 = str1.replace(QRegExp("[ \t\n\r]*"),"");
            str1 = str1.simplified();
            str1 = str1.replace(QRegExp("class\\:\\:"),"");

            QStringList  str1_list;
            str1_list << str1.split(";", QString::SkipEmptyParts, Qt::CaseInsensitive);
 
            QString tmpstr;
            for (int i = 0; i < str1_list.count(); ++i) {
                tmpstr = "";
                tmpstr = tmpstr + QString(this_object);
                tmpstr = tmpstr + QString("->form_OnMouseClick << std::bind(&myclass_");
                tmpstr = tmpstr + QString(class_name);
                tmpstr = tmpstr + QString("::");
                tmpstr = tmpstr + QString(str1_list[i].toLower());
                tmpstr = tmpstr + QString(",this,");
                tmpstr = tmpstr + QString(this_object);
                tmpstr = tmpstr + QString("->event_OnMouseClick);\n");

                print_code("s",tmpstr.toStdString().c_str());

                QString str =
                QString("myclass_")  +
                QString(class_name)  +
                QString("::")        +
                str1_list[i].toLower();

                class_function_name = str;

                QStringList sl; sl << "@init:onMouseClick";
                procedure_parameters.insert(str,sl); 
            }
        }
    }
	| _CLASS_ONCLICK_ _ID_ {
        if run_parse(3) {
            QString  tmpstr ;
            tmpstr = tmpstr + QString(this_object);
            tmpstr = tmpstr + QString("->form_OnMouseClick << std::bind(&myclass_");
            tmpstr = tmpstr + QString(class_name);
            tmpstr = tmpstr + QString("::");
            tmpstr = tmpstr + QString(QString($2).toLower());
            tmpstr = tmpstr + QString(",this,");
            tmpstr = tmpstr + QString(this_object);
            tmpstr = tmpstr + QString("->event_OnMouseClick);\n");

            print_code("s",tmpstr.toStdString().c_str());

            QString str =
            QString("myclass_")  +
            QString(class_name)  +
            QString("::")        +
            QString($2).toLower();

            class_function_name = str;


            QStringList sl; sl << "@init:onMouseClick";
            procedure_parameters.insert(str,sl);
        }
	}
	| _WITH_ _ARRAY_DIM1_ {

        QString str1 = QString($2).toLower();
        QString str0 = QString(class_name).toLower();

        strcpy(class_name,str0.toStdString().c_str());

        str1 = str1.replace(QRegExp("[ \t\n]\\("),"");
        str1 = str1.replace(QRegExp("\\)"),"");
        str1 = str1.replace(QRegExp("\\("),"");

        QString str2 = str1;
        str2 = str2.replace("this",class_name);
        str2 = str2.replace(".","_");

        str1 = str1.replace(".","->");

        this_object = new char[str1.size()+1];
        //strcpy(class_name ,str2.toStdString().c_str());
        strcpy(this_object,str1.toStdString().c_str());

    }  with_class _ENDWITH_ { }
    | id_stmt    ;

array_stmt
    : _ID_ _ASSIGN_ _NEW_ _ID_ _ARRAY_DIM1_ {

        QString cmp = QString($4).toLower();
        if (cmp == QString("array"))
        {
            if run_parse(5)
            {
                print_code("ssissis",
                    "\tmov rdx, 1\t; 1 = MyQVariant\n",
                    "\tmov rsi, ",
                    commaCount,
                    "\t; array dimension's\n",
                    "\tmov rdi, ",
                    array_var_counter++,
                    "\t; var. counter\n"
                    "\tpop rax\n"
                    "mov rbx, [rax + create_new_array]\n"
                    "\tcall create_new_array\n"
                );
            }

            if run_parse(1)
            {
                print_def($1);
                print_code("sssis",
                "#define __COMPILER_DIM_ARRAY_",
                $1,
                " ",
                in_array_cnt,
                "\n"
                );
                in_array_cnt = 0;
            }

            if run_parse(2)
            {
                print_code("sssss",
                    "\ttypedef boost::multi_array<MyQVariant, __COMPILER_DIM_ARRAY_",
                    $1,
                    "> ARRAY_",
                    $1,
                    ";\n"
                );

                QString str = QString($5).replace(QRegExp("("),"");
                        str = str.        replace(QRegExp(")"),"");

                print_code("sssssss",
                    "\tARRAY_",
                    $1,
                    " ARRAYTYPE_",
                    $1,
                    "(boost::extents[",
                    str.toStdString().c_str(),
                    "]);\n"
                );
            }
        }
        else {
            if run_parse(1)
            {
               //add_symbol($4,3);
                print_code("ssssssssss",
                        "#ifdef __MAIN_RUN__\n",
                        "  #ifndef _ISDEFINED__class_",   $4, "\n",
                        "  #define _ISDEFINED__class_",   $4, "\n",
                        "MyQForm *myclass_local_",
                        $1,
                        ";\n  #endif\n#endif\n"
                );
            }

            if run_parse(2)
            print_code("sssss",
                "\t{\n\tmyclass_local_",
                $1,
                " = new myclass_",
                $4,
                "();\n\t}\n"
            );
        }
    }
    ;

numeric_expr
    : _NUM_ {
        char buffer[2048];
        sprintf(buffer,"%f",$1);
        QString s = QString(buffer).replace(",",".");

        if run_parse(2) {
            if (has_for_flag)
            print_code("s",QString("int(%1)").arg(s).toStdString().c_str()); else
            print_code("s",s.toStdString().c_str());
        }
        else if run_parse(3) {
            if (!has_if_flag && !has_for_flag)
            print_code("s",s.toStdString().c_str());
        }
        else if run_parse(4) {
            QList <QString> str;
            if (has_for_flag)
            str << QString("int(%1)").arg(s); else
            str << QString("double(%1)").arg(s);
            procedure_members[current_function] += str;
        }
    }
    | _AT_ {
        if run_parse(2)
            print_code("s","\tget_stringindex(\n");
    } string_expr _COMMA_ { if run_parse(2) print_code("s",",\n");
    } string_expr _CBR_ {
            if run_parse(2)
            print_code("s",")");
    }
    | _ASC_ {
            if run_parse(2)
            print_code("s","\tget_char_code(");
        } string_expr _CBR_ {
            if run_parse(2)
            print_code("s",")");
        }
	| _ID_ _CBR_ {
	    printf("oo> %s\n",$1);

            if run_parse(2)
            print_code("sss",
                "\tQString(boost::get<std::string>(global_",
                $1,
                ".data).c_str()).toUpper()"
            );
        }
        | _ID_ {
            run_parse_mode = 1;
            print_def($1);
            if run_parse(2)
            print_code("ss",
                "global_",
                $1
            );
        }
        | _ID_ _ARRAY_DIM_ {
            if run_parse(2)
            print_code("sss","ARRAYTYPE_",$1,$2);
        }
        | _LEN_ string_expr {
            if run_parse(2)
            print_code("s",".length())");
        } _CBR_
        | numeric_expr _PLUS_  { if run_parse(2) print_code("s"," + "); } numeric_expr
        | numeric_expr _MINUS_ { if run_parse(2) print_code("s"," - "); } numeric_expr
        | numeric_expr _MUL_   { if run_parse(2) print_code("s"," * "); } numeric_expr
        | numeric_expr _DIV_   { if run_parse(2) print_code("s"," / "); } numeric_expr
        | numeric_expr _POW_   { if run_parse(2) print_code("s"," ^ "); } numeric_expr
        | numeric_expr _MOD_   { if run_parse(2) print_code("s"," % "); } numeric_expr {
          /* special form of expression ... */ }
        | numeric_expr _PLUS_  {
            if run_parse(2)
            print_code("s",") + \n");
        } string_expr
        ;

id_stmt
        : id_stmt id_stmts { }
        | id_stmts
        ;

id_stmts
	: _FUNCTION_CALL_CLASS_ {
        if run_parse(2) {
            QString str = $1;
            str = str.replace(QRegExp("[ \t\n\r]*"),"");

            QList <QString> liste;
            liste << str.split(".",
                QString::SkipEmptyParts,
                Qt::CaseInsensitive);

            str.clear();
            liste[0] = liste[0] + QString("->");
            for (int i = 0; i < liste.count(); ++i)
            str = str + QString(liste[i]);
            str = str + QString(";\n");

            print_code("sss","\tmyclass_local_",str.toStdString().c_str(),"\n");
        }
    }
    | _ID_ _ASSIGN_ {       // ID = <expr>[+-/*<expr>...]

        if run_parse(1) print_def($1);
        if run_parse(2) {
            	print_code("sss",
                	"\t{\n\tMyQVariant local_",
                	$1,
                	" =\n"
            	);
  	    }
	    else if run_parse(3) {
            bool    flg = false;
            QString str =
            QString(this_object);
            str = str.replace("this","");
            str = str.replace("this->","");

            if (str.contains("->")) {
                str = str.replace("->","");
                flg = true;
            }

            tmp_object = QString(this_object);
            tmp_object = tmp_object.replace(QRegExp("this\\-\\>"),"this@");
            tmp_object = tmp_object.replace(QRegExp("\\-\\>"),"_");
            tmp_object = tmp_object.replace(QRegExp("this\\@"),"this->");

            QString cmp = QString($1).toLower();

            if (cmp == QString("top"))    print_code("sss","\t",tmp_object.toStdString().c_str(),"->setTop("); else
            if (cmp == QString("left"))   print_code("sss","\t",tmp_object.toStdString().c_str(),"->setLeft("); else
            if (cmp == QString("width"))  print_code("sss","\t",tmp_object.toStdString().c_str(),"->setWidth("); else
            if (cmp == QString("height")) print_code("sss","\t",tmp_object.toStdString().c_str(),"->setHeight(");

            QString scl = QString(tmp_object).
            replace(QRegExp("this\\-\\>"),"");
            scl.append("_");

            if (flg == true)  str =
                QString("(__class__") +
                QString(scl) +
                QString($1)  +
                QString(" = "); else str =

                QString("(__class__") +
                QString(scl) +
                QString($1)  +
                QString(" = ");

            str = str.toLower();
            check_added_symbol(str.toStdString().c_str(),4);
            print_code("s",    str.toStdString().c_str());
	    }
    }  numeric_expr {
        if run_parse(2)
        print_code("sssss",
            ";\n\tglobal_",
            $1,
            " = local_",
            $1,
            ";\n\t}\n"
        );
        if run_parse(3)
        {
            QString cmp = QString($1).toLower();

            if (cmp == QString("top")) print_code("s",")"); else
            if (cmp == QString("left")) print_code("s",")"); else
            if (cmp == QString("width")) print_code("s",")"); else
            if (cmp == QString("height")) print_code("s",")");

            print_code("s",");\n");

        	if (class_type == clButton)
            print_code("sss","\t",this_object,"->showButton();\n");
        }
    }
    | _ID_ _ARRAY_DIM_ {    // ARRAY[ <dimension:expr> ] = <expr>
	    if run_parse(1) print_def($1);
        if run_parse(2) {
            QString str = QString($2);
            str = str.replace(",","][");
            print_code("sss",
                "\tARRAYTYPE_",
                $1,
                str.toStdString().c_str()
            );
	    }
    } _ASSIGN_ {
            if run_parse(2) print_code("s"," = "); } numeric_expr {
            if run_parse(2) print_code("s",";\n");
    }
    | _ID_ _ARRAY_DIM_ {    // ARRAY[ <dimension:expr> ] = <expr>
        if run_parse(1) print_def($1);
        if run_parse(2) {
            QString str = QString($2);
            str = str.replace(",","][");
            print_code("sss",
                "\tARRAYTYPE_",
                $1,
                str.toStdString().c_str()
            );
        }
    } _ASSIGN_ _ID_ _ARRAY_DIM_ {
        if run_parse(2) {
            print_code("s"," = ");

            QString str = QString($6);
            str = str.replace(",","][");
            print_code("sss",
                "\tARRAYTYPE_",
                $5,
                str.toStdString().c_str()
            );
	
            print_code("s",";\n");
        }
    }
    | _ID_ _ASSIGN_ {       // ID = <string>
	    if run_parse(1) print_def($1);
            if run_parse(2) {
                print_code("sss",
                "\t{\n\tMyQVariant local_",
                $1,
                " =\n"
                );
	    }
        } string_expr {
            if run_parse(2)
            print_code("sssss",
                ";\n\tglobal_",
                $1,
                " = local_",
                $1,
                ";\n\t}\n"
            );
        }
        | _ID_ _ASSIGN_ {       // ID = <bool>
	    if run_parse(1) print_def($1);
            if run_parse(2) {
	            print_code("sss",
        	        "\tMyQVariant local_",
        	        $1,
        	        " = "
        	    );
	    }
        } false_true_expr {
            if run_parse(2)
            print_code("ssssss",
                $4,
                ";\n\tglobal_",
                $1,
                " = local_",
                $1,
                ";\n"
            );
        }
        ;

false_true_expr
        : _FALSE_ {
            if run_parse(2)
            strcpy($$,"false");
        }
        | _TRUE_ {
            if run_parse(2)
            strcpy($$,"true");
        }
        ;

str_sub
	: _SUBSTR_ {
	    if run_parse(2)
	    print_code("ss","\tset_",$1);
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tset_");
            str << QString($1);

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
	}
	;

str_date
	: _DATE_ {
        if run_parse(2) print_code("s","\tmy_date_now()");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tmy_date_now()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
	;

str_time
	: _TIME_ {
        if run_parse(2) print_code("s","\tmy_time_now()");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tmy_time_now()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
	;

string_expr
    : _STRING_ {
        if run_parse(2)
        {
          msgbox(QString("info"),QString("STRP000000"));
            if (!ident_code)
            print_code("sss","\tQString(",$1,")"); else
            print_code("sss",  "QString(",$1,")");
            ident_code = false;
            in_upper_case = false;
        }
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str; str
                << QString("\tQString(")
                << QString($1)
                << QString(")");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
            in_upper_case  = false;
        }
    }
	| str_date _PLUS_ {
        if run_parse(2) print_code("s",".addDays(");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(".addDays(");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    } numeric_expr {
        if run_parse(2) print_code("s",")");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(")");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
	| str_time _PLUS_ {
        if run_parse(2) print_code("s",".addSecs(");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(".addSecs(");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    } numeric_expr {
        if run_parse(2) print_code("s",")");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(")");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
	| str_date { }
	| str_time { }
	| _TYPE_ _OBR_ numeric_expr _CBR_ {
        if run_parse(2) print_code("s", "N");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("N");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
	| _TYPE_ _OBR_ string_expr  _CBR_ {
        if run_parse(2) print_code("s", "C");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("C");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    | _TEST_ _OBR_ numeric_expr _CBR_ {
        if run_parse(2) print_code("s","-6");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("-6");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
	| _TRIM_ string_expr _CBR_ {
	    if run_parse(2)
	    print_code("s",".simplified()");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(".simplified()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
	}
    | _SPACE_ {
        if run_parse(2) {
	    	QString y = $1;
	    	//QString y = x.left(6);

	    	print_code("ss",
                    "\tset_strspace(",
		    y.toStdString().c_str()
	    	);
	    }
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tset_strspace(");
            str << QString($1);

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    } _CBR_ {
        if run_parse(2)
        print_code("s","))");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("))");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
	}
    | _UPPER_ string_expr { in_upper_case = true; } _CBR_ {
        if run_parse(2)
        print_code("s",".toUpper()");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(".toUpper()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    | _UPPER_ _ID_ _CBR_ {

        if run_parse(2)
        print_code("sss",
            "\tQString(boost::get<std::string>(global_",
            $2,
            ".data).c_str()).toUpper()"
        );
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tQString(boost::get<std::string>(global_");
            str << QString($2);
            str << QString(".data).c_str()).toUpper()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    | _LOWER_ _ID_ _CBR_ {
        if run_parse(2)
        print_code("sss",
            "\tQString(boost::get<std::string>(global_",
            $2,
            ".data).c_str()).toLower()"
        );
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tQString(boost::get<std::string>(global_");
            str << QString($2);
            str << QString(".data).c_str()).toLower()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
	| str_sub { }
    | _FUNCTION_CALL_CLASS_ {
        if run_parse(2) {
            qDebug() << $1;
            print_code("sss","\tmyclass_local_",$1,"\n");
        }
        else if run_parse(4) {
            run_parse_mode = 3;

            QString str1;
            str1 = QString($1);
            str1 = str1.simplified();

            QList <QString> liste;
            liste << str1.split(".", QString::SkipEmptyParts, Qt::CaseInsensitive);

            QString str;
            for (int i = 0; i < liste.count(); ++i)
            {
                if (i == 0)
                str = str + QString("\tp1->"); else
                str = str + liste[i];
            }

            QList <QString> strlist;
            strlist << QString(str);

            procedure_members[current_function] += strlist;
            run_parse_mode = 4;
        }
    }
    | _ID_ {
        if run_parse(2)
        print_code("sss",
            "\tQString(boost::get<std::string>(global_",
            $1,
            ".data).c_str())))"
        );
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tQString(boost::get<std::string>(global_");
            str << QString($1);
            str << QString(".data).c_str()))))");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    | string_expr _PLUS_ {
        if run_parse(2) {
            if (in_upper_case)
            print_code("s",".toUpper()");
            print_code("s",") + MyQVariant(\n");

            in_upper_case = false;
        }
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str; if (in_upper_case)
            str << QString(".toUpper()");
            str << QString(") + MyQVariant(\n");
            procedure_members[current_function] += str;

            run_parse_mode = 4;
            in_upper_case  = false;
        }
    } string_expr
    | string_expr _PLUS_ { if run_parse(2) { print_code("s"," +\n\tMyQVariant("); in_myqvariant = true; } } numeric_expr
    ;

print_helper
    : _PRINT_TEXT_ {
        if run_parse(2) { print_code("s","\tprint_console("); } else
        if run_parse(4) {
            QList <QString> str; str
                << QString("\tprint_console(");
            procedure_members[current_function] += str;
        }

        in_print_console = true;
    }
    ;

print_stmt
    : print_helper {
        if run_parse(2) { print_code("s","MyQVariant("); } else
        if run_parse(4) {
            QList <QString> str; str << QString("MyQVariant(\n");
            procedure_members[current_function] += str;
        }
    } string_expr  {
        if run_parse(2) { print_code("s","));\n"); } else
        if run_parse(4) {
            QList <QString> str; str << QString("));\n");
            procedure_members[current_function] += str;
        }
    }
	| print_helper { } numeric_expr {
        if run_parse(2) print_code("s","));\n"); else 
        if run_parse(4) {
            QList <QString> str; str
                << QString("));\n");
            procedure_members[current_function] += str;
        }
    }
    ;

%%

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
            switch( str[i] )    {
            case 'd':
            case 'i':
                Printable.i = va_arg( vl, int );
                if run_parse(1) { fprintf(file_header ,"%d", Printable.i); } else
                if run_parse(2) { fprintf(file_main   ,"%d", Printable.i); } else
                if run_parse(3) { fprintf(file_classes,"%d", Printable.i); } else
                if run_parse(4) { fprintf(file_classes_header,"%d", Printable.i); } else
                if run_parse(5) { fprintf(file_assembler ,"%d", Printable.i); }
            break;

            case 'f':
                Printable.f = va_arg( vl, double);
                if run_parse(1) { fprintf(file_header ,"%f", Printable.f); } else
                if run_parse(2) { fprintf(file_main   ,"%f", Printable.f); } else
                if run_parse(3) { fprintf(file_classes,"%f", Printable.f); } else
                if run_parse(4) { fprintf(file_classes_header,"%f", Printable.f); } else
                if run_parse(5) { fprintf(file_assembler ,"%f", Printable.f); }
            break;

            case 'c':
                Printable.c = va_arg( vl, int );
                if run_parse(1) { fprintf(file_header ,"%c", Printable.c); } else
                if run_parse(2) { fprintf(file_main   ,"%c", Printable.c); } else
                if run_parse(3) { fprintf(file_classes,"%c", Printable.c); } else
                if run_parse(4) { fprintf(file_classes_header,"%c", Printable.c); } else
                if run_parse(5) { fprintf(file_assembler ,"%c", Printable.c); }
             break;

             case 's':
                Printable.s = va_arg( vl, char *);
                if run_parse(1) { fprintf(file_header ,"%s", Printable.s); } else
                if run_parse(2) { fprintf(file_main   ,"%s", Printable.s); } else
                if run_parse(3) { fprintf(file_classes,"%s", Printable.s); } else
                if run_parse(4) { fprintf(file_classes_header,"%s", Printable.s); } else
                if run_parse(5) { fprintf(file_assembler ,"%s", Printable.s); }
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

char* get_symbol_str(char *str)
{
    int i;
    for (i = 0; i < symbol_list_counter; i++)
    {
        if (!strcmp(symbol_list[i].name,str))
        return symbol_list[i].name;
    }   return (char*) 0;
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

extern void prepare_compile(int argc, char **argv);
extern void displayEnvError(void);

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    prepare_compile (argc,argv);
    return 0;
}

extern void DisplayFileError(char *msg);
extern void compile_program(void);

void start_parser(void)
{
    yyparse();
}

void check_added_symbol(const char *str, int type)
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

        if (type == 1)
        {
	    run_parse_mode = 1;
            print_code("ssssssssss",
            "#ifdef __MAIN_RUN__\n",
            "  #ifndef _ISDEFINED__",   str, "\n",
            "  #define _ISDEFINED__",   str, "\n",
            "  MyQVariant ",
            str,
            ";\n  #endif\n#endif\n");
        }
        else if (type == 4)
        {
		    int old_val = run_parse_mode;
		    run_parse_mode = 4;

            print_code("s",
                "#ifndef __APP_CLASSES_H__\n"
                "#define __APP_CLASSES_H__\n"
                "#include \"pch.h\"\n"
                //"#endif\n"
            );

            QString pstr = QString(str);
            pstr = pstr.replace("(","");
            pstr = pstr.replace(QRegExp("[ ]*=[ ]*"),"");

            print_code("ssssssssss",
                "#ifdef __APP_HEADER__\n",
                "  #ifndef _ISDEFINED", pstr.toStdString().c_str(), "\n",
                "  #define _ISDEFINED", pstr.toStdString().c_str(), "\n",
                "  MyQVariant ",
                pstr.toStdString().c_str(),
                ";\n  #endif\n#endif\n"
            );
            run_parse_mode = old_val;
        }
    }
}


struct dll_func_list
{
    char *name;
    char *func;
    char * dll;
    char *fvar;
};
struct dll_func_list dll_list[4096*100];
static int dll_list_counter = 0;
void add_dll_func(char *id, char *dll, char *func)
{
    int i;
    bool found = false;
    for (i = 0; i < dll_list_counter; i++)
    {
        if (!strcmp(dll_list[i].name,id))
        {
            found = true;
            break;
        }
    }

    if (found == false)
    {
        i = dll_list_counter++;
        dll_list[i].name = (char*) malloc(strlen(id)   + 1  );
        dll_list[i].fvar = (char*) malloc(strlen(func) + 10 );
        dll_list[i].func = (char*) malloc(strlen(id)   + 1  );
        dll_list[i].dll  = (char*) malloc(strlen(id)   + 1  );

        strcpy(dll_list[i].name,id);
        strcpy(dll_list[i].fvar,id);
        strcat(dll_list[i].fvar,"Func");
        strcpy(dll_list[i].dll ,dll);

        if (strlen(func) > 0)
        strcpy(dll_list[i].func,func); else
        strcpy(dll_list[i].func,id);
    }
}

struct dll_func_list_name
{
    char *name;
};
struct dll_func_list_name dll_name_list[4096*10];
static int dll_name_list_counter = 0;
bool check_dll_name(char *id)
{
    int i;
    bool found = false;
    for (i = 0; i < dll_name_list_counter; i++)
    {
        if (!strcmp(dll_name_list[i].name,id))
        {
            found = true;
            return found;
        }
    }

    if (found == false)
    {
        i = dll_name_list_counter++;
        dll_name_list[i].name = (char*) malloc(strlen(id)   + 1  );
        strcpy(dll_name_list[i].name,id);
        return false;
    }

    return false;
}

void write_dll_free(void)
{
    if run_parse(2)
    {
        int i;
        #ifdef WIN32
        for (i = 0; i < dll_name_list_counter-1; i++)
        {
            print_code("sss",
            "\tFreeLibrary(inc_",
            dll_name_list[i].name,
            ");\n"
            );
        }
        #endif
    }
}

void write_dll_includes(void)
{
    if run_parse(2)
    {
        int i;
        #ifdef WIN32
        for (i = 0; i < dll_list_counter; i++)
        {
            if (!check_dll_name(dll_list[i].dll))
            {
                print_code("sssss",
                    "\tHINSTANCE inc_",
                    dll_list[i].dll,
                    " = LoadLibrary(TEXT(\"",
                    dll_list[i].dll,
                    ".dll\"));\n"
                );
                ++dll_name_list_counter;
            }
        }

        for (i = 0; i < dll_list_counter; i++)
        {
            print_code("sssssss",
                "\t",
                dll_list[i].name,
                "_dll* ",
                dll_list[i].name,
                " = ",
                "GetProcAddress(inc_",
                dll_list[i].dll
            );

            if (dll_list[i].func[0] == '\"')
            print_code("sss",
                ", ",
                dll_list[i].func,
                ");\n"
            ); else
            print_code("sss",
                ", \"",
                dll_list[i].func,
                "\");\n"
                );
        }
        #endif
    }
}

void print_def(char *sym)
{
    int i;
    bool found = false;
    for (i = 0; i < symbol_list_counter; i++)
    {
        if (!strcmp(symbol_list[i].name,sym))
        {
            found = true;
            break;
        }
    }

    if (found == false)
    {
        i = symbol_list_counter++;
        symbol_list[i].name = (char*) malloc(strlen(sym)+1);
        strcpy(symbol_list[i].name,sym);
        symbol_list[i].type = 1;

        if run_parse(1)
        print_code("ssssssssss",
            "#ifdef __MAIN_RUN__\n",
            "  #ifndef _ISDEFINED__global_",   sym, "\n",
            "  #define _ISDEFINED__global_",   sym, "\n",
            "  MyQVariant global_",
            sym,
            ";\n  #endif\n#endif\n"
        );
    }
}


void print_comma(void)
{
    if run_parse(2)
    print_code("s",",");
}

