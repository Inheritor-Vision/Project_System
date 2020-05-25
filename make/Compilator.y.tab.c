/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "syntaxique_C_Return.y" /* yacc.c:339  */

	#define _GNU_SOURCE
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "src/symboltable.h"
	#include "src/tvartable.h"
	#include "src/write.h"
	#include "src/conditionaljump.h"
	#include "src/operation.h"
	#include "src/functable.h"

	
	int yydebug = 1;
	int yyerror(char *s);
	int yylex();
	void addVarray(char*);
	void addTVars(int a);
	void freeAllTVars();
	void freeAllVarray();
	char * strdup( const char * source );
	extern FILE * f;
	extern int mylineno;
	int deb[50] = {0};
	int debIndex = 0;
	int arg = 0;
	int wile = 0;
	char ** argt = NULL;
	char* nameFct;

	typedef struct {
		int* tab;
		int size;
	} argsArray;
	argsArray  *RepTVars;

	typedef struct {
    	char** tab;
    	int size;
	} Varray;
	Varray *RepVars;

    

#line 111 "Compilator.y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Compilator.y.tab.h".  */
#ifndef YY_YY_COMPILATOR_Y_TAB_H_INCLUDED
# define YY_YY_COMPILATOR_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tInt = 258,
    tMain = 259,
    tReturn = 260,
    tPrintf = 261,
    tConst = 262,
    tVoid = 263,
    tAdd = 264,
    tSub = 265,
    tMul = 266,
    tEqu = 267,
    tSC = 268,
    tDiv = 269,
    tOCB = 270,
    tCCB = 271,
    tORB = 272,
    tCRB = 273,
    tComma = 274,
    tCR = 275,
    tVar = 276,
    tValInt = 277,
    tDecVal = 278,
    tExpVal = 279,
    tIf = 280,
    tElse = 281,
    tEquEqu = 282,
    tSupEqu = 283,
    tInfEqu = 284,
    tSup = 285,
    tInf = 286,
    tWhile = 287,
    tEt = 288
  };
#endif
/* Tokens.  */
#define tInt 258
#define tMain 259
#define tReturn 260
#define tPrintf 261
#define tConst 262
#define tVoid 263
#define tAdd 264
#define tSub 265
#define tMul 266
#define tEqu 267
#define tSC 268
#define tDiv 269
#define tOCB 270
#define tCCB 271
#define tORB 272
#define tCRB 273
#define tComma 274
#define tCR 275
#define tVar 276
#define tValInt 277
#define tDecVal 278
#define tExpVal 279
#define tIf 280
#define tElse 281
#define tEquEqu 282
#define tSupEqu 283
#define tInfEqu 284
#define tSup 285
#define tInf 286
#define tWhile 287
#define tEt 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 56 "syntaxique_C_Return.y" /* yacc.c:355  */

    int integerValue;
    char *stringValue;

