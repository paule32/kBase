%{
/*
   (c) Copyright 2013-2015  Kallup Software.
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

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include "y.tab.h"

#include "QtCore/QVector"
#include "QtCore/QString"
#include "QtCore/QStringList"
#include "QtCore/QRegExp"
#include "QtCore/QDebug"

#include <QString>

using namespace std;

extern "C" int WordCount(char*);
int commaCount;
int line_num = 0;
extern int errors;

bool compile_error = true;
char linebuf[500];

extern int program_exec_mode;
extern int run_parse_mode;
extern int in_array_cnt;

extern char * stringReplace(char *substr, char *replacement, char *string);
extern char * strlwr(char *c);

extern void print_code(char* str, ... );
extern void msgbox(QString,QString);

void yyerror(char *);
void skip_comment(void);
void set_dbg_line(int);
int get_array_dimension(char*);

struct MyException : public std::exception
{
    std::string s;
    MyException(std::string ss) : s(ss) {}
    ~MyException() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};

QVector<QString> symbols_vec;

%}

%x IN_COMMENT CHECK_NEXT_DIM AT_UPPER IN_STRING

_space  [ \t]
id      [a-zA-Z_]+[0-9a-zA-Z_]
digit   [0-9]

%%

^\0x00*       { ++line_num; }
[ \t]*    { }
\n*         { ++line_num; }
^\/\/\n      { ++line_num; }
^\/\/.*\n    { ++line_num; }
^[ \t]*\n*         { ++line_num; }
^[ \t]*\/\/\n      { ++line_num; }
^[ \t]*\/\/.*\n    { ++line_num; }

"/*"              BEGIN(IN_COMMENT);
<IN_COMMENT>{
"*/"      BEGIN(INITIAL);
[^*\n]+   // eat comment in chunks
"*"       // eat the lone star
\n        ++line_num;
}

\(    { return _OBR_; }
\)    { return _CBR_; }

\?[ \t\n]*  { return _PRINT_TEXT_; }
\,		      { return _COMMA_; }

\([ \t\n]*[\+\-]*(\".*\")*((\/\*.*\*\/)*|(\/\/.*\n*)*)*(((([0-9])+\.[0-9]*)|([0-9]*))|([a-zA-Z0-9_]*))*([ \t\n]*\.?|\,?[a-zA-Z0-9_]*)*[ \t\n]*\)[ \t\n]* {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);

    QString str = QString(yytext);
    commaCount = 1;
    for (const auto& c : str) if(c == ',') ++commaCount;

    in_array_cnt =  get_array_dimension(yytext);
    str = QString(yytext).replace(QRegExp("\\,"),"][");
    strcpy(yylval.text,str.toStdString().c_str());
    return _ARRAY_DIM1_;
}

([ \t\n])*onclick([ \t\n])*\=([ \t\n])*class([ \t\n])*\:\:([ \t\n])* {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _CLASS_ONCLICK_;
}

([ \t\n])*onclick([ \t\n])*\=([ \t\n])*\{([ \t\n]*[a-zA-Z0-9_]*[ \t\n]*\;)*[ \t\n]*\} {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _CLASS_ONCLICK2_;
}

([ \t\n])*onclick([ \t\n])*\=([ \t\n])*\{([ \t\n]*\;[ \t\n]*[a-zA-Z0-9_]*[ \t\n]*)*[ \t\n]*\} {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _CLASS_ONCLICK2_;
}

[ \t\n]*\"([^\"]*)\"[ \t\n]*\/[ \t\n]*\"([^\"]*)\"[ \t\n]* {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _LOGIN_USERPASS_;
}

\[[^\]]*\]      {
    //printf(">> %s\n",yytext);

    QString str = QString(yytext);
    str = str.remove(0,1);
    str = str.remove(str.size()-1,1);

    QStringList list1 = str.split(",");
    int idx =   list1.count()-1;

    int c = WordCount((char*)list1[idx].toStdString().c_str());
    //QDebug() << idx << c << list1;

    if (c > idx+1) {
        QString str;
        for (c = 0; c < idx+1; c++)
        str = str.append(list1[c]);

        //QDebug() << "a stringer:" << str;
    }
    else if (idx < 2 ) {
		str = QString(yytext);

        commaCount = 1;
        for(const auto& c : str) if(c == ',') ++commaCount;

		str = str.replace(QRegExp("\\,"),"][");
	    yylval.text = new char[str.size()];
	    strcpy(yylval.text,str.toStdString().c_str());
        return _ARRAY_DIM_;
    }
    else {
        //QDebug() << "error, array complete?";
    }

	str = QString(yytext);

    commaCount = 1;
    for(const auto& c : str) if(c == ',') ++commaCount;

	str = str.replace(QRegExp("\\,"),"][");
    yylval.text = new char[str.size()];
    strcpy(yylval.text,str.toStdString().c_str());
	return _ARRAY_DIM_;
}

