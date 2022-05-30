/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_Y_TAB_H_INCLUDED
# define YY_YY_BUILD_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CONST = 258,                   /* CONST  */
    BOOL = 259,                    /* BOOL  */
    CHAR = 260,                    /* CHAR  */
    DOUBLE = 261,                  /* DOUBLE  */
    FLOAT = 262,                   /* FLOAT  */
    INT = 263,                     /* INT  */
    LONG = 264,                    /* LONG  */
    SHORT = 265,                   /* SHORT  */
    SIGNED = 266,                  /* SIGNED  */
    UNSIGNED = 267,                /* UNSIGNED  */
    VOID = 268,                    /* VOID  */
    BREAK = 269,                   /* BREAK  */
    CASE = 270,                    /* CASE  */
    CONTINUE = 271,                /* CONTINUE  */
    DEFAULT = 272,                 /* DEFAULT  */
    DO = 273,                      /* DO  */
    ELSE = 274,                    /* ELSE  */
    ENUM = 275,                    /* ENUM  */
    FOR = 276,                     /* FOR  */
    IF = 277,                      /* IF  */
    RETURN = 278,                  /* RETURN  */
    SWITCH = 279,                  /* SWITCH  */
    WHILE = 280,                   /* WHILE  */
    COLON = 281,                   /* COLON  */
    COMMA = 282,                   /* COMMA  */
    LBRACE = 283,                  /* LBRACE  */
    LPAREN = 284,                  /* LPAREN  */
    QUESTION = 285,                /* QUESTION  */
    RBRACE = 286,                  /* RBRACE  */
    RPAREN = 287,                  /* RPAREN  */
    SEMICOLON = 288,               /* SEMICOLON  */
    ADD_ASSIGN = 289,              /* ADD_ASSIGN  */
    AND_ASSIGN = 290,              /* AND_ASSIGN  */
    ASSIGN = 291,                  /* ASSIGN  */
    DIV_ASSIGN = 292,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 293,              /* MOD_ASSIGN  */
    MUL_ASSIGN = 294,              /* MUL_ASSIGN  */
    OR_ASSIGN = 295,               /* OR_ASSIGN  */
    SHL_ASSIGN = 296,              /* SHL_ASSIGN  */
    SHR_ASSIGN = 297,              /* SHR_ASSIGN  */
    SUB_ASSIGN = 298,              /* SUB_ASSIGN  */
    XOR_ASSIGN = 299,              /* XOR_ASSIGN  */
    ADD = 300,                     /* ADD  */
    AND = 301,                     /* AND  */
    BIT_AND = 302,                 /* BIT_AND  */
    BIT_NOT = 303,                 /* BIT_NOT  */
    BIT_OR = 304,                  /* BIT_OR  */
    DEC = 305,                     /* DEC  */
    DIV = 306,                     /* DIV  */
    EQ = 307,                      /* EQ  */
    GE = 308,                      /* GE  */
    GT = 309,                      /* GT  */
    INC = 310,                     /* INC  */
    LE = 311,                      /* LE  */
    LT = 312,                      /* LT  */
    MOD = 313,                     /* MOD  */
    MUL = 314,                     /* MUL  */
    NE = 315,                      /* NE  */
    NOT = 316,                     /* NOT  */
    OR = 317,                      /* OR  */
    SHL = 318,                     /* SHL  */
    SHR = 319,                     /* SHR  */
    SUB = 320,                     /* SUB  */
    XOR = 321,                     /* XOR  */
    FALSE = 322,                   /* FALSE  */
    TRUE = 323,                    /* TRUE  */
    INT_LITERAL = 324,             /* INT_LITERAL  */
    FLOAT_LITERAL = 325,           /* FLOAT_LITERAL  */
    CHAR_LITERAL = 326,            /* CHAR_LITERAL  */
    STRING_LITERAL = 327,          /* STRING_LITERAL  */
    IDENTIFIER = 328               /* IDENTIFIER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CONST 258
#define BOOL 259
#define CHAR 260
#define DOUBLE 261
#define FLOAT 262
#define INT 263
#define LONG 264
#define SHORT 265
#define SIGNED 266
#define UNSIGNED 267
#define VOID 268
#define BREAK 269
#define CASE 270
#define CONTINUE 271
#define DEFAULT 272
#define DO 273
#define ELSE 274
#define ENUM 275
#define FOR 276
#define IF 277
#define RETURN 278
#define SWITCH 279
#define WHILE 280
#define COLON 281
#define COMMA 282
#define LBRACE 283
#define LPAREN 284
#define QUESTION 285
#define RBRACE 286
#define RPAREN 287
#define SEMICOLON 288
#define ADD_ASSIGN 289
#define AND_ASSIGN 290
#define ASSIGN 291
#define DIV_ASSIGN 292
#define MOD_ASSIGN 293
#define MUL_ASSIGN 294
#define OR_ASSIGN 295
#define SHL_ASSIGN 296
#define SHR_ASSIGN 297
#define SUB_ASSIGN 298
#define XOR_ASSIGN 299
#define ADD 300
#define AND 301
#define BIT_AND 302
#define BIT_NOT 303
#define BIT_OR 304
#define DEC 305
#define DIV 306
#define EQ 307
#define GE 308
#define GT 309
#define INC 310
#define LE 311
#define LT 312
#define MOD 313
#define MUL 314
#define NE 315
#define NOT 316
#define OR 317
#define SHL 318
#define SHR 319
#define SUB 320
#define XOR 321
#define FALSE 322
#define TRUE 323
#define INT_LITERAL 324
#define FLOAT_LITERAL 325
#define CHAR_LITERAL 326
#define STRING_LITERAL 327
#define IDENTIFIER 328

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "src/parser.y"

    int int_value;
    double float_value;
    char char_value;
    char *string_value;
    _Bool bool_value;
    struct AST_Node *node_pointer;
    struct SymbolTableEntry *entry_pointer;
    struct PairType
    {
        struct AST_Node *node_pointer;
        union
        {
            int enum_value;
            enum TYPE *enum_pointer;
        };
    } pair;
    int enum_value;
    enum TYPE *enum_pointer;

#line 234 "build/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_Y_TAB_H_INCLUDED  */