#line 222 "Compilator.y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPILATOR_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 239 "Compilator.y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    67,    68,    72,    76,    80,    83,    84,
      86,    87,    89,    90,    91,    94,    98,   103,   104,   107,
     115,   124,   127,   131,   134,   144,   149,   150,   153,   154,
     155,   156,   157,   160,   163,   167,   173,   180,   186,   189,
     198,   201,   207,   216,   217,   220,   229,   238,   247,   260,
     261,   264,   272,   278,   284,   291,   295,   299,   300,   301,
     303,   306,   310,   313,   316,   334,   337,   339,   341,   343,
     344,   345
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tInt", "tMain", "tReturn", "tPrintf",
  "tConst", "tVoid", "tAdd", "tSub", "tMul", "tEqu", "tSC", "tDiv", "tOCB",
  "tCCB", "tORB", "tCRB", "tComma", "tCR", "tVar", "tValInt", "tDecVal",
  "tExpVal", "tIf", "tElse", "tEquEqu", "tSupEqu", "tInfEqu", "tSup",
  "tInf", "tWhile", "tEt", "$accept", "S", "Functions", "RepFunction",
  "Funct", "FunctReturn", "Function", "Princ", "Var", "Vide", "InitFunc",
  "Body", "Return", "BodyReturn", "Instructions", "Instruction",
  "ConditionnalJump", "InitIf", "InitElse", "EndIf", "InitWhile",
  "EndWhile", "WhileORB", "Assign", "RepInitialize", "Initialize",
  "Repdeclare", "Declare", "RepArgs", "IntegerValue", "Expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,    -2,   -48,    -2,   -48,     6,   -48,   -48,    23,   -13,
       0,   -48,    11,    21,   -48,   -48,   -48,     7,    13,     7,
      13,   -48,     5,     9,    40,    32,    57,    73,    46,    60,
      71,    46,    46,    46,   -48,     4,   -48,    27,   -48,   -48,
     -48,     4,   -48,   -48,    30,    80,    86,    43,    87,    94,
       4,   -48,     4,     4,   -48,   -48,   -48,   -48,    60,   111,
     101,    41,    36,   125,   -48,   107,    43,    43,    43,   113,
      43,   121,   -48,   -48,   -48,   118,   -48,    85,   -48,    43,
     -48,   -48,   124,   126,   -48,    43,   127,   129,   -48,   101,
     132,   -48,   101,    43,   128,    92,   -48,   -48,   -48,    69,
      43,   -48,    43,    43,    43,    43,   -48,    75,   -48,   119,
     -48,   -48,    98,   -48,    43,   135,   -48,    43,   -48,   104,
     136,   -48,   -48,   130,    63,    -6,    -6,   -48,   -48,   137,
     138,     4,   -48,   110,    43,   116,   -48,   -48,   -48,    43,
     -48,   -48,   124,   -48,   122,   -48,   -48,   -48,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    15,     0,    16,     0,     2,    13,     4,     0,
       0,    14,     0,     0,    12,     1,     3,    18,     7,    18,
       7,    17,     0,     0,     0,     0,     0,     0,    21,     0,
       0,    21,    25,    25,    19,    27,     8,     0,     6,     5,
       9,    27,    10,    11,     0,     0,     0,     0,     0,     0,
      27,    32,    27,    27,    28,    29,    30,    50,     0,    23,
       0,     0,    43,     0,    51,     0,     0,     0,     0,     0,
       0,    61,    57,    58,    59,     0,    60,     0,    41,     0,
      20,    26,     0,     0,    49,     0,     0,     0,    52,     0,
       0,    53,     0,     0,     0,     0,    70,    69,    63,     0,
       0,    62,     0,     0,     0,     0,    36,     0,    38,    33,
      40,    35,     0,    24,     0,     0,    54,     0,    44,     0,
       0,    42,    71,     0,    56,    65,    66,    67,    68,     0,
       0,    27,    22,     0,     0,     0,    45,    31,    64,     0,
      39,    37,     0,    46,     0,    47,    55,    34,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -48,   -48,   142,   131,   151,   -48,   -48,   154,   155,   139,
      37,   133,   -48,   134,   -41,   -48,   -48,   -48,   -48,    15,
     -48,   -48,   -48,   -48,   -47,   -48,   -26,   -48,    20,   -48,
     -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    25,     7,    11,     8,     9,    10,    22,
      35,    36,    86,    42,    49,    50,    51,    52,   131,   109,
      53,   111,    79,    54,    63,    55,    84,    56,   123,    76,
     124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    77,     2,    38,    17,   104,    15,    44,   105,    81,
      45,    82,    83,    87,    90,    21,    23,    18,    64,     4,
      95,    96,    97,    28,    99,    46,     1,     2,    19,    47,
      29,     3,    24,   107,    88,    91,    48,    60,    20,   112,
      57,    61,   115,    30,     4,   118,    58,   119,    89,    57,
      31,    62,    67,    68,    69,    92,   125,   126,   127,   128,
      70,    34,    62,   116,    71,    72,    73,    74,   133,    41,
      41,   135,   102,   103,   104,    32,    75,   105,   102,   103,
     104,    37,   139,   105,   102,   103,   104,   122,   144,   105,
     142,    33,    39,   129,   102,   103,   104,    65,    66,   105,
     106,   102,   103,   104,    78,   121,   105,   102,   103,   104,
      80,   132,   105,   102,   103,   104,    85,   136,   105,   102,
     103,   104,    62,   143,   105,   102,   103,   104,    94,   145,
     105,   102,   103,   104,    98,   148,   105,    93,   100,   101,
     108,   114,   110,   113,   117,   130,   120,   134,   138,   137,
      16,    27,   140,   141,    14,    12,    13,   147,    26,   146,
       0,     0,     0,     0,    40,     0,     0,    43
};