"upper" { BEGIN(AT_UPPER); return _UPPER_; }
<AT_UPPER>{
[ \t]
\n      ++line_num;
\(      BEGIN(INITIAL);
}

"lower"[ \t\n]*\(         { return _LOWER_; }

"asc"[ \t\n]*\(           { return _ASC_; }
"len"[ \t\n]*\(           { return _LEN_; }

"at"[ \t\n]*\(  {
    return _AT_;
}

"function"[ \t\n]*((\/\*.*\*\/)*|(\/\/.*\n*)*)*[ \t\n]*([a-zA-Z0-9_]*) {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _FUNCTION_ARRAY_;
}

"function"[ \t\n]*((\/\*.*\*\/)*|(\/\/.*\n*)*)*[ \t\n]*([a-zA-Z0-9_]*)[ \t\n\r]*\((([ \t\n\r])*[a-zA-Z0-9_]*)\)[ \t\n\r]* {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _FUNCTION_ARRAY_;
}

"function"[ \t\n]*((\/\*.*\*\/)*|(\/\/.*\n*)*)*[ \t\n]*([a-zA-Z0-9_]*)[ \t\n]*\(([ \t\n]*((\/\*.*\*\/)*|(\/\/.*\n*)*)*[ \t\n]*([a-zA-Z0-9_]*)[ \t\n]*\,[ \t\n]*((\/\*.*\*\/)*|(\/\/.*\n*)*)*[ \t\n]*([a-zA-Z0-9_]*))*[ \t\n]*\)[ \t\n]* {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _FUNCTION_ARRAY_;
}

"space"[ \t\n]*\([ \t\n]*[\+\-]*((\/\*.*\*\/)*|(\/\/.*\n*)*)*(((([0-9])+\.[0-9]*)|([0-9]*))|([a-zA-Z0-9_]*))*([ \t\n]*\.?|\,?[a-zA-Z0-9_]*)*[ \t\n]* {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _SPACE_;
}

"substr"[ \t\n]*\([\t\n]*([a-zA-Z0-9_]*.*)*[ \t\n]*("\"".*"\"")*((\/\*.*\*\/)*|(\/\/.*\n*)*)*(((([0-9])+\.[0-9]*)|([0-9]*))|([a-zA-Z0-9_]*))*([ \t\n]*\.?|\,?[a-zA-Z0-9_]*)*\) {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _SUBSTR_;
}

([ \t\n\r]*[a-zA-Z0-9]*[ \t\n\r]*\.[ \t\n\r]*[a-zA-Z0-9]*[ \t\n\r]*\([ \t\n\r]*\))* {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _FUNCTION_CALL_CLASS_;
}

[ \t\n\r]*[a-zA-Z0-9]*[ \t\n\r]*\.[ \t\n\r]*[a-zA-Z0-9]*[ \t\n\r]*\([ \t\n\r]*\) {
    yylval.text = (char*)malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _FUNCTION_CALL_CLASS_;
}

trim[ \t\n]*\(   { return _TRIM_; }

"time"[ \t\n]*\([ \t\n]*\)[ \t\n]* { return _TIME_; }
"date"[ \t\n]*\([ \t\n]*\)[ \t\n]* { return _DATE_; }

[ \t]  ;
[\r\n] {
    ++line_num;
}

this([ \t\n]*\.[ \t\n]*[a-zA-Z0-9_]*)*[ \t\n]*\=[ \t\n]*new[ \t\n]*container[ \t\n]*\([ \t\n]*this([ \t\n]*\.[ \t\n]*[a-zA-Z0-9_]*)*[ \t\n]*\) {
	yylval.text = (char*)malloc(strlen(yytext)+1);
	strcpy(yylval.text,yytext);
	return _THIS_OBJECT_CONTAINER_;
}

this([ \t\n]*\.[ \t\n]*[a-zA-Z0-9_]*)*[ \t\n]*\=[ \t\n]*new[ \t\n]*pushbutton[ \t\n]*\([ \t\n]*this([ \t\n]*\.[ \t\n]*[a-zA-Z0-9_]*)*[ \t\n]*\) {
	yylval.text = (char*)malloc(strlen(yytext)+1);
	strcpy(yylval.text,yytext);
	return _THIS_OBJECT_PUSHBUTTON_;
}

do[ \t\n]*   {
    return _DO_;
}
case[ \t\n]* {
    return _CASE_;
}
endcase[ \t\n]* {
    return _ENDCASE_;
}

"pushbutton"	{ return _PUSHBUTTON_; }
"new"		{ return _NEW_; }
"with"		{ return _WITH_; }
"endwith"	{ return _ENDWITH_; }
"class"		{ return _CLASS_; }
"of"		{ return _OF_; }
"endclass"	{ return _ENDCLASS_; }
"type"		{ return _TYPE_; }
"test"		{ return _TEST_; }
"open"      { return _OPEN_; }
"database"  { return _DATABASE_; }
"local"			{ return _LOCAL_; }
"login"     { return _LOGIN_; }
"msgbox"		{ return _MSGBOX_; }
"not"			{ return _NOT_; }
"int"			{ return _INT_; }
"if"			{ return _IF_; }
"else"			{ return _ELSE_; }
"endif" 		{ return _ENDIF_; }
"parameter"		{ return _PARAMETER_; }
"return"	{ return _RETURN_; }
"menubar"       { return _MENUBAR_; }
"for"           { return _FOR_; }
"endfor"        { return _ENDFOR_; }
"extern"    { return _EXTERN_; }
"cstring"   { return _CSTRING_; }
"to"            { return _TO_; }
"while" { return _WHILE_; }
"enddo" { return _ENDDO_; }
"otherwise" { return _OTHERWISE_; }
"store" { return _STORE_; }
"path"          { return _PATH_; }
"use"           { return _USE_; }
"select"           { return _SELECT_; }
"count"		{ return _COUNT_; }
"getline"       { return _GETLINE_; }
\$          { return _DOLLAR_SIGN_; }
\#          { return _SHARP_; }
\=              {  return _ASSIGN_; }
\=\=			{ return _EQUAL_; }
"false"                 {
        yylval.trfa = (char*) malloc(strlen(yytext)+1);
        strcpy(yylval.trfa,"false");
        return _FALSE_;
}
\.f\.                   {
        yylval.trfa = (char*) malloc(strlen("false")+1);
        strcpy(yylval.trfa,"false");
        return _FALSE_;
}
"true"                 {
        yylval.trfa = (char*) malloc(strlen("true")+1);
        strcpy(yylval.trfa,"true");
        return _TRUE_;
}
\.t\.                   {
        yylval.trfa = (char*) malloc(strlen("true")+1);
        strcpy(yylval.trfa,"true");
        return _TRUE_;
}
\!          { return _AUSRUF_; }
\+			{ return _PLUS_;   }
\-			{ return _MINUS_;  }
\/			{ return _DIV_;    }
\*			{ return _MUL_;    }
"%"			{ return _MOD_;    }
\^			{ return _POW_;    }
\.			{ return _POINT_; }
\"([^\"]*)\"            {
     yylval.text = (char*) malloc(strlen(yytext)+1);
     strcpy(yylval.text,yytext);
     return _STRING_;
}
\'([^\"]*)\'            {
         yylval.text = (char*) malloc(strlen(yytext)+1);
         strcpy(yylval.text,yytext);
         return _STRING_;
}

[0-9]*   {
                yylval.val = (double) atof(yytext);
                return _NUM_;
}
([0-9])+\.[0-9]*	{
                yylval.val = (double) atof(yytext);
                return _NUM_;
}
[a-zA-Z_]+[0-9a-zA-Z_]* {
                yylval.id = (char*)malloc(strlen(yytext)+1);
                strcpy(yylval.id,yytext);

		if (symbols_vec.indexOf(yytext) < 0)
		symbols_vec << yytext;
                return _ID_;
}
[a-zA-Z]+\:\\[a-zA-Z0-9\\\-\.]*  {
                yylval.path = (char*)malloc(strlen(yytext)+1);
                strcpy(yylval.id,yytext);
                return _PATHID_;
}
\n.*   {
        strncpy(linebuf, yytext+1, sizeof(linebuf));
        yyless(1);
}
<<EOF>> 	{
		if (run_parse_mode == 4)
		print_code("s","#endif");

        return EOF;
}

%%

void skip_comment(void)
{
    register int c;

    for (;;)
    {
        c = getc(yyin);

        if (c == '\n')
        {
            if (run_parse_mode == 2)
            ++line_num;
            continue;
        }
        else if (c == '*')
        {
            for (;;)
            {
                c = getc(yyin);
                if (c == '/') {
                    return;
                    break;  /* found the end */
                }
                else if (c == EOF)
                {
                    yyerror("EOF in comment");
                    break;
                }
                else continue;
            }

            if (c == '\n')
            {
                if (run_parse_mode == 2)
                ++line_num;
                continue;
            }
            if (c == '/') {
                ++line_num;
                break;
            }
            if (c == EOF)
            {
                yyerror("EOF in comment");
                break;
            }
        }
        else if (c == EOF)
        {
            yyerror("EOF in comment");
            break;
        }
    }
}

extern void close_all_compiler_files();
extern void DisplayErrorMessage(int,char*);
void yyerror(char* message)
{
    char buffer[2048];
    close_all_compiler_files();
    sprintf(buffer,"%s at %s in this line:\n%s\n", message, yytext, linebuf);
    DisplayErrorMessage(line_num,buffer);
}

void set_dbg_line(int line)
{
    if (run_parse_mode == 2)
        print_code("sisss",
                   "#line ",
                   line,
                   " \"",
                   "test.prg",   // name todo
                   "\"\n"
                   );
}

int get_array_dimension(char *str)
{
    int c, idx = 0;
    int n = 1;
    while ((c = str[idx]) != '\0')
    {
        if (c == ',') n++;
        idx++;
    }
    return n;
}

