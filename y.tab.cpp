
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "pcode.y"

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


/* Line 189 of yacc.c  */
#line 240 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _POINT_ = 258,
     _DBPOINT_ = 259,
     _MSGBOX_ = 260,
     _EQUAL_ = 261,
     _PARAMETER_ = 262,
     _OBR2_ = 263,
     _CBR2_ = 264,
     _MENUBAR_ = 265,
     _GETLINE_ = 266,
     _SET_ = 267,
     _PATH_ = 268,
     _PATHID_ = 269,
     _WHILE_ = 270,
     _EOF_ = 271,
     _STORE_ = 272,
     _COUNT_ = 273,
     _AUSRUF_ = 274,
     _DOLLAR_SIGN_ = 275,
     _CLI_PROGRAM_ = 276,
     _DEFINE_ = 277,
     _SHARP_ = 278,
     _EXTERN_ = 279,
     _FROM_ = 280,
     _CSTRING_ = 281,
     _CLEAR_ = 282,
     _INT_ = 283,
     _NULLOBJ_ = 284,
     _NUM_ = 285,
     _ID_ = 286,
     _ASSIGN_ = 287,
     _PLUS_ = 288,
     _MINUS_ = 289,
     _DIV_ = 290,
     _MUL_ = 291,
     _MOD_ = 292,
     _POW_ = 293,
     _OBR_ = 294,
     _CBR_ = 295,
     _TYPE_ = 296,
     _DATE_ = 297,
     _TIME_ = 298,
     _TRUE_ = 299,
     _FALSE_ = 300,
     _STRING_ = 301,
     _COMMA_ = 302,
     _LEN_ = 303,
     _ASC_ = 304,
     _AT_ = 305,
     _SPACE_ = 306,
     _TRIM_ = 307,
     _SUBSTR_ = 308,
     _TEST_ = 309,
     _ARRAY_DIM0_ = 310,
     _LOWER_ = 311,
     _UPPER_ = 312,
     _ARRAY_DIM_ = 313,
     _ARRAY_DIM1_ = 314,
     _ARRAY_DIM2_ = 315,
     _ARRAY_ = 316,
     _PRINT_TEXT_ = 317,
     _NOT_ = 318,
     _NEW_ = 319,
     _CLASS_ = 320,
     _OF_ = 321,
     _ENDCLASS_ = 322,
     _WITH_ = 323,
     _ENDWITH_ = 324,
     _ARRAY_DIM3_ = 325,
     _ARRAY_DIM4_ = 326,
     _PUSHBUTTON_ = 327,
     _FUNCTION_ = 328,
     _FUNCTION_ARRAY_ = 329,
     _RETURN_ = 330,
     _IF_ = 331,
     _ELSE_ = 332,
     _ENDIF_ = 333,
     _FOR_ = 334,
     _ENDFOR_ = 335,
     _TO_ = 336,
     _USE_ = 337,
     _OBJECT_ID_ = 338,
     _OBJECT_ID2_ = 339,
     _ARRAY_REMARK0_ = 340,
     _THIS_OBJECT_PUSHBUTTON_ = 341,
     _CLASS_ONCLICK_ = 342,
     _CLASS_ONCLICK2_ = 343,
     _FUNCTION_CALL_CLASS_ = 344,
     _DO_ = 345,
     _CASE_ = 346,
     _OTHERWISE_ = 347,
     _ENDDO_ = 348,
     _ENDCASE_ = 349,
     _LOCAL_ = 350,
     _INNER_TEXT_ = 351,
     _DATABASE_ = 352,
     _OPEN_ = 353,
     _LOGIN_ = 354,
     _LOGIN_USERPASS_ = 355,
     _SELECT_ = 356,
     _THIS_OBJECT_CONTAINER_ = 357
   };
#endif
/* Tokens.  */
#define _POINT_ 258
#define _DBPOINT_ 259
#define _MSGBOX_ 260
#define _EQUAL_ 261
#define _PARAMETER_ 262
#define _OBR2_ 263
#define _CBR2_ 264
#define _MENUBAR_ 265
#define _GETLINE_ 266
#define _SET_ 267
#define _PATH_ 268
#define _PATHID_ 269
#define _WHILE_ 270
#define _EOF_ 271
#define _STORE_ 272
#define _COUNT_ 273
#define _AUSRUF_ 274
#define _DOLLAR_SIGN_ 275
#define _CLI_PROGRAM_ 276
#define _DEFINE_ 277
#define _SHARP_ 278
#define _EXTERN_ 279
#define _FROM_ 280
#define _CSTRING_ 281
#define _CLEAR_ 282
#define _INT_ 283
#define _NULLOBJ_ 284
#define _NUM_ 285
#define _ID_ 286
#define _ASSIGN_ 287
#define _PLUS_ 288
#define _MINUS_ 289
#define _DIV_ 290
#define _MUL_ 291
#define _MOD_ 292
#define _POW_ 293
#define _OBR_ 294
#define _CBR_ 295
#define _TYPE_ 296
#define _DATE_ 297
#define _TIME_ 298
#define _TRUE_ 299
#define _FALSE_ 300
#define _STRING_ 301
#define _COMMA_ 302
#define _LEN_ 303
#define _ASC_ 304
#define _AT_ 305
#define _SPACE_ 306
#define _TRIM_ 307
#define _SUBSTR_ 308
#define _TEST_ 309
#define _ARRAY_DIM0_ 310
#define _LOWER_ 311
#define _UPPER_ 312
#define _ARRAY_DIM_ 313
#define _ARRAY_DIM1_ 314
#define _ARRAY_DIM2_ 315
#define _ARRAY_ 316
#define _PRINT_TEXT_ 317
#define _NOT_ 318
#define _NEW_ 319
#define _CLASS_ 320
#define _OF_ 321
#define _ENDCLASS_ 322
#define _WITH_ 323
#define _ENDWITH_ 324
#define _ARRAY_DIM3_ 325
#define _ARRAY_DIM4_ 326
#define _PUSHBUTTON_ 327
#define _FUNCTION_ 328
#define _FUNCTION_ARRAY_ 329
#define _RETURN_ 330
#define _IF_ 331
#define _ELSE_ 332
#define _ENDIF_ 333
#define _FOR_ 334
#define _ENDFOR_ 335
#define _TO_ 336
#define _USE_ 337
#define _OBJECT_ID_ 338
#define _OBJECT_ID2_ 339
#define _ARRAY_REMARK0_ 340
#define _THIS_OBJECT_PUSHBUTTON_ 341
#define _CLASS_ONCLICK_ 342
#define _CLASS_ONCLICK2_ 343
#define _FUNCTION_CALL_CLASS_ 344
#define _DO_ 345
#define _CASE_ 346
#define _OTHERWISE_ 347
#define _ENDDO_ 348
#define _ENDCASE_ 349
#define _LOCAL_ 350
#define _INNER_TEXT_ 351
#define _DATABASE_ 352
#define _OPEN_ 353
#define _LOGIN_ 354
#define _LOGIN_USERPASS_ 355
#define _SELECT_ 356
#define _THIS_OBJECT_CONTAINER_ 357




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 167 "pcode.y"

    int type;
    float	val;
    char* 	id;
    char*       path;
    char*	text;
    char*       trfa;
    char*	object_class_name;
    char*	object_class_name_type;
    char*	object_new_id;