static const yytype_int16 yycheck[] =
{
      41,    47,     4,    29,    17,    11,     0,     3,    14,    50,
       6,    52,    53,    60,    61,     8,     3,    17,    44,    21,
      66,    67,    68,    18,    70,    21,     3,     4,    17,    25,
      21,     8,    19,    79,    60,    61,    32,     7,    17,    85,
      13,    11,    89,     3,    21,    92,    19,    93,     7,    13,
      18,    21,     9,    10,    11,    19,   102,   103,   104,   105,
      17,    15,    21,    89,    21,    22,    23,    24,   114,    32,
      33,   117,     9,    10,    11,    18,    33,    14,     9,    10,
      11,    21,    19,    14,     9,    10,    11,    18,   134,    14,
     131,    18,    21,    18,     9,    10,    11,    17,    12,    14,
      15,     9,    10,    11,    17,    13,    14,     9,    10,    11,
      16,    13,    14,     9,    10,    11,     5,    13,    14,     9,
      10,    11,    21,    13,    14,     9,    10,    11,    21,    13,
      14,     9,    10,    11,    21,    13,    14,    12,    17,    21,
      16,    12,    16,    16,    12,    26,    18,    12,    18,    13,
       8,    20,    15,    15,     3,     1,     1,   142,    19,   139,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     8,    21,    35,    36,    38,    40,    41,
      42,    39,    41,    42,    38,     0,    36,    17,    17,    17,
      17,     8,    43,     3,    19,    37,    43,    37,    18,    21,
       3,    18,    18,    18,    15,    44,    45,    21,    60,    21,
      45,    44,    47,    47,     3,     6,    21,    25,    32,    48,
      49,    50,    51,    54,    57,    59,    61,    13,    19,    48,
       7,    11,    21,    58,    60,    17,    12,     9,    10,    11,
      17,    21,    22,    23,    24,    33,    63,    64,    17,    56,
      16,    48,    48,    48,    60,     5,    46,    58,    60,     7,
      58,    60,    19,    12,    21,    64,    64,    64,    21,    64,
      17,    21,     9,    10,    11,    14,    15,    64,    16,    53,
      16,    55,    64,    16,    12,    58,    60,    12,    58,    64,
      18,    13,    18,    62,    64,    64,    64,    64,    64,    18,
      26,    52,    13,    64,    12,    64,    13,    13,    18,    19,
      15,    15,    48,    13,    64,    13,    62,    53,    13
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    37,    38,    38,
      39,    39,    40,    40,    40,    41,    42,    43,    43,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    50,    50,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    58,    59,    59,    59,    59,    60,
      60,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     0,     5,     5,
       5,     5,     2,     1,     2,     1,     1,     1,     0,     1,
       3,     0,     3,     0,     4,     0,     2,     0,     1,     1,
       1,     5,     1,     3,     6,     3,     3,     2,     1,     5,
       1,     1,     4,     1,     3,     5,     6,     6,     7,     3,
       2,     2,     3,     3,     4,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     3,     3,     3,     3,     2,
       2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 3:
#line 67 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1419 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1425 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		arg++;
		argt = realloc(argt, sizeof(char*) * arg);
		argt[arg-1] = strdup((yyvsp[0].stringValue));}
#line 1434 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		arg++;
		argt = realloc(argt, sizeof(char*) * arg);
		argt[arg-1] = strdup((yyvsp[0].stringValue));}
#line 1443 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 80 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1449 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 84 "syntaxique_C_Return.y" /* yacc.c:1646  */
    { }
#line 1455 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 87 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1461 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 89 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1467 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 90 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1473 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 91 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1479 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 94 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		addFunc("main",ligne, 0, NULL);}
#line 1486 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 98 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		addFunc((yyvsp[0].stringValue),ligne, 0, argt);
		argt = NULL;}
#line 1494 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 107 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		modifyLastArgc(arg);
		arg = 0;
		write_str("%%Début de la fonction %s\n", getLastName());
		(yyval.stringValue) = getLastName();
	}
