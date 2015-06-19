
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 270 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