/* Line 214 of yacc.c  */
#line 494 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 506 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  168
/* YYNRULES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   357

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    12,    14,    15,    18,
      21,    24,    27,    30,    33,    36,    39,    42,    43,    44,
      51,    52,    53,    60,    61,    62,    69,    70,    76,    79,
      83,    87,    90,    91,    95,    98,   101,   104,   105,   113,
     116,   118,   119,   121,   123,   124,   128,   130,   132,   135,
     137,   138,   140,   142,   144,   146,   148,   150,   153,   155,
     159,   160,   161,   162,   172,   173,   174,   175,   185,   187,
     188,   193,   194,   195,   196,   208,   211,   213,   217,   218,
     224,   226,   227,   233,   234,   236,   237,   244,   247,   249,
     250,   252,   255,   256,   262,   264,   270,   272,   273,   274,
     282,   283,   288,   291,   293,   296,   297,   302,   303,   308,
     309,   314,   315,   320,   321,   326,   327,   332,   333,   338,
     339,   344,   347,   349,   351,   352,   357,   358,   359,   366,
     367,   374,   375,   380,   381,   386,   388,   390,   392,   394,
     396,   398,   399,   404,   405,   410,   412,   414,   419,   424,
     429,   433,   434,   438,   439,   444,   448,   452,   454,   456,
     458,   459,   464,   465,   470,   472,   473,   477,   478
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     104,     0,    -1,   105,    -1,    -1,   106,   107,    -1,   107,
     108,    -1,   108,    -1,    -1,   108,   190,    -1,   108,   157,
      -1,   108,   170,    -1,   108,   109,    -1,   108,   110,    -1,
     108,   121,    -1,   108,   123,    -1,   108,   124,    -1,    95,
      31,    -1,    -1,    -1,   119,    31,   111,    35,   112,    31,
      -1,    -1,    -1,   119,    31,   113,    35,   114,   182,    -1,
      -1,    -1,   118,    31,   115,    35,   116,   182,    -1,    -1,
     118,   182,   117,    35,    31,    -1,   118,   100,    -1,   120,
     182,    99,    -1,   120,    31,    99,    -1,    98,    97,    -1,
      -1,   101,   122,   158,    -1,    82,   182,    -1,    82,    31,
      -1,    82,    54,    -1,    -1,    65,    31,    66,    31,   125,
     126,    67,    -1,   126,   127,    -1,   127,    -1,    -1,   152,
      -1,   154,    -1,    -1,    74,   128,   129,    -1,   102,    -1,
      86,    -1,   129,   130,    -1,   130,    -1,    -1,   131,    -1,
     190,    -1,   133,    -1,   142,    -1,   147,    -1,    75,    -1,
      95,   132,    -1,    31,    -1,   132,    47,   132,    -1,    -1,
      -1,    -1,    76,   134,   182,     6,   135,   182,   136,   129,
     140,    -1,    -1,    -1,    -1,    76,   137,   158,     6,   138,
     158,   139,   129,   140,    -1,    78,    -1,    -1,    77,   141,
     129,    78,    -1,    -1,    -1,    -1,    79,    31,    32,   143,
     158,   144,    81,   158,   145,   129,    80,    -1,   146,   149,
      -1,   149,    -1,    90,    91,    94,    -1,    -1,    90,    91,
     148,   146,    94,    -1,    92,    -1,    -1,    91,    31,     6,
     150,   151,    -1,    -1,   158,    -1,    -1,    83,    32,    64,
      72,   153,    84,    -1,   154,   155,    -1,   155,    -1,    -1,
      88,    -1,    87,    31,    -1,    -1,    68,    59,   156,   154,
      69,    -1,   170,    -1,    31,    32,    64,    31,    59,    -1,
      30,    -1,    -1,    -1,    50,   159,   182,    47,   160,   182,
      40,    -1,    -1,    49,   161,   182,    40,    -1,    31,    40,
      -1,    31,    -1,    31,    58,    -1,    -1,    48,   182,   162,
      40,    -1,    -1,   158,    33,   163,   158,    -1,    -1,   158,
      34,   164,   158,    -1,    -1,   158,    36,   165,   158,    -1,
      -1,   158,    35,   166,   158,    -1,    -1,   158,    38,   167,
     158,    -1,    -1,   158,    37,   168,   158,    -1,    -1,   158,
      33,   169,   182,    -1,   170,   171,    -1,   171,    -1,    89,
      -1,    -1,    31,    32,   172,   158,    -1,    -1,    -1,    31,
      58,   173,    32,   174,   158,    -1,    -1,    31,    58,   175,
      32,    31,    58,    -1,    -1,    31,    32,   176,   182,    -1,
      -1,    31,    32,   177,   178,    -1,    45,    -1,    44,    -1,
      53,    -1,    42,    -1,    43,    -1,    46,    -1,    -1,   180,
      33,   183,   158,    -1,    -1,   181,    33,   184,   158,    -1,
     180,    -1,   181,    -1,    41,    39,   158,    40,    -1,    41,
      39,   182,    40,    -1,    54,    39,   158,    40,    -1,    52,
     182,    40,    -1,    -1,    51,   185,    40,    -1,    -1,    57,
     182,   186,    40,    -1,    57,    31,    40,    -1,    56,    31,
      40,    -1,   179,    -1,    89,    -1,    31,    -1,    -1,   182,
      33,   187,   182,    -1,    -1,   182,    33,   188,   158,    -1,
      62,    -1,    -1,   189,   191,   182,    -1,    -1,   189,   192,
     158,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   212,   212,   215,   215,   335,   336,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   352,   359,   359,   359,
     369,   372,   369,   376,   380,   376,   384,   384,   392,   414,
     415,   421,   437,   437,   452,   461,   470,   477,   477,   554,
     555,   558,   560,   561,   562,   562,   657,   685,   724,   725,
     728,   730,   731,   732,   733,   734,   735,   745,   749,   756,
     760,   766,   771,   760,   779,   785,   790,   779,   801,   807,
     807,   821,   828,   834,   821,   851,   852,   856,   861,   861,
     880,   886,   886,   911,   913,   922,   922,   930,   931,   934,
     936,   976,  1003,  1003,  1025,  1028,  1113,  1135,  1138,  1135,
    1143,  1143,  1150,  1160,  1169,  1173,  1173,  1177,  1177,  1178,
    1178,  1179,  1179,  1180,  1180,  1181,  1181,  1182,  1182,  1184,
    1184,  1191,  1192,  1196,  1215,  1215,  1292,  1303,  1292,  1307,
    1307,  1333,  1333,  1352,  1352,  1375,  1379,  1386,  1403,  1418,
    1433,  1456,  1456,  1479,  1479,  1502,  1503,  1504,  1516,  1528,
    1540,  1553,  1553,  1586,  1586,  1599,  1619,  1638,  1639,  1669,
    1688,  1688,  1708,  1708,  1712,  1725,  1725,  1738,  1738
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_POINT_", "_DBPOINT_", "_MSGBOX_",
  "_EQUAL_", "_PARAMETER_", "_OBR2_", "_CBR2_", "_MENUBAR_", "_GETLINE_",
  "_SET_", "_PATH_", "_PATHID_", "_WHILE_", "_EOF_", "_STORE_", "_COUNT_",
  "_AUSRUF_", "_DOLLAR_SIGN_", "_CLI_PROGRAM_", "_DEFINE_", "_SHARP_",
  "_EXTERN_", "_FROM_", "_CSTRING_", "_CLEAR_", "_INT_", "_NULLOBJ_",
  "_NUM_", "_ID_", "_ASSIGN_", "_PLUS_", "_MINUS_", "_DIV_", "_MUL_",
  "_MOD_", "_POW_", "_OBR_", "_CBR_", "_TYPE_", "_DATE_", "_TIME_",
  "_TRUE_", "_FALSE_", "_STRING_", "_COMMA_", "_LEN_", "_ASC_", "_AT_",
  "_SPACE_", "_TRIM_", "_SUBSTR_", "_TEST_", "_ARRAY_DIM0_", "_LOWER_",
  "_UPPER_", "_ARRAY_DIM_", "_ARRAY_DIM1_", "_ARRAY_DIM2_", "_ARRAY_",
  "_PRINT_TEXT_", "_NOT_", "_NEW_", "_CLASS_", "_OF_", "_ENDCLASS_",
  "_WITH_", "_ENDWITH_", "_ARRAY_DIM3_", "_ARRAY_DIM4_", "_PUSHBUTTON_",
  "_FUNCTION_", "_FUNCTION_ARRAY_", "_RETURN_", "_IF_", "_ELSE_",
  "_ENDIF_", "_FOR_", "_ENDFOR_", "_TO_", "_USE_", "_OBJECT_ID_",
  "_OBJECT_ID2_", "_ARRAY_REMARK0_", "_THIS_OBJECT_PUSHBUTTON_",
  "_CLASS_ONCLICK_", "_CLASS_ONCLICK2_", "_FUNCTION_CALL_CLASS_", "_DO_",
  "_CASE_", "_OTHERWISE_", "_ENDDO_", "_ENDCASE_", "_LOCAL_",
  "_INNER_TEXT_", "_DATABASE_", "_OPEN_", "_LOGIN_", "_LOGIN_USERPASS_",
  "_SELECT_", "_THIS_OBJECT_CONTAINER_", "$accept", "program",
  "program_stmts", "$@1", "stmt_seq", "stmt", "local_stmt",
  "open_database_stmt", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "open_database_login_str", "open_database_login_id", "open_database",
  "select_stmt", "$@9", "use_stmt", "class_stmt", "$@10", "in_class_stmts",
  "class_stmts", "$@11", "class_func_stmts", "class_funcs",
  "class_local_stmt", "class_local_multi", "class_if_stmt", "$@12", "$@13",
  "$@14", "$@15", "$@16", "$@17", "end_if_stmt", "$@18", "class_for_stmt",
  "$@19", "$@20", "$@21", "case_expr_stmts", "class_docase_stmt", "$@22",
  "case_expr", "$@23", "case_expr_case", "new_class_ref", "$@24",
  "with_class", "with_event_stmts", "$@25", "array_stmt", "numeric_expr",
  "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34",
  "$@35", "$@36", "id_stmt", "id_stmts", "$@37", "$@38", "$@39", "$@40",
  "$@41", "$@42", "false_true_expr", "str_sub", "str_date", "str_time",
  "string_expr", "$@43", "$@44", "$@45", "$@46", "$@47", "$@48",
  "print_helper", "print_stmt", "$@49", "$@50", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   106,   105,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   109,   111,   112,   110,
     113,   114,   110,   115,   116,   110,   117,   110,   110,   118,
     119,   120,   122,   121,   123,   123,   123,   125,   124,   126,
     126,   127,   127,   127,   128,   127,   127,   127,   129,   129,
     130,   130,   130,   130,   130,   130,   130,   131,   132,   132,
     134,   135,   136,   133,   137,   138,   139,   133,   140,   141,
     140,   143,   144,   145,   142,   146,   146,   147,   148,   147,
     149,   150,   149,   151,   151,   153,   152,   154,   154,   155,
     155,   155,   156,   155,   155,   157,   158,   159,   160,   158,
     161,   158,   158,   158,   158,   162,   158,   163,   158,   164,
     158,   165,   158,   166,   158,   167,   158,   168,   158,   169,
     158,   170,   170,   171,   172,   171,   173,   174,   171,   175,
     171,   176,   171,   177,   171,   178,   178,   179,   180,   181,
     182,   183,   182,   184,   182,   182,   182,   182,   182,   182,
     182,   185,   182,   186,   182,   182,   182,   182,   182,   182,
     187,   182,   188,   182,   189,   191,   190,   192,   190
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     2,     1,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     0,     5,     2,     3,
       3,     2,     0,     3,     2,     2,     2,     0,     7,     2,
       1,     0,     1,     1,     0,     3,     1,     1,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       0,     0,     0,     9,     0,     0,     0,     9,     1,     0,
       4,     0,     0,     0,    11,     2,     1,     3,     0,     5,
       1,     0,     5,     0,     1,     0,     6,     2,     1,     0,
       1,     2,     0,     5,     1,     5,     1,     0,     0,     7,
       0,     4,     2,     1,     2,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     2,     1,     1,     0,     4,     0,     0,     6,     0,
       6,     0,     4,     0,     4,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     4,     1,     1,     4,     4,     4,
       3,     0,     3,     0,     4,     3,     3,     1,     1,     1,
       0,     4,     0,     4,     1,     0,     3,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     7,     1,     7,     6,     5,     0,   164,
       0,     0,   123,     0,     0,    32,    11,    12,     0,     0,
       0,    13,    14,    15,     9,    10,   122,   165,     8,   131,
     126,     0,    35,     0,   138,   139,   140,   151,     0,   137,
      36,     0,     0,   158,   157,   145,   146,    34,    16,    31,
       0,    23,     0,    28,    26,    17,   159,     0,     0,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   159,     0,     0,     0,   159,   153,   141,   143,   160,
      96,   103,     0,   100,    97,    33,     0,     0,     0,     0,
      30,    29,   131,   166,   168,     0,   125,   132,   136,   135,
     134,   127,     0,    37,   103,     0,     0,   152,   150,     0,
     156,   155,     0,     0,     0,     0,     0,   102,   104,   105,
       0,     0,   119,   109,   113,   111,   117,   115,    24,     0,
      18,    21,    95,     0,     0,    41,   147,   148,   149,   154,
     142,   144,   161,   163,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,     0,   128,   130,
       0,    44,     0,    47,     0,    90,    46,     0,    40,    42,
      43,    88,    94,   106,   101,    98,   108,   120,   110,   114,
     112,   118,   116,    25,    19,    22,    92,    50,     0,    91,
      38,    39,    87,     0,    89,    56,    60,     0,     0,     0,
      45,    49,    51,    53,    54,    55,    52,     0,     0,     0,
       0,     0,     0,    78,    58,    57,    48,    85,    99,    93,
       0,     0,    71,    77,     0,     0,     0,    61,    65,     0,
       0,    80,     0,    76,    59,    86,     0,     0,    72,     0,
      79,    75,    62,    66,     0,    81,    50,    50,     0,    83,
       0,     0,    73,    82,    84,    69,    68,    63,    67,    50,
      50,     0,     0,    74,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,     5,     6,    16,    17,    88,   156,
      89,   157,    86,   154,    87,    18,    19,    20,    21,    50,
      22,    23,   135,   167,   168,   187,   200,   201,   202,   215,
     203,   210,   236,   246,   211,   237,   247,   257,   260,   204,
     229,   244,   259,   232,   205,   224,   233,   249,   253,   169,
     226,   170,   171,   194,    24,    85,   121,   193,   120,   144,
     147,   149,   151,   150,   153,   152,   148,   172,    26,    63,
      66,   133,    67,    64,    65,   100,    44,    45,    46,    47,
     113,   114,    70,   112,   115,   116,    27,   206,    60,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -165
static const yytype_int16 yypact[] =
{
    -165,     8,  -165,  -165,  -165,    14,   -27,   -27,   -17,  -165,
       0,   152,  -165,    13,   -81,  -165,  -165,  -165,   -24,    18,
     169,  -165,  -165,  -165,  -165,   -19,  -165,   136,  -165,   123,
    -165,   -32,    19,    22,  -165,  -165,  -165,  -165,   186,  -165,
      28,    38,   203,  -165,  -165,    39,    55,    63,  -165,  -165,
     221,    19,    28,  -165,    63,  -165,     1,   -22,   -11,  -165,
     186,   221,    78,   221,   186,    81,    89,   105,   116,    92,
     110,  -165,    84,   221,   134,   140,    63,  -165,  -165,   276,
    -165,   -15,   186,  -165,  -165,   316,   141,   147,   156,   161,
    -165,  -165,   273,    63,   316,   106,   316,    63,  -165,  -165,
    -165,  -165,   168,  -165,   -15,   300,    87,  -165,  -165,   308,
    -165,  -165,   162,   221,   221,   186,   221,  -165,  -165,    63,
     186,   186,   279,  -165,  -165,  -165,  -165,  -165,  -165,   170,
    -165,  -165,  -165,   221,   149,    27,  -165,  -165,  -165,  -165,
     316,   316,    63,   316,   173,   130,     3,   221,   186,   221,
     221,   221,   221,   221,   186,  -165,   183,   186,   316,  -165,
     160,  -165,   184,  -165,   193,  -165,  -165,    -8,  -165,  -165,
      -5,  -165,   -19,  -165,  -165,  -165,   316,    63,   316,   316,
     316,   316,   316,    63,  -165,    63,  -165,   218,   166,  -165,
    -165,  -165,  -165,   186,    -5,  -165,   282,   200,   142,   204,
     218,  -165,  -165,  -165,  -165,  -165,  -165,   164,   157,    17,
     186,   221,   215,   154,  -165,   214,  -165,  -165,  -165,  -165,
       4,   122,  -165,  -165,   -52,   204,   178,  -165,  -165,   221,
     222,  -165,    70,  -165,   214,  -165,   186,   221,   316,   266,
    -165,  -165,    63,   316,   192,  -165,   218,   218,   221,   221,
     188,   188,   316,  -165,   316,  -165,  -165,  -165,  -165,   218,
     218,   206,   212,  -165,  -165
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -165,  -165,  -165,  -165,  -165,   271,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,   112,  -165,  -148,  -143,  -165,    52,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,    33,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,    57,  -165,  -165,  -165,
    -165,   101,  -164,  -165,  -165,   -60,  -165,  -165,  -165,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,   125,   -20,  -165,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,  -165,   -18,
    -165,  -165,  -165,  -165,  -165,  -165,  -165,   172,  -165,  -165
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -168
static const yytype_int16 yytable[] =
{
      54,    94,    57,    96,     8,    59,   192,    51,     4,   105,
     227,    79,    58,   109,    -4,    29,    49,    33,    34,    35,
      72,    92,    36,    58,    76,   117,    58,    37,    38,    39,
      52,    31,    41,    42,    68,     9,    79,    79,    10,   230,
     231,    30,    93,   118,    48,   192,    97,    30,    58,    55,
     175,   106,  -159,   140,   141,    11,   143,   216,    58,   190,
     160,    69,    12,   160,   119,    43,   161,    73,    13,    74,
      12,    14,    77,   158,    15,   162,    53,    91,   163,   164,
     165,    12,   164,   165,    12,   160,   219,   176,    78,   178,
     179,   180,   181,   182,   166,   160,    79,   142,   250,   251,
      90,   161,   145,   146,   164,   165,    12,   216,   216,    95,
     162,   261,   262,   163,   164,   165,    12,    79,   216,   216,
      79,   101,    80,   104,   108,    98,    99,   137,   228,   166,
     177,    25,    25,    33,    34,    35,   183,   102,    36,   185,
      82,    83,    84,    37,    38,    39,    52,   103,    41,    42,
     107,   221,    59,  -124,  -124,   122,   123,   124,   125,   126,
     127,   230,   231,    79,   240,   132,  -167,  -133,  -133,   238,
     174,  -124,  -124,  -124,   110,   208,   128,   243,    28,    28,
     111,    43,   129,    32,  -167,  -167,  -167,    62,   252,   254,
      79,   130,   220,    33,    34,    35,   131,   218,    36,   134,
      56,   155,   139,    37,    38,    39,    40,   159,    41,    42,
      33,    34,    35,   173,   184,    36,   188,    71,   242,   186,
      37,    38,    39,    52,   189,    41,    42,    33,    34,    35,
     207,   212,    36,   213,    75,   214,   217,    37,    38,    39,
      52,    43,    41,    42,    33,    34,    35,   222,   223,    36,
       9,    80,    81,   239,    37,    38,    39,    52,    43,    41,
      42,   225,   235,   195,   196,   255,   256,   197,     9,    82,
      83,    84,   245,   248,     9,    43,     7,   234,   198,   191,
       9,   195,   196,   199,   258,   197,   263,   195,   196,   241,
     264,   197,    43,   195,   196,   209,   198,   197,     0,     0,
       0,   199,   198,  -124,  -124,     0,  -162,   199,   198,  -107,
    -107,     0,   -64,   199,     0,     0,     0,  -133,  -133,     0,
       0,  -124,  -124,  -124,  -162,  -162,  -162,  -107,  -107,  -107,
     -64,   -64,   -64,   122,   123,   124,   125,   126,   127,     0,
     136,   122,   123,   124,   125,   126,   127,     0,   138,   122,
     123,   124,   125,   126,   127
};

static const yytype_int16 yycheck[] =
{
      18,    61,    20,    63,    31,    25,   170,    31,     0,    69,
       6,    33,    31,    73,     0,    32,    97,    41,    42,    43,
      38,    32,    46,    31,    42,    40,    31,    51,    52,    53,
      54,    31,    56,    57,    66,    62,    33,    33,    65,    91,
      92,    58,    60,    58,    31,   209,    64,    58,    31,    31,
      47,    69,    33,   113,   114,    82,   116,   200,    31,    67,
      68,    39,    89,    68,    82,    89,    74,    39,    95,    31,
      89,    98,    33,   133,   101,    83,   100,    99,    86,    87,
      88,    89,    87,    88,    89,    68,    69,   147,    33,   149,
     150,   151,   152,   153,   102,    68,    33,   115,   246,   247,
      99,    74,   120,   121,    87,    88,    89,   250,   251,    31,
      83,   259,   260,    86,    87,    88,    89,    33,   261,   262,
      33,    32,    30,    31,    40,    44,    45,    40,     6,   102,
     148,     6,     7,    41,    42,    43,   154,    32,    46,   157,
      48,    49,    50,    51,    52,    53,    54,    31,    56,    57,
      40,   211,   172,    30,    31,    33,    34,    35,    36,    37,
      38,    91,    92,    33,    94,    59,    30,    44,    45,   229,
      40,    48,    49,    50,    40,   193,    35,   237,     6,     7,
      40,    89,    35,    31,    48,    49,    50,    64,   248,   249,
      33,    35,   210,    41,    42,    43,    35,    40,    46,    31,
      31,    31,    40,    51,    52,    53,    54,    58,    56,    57,
      41,    42,    43,    40,    31,    46,    32,    31,   236,    59,
      51,    52,    53,    54,    31,    56,    57,    41,    42,    43,
      64,    31,    46,    91,    31,    31,    72,    51,    52,    53,
      54,    89,    56,    57,    41,    42,    43,    32,    94,    46,
      62,    30,    31,    31,    51,    52,    53,    54,    89,    56,
      57,    47,    84,    75,    76,    77,    78,    79,    62,    48,
      49,    50,     6,    81,    62,    89,     5,   225,    90,   167,
      62,    75,    76,    95,   251,    79,    80,    75,    76,   232,
      78,    79,    89,    75,    76,   194,    90,    79,    -1,    -1,
      -1,    95,    90,    30,    31,    -1,    30,    95,    90,    30,
      31,    -1,    30,    95,    -1,    -1,    -1,    44,    45,    -1,
      -1,    48,    49,    50,    48,    49,    50,    48,    49,    50,
      48,    49,    50,    33,    34,    35,    36,    37,    38,    -1,
      40,    33,    34,    35,    36,    37,    38,    -1,    40,    33,
      34,    35,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   104,   105,   106,     0,   107,   108,   108,    31,    62,
      65,    82,    89,    95,    98,   101,   109,   110,   118,   119,
     120,   121,   123,   124,   157,   170,   171,   189,   190,    32,
      58,    31,    31,    41,    42,    43,    46,    51,    52,    53,
      54,    56,    57,    89,   179,   180,   181,   182,    31,    97,
     122,    31,    54,   100,   182,    31,    31,   182,    31,   171,
     191,   192,    64,   172,   176,   177,   173,   175,    66,    39,
     185,    31,   182,    39,    31,    31,   182,    33,    33,    33,
      30,    31,    48,    49,    50,   158,   115,   117,   111,   113,
      99,    99,    32,   182,   158,    31,   158,   182,    44,    45,
     178,    32,    32,    31,    31,   158,   182,    40,    40,   158,
      40,    40,   186,   183,   184,   187,   188,    40,    58,   182,
     161,   159,    33,    34,    35,    36,    37,    38,    35,    35,
      35,    35,    59,   174,    31,   125,    40,    40,    40,    40,
     158,   158,   182,   158,   162,   182,   182,   163,   169,   164,
     166,   165,   168,   167,   116,    31,   112,   114,   158,    58,
      68,    74,    83,    86,    87,    88,   102,   126,   127,   152,
     154,   155,   170,    40,    40,    47,   158,   182,   158,   158,
     158,   158,   158,   182,    31,   182,    59,   128,    32,    31,
      67,   127,   155,   160,   156,    75,    76,    79,    90,    95,
     129,   130,   131,   133,   142,   147,   190,    64,   182,   154,
     134,   137,    31,    91,    31,   132,   130,    72,    40,    69,
     182,   158,    32,    94,   148,    47,   153,     6,     6,   143,
      91,    92,   146,   149,   132,    84,   135,   138,   158,    31,
      94,   149,   182,   158,   144,     6,   136,   139,    81,   150,
     129,   129,   158,   151,   158,    77,    78,   140,   140,   145,
     141,   129,   129,    80,    78
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1455 of yacc.c  */
#line 215 "pcode.y"
    {
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
     }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 298 "pcode.y"
    {
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
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 335 "pcode.y"
    { }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 340 "pcode.y"
    { /* empty */ }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 341 "pcode.y"
    { }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 342 "pcode.y"
    { }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 343 "pcode.y"
    { }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 344 "pcode.y"
    { }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 345 "pcode.y"
    { }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 346 "pcode.y"
    { }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 347 "pcode.y"
    { }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 348 "pcode.y"
    { }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 352 "pcode.y"
    {
        if run_parse(1)
        print_def((yyvsp[(2) - (2)].id));
    }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 359 "pcode.y"
    { print_comma(); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 359 "pcode.y"
    { print_comma(); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 359 "pcode.y"
    {
        if run_parse(2)
        print_code("sssss",
            "QString(\"",
            (yyvsp[(2) - (6)].id),
            "\"),QString(\"",
            (yyvsp[(6) - (6)].id),
            "\"));\n"
        );
    }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 369 "pcode.y"
    {
        if run_parse(2)
        print_code("ss",(yyvsp[(2) - (2)].id),",");
    }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 372 "pcode.y"
    { print_comma(); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 372 "pcode.y"
    {
        if run_parse(2)
        print_code("s",");\n");
    }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 376 "pcode.y"
    {
        if run_parse(2)
        print_code("s",(yyvsp[(2) - (2)].id));
        print_comma();
    }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 380 "pcode.y"
    { print_comma(); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 380 "pcode.y"
    {
        if run_parse(2)
        print_code("s",");\n");
    }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 384 "pcode.y"
    { print_comma(); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 384 "pcode.y"
    {
        if run_parse(2)
        print_code("sss",
            "QString(\"",
            (yyvsp[(5) - (5)].id),
            "\"));\n"
        );
    }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 392 "pcode.y"
    {
        if run_parse(2) {
            char *user = (char*)malloc(2048);
            char *pass = (char*)malloc(2048);

            char buffer[4000];

            strcpy(buffer,(yyvsp[(2) - (2)].text));
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
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 414 "pcode.y"
    { print_comma(); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 415 "pcode.y"
    {
    if run_parse(2) print_code("ss",(yyvsp[(2) - (3)].id),",");
    }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 421 "pcode.y"
    {
        if run_parse(2)
        print_code("s","\txbase_open_database(");
    }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 437 "pcode.y"
    {
        if run_parse(2)
        {
            has_for_flag = true;
            print_code("s","\txbase_select(");
        }
    }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 443 "pcode.y"
    {
        if run_parse(2) {
            print_code("s",");\n");
            has_for_flag = false;
        }
    }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 452 "pcode.y"
    {
        if run_parse(2) {
            print_code("sss",
                "\txbase_open_dbf(",
                (yyvsp[(2) - (2)].text),
                ");\n"
            );
        }
    }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 461 "pcode.y"
    {
        if run_parse(2) {
            print_code("sss",
                "\txbase_open_dbf(\"",
                (yyvsp[(2) - (2)].id),
                "\");\n"
            );
        }
    }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 470 "pcode.y"
    {
        if run_parse(2)
        print_code("s","\txbase_open_dbf(\"test\");\n");
    }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 477 "pcode.y"
    {

		yylval.object_class_name = (char*) malloc(strlen((yyvsp[(2) - (4)].id))+1);
		strcpy(yylval.object_class_name,(yyvsp[(2) - (4)].id));

		yylval.object_class_name_type = (char*) malloc(strlen((yyvsp[(4) - (4)].id))+1);
		strcpy(yylval.object_class_name_type,(yyvsp[(4) - (4)].id));
        strcpy(class_name,(yyvsp[(2) - (4)].id));

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
            QString str = QString((yyvsp[(2) - (4)].id)).toLower();

		    print_code("ssss",
			"void myclass_",
                        str.toStdString().c_str(),
			"::myclass_init",
			"(void)\n{\n"
		    );
		}
		if run_parse(4)
		{
                    QString str = QString((yyvsp[(4) - (4)].id)).toLower();
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
                            QString((yyvsp[(2) - (4)].id)).toLower().toStdString().c_str(),
			    ": public ",
                            obj.toStdString().c_str(),
			    "\n{\npublic:\n\tmyclass_",
                            QString((yyvsp[(2) - (4)].id)).toLower().toStdString().c_str(),
			    "(void) { myclass_init(); } \n"
		        );
		        print_code("ss",
			    "\n\tvoid myclass_init",
			    "(void);\n"
		    );
		}
	}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 539 "pcode.y"
    {
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
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 554 "pcode.y"
    { }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 562 "pcode.y"
    {
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
    }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 638 "pcode.y"
    {
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
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 657 "pcode.y"
    {
        QString str1 = QString((yyvsp[(1) - (1)].text)).toLower();
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
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 685 "pcode.y"
    {
        QString str1 = QString((yyvsp[(1) - (1)].text)).toLower();
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
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 724 "pcode.y"
    { }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 735 "pcode.y"
    {
        if run_parse(4) {
            run_parse_mode = 3;
            procedure_members[current_function] += QString("\treturn result;\n");
            run_parse_mode = 4;
        }
    }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 749 "pcode.y"
    {
        if run_parse(4) {
            QString str1 = QString((yyvsp[(1) - (1)].id)).toLower();
            QString str2 = QString("\tMyQVariant %1;\n").arg(str1);
            procedure_members[current_function] += str2;
        }
    }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 760 "pcode.y"
    {
        has_if_flag = true;
        if run_parse(4)   {
            QString str = "\tif (";
            procedure_members[current_function] += str;
        }
    }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 766 "pcode.y"
    {
        if run_parse(4)   {
            QString str = QString(" == ");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 771 "pcode.y"
    {
        if run_parse(4)   {
            QString str = QString(") {\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 776 "pcode.y"
    {
        has_if_flag = false;
    }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 779 "pcode.y"
    {
        has_if_flag = true;
        if run_parse(4)   {
            QString str = "\tif (";
            procedure_members[current_function] += str;
        }
    }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 785 "pcode.y"
    {
        if run_parse(4)   {
            QString str = QString(" == ");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 790 "pcode.y"
    {
        if run_parse(4)   {
            QString str = QString(") {\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 795 "pcode.y"
    {
        has_if_flag = false;
    }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 801 "pcode.y"
    {
        if run_parse(4) {
            QString str = QString("\t}\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 807 "pcode.y"
    {
        if run_parse(4) {
            QString str = QString("\t}\n\telse {\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 812 "pcode.y"
    {
        if run_parse(4) {
            QString str = QString("\t}\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 821 "pcode.y"
    {
        has_for_flag = true;
        if run_parse(4) {
            QString str1 = QString((yyvsp[(2) - (3)].id)).toLower();
            QString str2 = QString("\tfor (int %1 = ").arg(str1);
            procedure_members[current_function] += str2;
        }
    }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 828 "pcode.y"
    {
        if run_parse(4) {
            QString str1 = QString((yyvsp[(2) - (5)].id)).toLower();
            QString str2 = QString("; %1 < ").arg(str1);
            procedure_members[current_function] += str2;
        }
    }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 834 "pcode.y"
    {
        if run_parse(4) {
            QString str1 = QString((yyvsp[(2) - (8)].id)).toLower();
            QString str2 = QString("; ++%1)\n\t{\n").arg(str1);
            procedure_members[current_function] += str2;
        }
    }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 840 "pcode.y"
    {
        has_for_flag = false;
        if run_parse(4) {
            QString str = QString("\t}\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 851 "pcode.y"
    { }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 856 "pcode.y"
    {
        if run_parse(4) {
            --do_case_counter;
        }
    }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 861 "pcode.y"
    {
        if run_parse(3)
        has_if_flag = true;
        else if run_parse(4)
        has_case_flag = true;
    }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 866 "pcode.y"
    {
        if run_parse(3) {
            has_if_flag = false;
        }
        else if run_parse(4) {
            QString str = QString("\t}\n");
            procedure_members[current_function] += str;

            --do_case_counter;
        }
    }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 880 "pcode.y"
    {
        if run_parse(4) {
            QString str = QString("\t} else {\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 886 "pcode.y"
    {
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
                    QString str = QString("\tMyQVariant %1;\n").arg((yyvsp[(2) - (3)].id));
                    procedure_members[current_function] += str;
                }
            }

            QString str1 = QString((yyvsp[(2) - (3)].id)).toLower();
            QString str2 = QString("\tif (%1 == ").arg(str1);
            procedure_members[current_function] += str2;

            ++do_case_counter;
        }
    }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 913 "pcode.y"
    {
        if run_parse(4) {
            QString str = QString(")\n\t{\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 922 "pcode.y"
    {
		printf(" pusher\n");
	}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 924 "pcode.y"
    {
		printf("objid: %s\n",yylval.object_class_name);
	}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 930 "pcode.y"
    { }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 936 "pcode.y"
    {
        if run_parse(3)
        {
            QString str1 = QString((yyvsp[(1) - (1)].text));
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
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 976 "pcode.y"
    {
        if run_parse(3) {
            QString  tmpstr ;
            tmpstr = tmpstr + QString(this_object);
            tmpstr = tmpstr + QString("->form_OnMouseClick << std::bind(&myclass_");
            tmpstr = tmpstr + QString(class_name);
            tmpstr = tmpstr + QString("::");
            tmpstr = tmpstr + QString(QString((yyvsp[(2) - (2)].id)).toLower());
            tmpstr = tmpstr + QString(",this,");
            tmpstr = tmpstr + QString(this_object);
            tmpstr = tmpstr + QString("->event_OnMouseClick);\n");

            print_code("s",tmpstr.toStdString().c_str());

            QString str =
            QString("myclass_")  +
            QString(class_name)  +
            QString("::")        +
            QString((yyvsp[(2) - (2)].id)).toLower();

            class_function_name = str;


            QStringList sl; sl << "@init:onMouseClick";
            procedure_parameters.insert(str,sl);
        }
	}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1003 "pcode.y"
    {

        QString str1 = QString((yyvsp[(2) - (2)].text)).toLower();
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

    }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1024 "pcode.y"
    { }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1028 "pcode.y"
    {

        QString cmp = QString((yyvsp[(4) - (5)].id)).toLower();
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
                print_def((yyvsp[(1) - (5)].id));
                print_code("sssis",
                "#define __COMPILER_DIM_ARRAY_",
                (yyvsp[(1) - (5)].id),
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
                    (yyvsp[(1) - (5)].id),
                    "> ARRAY_",
                    (yyvsp[(1) - (5)].id),
                    ";\n"
                );

                QString str = QString((yyvsp[(5) - (5)].text)).replace(QRegExp("("),"");
                        str = str.        replace(QRegExp(")"),"");

                print_code("sssssss",
                    "\tARRAY_",
                    (yyvsp[(1) - (5)].id),
                    " ARRAYTYPE_",
                    (yyvsp[(1) - (5)].id),
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
                        "  #ifndef _ISDEFINED__class_",   (yyvsp[(4) - (5)].id), "\n",
                        "  #define _ISDEFINED__class_",   (yyvsp[(4) - (5)].id), "\n",
                        "MyQForm *myclass_local_",
                        (yyvsp[(1) - (5)].id),
                        ";\n  #endif\n#endif\n"
                );
            }

            if run_parse(2)
            print_code("sssss",
                "\t{\n\tmyclass_local_",
                (yyvsp[(1) - (5)].id),
                " = new myclass_",
                (yyvsp[(4) - (5)].id),
                "();\n\t}\n"
            );
        }
    }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1113 "pcode.y"
    {
        char buffer[2048];
        sprintf(buffer,"%f",(yyvsp[(1) - (1)].val));
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
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1135 "pcode.y"
    {
        if run_parse(2)
            print_code("s","\tget_stringindex(\n");
    }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1138 "pcode.y"
    { if run_parse(2) print_code("s",",\n");
    }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1139 "pcode.y"
    {
            if run_parse(2)
            print_code("s",")");
    }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1143 "pcode.y"
    {
            if run_parse(2)
            print_code("s","\tget_char_code(");
        }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1146 "pcode.y"
    {
            if run_parse(2)
            print_code("s",")");
        }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1150 "pcode.y"
    {
	    printf("oo> %s\n",(yyvsp[(1) - (2)].id));

            if run_parse(2)
            print_code("sss",
                "\tQString(boost::get<std::string>(global_",
                (yyvsp[(1) - (2)].id),
                ".data).c_str()).toUpper()"
            );
        }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1160 "pcode.y"
    {
            run_parse_mode = 1;
            print_def((yyvsp[(1) - (1)].id));
            if run_parse(2)
            print_code("ss",
                "global_",
                (yyvsp[(1) - (1)].id)
            );
        }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1169 "pcode.y"
    {
            if run_parse(2)
            print_code("sss","ARRAYTYPE_",(yyvsp[(1) - (2)].id),(yyvsp[(2) - (2)].text));
        }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1173 "pcode.y"
    {
            if run_parse(2)
            print_code("s",".length())");
        }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 1177 "pcode.y"
    { if run_parse(2) print_code("s"," + "); }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1178 "pcode.y"
    { if run_parse(2) print_code("s"," - "); }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 1179 "pcode.y"
    { if run_parse(2) print_code("s"," * "); }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1180 "pcode.y"
    { if run_parse(2) print_code("s"," / "); }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1181 "pcode.y"
    { if run_parse(2) print_code("s"," ^ "); }
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1182 "pcode.y"
    { if run_parse(2) print_code("s"," % "); }
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1182 "pcode.y"
    {
          /* special form of expression ... */ }
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1184 "pcode.y"
    {
            if run_parse(2)
            print_code("s",") + \n");
        }
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1191 "pcode.y"
    { }
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1196 "pcode.y"
    {
        if run_parse(2) {
            QString str = (yyvsp[(1) - (1)].text);
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
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1215 "pcode.y"
    {       // ID = <expr>[+-/*<expr>...]

        if run_parse(1) print_def((yyvsp[(1) - (2)].id));
        if run_parse(2) {
            	print_code("sss",
                	"\t{\n\tMyQVariant local_",
                	(yyvsp[(1) - (2)].id),
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

            QString cmp = QString((yyvsp[(1) - (2)].id)).toLower();

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
                QString((yyvsp[(1) - (2)].id))  +
                QString(" = "); else str =

                QString("(__class__") +
                QString(scl) +
                QString((yyvsp[(1) - (2)].id))  +
                QString(" = ");

            str = str.toLower();
            check_added_symbol(str.toStdString().c_str(),4);
            print_code("s",    str.toStdString().c_str());
	    }
    }
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 1268 "pcode.y"
    {
        if run_parse(2)
        print_code("sssss",
            ";\n\tglobal_",
            (yyvsp[(1) - (4)].id),
            " = local_",
            (yyvsp[(1) - (4)].id),
            ";\n\t}\n"
        );
        if run_parse(3)
        {
            QString cmp = QString((yyvsp[(1) - (4)].id)).toLower();

            if (cmp == QString("top")) print_code("s",")"); else
            if (cmp == QString("left")) print_code("s",")"); else
            if (cmp == QString("width")) print_code("s",")"); else
            if (cmp == QString("height")) print_code("s",")");

            print_code("s",");\n");

        	if (class_type == clButton)
            print_code("sss","\t",this_object,"->showButton();\n");
        }
    }
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1292 "pcode.y"
    {    // ARRAY[ <dimension:expr> ] = <expr>
	    if run_parse(1) print_def((yyvsp[(1) - (2)].id));
        if run_parse(2) {
            QString str = QString((yyvsp[(2) - (2)].text));
            str = str.replace(",","][");
            print_code("sss",
                "\tARRAYTYPE_",
                (yyvsp[(1) - (2)].id),
                str.toStdString().c_str()
            );
	    }
    }
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1303 "pcode.y"
    {
            if run_parse(2) print_code("s"," = "); }
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1304 "pcode.y"
    {
            if run_parse(2) print_code("s",";\n");
    }
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1307 "pcode.y"
    {    // ARRAY[ <dimension:expr> ] = <expr>
        if run_parse(1) print_def((yyvsp[(1) - (2)].id));
        if run_parse(2) {
            QString str = QString((yyvsp[(2) - (2)].text));
            str = str.replace(",","][");
            print_code("sss",
                "\tARRAYTYPE_",
                (yyvsp[(1) - (2)].id),
                str.toStdString().c_str()
            );
        }
    }
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1318 "pcode.y"
    {
        if run_parse(2) {
            print_code("s"," = ");

            QString str = QString((yyvsp[(6) - (6)].text));
            str = str.replace(",","][");
            print_code("sss",
                "\tARRAYTYPE_",
                (yyvsp[(5) - (6)].id),
                str.toStdString().c_str()
            );
	
            print_code("s",";\n");
        }
    }
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1333 "pcode.y"
    {       // ID = <string>
	    if run_parse(1) print_def((yyvsp[(1) - (2)].id));
            if run_parse(2) {
                print_code("sss",
                "\t{\n\tMyQVariant local_",
                (yyvsp[(1) - (2)].id),
                " =\n"
                );
	    }
        }
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1342 "pcode.y"
    {
            if run_parse(2)
            print_code("sssss",
                ";\n\tglobal_",
                (yyvsp[(1) - (4)].id),
                " = local_",
                (yyvsp[(1) - (4)].id),
                ";\n\t}\n"
            );
        }
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1352 "pcode.y"
    {       // ID = <bool>
	    if run_parse(1) print_def((yyvsp[(1) - (2)].id));
            if run_parse(2) {
	            print_code("sss",
        	        "\tMyQVariant local_",
        	        (yyvsp[(1) - (2)].id),
        	        " = "
        	    );
	    }
        }
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 1361 "pcode.y"
    {
            if run_parse(2)
            print_code("ssssss",
                (yyvsp[(4) - (4)].trfa),
                ";\n\tglobal_",
                (yyvsp[(1) - (4)].id),
                " = local_",
                (yyvsp[(1) - (4)].id),
                ";\n"
            );
        }
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1375 "pcode.y"
    {
            if run_parse(2)
            strcpy((yyval.trfa),"false");
        }
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1379 "pcode.y"
    {
            if run_parse(2)
            strcpy((yyval.trfa),"true");
        }
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1386 "pcode.y"
    {
	    if run_parse(2)
	    print_code("ss","\tset_",(yyvsp[(1) - (1)].text));
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tset_");
            str << QString((yyvsp[(1) - (1)].text));

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
	}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 1403 "pcode.y"
    {
        if run_parse(2) print_code("s","\tmy_date_now()");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tmy_date_now()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1418 "pcode.y"
    {
        if run_parse(2) print_code("s","\tmy_time_now()");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tmy_time_now()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1433 "pcode.y"
    {
        if run_parse(2)
        {
          msgbox(QString("info"),QString("STRP000000"));
            if (!ident_code)
            print_code("sss","\tQString(",(yyvsp[(1) - (1)].text),")"); else
            print_code("sss",  "QString(",(yyvsp[(1) - (1)].text),")");
            ident_code = false;
            in_upper_case = false;
        }
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str; str
                << QString("\tQString(")
                << QString((yyvsp[(1) - (1)].text))
                << QString(")");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
            in_upper_case  = false;
        }
    }
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1456 "pcode.y"
    {
        if run_parse(2) print_code("s",".addDays(");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(".addDays(");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1467 "pcode.y"
    {
        if run_parse(2) print_code("s",")");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(")");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1479 "pcode.y"
    {
        if run_parse(2) print_code("s",".addSecs(");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(".addSecs(");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1490 "pcode.y"
    {
        if run_parse(2) print_code("s",")");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString(")");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1502 "pcode.y"
    { }
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1503 "pcode.y"
    { }
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1504 "pcode.y"
    {
        if run_parse(2) print_code("s", "N");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("N");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1516 "pcode.y"
    {
        if run_parse(2) print_code("s", "C");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("C");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1528 "pcode.y"
    {
        if run_parse(2) print_code("s","-6");
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("-6");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1540 "pcode.y"
    {
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
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1553 "pcode.y"
    {
        if run_parse(2) {
	    	QString y = (yyvsp[(1) - (1)].text);
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
            str << QString((yyvsp[(1) - (1)].text));

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1573 "pcode.y"
    {
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
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1586 "pcode.y"
    { in_upper_case = true; }
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1586 "pcode.y"
    {
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
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1599 "pcode.y"
    {

        if run_parse(2)
        print_code("sss",
            "\tQString(boost::get<std::string>(global_",
            (yyvsp[(2) - (3)].id),
            ".data).c_str()).toUpper()"
        );
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tQString(boost::get<std::string>(global_");
            str << QString((yyvsp[(2) - (3)].id));
            str << QString(".data).c_str()).toUpper()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1619 "pcode.y"
    {
        if run_parse(2)
        print_code("sss",
            "\tQString(boost::get<std::string>(global_",
            (yyvsp[(2) - (3)].id),
            ".data).c_str()).toLower()"
        );
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tQString(boost::get<std::string>(global_");
            str << QString((yyvsp[(2) - (3)].id));
            str << QString(".data).c_str()).toLower()");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1638 "pcode.y"
    { }
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1639 "pcode.y"
    {
        if run_parse(2) {
            qDebug() << (yyvsp[(1) - (1)].text);
            print_code("sss","\tmyclass_local_",(yyvsp[(1) - (1)].text),"\n");
        }
        else if run_parse(4) {
            run_parse_mode = 3;

            QString str1;
            str1 = QString((yyvsp[(1) - (1)].text));
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
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1669 "pcode.y"
    {
        if run_parse(2)
        print_code("sss",
            "\tQString(boost::get<std::string>(global_",
            (yyvsp[(1) - (1)].id),
            ".data).c_str())))"
        );
        else if run_parse(4) {
            run_parse_mode = 3;

            QList <QString> str;
            str << QString("\tQString(boost::get<std::string>(global_");
            str << QString((yyvsp[(1) - (1)].id));
            str << QString(".data).c_str()))))");

            procedure_members[current_function] += str;
            run_parse_mode = 4;
        }
    }
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1688 "pcode.y"
    {
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
    }
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1708 "pcode.y"
    { if run_parse(2) { print_code("s"," +\n\tMyQVariant("); in_myqvariant = true; } }
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1712 "pcode.y"
    {
        if run_parse(2) { print_code("s","\tprint_console("); } else
        if run_parse(4) {
            QList <QString> str; str
                << QString("\tprint_console(");
            procedure_members[current_function] += str;
        }

        in_print_console = true;
    }
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1725 "pcode.y"
    {
        if run_parse(2) { print_code("s","MyQVariant("); } else
        if run_parse(4) {
            QList <QString> str; str << QString("MyQVariant(\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1731 "pcode.y"
    {
        if run_parse(2) { print_code("s","));\n"); } else
        if run_parse(4) {
            QList <QString> str; str << QString("));\n");
            procedure_members[current_function] += str;
        }
    }
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1738 "pcode.y"
    { }
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1738 "pcode.y"
    {
        if run_parse(2) print_code("s","));\n"); else 
        if run_parse(4) {
            QList <QString> str; str
                << QString("));\n");
            procedure_members[current_function] += str;
        }
    }
    break;



/* Line 1455 of yacc.c  */
#line 4262 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1748 "pcode.y"


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