#line 1505 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 115 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		write_str("%% Fin de la fonction %s\n", (yyvsp[-2].stringValue));
		decrementeDepth(deb[debIndex]);
		debIndex--;
		write_str("%%Récupération de l'addresse de retour\n");
		write_ligne();write_char(LODR);write_int(0);write_int(SP);write_endl();
		write_ligne();write_char(SOU);write_int(SP);write_int(SP);write_int(4);write_endl();
		write_ligne();write_char(JMP[0]);write_int(0);write_endl();
		}
#line 1519 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 124 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {fprintf(stderr,"Error l%d: No body detected1, maybe  { or } missing\n",mylineno);exit(EXIT_FAILURE);}
#line 1525 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 127 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
	delLastVal();
	(yyval.integerValue) = (yyvsp[-1].integerValue);
	}
#line 1534 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 131 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {fprintf(stderr,"Error l%d: No return detected\n",mylineno);exit(EXIT_FAILURE);}
#line 1540 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 134 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		write_str("%% Fin de la fonction %s\n", (yyvsp[-3].stringValue));
		decrementeDepth(deb[debIndex]);
		debIndex--;
		write_str("%%Récupération de l'addresse de retour et return ds r0\n");
		write_ligne();write_char(AFC);write_int(0);write_int((yyvsp[-1].integerValue));write_endl();
		write_ligne();write_char(LODR);write_int(1);write_int(SP);write_endl();
		write_ligne();write_char(SOU);write_int(SP);write_int(SP);write_int(4);write_endl();
		write_ligne();write_char(JMP[0]);write_int(1);write_endl();
		}
#line 1555 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 144 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {fprintf(stderr,"Error l%d: No body detected2, maybe  { or } missing\n",mylineno);exit(EXIT_FAILURE);}
#line 1561 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 149 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1567 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 153 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1573 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 154 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1579 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 155 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1585 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 156 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1591 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 157 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1597 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 160 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		modifyLast((yyvsp[-2].integerValue),(yyvsp[0].integerValue));
		}
#line 1605 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 163 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		modifyLast((yyvsp[-5].integerValue),(yyvsp[-3].integerValue)+1);
		modifyLast((yyvsp[-2].integerValue),(yyvsp[0].integerValue));
		}
#line 1614 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 167 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		modifyLast((yyvsp[-2].integerValue),(yyvsp[0].integerValue)+1);
		write_ligne();write_char(JMP[0]);write_int(wile);write_endl();
	}
#line 1623 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 173 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		delLastVal();
		incrementeDepth(deb[debIndex]);
		write_ligne();write_char(LOD);write_int(0);write_int((yyvsp[-1].integerValue));write_endl();
		(yyval.integerValue) = pushCondJump(JMF,ligneCom,ligne);write_endl();
	}
#line 1634 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 180 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		incrementeDepth(deb[debIndex]);
		(yyval.integerValue) = pushCondJump(JMP,ligneCom,ligne);write_endl();
	}
#line 1643 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 186 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {decrementeDepth(deb[debIndex]);(yyval.integerValue) = ligne;}
#line 1649 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 189 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		delLastVal();
		incrementeDepth(deb[debIndex]);
		write_ligne();write_char(LOD);write_int(0);write_int((yyvsp[-2].integerValue));write_endl();
		(yyval.integerValue) = pushCondJump(JMF,ligneCom,ligne);write_endl();
		wile = (yyvsp[-3].integerValue);
	}
#line 1661 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 198 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {decrementeDepth(deb[debIndex]);(yyval.integerValue) = ligne;}
#line 1667 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 201 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {(yyval.integerValue) = ligne;}
#line 1673 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 207 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		write_str("%%Assignation var: %s\n",(yyvsp[-3].stringValue));
		write_ligne();write_char(LOD);write_int(0);write_int((yyvsp[-1].integerValue));write_endl();
		write_ligne();write_char(STR); write_int(assign_var_to_local_int(deb[debIndex],(yyvsp[-3].stringValue))); write_int(0);write_endl();
		delLastVal();}
#line 1683 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 216 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {addVarray((yyvsp[0].stringValue));}
#line 1689 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 217 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {addVarray((yyvsp[-2].stringValue));}
#line 1695 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 220 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		  for(int i = 0; i < RepVars->size; i++){
			  write_str("%%Initialize var : %s\n",RepVars->tab[i]);
			  write_ligne();write_char(LOD);write_int(0);write_int((yyvsp[-1].integerValue));write_endl();
			  write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], false, true, 0)); write_int(0);write_endl();
			}
			freeAllVarray();
			delLastVal();
		}
