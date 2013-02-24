%{
// ------------------------------------
// dBase for Linux (c) 2012 Jens Kallup
// All Rights Reserved.
// ------------------------------------
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"

#define false 0
#define true  1
typedef unsigned short bool;

FILE *yyin;

int nvar_counter;
extern int lineno;
extern int errors;

void yyerror(char *);
bool skip_comment(void);

%}

%x _MACRO1_ _MACRO2_

%%

"\*\*".*\n		{ lineno++; }
\/\/.*\n		{ lineno++; BEGIN(INITIAL); }
\/\*			{ if (!skip_comment()) return -1; }
\"([^\"]*)\"            {

    yylval.text = (char*) malloc(strlen(yytext)+1);
    strcpy(yylval.text,yytext);
    return _STRING_;
}
"local"			{ return _LOCAL_; }
"new"			{ return _NEW_; }
"class" 		{ return _CLASS_; }
"of"			{ return _OF_; }
"with"			{ return _WITH_; }
"endwith"		{ return _ENDWITH_; }
"endclass"		{ return _ENDCLASS_; }
"function"		{ return _FUNCTION_; }
"return"		{ return _RETURN_; }
"msgbox"		{ return _MSGBOX_; }
"not"			{ return _NOT_; }
"if"			{ return _IF_; }
"else"			{ return _ELSE_; }
"endif" 		{ return _ENDIF_; }
"parameter"		{ return _PARAMETER_; }
"menubar"       { return _MENUBAR_; }
"for"           { return _FOR_; }
"endfor"        { return _ENDFOR_; }
"to"            { return _TO_; }
"array"         { return _ARRAY_; }
"::"			{ return _DBPOINT_; }
\=              { return _ASSIGN_; }
\=\=			{ return _EQUAL_; }
\.f\.                   { return _FALSE_; }
\.t\.                   { return _TRUE_; }
\?          { return _PRINT_TEXT_; }
\+			{ return _PLUS_;   }
\-			{ return _MINUS_;  }
\/			{ return _DIV_;    }
\*			{ return _MUL_;    }
"%"			{ return _MOD_;    }
\^			{ return _POW_;    }
\(			{ return _OBR_; }
\)			{ return _CBR_; }
\[			{ return _OBR2_; }
\]			{ return _CBR2_; }
"#"			{ BEGIN(_MACRO1_); }
\,			{ return _COMMA_; }
\.			{ return _POINT_; }
<_MACRO1_>[ \t]*[1-9]+[0-9]*	{ BEGIN(_MACRO2_); }
<_MACRO2_>[ \t]*\".*\".*\n	{ lineno++; BEGIN(INITIAL); }
[0-9]*			{
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
                return _ID_;
}
[\n\r]* 	{ lineno++; }
[ \t]*		;
.		{
	errors++;
	yyerror("Fehlerzeichen");
}
<<EOF>> 	{
	if (errors > 0)
	yyerror("Fehler in Quelldatei!");
	return EOF;
}
%%

extern void DisplayErrorMessage(int,char*);
void yyerror(char* message)
{
	if (errors > 0)
	{
        //printf("\nError: %d: %s\n",lineno,message);
        DisplayErrorMessage(lineno,message);
		exit(1);
	}
}

bool skip_comment(void)
{
	int key;
	key != EOF;
	while (true)
	{
		if (key == EOF)
		{
			errors++;
			yyerror("Unexpected EOF within comment.");
			break;
		}

		switch ((char)key)
		{
			case '*' :
                                key = getc(yyin);
				if ((char)key == '/') return true;
				else continue;
			break;

			case '\n' :
			  ++lineno;
			break;
		}

                key = getc(yyin);
	}
}
