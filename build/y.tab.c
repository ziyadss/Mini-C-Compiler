/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

    #include <stdio.h>
    
    #include "quadruples.h"
    
    extern int yyerror(char *error);
    
    int yylex();
    int yywrap() { return 1; }

#line 82 "build/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_BOOL = 4,                       /* BOOL  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_DOUBLE = 6,                     /* DOUBLE  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_LONG = 9,                       /* LONG  */
  YYSYMBOL_SHORT = 10,                     /* SHORT  */
  YYSYMBOL_SIGNED = 11,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 12,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_BREAK = 14,                     /* BREAK  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_ENUM = 20,                      /* ENUM  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_SWITCH = 24,                    /* SWITCH  */
  YYSYMBOL_WHILE = 25,                     /* WHILE  */
  YYSYMBOL_COLON = 26,                     /* COLON  */
  YYSYMBOL_COMMA = 27,                     /* COMMA  */
  YYSYMBOL_LBRACE = 28,                    /* LBRACE  */
  YYSYMBOL_LPAREN = 29,                    /* LPAREN  */
  YYSYMBOL_QUESTION = 30,                  /* QUESTION  */
  YYSYMBOL_RBRACE = 31,                    /* RBRACE  */
  YYSYMBOL_RPAREN = 32,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_ADD_ASSIGN = 34,                /* ADD_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 35,                /* AND_ASSIGN  */
  YYSYMBOL_ASSIGN = 36,                    /* ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 37,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 38,                /* MOD_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 39,                /* MUL_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 40,                 /* OR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 41,                /* SHL_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 42,                /* SHR_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 43,                /* SUB_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 44,                /* XOR_ASSIGN  */
  YYSYMBOL_ADD = 45,                       /* ADD  */
  YYSYMBOL_AND = 46,                       /* AND  */
  YYSYMBOL_BIT_AND = 47,                   /* BIT_AND  */
  YYSYMBOL_BIT_NOT = 48,                   /* BIT_NOT  */
  YYSYMBOL_BIT_OR = 49,                    /* BIT_OR  */
  YYSYMBOL_DEC = 50,                       /* DEC  */
  YYSYMBOL_DIV = 51,                       /* DIV  */
  YYSYMBOL_EQ = 52,                        /* EQ  */
  YYSYMBOL_GE = 53,                        /* GE  */
  YYSYMBOL_GT = 54,                        /* GT  */
  YYSYMBOL_INC = 55,                       /* INC  */
  YYSYMBOL_LE = 56,                        /* LE  */
  YYSYMBOL_LT = 57,                        /* LT  */
  YYSYMBOL_MOD = 58,                       /* MOD  */
  YYSYMBOL_MUL = 59,                       /* MUL  */
  YYSYMBOL_NE = 60,                        /* NE  */
  YYSYMBOL_NOT = 61,                       /* NOT  */
  YYSYMBOL_OR = 62,                        /* OR  */
  YYSYMBOL_SHL = 63,                       /* SHL  */
  YYSYMBOL_SHR = 64,                       /* SHR  */
  YYSYMBOL_SUB = 65,                       /* SUB  */
  YYSYMBOL_XOR = 66,                       /* XOR  */
  YYSYMBOL_FALSE = 67,                     /* FALSE  */
  YYSYMBOL_TRUE = 68,                      /* TRUE  */
  YYSYMBOL_INT_LITERAL = 69,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 70,             /* FLOAT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 71,              /* CHAR_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 72,            /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 73,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 74,                  /* $accept  */
  YYSYMBOL_program = 75,                   /* program  */
  YYSYMBOL_top_level_statement = 76,       /* top_level_statement  */
  YYSYMBOL_declaration = 77,               /* declaration  */
  YYSYMBOL_initializer_list = 78,          /* initializer_list  */
  YYSYMBOL_initializer = 79,               /* initializer  */
  YYSYMBOL_parameterized_identifier = 80,  /* parameterized_identifier  */
  YYSYMBOL_function_declaration = 81,      /* function_declaration  */
  YYSYMBOL_function = 82,                  /* function  */
  YYSYMBOL_83_1 = 83,                      /* $@1  */
  YYSYMBOL_84_2 = 84,                      /* $@2  */
  YYSYMBOL_parameter_list = 85,            /* parameter_list  */
  YYSYMBOL_parameter = 86,                 /* parameter  */
  YYSYMBOL_expression = 87,                /* expression  */
  YYSYMBOL_assign_expression = 88,         /* assign_expression  */
  YYSYMBOL_ternary_expression = 89,        /* ternary_expression  */
  YYSYMBOL_or_expression = 90,             /* or_expression  */
  YYSYMBOL_and_expression = 91,            /* and_expression  */
  YYSYMBOL_bit_or_expression = 92,         /* bit_or_expression  */
  YYSYMBOL_xor_expression = 93,            /* xor_expression  */
  YYSYMBOL_bit_and_expression = 94,        /* bit_and_expression  */
  YYSYMBOL_equal_expression = 95,          /* equal_expression  */
  YYSYMBOL_compare_expression = 96,        /* compare_expression  */
  YYSYMBOL_shift_expression = 97,          /* shift_expression  */
  YYSYMBOL_add_expression = 98,            /* add_expression  */
  YYSYMBOL_mul_expression = 99,            /* mul_expression  */
  YYSYMBOL_prefix_expression = 100,        /* prefix_expression  */
  YYSYMBOL_postfix_expression = 101,       /* postfix_expression  */
  YYSYMBOL_base_expression = 102,          /* base_expression  */
  YYSYMBOL_statement = 103,                /* statement  */
  YYSYMBOL_104_3 = 104,                    /* $@3  */
  YYSYMBOL_block_statement = 105,          /* block_statement  */
  YYSYMBOL_block_item_list = 106,          /* block_item_list  */
  YYSYMBOL_selection_statement = 107,      /* selection_statement  */
  YYSYMBOL_switch_case_list = 108,         /* switch_case_list  */
  YYSYMBOL_switch_case = 109,              /* switch_case  */
  YYSYMBOL_iteration_statement = 110,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 111,           /* jump_statement  */
  YYSYMBOL_type_modifier_list = 112,       /* type_modifier_list  */
  YYSYMBOL_type_modifier_items = 113,      /* type_modifier_items  */
  YYSYMBOL_type_modifier = 114,            /* type_modifier  */
  YYSYMBOL_enum_type = 115,                /* enum_type  */
  YYSYMBOL_unary_op = 116,                 /* unary_op  */
  YYSYMBOL_assignment_op = 117,            /* assignment_op  */
  YYSYMBOL_literal = 118                   /* literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   913

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   328


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    71,    72,    76,    77,    81,    82,    86,
      87,    91,    92,    97,   100,   103,   103,   104,   104,   105,
     106,   110,   111,   115,   116,   129,   130,   134,   135,   139,
     140,   144,   145,   149,   150,   154,   155,   159,   160,   164,
     165,   169,   170,   171,   175,   176,   177,   178,   179,   183,
     184,   185,   189,   190,   191,   195,   196,   197,   198,   202,
     203,   207,   208,   209,   210,   211,   215,   216,   217,   223,
     223,   224,   225,   226,   227,   228,   229,   230,   234,   235,
     239,   240,   244,   245,   246,   250,   251,   255,   256,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   276,   277,   278,   279,   285,   286,   289,
     290,   291,   292,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   309,   310,   311,   315,   316,   317,   318,
     319,   320,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   338,   339,   340,   341,   342,   343
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "BOOL",
  "CHAR", "DOUBLE", "FLOAT", "INT", "LONG", "SHORT", "SIGNED", "UNSIGNED",
  "VOID", "BREAK", "CASE", "CONTINUE", "DEFAULT", "DO", "ELSE", "ENUM",
  "FOR", "IF", "RETURN", "SWITCH", "WHILE", "COLON", "COMMA", "LBRACE",
  "LPAREN", "QUESTION", "RBRACE", "RPAREN", "SEMICOLON", "ADD_ASSIGN",
  "AND_ASSIGN", "ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "MUL_ASSIGN",
  "OR_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN", "SUB_ASSIGN", "XOR_ASSIGN",
  "ADD", "AND", "BIT_AND", "BIT_NOT", "BIT_OR", "DEC", "DIV", "EQ", "GE",
  "GT", "INC", "LE", "LT", "MOD", "MUL", "NE", "NOT", "OR", "SHL", "SHR",
  "SUB", "XOR", "FALSE", "TRUE", "INT_LITERAL", "FLOAT_LITERAL",
  "CHAR_LITERAL", "STRING_LITERAL", "IDENTIFIER", "$accept", "program",
  "top_level_statement", "declaration", "initializer_list", "initializer",
  "parameterized_identifier", "function_declaration", "function", "$@1",
  "$@2", "parameter_list", "parameter", "expression", "assign_expression",
  "ternary_expression", "or_expression", "and_expression",
  "bit_or_expression", "xor_expression", "bit_and_expression",
  "equal_expression", "compare_expression", "shift_expression",
  "add_expression", "mul_expression", "prefix_expression",
  "postfix_expression", "base_expression", "statement", "$@3",
  "block_statement", "block_item_list", "selection_statement",
  "switch_case_list", "switch_case", "iteration_statement",
  "jump_statement", "type_modifier_list", "type_modifier_items",
  "type_modifier", "enum_type", "unary_op", "assignment_op", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-245)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     234,   -11,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,   -21,   882,  -245,    27,   307,    44,  -245,
     -64,   380,  -245,  -245,  -245,   -48,   119,  -245,  -245,  -245,
     102,  -245,   -48,  -245,   121,    -8,    59,  -245,  -245,  -245,
      97,    52,   -48,   307,   127,  -245,   349,  -245,   133,   779,
     -48,  -245,    90,  -245,   142,   121,   148,   152,   155,    26,
     163,   172,    55,   174,   193,   779,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
     869,   200,   -14,  -245,  -245,   -19,   204,   206,   183,   205,
     -42,   137,    51,   -41,    50,  -245,    80,  -245,  -245,   121,
     422,  -245,  -245,  -245,   -48,   808,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,   231,   453,   779,  -245,
     -10,   779,   779,   104,   483,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,   779,  -245,   779,  -245,
     779,   808,   808,   808,   808,   808,   808,   808,   808,   808,
     808,   808,   808,   808,   808,   808,   808,   808,   808,  -245,
    -245,  -245,  -245,  -245,   228,  -245,   236,   512,   230,    36,
     105,  -245,   113,   116,  -245,  -245,   126,  -245,  -245,   151,
     204,   206,   183,   205,   -42,   137,   137,    51,    51,    51,
      51,   -41,   -41,    50,    50,  -245,  -245,  -245,   779,   542,
      45,   571,   600,    26,   238,    26,  -245,   808,   128,    26,
     129,   630,   660,    79,   690,    86,   248,    87,  -245,  -245,
     245,  -245,    26,    26,   130,    26,   141,   720,    26,   144,
     750,    26,   808,   243,    58,  -245,  -245,  -245,  -245,    26,
    -245,    26,    26,   147,  -245,    26,    26,   157,  -245,   269,
      26,  -245,  -245,  -245,  -245,  -245,    26,  -245,  -245,    26,
      26,   203,  -245,  -245,   276
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     3,     0,     0,    17,     6,
       8,   108,   111,   107,     4,     0,   125,     1,     2,     5,
       0,    22,    24,    20,     0,    12,     7,    10,   110,   109,
      12,     0,     0,     0,    15,    23,     0,    18,    13,     0,
       0,   124,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    76,   128,   131,
     127,   126,   130,   129,   143,   144,   145,   146,   147,   148,
      66,     0,     0,    26,    28,    30,    32,    34,    36,    38,
      40,    43,    48,    51,    54,    58,    60,    65,    81,     0,
       0,    71,    72,    73,     8,     0,    67,    14,    11,     9,
     123,    19,    16,    77,   104,   103,     0,     0,     0,   105,
       0,     0,     0,     0,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,    75,     0,    74,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      61,    70,    78,    80,    66,    59,     0,     0,     0,     0,
       0,   106,     0,     0,    68,    64,     0,    27,    25,     0,
      31,    33,    35,    37,    39,    41,    42,    47,    45,    46,
      44,    49,    50,    52,    53,    56,    57,    55,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,     0,    89,    29,
       0,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    90,   101,   100,     0,
      98,     0,     0,     0,    94,     0,     0,     0,    83,     0,
       0,    84,    85,    99,    97,    96,     0,    93,    92,     0,
       0,     0,    95,    91,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -245,  -245,   288,     1,    28,   -24,  -245,  -245,  -245,  -245,
    -245,  -245,   260,   -60,   -46,  -187,  -245,   165,   166,   179,
     181,   178,    49,   111,    46,    75,   -91,  -245,  -245,   -59,
    -245,   -43,  -244,  -245,  -245,    94,  -245,  -245,    68,  -245,
     308,  -245,  -245,  -245,  -245
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    14,    15,    81,    36,    37,    17,    18,    19,    55,
      34,    30,    31,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,    47,   100,   101,   234,   235,   102,   103,   104,    21,
      22,    23,   105,   136,   106
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,    16,   120,   108,   154,   123,   261,    25,    45,    35,
     146,   140,   112,   138,   165,    16,   264,   138,   147,   139,
     219,    48,    24,   171,   155,    40,   109,    56,    49,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      57,   163,    58,   141,    59,   249,    13,    60,    61,    62,
      63,    64,    26,    41,   -69,    65,   161,   169,   170,    67,
      29,   172,   173,   138,   176,   195,   196,   197,    20,   202,
      52,    68,   138,   232,    69,   233,    70,    33,   211,    50,
     179,    71,    20,    51,    65,    32,    50,    72,   119,   251,
     177,    73,   178,    74,    75,    76,    77,    78,    79,    80,
      68,   156,   232,    69,   233,    70,   138,   200,   157,   158,
      71,    32,   227,   138,   152,   153,    72,    50,   168,   230,
      73,   110,    74,    75,    76,    77,    78,    79,    80,    43,
     159,   138,   138,    49,    44,   160,   174,   203,   208,   210,
     138,   213,   215,   138,   216,   204,   218,    42,   205,    46,
     221,   224,   226,   138,   229,   138,   138,   138,   206,    54,
     220,   222,   239,   237,   238,   107,   240,   243,   138,   244,
     247,   138,   248,   241,   138,   111,   245,   207,   138,   256,
     253,   113,   254,   255,   138,   114,   257,   258,   115,   259,
     148,   149,   117,   150,   151,   185,   186,   262,   191,   192,
     263,   118,   163,   121,    56,   163,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    57,   -88,    58,
     -88,    59,   122,    13,    60,    61,    62,    63,    64,   193,
     194,   -69,    65,   137,   -88,     1,    67,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    68,   144,
     142,    69,   145,    70,    13,   143,   166,   124,    71,   187,
     188,   189,   190,   201,    72,   198,   217,   231,    73,   250,
      74,    75,    76,    77,    78,    79,    80,    56,   236,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      57,   -87,    58,   -87,    59,   260,    13,    60,    61,    62,
      63,    64,    28,    53,   -69,    65,   180,   -87,   181,    67,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    68,   182,   184,    69,   183,    70,    13,   252,    39,
       0,    71,     0,     0,     0,     0,     0,    72,     0,     0,
       0,    73,     0,    74,    75,    76,    77,    78,    79,    80,
      56,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    57,     0,    58,     0,    59,     0,    13,
      60,    61,    62,    63,    64,     0,     0,   -69,    65,     0,
      66,     0,    67,    38,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    68,     0,     0,    69,     0,    70,
       0,     0,     0,     0,    71,     0,     0,     0,     0,     0,
      72,     0,     0,     0,    73,     0,    74,    75,    76,    77,
      78,    79,    80,    56,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    57,     0,    58,     0,
      59,     0,    13,    60,    61,    62,    63,    64,     0,     0,
     -69,    65,     0,   162,     0,    67,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    68,     0,     0,
      69,     0,    70,    13,     0,     0,     0,    71,     0,     0,
       0,     0,    65,    72,     0,     0,   167,    73,     0,    74,
      75,    76,    77,    78,    79,    80,     0,     0,    68,     0,
       0,    69,     0,    70,     0,     0,     0,     0,    71,     0,
       0,     0,    65,     0,    72,   175,     0,     0,    73,     0,
      74,    75,    76,    77,    78,    79,    80,     0,    68,     0,
       0,    69,     0,    70,     0,     0,     0,     0,    71,     0,
       0,    65,     0,     0,    72,   199,     0,     0,    73,     0,
      74,    75,    76,    77,    78,    79,    80,    68,     0,     0,
      69,     0,    70,     0,     0,     0,     0,    71,     0,     0,
       0,    65,     0,    72,   209,     0,     0,    73,     0,    74,
      75,    76,    77,    78,    79,    80,     0,    68,     0,     0,
      69,     0,    70,     0,     0,     0,     0,    71,     0,     0,
      65,     0,     0,    72,   212,     0,     0,    73,     0,    74,
      75,    76,    77,    78,    79,    80,    68,     0,     0,    69,
       0,    70,     0,     0,     0,     0,    71,     0,     0,    65,
       0,     0,    72,   214,     0,     0,    73,     0,    74,    75,
      76,    77,    78,    79,    80,    68,     0,     0,    69,     0,
      70,     0,     0,     0,     0,    71,     0,     0,     0,    65,
       0,    72,   223,     0,     0,    73,     0,    74,    75,    76,
      77,    78,    79,    80,     0,    68,     0,     0,    69,     0,
      70,     0,     0,     0,     0,    71,     0,     0,     0,    65,
       0,    72,   225,     0,     0,    73,     0,    74,    75,    76,
      77,    78,    79,    80,     0,    68,     0,     0,    69,     0,
      70,     0,     0,     0,     0,    71,     0,     0,     0,    65,
       0,    72,   228,     0,     0,    73,     0,    74,    75,    76,
      77,    78,    79,    80,     0,    68,     0,     0,    69,     0,
      70,     0,     0,     0,     0,    71,     0,     0,     0,    65,
       0,    72,   242,     0,     0,    73,     0,    74,    75,    76,
      77,    78,    79,    80,     0,    68,     0,     0,    69,     0,
      70,     0,     0,     0,     0,    71,     0,     0,     0,    65,
       0,    72,   246,     0,     0,    73,     0,    74,    75,    76,
      77,    78,    79,    80,     0,    68,     0,     0,    69,     0,
      70,     0,     0,     0,     0,    71,     0,     0,    65,     0,
       0,    72,     0,     0,     0,    73,     0,    74,    75,    76,
      77,    78,    79,    80,    68,     0,     0,    69,     0,    70,
       0,     0,     0,     0,    71,     0,     0,    65,     0,     0,
      72,     0,     0,     0,    73,     0,    74,    75,    76,    77,
      78,    79,    80,    68,     0,     0,    69,     0,    70,     0,
       0,     0,     0,    71,     0,     0,     0,     0,     0,    72,
       0,     0,     0,    73,     0,    74,    75,    76,    77,    78,
      79,   164,    27,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,     0,   124,     0,
       0,     0,    13,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135
};

static const yytype_int16 yycheck[] =
{
      59,     0,    62,    49,    45,    65,   250,    28,    32,    73,
      52,    30,    55,    27,   105,    14,   260,    27,    60,    33,
     207,    29,    33,    33,    65,    73,    50,     1,    36,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,   100,    16,    62,    18,   232,    20,    21,    22,    23,
      24,    25,    73,    25,    28,    29,    99,   117,   118,    33,
      33,   121,   122,    27,   124,   156,   157,   158,     0,    33,
      42,    45,    27,    15,    48,    17,    50,    33,    33,    27,
     140,    55,    14,    31,    29,    17,    27,    61,    33,    31,
     136,    65,   138,    67,    68,    69,    70,    71,    72,    73,
      45,    51,    15,    48,    17,    50,    27,   167,    58,    59,
      55,    43,    33,    27,    63,    64,    61,    27,   117,    33,
      65,    31,    67,    68,    69,    70,    71,    72,    73,    27,
      50,    27,    27,    36,    32,    55,    32,    32,   198,   199,
      27,   201,   202,    27,   203,    32,   205,    28,    32,    28,
     209,   211,   212,    27,   214,    27,    27,    27,    32,    32,
      32,    32,    32,   222,   223,    32,   225,   227,    27,   228,
     230,    27,   231,    32,    27,    33,    32,    26,    27,    32,
     239,    33,   241,   242,    27,    33,   245,   246,    33,    32,
      53,    54,    29,    56,    57,   146,   147,   256,   152,   153,
     259,    29,   261,    29,     1,   264,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    29,    20,    21,    22,    23,    24,    25,   154,
     155,    28,    29,    33,    31,     1,    33,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    45,    66,
      46,    48,    47,    50,    20,    49,    25,    29,    55,   148,
     149,   150,   151,    33,    61,    29,    28,    19,    65,    26,
      67,    68,    69,    70,    71,    72,    73,     1,    33,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    26,    20,    21,    22,    23,
      24,    25,    14,    43,    28,    29,   141,    31,   142,    33,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    45,   143,   145,    48,   144,    50,    20,   234,    21,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    65,    -1,    67,    68,    69,    70,    71,    72,    73,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    18,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    -1,
      31,    -1,    33,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    45,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      18,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    -1,    31,    -1,    33,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    45,    -1,    -1,
      48,    -1,    50,    20,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    29,    61,    -1,    -1,    33,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    -1,    -1,    45,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    29,    -1,    61,    32,    -1,    -1,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    45,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    29,    -1,    -1,    61,    33,    -1,    -1,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    45,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    29,    -1,    61,    32,    -1,    -1,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    -1,    45,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      29,    -1,    -1,    61,    33,    -1,    -1,    65,    -1,    67,
      68,    69,    70,    71,    72,    73,    45,    -1,    -1,    48,
      -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    29,
      -1,    -1,    61,    33,    -1,    -1,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    45,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    29,
      -1,    61,    32,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    -1,    45,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    29,
      -1,    61,    32,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    -1,    45,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    29,
      -1,    61,    32,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    -1,    45,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    29,
      -1,    61,    32,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    -1,    45,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    29,
      -1,    61,    32,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    -1,    45,    -1,    -1,    48,    -1,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    29,    -1,
      -1,    61,    -1,    -1,    -1,    65,    -1,    67,    68,    69,
      70,    71,    72,    73,    45,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    29,    -1,    -1,
      61,    -1,    -1,    -1,    65,    -1,    67,    68,    69,    70,
      71,    72,    73,    45,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,     0,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    29,    -1,
      -1,    -1,    20,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    20,    75,    76,    77,    80,    81,    82,
     112,   113,   114,   115,    33,    28,    73,     0,    76,    33,
      85,    86,   112,    33,    84,    73,    78,    79,     3,   114,
      73,    78,    28,    27,    32,    79,    28,   105,    29,    36,
      27,    31,    78,    86,    32,    83,     1,    14,    16,    18,
      21,    22,    23,    24,    25,    29,    31,    33,    45,    48,
      50,    55,    61,    65,    67,    68,    69,    70,    71,    72,
      73,    77,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     106,   107,   110,   111,   112,   116,   118,    32,    88,    79,
      31,    33,   105,    33,    33,    33,   103,    29,    29,    33,
      87,    29,    29,    87,    29,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,   117,    33,    27,    33,
      30,    62,    46,    49,    66,    47,    52,    60,    53,    54,
      56,    57,    63,    64,    45,    65,    51,    58,    59,    50,
      55,   105,    31,   103,    73,   100,    25,    33,    77,    87,
      87,    33,    87,    87,    32,    32,    87,    88,    88,    87,
      91,    92,    93,    94,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    99,    99,   100,   100,   100,    29,    33,
      87,    33,    33,    32,    32,    32,    32,    26,    87,    32,
      87,    33,    33,    87,    33,    87,   103,    28,   103,    89,
      32,   103,    32,    32,    87,    32,    87,    33,    32,    87,
      33,    19,    15,    17,   108,   109,    33,   103,   103,    32,
     103,    32,    32,    87,   103,    32,    32,    87,   103,    89,
      26,    31,   109,   103,   103,   103,    32,   103,   103,    32,
      26,   106,   103,   103,   106
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    74,    75,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    81,    83,    82,    84,    82,    82,
      82,    85,    85,    86,    86,    87,    87,    88,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    95,    96,    96,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    99,    99,    99,    99,   100,
     100,   101,   101,   101,   101,   101,   102,   102,   102,   104,
     103,   103,   103,   103,   103,   103,   103,   103,   105,   105,
     106,   106,   107,   107,   107,   108,   108,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   111,   111,   112,   112,   113,
     113,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   115,   116,   116,   116,   116,
     116,   116,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   118,   118,   118,   118,   118,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     1,     2,     1,     3,
       1,     3,     1,     3,     4,     0,     5,     0,     3,     5,
       2,     3,     1,     2,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       1,     2,     2,     4,     3,     1,     1,     1,     3,     0,
       2,     1,     1,     1,     2,     2,     1,     2,     3,     2,
       2,     1,     5,     7,     7,     2,     1,     4,     3,     5,
       7,     9,     8,     8,     7,     9,     8,     8,     7,     8,
       7,     7,     6,     2,     2,     2,     3,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: program top_level_statement  */