#line 1709 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 229 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		for(int i = 0; i < RepVars->size; i++){
			write_str("%%Initialize var : %s\n",RepVars->tab[i]);
			write_ligne();write_char(LOD);write_int(0);write_int((yyvsp[-1].integerValue));write_endl();
			write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], true, true, 0)); write_int(0);write_endl();
		}
		freeAllVarray();
		delLastVal();
	}
#line 1723 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 238 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		for(int i = 0; i < RepVars->size; i++){
			write_str("%%Initialize var : %s\n ",RepVars->tab[i]);
			write_ligne();write_char(LOD);write_int(0);write_int((yyvsp[-1].integerValue));write_endl();
			write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], false, true, 0)); write_int(0);write_endl();
		}
		freeAllVarray();
		delLastVal();
	}
#line 1737 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 247 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		for(int i = 0; i < RepVars->size; i++){
			write_str("%%Initialize var : %s\n ",RepVars->tab[i]);
			write_ligne();write_char(LOD);write_int(0);write_int((yyvsp[-1].integerValue));write_endl();
			write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], true, true, 0)); write_int(0);write_endl();
		}
		freeAllVarray();
		delLastVal();
	}
#line 1751 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 260 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {addVarray((yyvsp[-2].stringValue));}
#line 1757 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 261 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {addVarray((yyvsp[-1].stringValue));}
#line 1763 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 264 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		
		for(int i = 0; i < RepVars->size; i++){
			initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], false, false, 0);
		}
		freeAllVarray();
		
	}
#line 1776 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 272 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		for(int i = 0; i < RepVars->size; i++){
			initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], true, false, 0);
		}
		freeAllVarray();
	}
#line 1787 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 278 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		for(int i = 0; i < RepVars->size; i++){
			initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], false, false, 0);
		}
		freeAllVarray();
	}
#line 1798 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 284 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		for(int i = 0; i < RepVars->size; i++){
			initialize_var_to_local_int(deb[debIndex],RepVars->tab[i], true, false, 0);
		}
		freeAllVarray();
	}
#line 1809 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 291 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		delLastVal();
		addTVars((yyvsp[-2].integerValue));
	}
#line 1818 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 295 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		delLastVal();
		addTVars((yyvsp[0].integerValue));}
#line 1826 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 299 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {(yyval.integerValue) = (yyvsp[0].integerValue);}
#line 1832 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 300 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1838 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 301 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1844 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 303 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		  	(yyval.integerValue) = addTVarFromVal((yyvsp[0].integerValue));
	  }
#line 1852 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 306 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {

		(yyval.integerValue) = addTVarfromLVar(get_local_var_addr(deb[debIndex],(yyvsp[0].stringValue)));
	}
#line 1861 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 310 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		(yyval.integerValue) = addTVarFromVal(get_local_var_addr(deb[debIndex],(yyvsp[0].stringValue)));
	}
#line 1869 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 313 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		(yyval.integerValue) = addTVarFromPointer(get_local_var_addr(deb[debIndex],(yyvsp[0].stringValue)));
	}
#line 1877 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 316 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		func tmp = getFunc((yyvsp[-3].stringValue));
		debIndex++;
		deb[debIndex] = getSize();
		write_ligne();write_char(ADD);write_int(SP);write_int(SP);write_int(4);write_endl();
		write_ligne();write_char(STRR);write_int(SP);write_int(ligne+1+2*RepTVars->size);write_endl();
		write_ligne();write_char(JMP[0]);write_int(tmp.address);write_endl();
		if(!(tmp.nbr_args == RepTVars->size)){
			fprintf(stderr,"Error l%d: Function %s as wrong number of args\n",mylineno,tmp.varname);exit(EXIT_FAILURE);
		}
		for(int i = 0; i < RepTVars->size; i++){
			write_str("%%Initialize args of function: %s\n ", tmp.args[i]);
			write_ligne();write_char(LOD);write_int(0);write_int(RepTVars->tab[i]);write_endl();
			write_ligne();write_char(STR); write_int(initialize_var_to_local_int(deb[debIndex],tmp.args[i], true, true, 0)); write_int(0);write_endl();
		}
		freeAllTVars();
		(yyval.integerValue) = addTVarFromReg0();
	}
#line 1900 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 334 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		(yyval.integerValue) = addTVarFromOperation(add,(yyvsp[-2].integerValue), (yyvsp[0].integerValue));
	}
#line 1908 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 337 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		(yyval.integerValue) = addTVarFromOperation(sub,(yyvsp[-2].integerValue), (yyvsp[0].integerValue));}
#line 1915 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 339 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		(yyval.integerValue) = addTVarFromOperation(mul,(yyvsp[-2].integerValue), (yyvsp[0].integerValue));}
#line 1922 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 341 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {
		(yyval.integerValue) = addTVarFromOperation(divi,(yyvsp[-2].integerValue), (yyvsp[0].integerValue));}
#line 1929 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 343 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1935 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 344 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {}
#line 1941 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 345 "syntaxique_C_Return.y" /* yacc.c:1646  */
    {(yyval.integerValue) = (yyvsp[-1].integerValue);}
#line 1947 "Compilator.y.tab.c" /* yacc.c:1646  */
    break;


#line 1951 "Compilator.y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 347 "syntaxique_C_Return.y" /* yacc.c:1906  */



void addVarray(char* a){
    RepVars->size++;
    RepVars->tab = (char**)realloc(RepVars->tab,RepVars->size * sizeof(char*));
	
	RepVars->tab[RepVars->size-1] = strdup(a);
}

void freeAllVarray(){
	for(int i = 0; i<RepVars->size; i++){
		free(RepVars->tab[i]);
	}
    free(RepVars->tab);
    free(RepVars);
	RepVars = malloc(sizeof(Varray));
    RepVars->size = 0;
    RepVars->tab = malloc(sizeof(char**));
}
void addTVars(int a){
    RepTVars->size++;
    RepTVars->tab = (int*)realloc(RepTVars->tab,RepTVars->size * sizeof(int));
	RepTVars->tab[RepTVars->size-1] = a;
}

void freeAllTVars(){
    free(RepTVars->tab);
    free(RepTVars);
	RepTVars = (argsArray*) malloc(sizeof(argsArray));
	RepTVars->size = 0;
	RepTVars->tab = (int*) malloc(sizeof(int));
}





int yyerror(char *s){
	printf("Error: %s at line %d\n",s,mylineno);
	exit(EXIT_FAILURE);
}
int main(void){
	//printf("|>.-O_|3(7_5`/573|\\/| : /<o|\\/||>1|_47o.-");
	printf("\nDebut de l'analyse syntaxique\n");

	//init vars locals
	init();
	//init RepVars
	RepVars = (Varray*) malloc(sizeof(Varray));
    RepVars->size = 0;
    RepVars->tab = (char**) malloc(sizeof(char*));
	RepTVars = (argsArray*) malloc(sizeof(argsArray));
	RepTVars->size = 0;
	RepTVars->tab = (int*) malloc(sizeof(int));
	

	
	yyparse();
	
	fclose(f);
	if(CondJumpList->size > 0){
		f = fopen("compil.asm","r");
		FILE * ftemp = fopen("temp.tmp","w");
		if(ftemp == NULL || f == NULL){
			printf("\nUnable to open file temp.tmp or compil.asm for patching.\n");
			exit(EXIT_FAILURE);
		}
		int count = 0;
		int indexPatch = 0;
		char* laligne;
		size_t len = 0;
		while((getline(&laligne,&len, f)) != -1){
			if(count == CondJumpList->liste[indexPatch].from){
				char yo[254];
				if(!strcmp(CondJumpList->liste[indexPatch].op,JMF)){
					sprintf(yo,"%-9d %-9s %-9d %-9d", CondJumpList->liste[indexPatch].pos,JMF,0, CondJumpList->liste[indexPatch].to);
				}else{
					sprintf(yo,"%-9d %-9s %-9d", CondJumpList->liste[indexPatch].pos,JMP, CondJumpList->liste[indexPatch].to);
				}
				
				fprintf(ftemp,"%s\n",yo);
				if(indexPatch+1 != CondJumpList->size){
					indexPatch++;
				}
			}else{
				fprintf(ftemp,"%s",laligne);
			}
			
			count++;
		}
		fclose(f);
		fclose(ftemp);
		remove("compil.asm");
		rename("temp.tmp", "compil.asm");
	}
	printAll();
	printf("\nFin de l'analyse syntaxique\n\n");
}