#line 70 "src/parser.y"
                                                                    { program_append((yyvsp[0].node_pointer)); }
#line 1511 "build/y.tab.c"
    break;

  case 3: /* program: top_level_statement  */
#line 71 "src/parser.y"
                                                                    { program_append((yyvsp[0].node_pointer)); }
#line 1517 "build/y.tab.c"
    break;

  case 4: /* program: error SEMICOLON  */
#line 72 "src/parser.y"
                                                                    { yyerror("Invalid top level statement."); }
#line 1523 "build/y.tab.c"
    break;

  case 7: /* declaration: type_modifier_list initializer_list  */
#line 81 "src/parser.y"
                                                                    { struct AST_Node *tmp = change_list_params((yyvsp[0].node_pointer), (yyvsp[-1].pair).enum_pointer, 0); if (tmp==NULL) YYERROR; else (yyval.node_pointer) = (yyvsp[-1].pair).node_pointer == NULL ? tmp : operation_node(COMMA_OP, (yyvsp[-1].pair).node_pointer, tmp); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1529 "build/y.tab.c"
    break;

  case 8: /* declaration: type_modifier_list  */
#line 82 "src/parser.y"
                                                                    { (yyval.node_pointer) = (yyvsp[0].pair).node_pointer; }
#line 1535 "build/y.tab.c"
    break;

  case 9: /* initializer_list: initializer_list COMMA initializer  */
#line 86 "src/parser.y"
                                                                    { (yyval.node_pointer) = operation_node(COMMA_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1541 "build/y.tab.c"
    break;

  case 11: /* initializer: IDENTIFIER ASSIGN assign_expression  */
#line 91 "src/parser.y"
                                                                    { struct SymbolTableEntry* symbol = insert((yyvsp[-2].string_value), 0, 1, 0, 0); if (symbol==NULL) YYERROR; else (yyval.node_pointer) = operation_node(ASSIGN_OP, identifier_node(symbol), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1547 "build/y.tab.c"
    break;

  case 12: /* initializer: IDENTIFIER  */
#line 92 "src/parser.y"
                                                                    { struct SymbolTableEntry* symbol = insert((yyvsp[0].string_value), 0, 0, 0, 0); if (symbol==NULL) YYERROR; else (yyval.node_pointer) = identifier_node(symbol); }
#line 1553 "build/y.tab.c"
    break;

  case 13: /* parameterized_identifier: type_modifier_list IDENTIFIER LPAREN  */
#line 97 "src/parser.y"
                                                                        { struct SymbolTableEntry* symbol = insert((yyvsp[-1].string_value), 1, 0, 1, 0); if (symbol == NULL) YYERROR; else (yyval.entry_pointer) = symbol; scope_down();  }
#line 1559 "build/y.tab.c"
    break;

  case 14: /* function_declaration: type_modifier_list IDENTIFIER LPAREN RPAREN  */
#line 100 "src/parser.y"
                                                                        { struct SymbolTableEntry* symbol = insert((yyvsp[-2].string_value), 1, 0, 1, 0); if (symbol == NULL) YYERROR; else (yyval.entry_pointer) = symbol; }
#line 1565 "build/y.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 103 "src/parser.y"
                                                                         { def_func((yyvsp[-2].entry_pointer)); }
#line 1571 "build/y.tab.c"
    break;

  case 16: /* function: parameterized_identifier parameter_list RPAREN $@1 block_statement  */
#line 103 "src/parser.y"
                                                                                                            { scope_up(); (yyval.node_pointer) = function_node((yyvsp[-4].entry_pointer), (yyvsp[-3].node_pointer), (yyvsp[0].node_pointer)); }
#line 1577 "build/y.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 104 "src/parser.y"
                                               { scope_down(); def_func((yyvsp[0].entry_pointer)); }
#line 1583 "build/y.tab.c"
    break;

  case 18: /* function: function_declaration $@2 block_statement  */
#line 104 "src/parser.y"
                                                                                                            { scope_up(); (yyval.node_pointer) = function_node((yyvsp[-2].entry_pointer), NULL, (yyvsp[0].node_pointer)); }
#line 1589 "build/y.tab.c"
    break;

  case 19: /* function: parameterized_identifier parameter_list RPAREN RPAREN SEMICOLON  */
#line 105 "src/parser.y"
                                                                                                            { scope_up(); (yyval.node_pointer) = function_node((yyvsp[-4].entry_pointer), (yyvsp[-3].node_pointer), NULL); }
#line 1595 "build/y.tab.c"
    break;

  case 20: /* function: function_declaration SEMICOLON  */
#line 106 "src/parser.y"
                                                                                                            {             (yyval.node_pointer) = function_node((yyvsp[-1].entry_pointer), NULL, NULL); }
#line 1601 "build/y.tab.c"
    break;

  case 21: /* parameter_list: parameter_list COMMA parameter  */
#line 110 "src/parser.y"
                                                                                            { (yyval.node_pointer) = operation_node(COMMA_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1607 "build/y.tab.c"
    break;

  case 23: /* parameter: type_modifier_list initializer  */
#line 115 "src/parser.y"
                                                                                            { struct AST_Node *identifiers = change_list_params((yyvsp[0].node_pointer), (yyvsp[-1].pair).enum_pointer, 1); if (identifiers==NULL) YYERROR; else (yyval.node_pointer) = identifiers;}
#line 1613 "build/y.tab.c"
    break;

  case 24: /* parameter: type_modifier_list  */
#line 116 "src/parser.y"
                                                                                            { (yyval.node_pointer) = NULL; }
#line 1619 "build/y.tab.c"
    break;

  case 25: /* expression: expression COMMA assign_expression  */
#line 129 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(COMMA_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1625 "build/y.tab.c"
    break;

  case 27: /* assign_expression: IDENTIFIER assignment_op assign_expression  */
#line 134 "src/parser.y"
                                                                        { struct SymbolTableEntry* symbol = lookup((yyvsp[-2].string_value), 0, (yyvsp[-1].enum_value)!=ASSIGN_OP, (yyvsp[-1].enum_value)==ASSIGN_OP); if (symbol == NULL) YYERROR; else (yyval.node_pointer) = operation_node((yyvsp[-1].enum_value), identifier_node(symbol), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1631 "build/y.tab.c"
    break;

  case 29: /* ternary_expression: or_expression QUESTION expression COLON ternary_expression  */
#line 139 "src/parser.y"
                                                                                        { (yyval.node_pointer) = if_node((yyvsp[-4].node_pointer), (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); }
#line 1637 "build/y.tab.c"
    break;

  case 31: /* or_expression: or_expression OR and_expression  */
#line 144 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(OR_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1643 "build/y.tab.c"
    break;

  case 33: /* and_expression: and_expression AND bit_or_expression  */
#line 149 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(AND_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1649 "build/y.tab.c"
    break;

  case 35: /* bit_or_expression: bit_or_expression BIT_OR xor_expression  */
#line 154 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(BIT_OR_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1655 "build/y.tab.c"
    break;

  case 37: /* xor_expression: xor_expression XOR bit_and_expression  */
#line 159 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(XOR_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1661 "build/y.tab.c"
    break;

  case 39: /* bit_and_expression: bit_and_expression BIT_AND equal_expression  */
#line 164 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(BIT_AND_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1667 "build/y.tab.c"
    break;

  case 41: /* equal_expression: equal_expression EQ compare_expression  */
#line 169 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(EQ_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1673 "build/y.tab.c"
    break;

  case 42: /* equal_expression: equal_expression NE compare_expression  */
#line 170 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(NE_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1679 "build/y.tab.c"
    break;

  case 44: /* compare_expression: compare_expression LT shift_expression  */
#line 175 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(LT_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1685 "build/y.tab.c"
    break;

  case 45: /* compare_expression: compare_expression GT shift_expression  */
#line 176 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(GT_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1691 "build/y.tab.c"
    break;

  case 46: /* compare_expression: compare_expression LE shift_expression  */
#line 177 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(LE_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1697 "build/y.tab.c"
    break;

  case 47: /* compare_expression: compare_expression GE shift_expression  */
#line 178 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(GE_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1703 "build/y.tab.c"
    break;

  case 49: /* shift_expression: shift_expression SHL add_expression  */
#line 183 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(SHL_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1709 "build/y.tab.c"
    break;

  case 50: /* shift_expression: shift_expression SHR add_expression  */
#line 184 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(SHR_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1715 "build/y.tab.c"
    break;

  case 52: /* add_expression: add_expression ADD mul_expression  */
#line 189 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(ADD_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1721 "build/y.tab.c"
    break;

  case 53: /* add_expression: add_expression SUB mul_expression  */
#line 190 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(SUB_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1727 "build/y.tab.c"
    break;

  case 55: /* mul_expression: mul_expression MUL prefix_expression  */
#line 195 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(MUL_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1733 "build/y.tab.c"
    break;

  case 56: /* mul_expression: mul_expression DIV prefix_expression  */
#line 196 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(DIV_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1739 "build/y.tab.c"
    break;

  case 57: /* mul_expression: mul_expression MOD prefix_expression  */
#line 197 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(MOD_OP, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1745 "build/y.tab.c"
    break;

  case 59: /* prefix_expression: unary_op prefix_expression  */
#line 202 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node((yyvsp[-1].enum_value), NULL, (yyvsp[0].node_pointer)); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1751 "build/y.tab.c"
    break;

  case 61: /* postfix_expression: postfix_expression INC  */
#line 207 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(INC_OP, (yyvsp[-1].node_pointer), NULL); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1757 "build/y.tab.c"
    break;

  case 62: /* postfix_expression: postfix_expression DEC  */
#line 208 "src/parser.y"
                                                                        { (yyval.node_pointer) = operation_node(DEC_OP, (yyvsp[-1].node_pointer), NULL); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1763 "build/y.tab.c"
    break;

  case 63: /* postfix_expression: IDENTIFIER LPAREN expression RPAREN  */
#line 209 "src/parser.y"
                                                                        { struct SymbolTableEntry* symbol = lookup((yyvsp[-3].string_value), 1, 1, 0); if (symbol == NULL) YYERROR; else (yyval.node_pointer) = call_node(identifier_node(symbol), (yyvsp[-1].node_pointer)); }
#line 1769 "build/y.tab.c"
    break;

  case 64: /* postfix_expression: IDENTIFIER LPAREN RPAREN  */
#line 210 "src/parser.y"
                                                                        { struct SymbolTableEntry* symbol = lookup((yyvsp[-2].string_value), 1, 1, 0); if (symbol == NULL) YYERROR; else (yyval.node_pointer) = call_node(identifier_node(symbol), NULL); }
#line 1775 "build/y.tab.c"
    break;

  case 66: /* base_expression: IDENTIFIER  */
#line 215 "src/parser.y"
                                                                        { struct SymbolTableEntry* symbol = lookup((yyvsp[0].string_value), 0, 1, 0); if (symbol == NULL) YYERROR; else (yyval.node_pointer) = identifier_node(symbol); }
#line 1781 "build/y.tab.c"
    break;

  case 68: /* base_expression: LPAREN expression RPAREN  */
#line 217 "src/parser.y"
                                                                        { (yyval.node_pointer) = (yyvsp[-1].node_pointer); }
#line 1787 "build/y.tab.c"
    break;

  case 69: /* $@3: %empty  */
#line 223 "src/parser.y"
                          { scope_down(); }
#line 1793 "build/y.tab.c"
    break;

  case 70: /* statement: $@3 block_statement  */
#line 223 "src/parser.y"
                                                            { scope_up(); (yyval.node_pointer) = (yyvsp[0].node_pointer); }
#line 1799 "build/y.tab.c"
    break;

  case 76: /* statement: SEMICOLON  */
#line 229 "src/parser.y"
                                                            { (yyval.node_pointer) = NULL; }
#line 1805 "build/y.tab.c"
    break;

  case 77: /* statement: error SEMICOLON  */
#line 230 "src/parser.y"
                                                            { (yyval.node_pointer) = NULL; yyerror("Invalid statement"); }
#line 1811 "build/y.tab.c"
    break;

  case 78: /* block_statement: LBRACE block_item_list RBRACE  */
#line 234 "src/parser.y"
                                                                { (yyval.node_pointer) = (yyvsp[-1].node_pointer); }
#line 1817 "build/y.tab.c"
    break;

  case 79: /* block_statement: LBRACE RBRACE  */
#line 235 "src/parser.y"
                                                                { (yyval.node_pointer) = NULL; }
#line 1823 "build/y.tab.c"
    break;

  case 80: /* block_item_list: block_item_list statement  */
#line 239 "src/parser.y"
                                                                { (yyval.node_pointer) = add_statement((yyvsp[-1].node_pointer), (yyvsp[0].node_pointer)); }
#line 1829 "build/y.tab.c"
    break;

  case 81: /* block_item_list: statement  */
#line 240 "src/parser.y"
                                                                { (yyval.node_pointer) = block_node((yyvsp[0].node_pointer)); }
#line 1835 "build/y.tab.c"
    break;

  case 82: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 244 "src/parser.y"
                                                                                            { (yyval.node_pointer) = if_node((yyvsp[-2].node_pointer), (yyvsp[0].node_pointer), NULL); }
#line 1841 "build/y.tab.c"
    break;

  case 83: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 245 "src/parser.y"
                                                                                            { (yyval.node_pointer) = if_node((yyvsp[-4].node_pointer), (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); }
#line 1847 "build/y.tab.c"
    break;

  case 84: /* selection_statement: SWITCH LPAREN expression RPAREN LBRACE switch_case_list RBRACE  */
#line 246 "src/parser.y"
                                                                                            { (yyval.node_pointer) = switch_node((yyvsp[-4].node_pointer), (yyvsp[-1].node_pointer)); }
#line 1853 "build/y.tab.c"
    break;

  case 85: /* switch_case_list: switch_case_list switch_case  */
#line 250 "src/parser.y"
                                                                                { (yyval.node_pointer) = add_statement((yyvsp[-1].node_pointer), (yyvsp[0].node_pointer)); }
#line 1859 "build/y.tab.c"
    break;

  case 86: /* switch_case_list: switch_case  */
#line 251 "src/parser.y"
                                                                                { (yyval.node_pointer) = block_node((yyvsp[0].node_pointer)); }
#line 1865 "build/y.tab.c"
    break;

  case 87: /* switch_case: CASE ternary_expression COLON block_item_list  */
#line 255 "src/parser.y"
                                                                                { struct AST_Node* tmp = operation_node(EQ_OP, NULL, (yyvsp[-2].node_pointer)); if (tmp==NULL) YYERROR; else (yyval.node_pointer) = if_node(tmp, (yyvsp[0].node_pointer), NULL); }
#line 1871 "build/y.tab.c"
    break;

  case 88: /* switch_case: DEFAULT COLON block_item_list  */
#line 256 "src/parser.y"
                                                                                { (yyval.node_pointer) = (yyvsp[0].node_pointer); }
#line 1877 "build/y.tab.c"
    break;

  case 89: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 259 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = while_node((yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); }
#line 1883 "build/y.tab.c"
    break;

  case 90: /* iteration_statement: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 260 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = do_while_node((yyvsp[-2].node_pointer), (yyvsp[-5].node_pointer)); }
#line 1889 "build/y.tab.c"
    break;

  case 91: /* iteration_statement: FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement  */
#line 261 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node((yyvsp[-6].node_pointer), (yyvsp[-4].node_pointer), (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); }
#line 1895 "build/y.tab.c"
    break;

  case 92: /* iteration_statement: FOR LPAREN expression SEMICOLON expression SEMICOLON RPAREN statement  */
#line 262 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node((yyvsp[-5].node_pointer), (yyvsp[-3].node_pointer), NULL, (yyvsp[0].node_pointer)); }
#line 1901 "build/y.tab.c"
    break;

  case 93: /* iteration_statement: FOR LPAREN expression SEMICOLON SEMICOLON expression RPAREN statement  */
#line 263 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node((yyvsp[-5].node_pointer), NULL, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); }
#line 1907 "build/y.tab.c"
    break;

  case 94: /* iteration_statement: FOR LPAREN expression SEMICOLON SEMICOLON RPAREN statement  */
#line 264 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node((yyvsp[-4].node_pointer), NULL, NULL, (yyvsp[0].node_pointer)); }
#line 1913 "build/y.tab.c"
    break;

  case 95: /* iteration_statement: FOR LPAREN declaration SEMICOLON expression SEMICOLON expression RPAREN statement  */
#line 265 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node((yyvsp[-6].node_pointer), (yyvsp[-4].node_pointer), (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); }
#line 1919 "build/y.tab.c"
    break;

  case 96: /* iteration_statement: FOR LPAREN declaration SEMICOLON expression SEMICOLON RPAREN statement  */
#line 266 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node((yyvsp[-5].node_pointer), (yyvsp[-3].node_pointer), NULL, (yyvsp[0].node_pointer)); }
#line 1925 "build/y.tab.c"
    break;

  case 97: /* iteration_statement: FOR LPAREN declaration SEMICOLON SEMICOLON expression RPAREN statement  */
#line 267 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node((yyvsp[-5].node_pointer), NULL, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); }
#line 1931 "build/y.tab.c"
    break;

  case 98: /* iteration_statement: FOR LPAREN declaration SEMICOLON SEMICOLON RPAREN statement  */
#line 268 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node((yyvsp[-4].node_pointer), NULL, NULL, (yyvsp[0].node_pointer)); }
#line 1937 "build/y.tab.c"
    break;

  case 99: /* iteration_statement: FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement  */
#line 269 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node(NULL, (yyvsp[-4].node_pointer), (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); }
#line 1943 "build/y.tab.c"
    break;

  case 100: /* iteration_statement: FOR LPAREN SEMICOLON expression SEMICOLON RPAREN statement  */
#line 270 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node(NULL, (yyvsp[-3].node_pointer), NULL, (yyvsp[0].node_pointer)); }
#line 1949 "build/y.tab.c"
    break;

  case 101: /* iteration_statement: FOR LPAREN SEMICOLON SEMICOLON expression RPAREN statement  */
#line 271 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node(NULL, NULL, (yyvsp[-2].node_pointer), (yyvsp[0].node_pointer)); }
#line 1955 "build/y.tab.c"
    break;

  case 102: /* iteration_statement: FOR LPAREN SEMICOLON SEMICOLON RPAREN statement  */
#line 272 "src/parser.y"
                                                                                                            { (yyval.node_pointer) = for_node(NULL, NULL, NULL, (yyvsp[0].node_pointer)); }
#line 1961 "build/y.tab.c"
    break;

  case 103: /* jump_statement: CONTINUE SEMICOLON  */
#line 276 "src/parser.y"
                                                                            { (yyval.node_pointer) = continue_node(); }
#line 1967 "build/y.tab.c"
    break;

  case 104: /* jump_statement: BREAK SEMICOLON  */
#line 277 "src/parser.y"
                                                                            { (yyval.node_pointer) = break_node(); }
#line 1973 "build/y.tab.c"
    break;

  case 105: /* jump_statement: RETURN SEMICOLON  */
#line 278 "src/parser.y"
                                                                            { (yyval.node_pointer) = operation_node(RET_OP, NULL, NULL); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1979 "build/y.tab.c"
    break;

  case 106: /* jump_statement: RETURN expression SEMICOLON  */
#line 279 "src/parser.y"
                                                                   { (yyval.node_pointer) = operation_node(RET_OP, (yyvsp[-1].node_pointer), NULL); if ((yyval.node_pointer) == NULL) YYERROR; }
#line 1985 "build/y.tab.c"
    break;

  case 107: /* type_modifier_list: enum_type  */
#line 285 "src/parser.y"
                                                            { struct PairType tmp = { .node_pointer = (yyvsp[0].node_pointer),   .enum_pointer = insert_into_array(NULL, ENUM_TYPE) }; (yyval.pair) = tmp; }
#line 1991 "build/y.tab.c"
    break;

  case 108: /* type_modifier_list: type_modifier_items  */
#line 286 "src/parser.y"
                                                            { struct PairType tmp = { .node_pointer = NULL, .enum_pointer = (yyvsp[0].enum_pointer) }; (yyval.pair) = tmp; }
#line 1997 "build/y.tab.c"
    break;

  case 109: /* type_modifier_items: type_modifier_items type_modifier  */
#line 289 "src/parser.y"
                                                            { (yyval.enum_pointer) = insert_into_array((yyvsp[-1].enum_pointer), (yyvsp[0].enum_value)); }
#line 2003 "build/y.tab.c"
    break;

  case 110: /* type_modifier_items: type_modifier_items CONST  */
#line 290 "src/parser.y"
                                                            { (yyval.enum_pointer) = insert_into_array((yyvsp[-1].enum_pointer), CONST_TYPE); }
#line 2009 "build/y.tab.c"
    break;

  case 111: /* type_modifier_items: type_modifier  */
#line 291 "src/parser.y"
                                                            { (yyval.enum_pointer) = insert_into_array(NULL, (yyvsp[0].enum_value)); }
#line 2015 "build/y.tab.c"
    break;

  case 112: /* type_modifier_items: CONST  */
#line 292 "src/parser.y"
                                                            { (yyval.enum_pointer) = insert_into_array(NULL, CONST_TYPE); }
#line 2021 "build/y.tab.c"
    break;

  case 113: /* type_modifier: BOOL  */
#line 296 "src/parser.y"
                                                { (yyval.enum_value) = BOOL_TYPE; }
#line 2027 "build/y.tab.c"
    break;

  case 114: /* type_modifier: CHAR  */
#line 297 "src/parser.y"
                                                { (yyval.enum_value) = CHAR_TYPE; }
#line 2033 "build/y.tab.c"
    break;

  case 115: /* type_modifier: DOUBLE  */
#line 298 "src/parser.y"
                                                { (yyval.enum_value) = DOUBLE_TYPE; }
#line 2039 "build/y.tab.c"
    break;

  case 116: /* type_modifier: FLOAT  */
#line 299 "src/parser.y"
                                                { (yyval.enum_value) = FLOAT_TYPE; }
#line 2045 "build/y.tab.c"
    break;

  case 117: /* type_modifier: INT  */
#line 300 "src/parser.y"
                                                { (yyval.enum_value) = INT_TYPE; }
#line 2051 "build/y.tab.c"
    break;

  case 118: /* type_modifier: LONG  */
#line 301 "src/parser.y"
                                                { (yyval.enum_value) = LONG_TYPE; }
#line 2057 "build/y.tab.c"
    break;

  case 119: /* type_modifier: SHORT  */
#line 302 "src/parser.y"
                                                { (yyval.enum_value) = SHORT_TYPE; }
#line 2063 "build/y.tab.c"
    break;

  case 120: /* type_modifier: SIGNED  */
#line 303 "src/parser.y"
                                                { (yyval.enum_value) = SIGNED_TYPE; }
#line 2069 "build/y.tab.c"
    break;

  case 121: /* type_modifier: UNSIGNED  */
#line 304 "src/parser.y"
                                                { (yyval.enum_value) = UNSIGNED_TYPE; }
#line 2075 "build/y.tab.c"
    break;

  case 122: /* type_modifier: VOID  */
#line 305 "src/parser.y"
                                                { (yyval.enum_value) = VOID_TYPE; }
#line 2081 "build/y.tab.c"
    break;

  case 123: /* enum_type: ENUM IDENTIFIER LBRACE initializer_list RBRACE  */
#line 309 "src/parser.y"
                                                                            { struct SymbolTableEntry* symbol = insert((yyvsp[-3].string_value), 1, 1, 0, 0); if (symbol==NULL) YYERROR; else (yyval.node_pointer) = (yyvsp[-1].node_pointer); }
#line 2087 "build/y.tab.c"
    break;

  case 124: /* enum_type: ENUM LBRACE initializer_list RBRACE  */
#line 310 "src/parser.y"
                                                                            { (yyval.node_pointer) = (yyvsp[-1].node_pointer); }
#line 2093 "build/y.tab.c"
    break;

  case 125: /* enum_type: ENUM IDENTIFIER  */
#line 311 "src/parser.y"
                                                                            { struct SymbolTableEntry* symbol = lookup((yyvsp[0].string_value), 0, 1, 0); if (symbol==NULL) YYERROR; else (yyval.node_pointer) = NULL; }
#line 2099 "build/y.tab.c"
    break;

  case 126: /* unary_op: INC  */
#line 315 "src/parser.y"
                                                    { (yyval.enum_value) = INC_OP; }
#line 2105 "build/y.tab.c"
    break;

  case 127: /* unary_op: DEC  */
#line 316 "src/parser.y"
                                                    { (yyval.enum_value) = DEC_OP; }
#line 2111 "build/y.tab.c"
    break;

  case 128: /* unary_op: ADD  */
#line 317 "src/parser.y"
                                                    { (yyval.enum_value) = ADD_OP; }
#line 2117 "build/y.tab.c"
    break;

  case 129: /* unary_op: SUB  */
#line 318 "src/parser.y"
                                                    { (yyval.enum_value) = SUB_OP; }
#line 2123 "build/y.tab.c"
    break;

  case 130: /* unary_op: NOT  */
#line 319 "src/parser.y"
                                                    { (yyval.enum_value) = NOT_OP; }
#line 2129 "build/y.tab.c"
    break;

  case 131: /* unary_op: BIT_NOT  */
#line 320 "src/parser.y"
                                                    { (yyval.enum_value) = BIT_NOT_OP; }
#line 2135 "build/y.tab.c"
    break;

  case 132: /* assignment_op: ADD_ASSIGN  */
#line 324 "src/parser.y"
                                                    { (yyval.enum_value) = ADD_ASSIGN_OP; }
#line 2141 "build/y.tab.c"
    break;

  case 133: /* assignment_op: AND_ASSIGN  */
#line 325 "src/parser.y"
                                                    { (yyval.enum_value) = AND_ASSIGN_OP; }
#line 2147 "build/y.tab.c"
    break;

  case 134: /* assignment_op: ASSIGN  */
#line 326 "src/parser.y"
                                                    { (yyval.enum_value) = ASSIGN_OP; }
#line 2153 "build/y.tab.c"
    break;

  case 135: /* assignment_op: DIV_ASSIGN  */
#line 327 "src/parser.y"
                                                    { (yyval.enum_value) = DIV_ASSIGN_OP; }
#line 2159 "build/y.tab.c"
    break;

  case 136: /* assignment_op: MOD_ASSIGN  */
#line 328 "src/parser.y"
                                                    { (yyval.enum_value) = MOD_ASSIGN_OP; }
#line 2165 "build/y.tab.c"
    break;

  case 137: /* assignment_op: MUL_ASSIGN  */
#line 329 "src/parser.y"
                                                    { (yyval.enum_value) = MUL_ASSIGN_OP; }
#line 2171 "build/y.tab.c"
    break;

  case 138: /* assignment_op: OR_ASSIGN  */
#line 330 "src/parser.y"
                                                    { (yyval.enum_value) = OR_ASSIGN_OP; }
#line 2177 "build/y.tab.c"
    break;

  case 139: /* assignment_op: SHL_ASSIGN  */
#line 331 "src/parser.y"
                                                    { (yyval.enum_value) = SHL_ASSIGN_OP; }
#line 2183 "build/y.tab.c"
    break;

  case 140: /* assignment_op: SHR_ASSIGN  */
#line 332 "src/parser.y"
                                                    { (yyval.enum_value) = SHR_ASSIGN_OP; }
#line 2189 "build/y.tab.c"
    break;

  case 141: /* assignment_op: SUB_ASSIGN  */
#line 333 "src/parser.y"
                                                    { (yyval.enum_value) = SUB_ASSIGN_OP; }
#line 2195 "build/y.tab.c"
    break;

  case 142: /* assignment_op: XOR_ASSIGN  */
#line 334 "src/parser.y"
                                                    { (yyval.enum_value) = XOR_ASSIGN_OP; }
#line 2201 "build/y.tab.c"
    break;

  case 143: /* literal: FALSE  */
#line 338 "src/parser.y"
                                                            { (yyval.node_pointer) = bool_node(0); }
#line 2207 "build/y.tab.c"
    break;

  case 144: /* literal: TRUE  */
#line 339 "src/parser.y"
                                                            { (yyval.node_pointer) = bool_node(1); }
#line 2213 "build/y.tab.c"
    break;

  case 145: /* literal: INT_LITERAL  */
#line 340 "src/parser.y"
                                                            { (yyval.node_pointer) = int_node((yyvsp[0].int_value)); }
#line 2219 "build/y.tab.c"
    break;

  case 146: /* literal: FLOAT_LITERAL  */
#line 341 "src/parser.y"
                                                            { (yyval.node_pointer) = float_node((yyvsp[0].float_value)); }
#line 2225 "build/y.tab.c"
    break;

  case 147: /* literal: CHAR_LITERAL  */
#line 342 "src/parser.y"
                                                            { (yyval.node_pointer) = char_node((yyvsp[0].char_value)); }
#line 2231 "build/y.tab.c"
    break;

  case 148: /* literal: STRING_LITERAL  */
#line 343 "src/parser.y"
                                                            { (yyval.node_pointer) = string_node((yyvsp[0].string_value)); }
#line 2237 "build/y.tab.c"
    break;


#line 2241 "build/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 346 "src/parser.y"

