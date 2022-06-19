%{
    #include <stdio.h>
    
    #include "quadruples.h"
    
    extern int yyerror(char *error);
    
    int yylex();
    int yywrap() { return 1; }
%}

%union
{
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
};

    /* Keywords. */
%token CONST
%token BOOL CHAR DOUBLE FLOAT INT LONG SHORT SIGNED UNSIGNED VOID
%token BREAK CASE CONTINUE DEFAULT DO ELSE ENUM FOR IF RETURN SWITCH WHILE

    /* To resolve dangling else. */
%nonassoc IF
%nonassoc ELSE

    /* Operators. */
%token COLON COMMA LBRACE LPAREN QUESTION RBRACE RPAREN SEMICOLON
%token ADD_ASSIGN AND_ASSIGN ASSIGN DIV_ASSIGN MOD_ASSIGN MUL_ASSIGN OR_ASSIGN SHL_ASSIGN SHR_ASSIGN SUB_ASSIGN XOR_ASSIGN
%token ADD AND BIT_AND BIT_NOT BIT_OR DEC DIV EQ GE GT INC LE LT MOD MUL NE NOT OR SHL SHR SUB XOR

    /* Boolean, numeric, character, and string literals. */
%token <bool_value>FALSE <bool_value>TRUE <int_value>INT_LITERAL <float_value>FLOAT_LITERAL <char_value>CHAR_LITERAL <string_value>STRING_LITERAL

    /* Identifier. */
%token <string_value>IDENTIFIER

%type <node_pointer>expression assign_expression ternary_expression or_expression and_expression bit_or_expression xor_expression bit_and_expression equal_expression
%type <node_pointer>compare_expression shift_expression add_expression mul_expression prefix_expression postfix_expression base_expression
%type <node_pointer>initializer initializer_list function top_level_statement declaration parameter parameter_list
%type <node_pointer>block_statement block_item_list statement jump_statement selection_statement iteration_statement switch_case switch_case_list
%type <node_pointer>literal


%type <enum_value>unary_op assignment_op type_modifier
%type <entry_pointer>function_declaration parameterized_identifier
%type <pair>type_modifier_list
%type <node_pointer>enum_type
%type <enum_pointer>type_modifier_items

%%

    /* A program consists of a number of top level statements. */
program                 : program top_level_statement               { program_append($2); }
                        | top_level_statement                       { program_append($1); }
                        | error SEMICOLON                           { yyerror("Invalid top level statement."); }
                        ;

    /* Top level statements only declare or define functions and other language constructs (variables, enums, etc.). */
top_level_statement     : declaration SEMICOLON
                        | function
                        ;

    /* A declaration consists of a type, and optionally initializers. */
declaration             : type_modifier_list initializer_list       { struct AST_Node *tmp = change_list_params($2, $1.enum_pointer, 0); if (tmp==NULL) YYERROR; else $$ = $1.node_pointer == NULL ? tmp : operation_node(COMMA_OP, $1.node_pointer, tmp); if ($$ == NULL) YYERROR; }
                        | type_modifier_list                        { $$ = $1.node_pointer; }
                        ;

    /* Initializiers can be compounded using commas. */
initializer_list        : initializer_list COMMA initializer        { $$ = operation_node(COMMA_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | initializer
                        ;

    /* An initializer is an identifier optionally assigned an assignment expression. */
initializer             : IDENTIFIER ASSIGN assign_expression       { struct SymbolTableEntry* symbol = insert($1, 0, 1, 0, 0); if (symbol==NULL) YYERROR; else $$ = operation_node(ASSIGN_OP, identifier_node(symbol), $3); if ($$ == NULL) YYERROR; }
                        | IDENTIFIER                                { struct SymbolTableEntry* symbol = insert($1, 0, 0, 0, 0); if (symbol==NULL) YYERROR; else $$ = identifier_node(symbol); }
                        ;

    /* A function consists of type modifiers, an identifier, and optionally a parameter list and/or a body. */

parameterized_identifier: type_modifier_list IDENTIFIER LPAREN          { struct SymbolTableEntry* symbol = insert($2, 1, 0, 1, 0); if (symbol == NULL) YYERROR; else $$ = symbol; scope_down();  }
                        ;

function_declaration    : type_modifier_list IDENTIFIER LPAREN RPAREN   { struct SymbolTableEntry* symbol = insert($2, 1, 0, 1, 0); if (symbol == NULL) YYERROR; else $$ = symbol; }
                        ;

function                : parameterized_identifier parameter_list RPAREN { def_func($1); } block_statement  { scope_up(); $$ = function_node($1, $2, $5); }
                        | function_declaration { scope_down(); def_func($1); } block_statement              { scope_up(); $$ = function_node($1, NULL, $3); }
                        | parameterized_identifier parameter_list RPAREN RPAREN SEMICOLON                   { scope_up(); $$ = function_node($1, $2, NULL); }
                        | function_declaration SEMICOLON                                                    {             $$ = function_node($1, NULL, NULL); }
                        ;

    /* A parameter list is a comma-separated list of parameters. */
parameter_list          : parameter_list COMMA parameter                                    { $$ = operation_node(COMMA_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | parameter
                        ;

    /* A parameter is a type, and an optional initializer. */
parameter               : type_modifier_list initializer                                    { struct AST_Node *identifiers = change_list_params($2, $1.enum_pointer, 1); if (identifiers==NULL) YYERROR; else $$ = identifiers;}
                        | type_modifier_list                                                { $$ = NULL; }
                        ;

    /* EXPRESSIONS */

    /* Expressions ordered with precedence in mind, following from lecture's guide to enfore precedence with grammar rules.
        Reference: https://en.cppreference.com/w/c/language/operator_precedence

        We move up from the bottom up, never going back down until the last step to avoid reduce conflicts.
        Left-to-right expressions are left-recursive, and right-to-left expressions are right-recursive.
    */

    /* Any expression is a comma-separated list of assignment expressions. */
expression              : expression COMMA assign_expression            { $$ = operation_node(COMMA_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | assign_expression
                        ;

    /* An assignment expression is either an assignment expression or decays to a ternary expression. */
assign_expression       : IDENTIFIER assignment_op assign_expression    { struct SymbolTableEntry* symbol = lookup($1, 0, $2!=ASSIGN_OP, $2==ASSIGN_OP); if (symbol == NULL) YYERROR; else $$ = operation_node($2, identifier_node(symbol), $3); if ($$ == NULL) YYERROR; }
                        | ternary_expression
                        ;

    /* An ternary expression is either a ternary expression or decays to a logical or expression. */
ternary_expression      : or_expression QUESTION expression COLON ternary_expression    { $$ = if_node($1, $3, $5); }
                        | or_expression
                        ;

    /* A logical or expression is either a logical or expression or decays to a logical and expression. */
or_expression           : or_expression OR and_expression               { $$ = operation_node(OR_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | and_expression
                        ;

    /* A logical and expression is either a logical and expression or decays to a bitwise or expression. */
and_expression          : and_expression AND bit_or_expression          { $$ = operation_node(AND_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | bit_or_expression
                        ;

    /* A bitwise or expression is either a bitwise or expression or decays to a bitwise xor expression. */
bit_or_expression       : bit_or_expression BIT_OR xor_expression       { $$ = operation_node(BIT_OR_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | xor_expression
                        ;

    /* An xor expression is either an xor expression or decays to a bitwise and expression. */
xor_expression          : xor_expression XOR bit_and_expression         { $$ = operation_node(XOR_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | bit_and_expression
                        ;

    /* A bitwise and expression is either a bitwise and expression or decays to an equality expression. */
bit_and_expression      : bit_and_expression BIT_AND equal_expression   { $$ = operation_node(BIT_AND_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | equal_expression
                        ;

    /* An equality expression is either an equality expression or decays to a comparison expression. */
equal_expression        : equal_expression EQ compare_expression        { $$ = operation_node(EQ_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | equal_expression NE compare_expression        { $$ = operation_node(NE_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | compare_expression
                        ;

    /* A comparison expression is either a comparison expression or decays to a shift expression. */
compare_expression      : compare_expression LT shift_expression        { $$ = operation_node(LT_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | compare_expression GT shift_expression        { $$ = operation_node(GT_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | compare_expression LE shift_expression        { $$ = operation_node(LE_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | compare_expression GE shift_expression        { $$ = operation_node(GE_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | shift_expression
                        ;

    /* A shift expression is either a shift expression or decays to an addition expression. */
shift_expression        : shift_expression SHL add_expression           { $$ = operation_node(SHL_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | shift_expression SHR add_expression           { $$ = operation_node(SHR_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | add_expression
                        ;

    /* An addition expression is either an addition expression or decays to a multiplication expression. */
add_expression          : add_expression ADD mul_expression             { $$ = operation_node(ADD_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | add_expression SUB mul_expression             { $$ = operation_node(SUB_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | mul_expression
                        ;

    /* A multiplication expression is either a multiplication expression or decays to a prefix expression. */
mul_expression          : mul_expression MUL prefix_expression          { $$ = operation_node(MUL_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | mul_expression DIV prefix_expression          { $$ = operation_node(DIV_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | mul_expression MOD prefix_expression          { $$ = operation_node(MOD_OP, $1, $3); if ($$ == NULL) YYERROR; }
                        | prefix_expression
                        ;

    /* A prefix expression is either a prefix expression or decays to a postfix expression. */
prefix_expression       : unary_op prefix_expression                    { $$ = operation_node($1, NULL, $2); if ($$ == NULL) YYERROR; }
                        | postfix_expression
                        ;

    /* A postfix expression is either a postfix expression (including a function call) or decays to a base expression. */
postfix_expression      : postfix_expression INC                        { $$ = operation_node(INC_OP, $1, NULL); if ($$ == NULL) YYERROR; }
                        | postfix_expression DEC                        { $$ = operation_node(DEC_OP, $1, NULL); if ($$ == NULL) YYERROR; }
                        | IDENTIFIER LPAREN expression RPAREN           { struct SymbolTableEntry* symbol = lookup($1, 1, 1, 0); if (symbol == NULL) YYERROR; else $$ = call_node(identifier_node(symbol), $3); }
                        | IDENTIFIER LPAREN RPAREN                      { struct SymbolTableEntry* symbol = lookup($1, 1, 1, 0); if (symbol == NULL) YYERROR; else $$ = call_node(identifier_node(symbol), NULL); }
                        | base_expression
                        ;

    /* A base expression is either an identifier, a literal, or a parenthesized expression. */
base_expression         : IDENTIFIER                                    { struct SymbolTableEntry* symbol = lookup($1, 0, 1, 0); if (symbol == NULL) YYERROR; else $$ = identifier_node(symbol); }
                        | literal
                        | LPAREN expression RPAREN                      { $$ = $2; }
                        ;

    /* STATEMENTS */

    /* A statement is one of a block, selection, iteration, jump, a semicolon optionally preceded by an expression, a try or a declaration followed by a semicolon. */
statement               : { scope_down(); } block_statement { scope_up(); $$ = $2; }
                        | selection_statement
                        | iteration_statement
                        | jump_statement
                        | expression SEMICOLON
                        | declaration SEMICOLON
                        | SEMICOLON                         { $$ = NULL; }
                        | error SEMICOLON                   { $$ = NULL; yyerror("Invalid statement"); }
                        ;

    /* A block statement is a brace-enclosed list of optional block items. */
block_statement         : LBRACE block_item_list RBRACE         { $$ = $2; }
                        | LBRACE RBRACE                         { $$ = NULL; }
                        ;

    /* Block items can be compounded, and are statements. */
block_item_list         : block_item_list statement             { $$ = add_statement($1, $2); }
                        | statement                             { $$ = block_node($1); }
                        ;

    /* Selection statements are IFs and SWITCHes. */
selection_statement     : IF LPAREN expression RPAREN statement %prec IF                    { $$ = if_node($3, $5, NULL); }
                        | IF LPAREN expression RPAREN statement ELSE statement              { $$ = if_node($3, $5, $7); }
                        | SWITCH LPAREN expression RPAREN LBRACE switch_case_list RBRACE    { $$ = switch_node($3, $6); }
                        ;

    /* A switch case list is a sequence of switch cases. */
switch_case_list        : switch_case_list switch_case                          { $$ = add_statement($1, $2); }
                        | switch_case                                           { $$ = block_node($1); }
                        ;

    /* The two case types of a switch case. */
switch_case             : CASE ternary_expression COLON block_item_list         { struct AST_Node* tmp = operation_node(EQ_OP, NULL, $2); if (tmp==NULL) YYERROR; else $$ = if_node(tmp, $4, NULL); }
                        | DEFAULT COLON block_item_list                         { $$ = $3; }
                        ;

iteration_statement     : WHILE LPAREN expression RPAREN statement                                          { $$ = while_node($3, $5); }
                        | DO statement WHILE LPAREN expression RPAREN SEMICOLON                             { $$ = do_while_node($5, $2); }
                        | FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement  { $$ = for_node($3, $5, $7, $9); }
                        | FOR LPAREN expression SEMICOLON expression SEMICOLON RPAREN statement             { $$ = for_node($3, $5, NULL, $8); }
                        | FOR LPAREN expression SEMICOLON SEMICOLON expression RPAREN statement             { $$ = for_node($3, NULL, $6, $8); }
                        | FOR LPAREN expression SEMICOLON SEMICOLON RPAREN statement                        { $$ = for_node($3, NULL, NULL, $7); }
                        | FOR LPAREN declaration SEMICOLON expression SEMICOLON expression RPAREN statement { $$ = for_node($3, $5, $7, $9); }
                        | FOR LPAREN declaration SEMICOLON expression SEMICOLON RPAREN statement            { $$ = for_node($3, $5, NULL, $8); }
                        | FOR LPAREN declaration SEMICOLON SEMICOLON expression RPAREN statement            { $$ = for_node($3, NULL, $6, $8); }
                        | FOR LPAREN declaration SEMICOLON SEMICOLON RPAREN statement                       { $$ = for_node($3, NULL, NULL, $7); }
                        | FOR LPAREN SEMICOLON expression SEMICOLON expression RPAREN statement             { $$ = for_node(NULL, $4, $6, $8); }
                        | FOR LPAREN SEMICOLON expression SEMICOLON RPAREN statement                        { $$ = for_node(NULL, $4, NULL, $7); }
                        | FOR LPAREN SEMICOLON SEMICOLON expression RPAREN statement                        { $$ = for_node(NULL, NULL, $5, $7); }
                        | FOR LPAREN SEMICOLON SEMICOLON RPAREN statement                                   { $$ = for_node(NULL, NULL, NULL, $6); }
                        ;

    /* Jump statements are ones which affect control flow. */
jump_statement          : CONTINUE SEMICOLON                                { $$ = continue_node(); }
                        | BREAK SEMICOLON                                   { $$ = break_node(); }
                        | RETURN SEMICOLON                                  { $$ = operation_node(RET_OP, NULL, NULL); if ($$ == NULL) YYERROR; }
                        | RETURN expression SEMICOLON              { $$ = operation_node(RET_OP, $2, NULL); if ($$ == NULL) YYERROR; }
                        ;

    /* MISCELLANEOUS */

    /* A sequence of type modifiers. Need semantic checks.*/
type_modifier_list      : enum_type                         { struct PairType tmp = { .node_pointer = $1,   .enum_pointer = insert_into_array(NULL, ENUM_TYPE) }; $$ = tmp; }
                        | type_modifier_items               { struct PairType tmp = { .node_pointer = NULL, .enum_pointer = $1 }; $$ = tmp; }
                        ;

type_modifier_items     : type_modifier_items type_modifier { $$ = insert_into_array($1, $2); }
                        | type_modifier_items CONST         { $$ = insert_into_array($1, CONST_TYPE); }
                        | type_modifier                     { $$ = insert_into_array(NULL, $1); }
                        | CONST                             { $$ = insert_into_array(NULL, CONST_TYPE); }
                        ;

    /* A type modifier is a data type. */
type_modifier           : BOOL                  { $$ = BOOL_TYPE; }
                        | CHAR                  { $$ = CHAR_TYPE; }
                        | DOUBLE                { $$ = DOUBLE_TYPE; }
                        | FLOAT                 { $$ = FLOAT_TYPE; }
                        | INT                   { $$ = INT_TYPE; }
                        | LONG                  { $$ = LONG_TYPE; }
                        | SHORT                 { $$ = SHORT_TYPE; }
                        | SIGNED                { $$ = SIGNED_TYPE; }
                        | UNSIGNED              { $$ = UNSIGNED_TYPE; }
                        | VOID                  { $$ = VOID_TYPE; }
                        ;

    /* An enum type is ENUM followed by an identifier, or an (optionally anonymous) enum declaration. */
enum_type               : ENUM IDENTIFIER LBRACE initializer_list RBRACE    { struct SymbolTableEntry* symbol = insert($2, 1, 1, 0, 0); if (symbol==NULL) YYERROR; else $$ = $4; }
                        | ENUM LBRACE initializer_list RBRACE               { $$ = $3; }
                        | ENUM IDENTIFIER                                   { struct SymbolTableEntry* symbol = lookup($2, 0, 1, 0); if (symbol==NULL) YYERROR; else $$ = NULL; }
                        ;

    /* Unary operators. */
unary_op                : INC                       { $$ = INC_OP; }
                        | DEC                       { $$ = DEC_OP; }
                        | ADD                       { $$ = ADD_OP; }
                        | SUB                       { $$ = SUB_OP; }
                        | NOT                       { $$ = NOT_OP; }
                        | BIT_NOT                   { $$ = BIT_NOT_OP; }
                        ;

    /* Assignment perators. */
assignment_op           : ADD_ASSIGN                { $$ = ADD_ASSIGN_OP; }
                        | AND_ASSIGN                { $$ = AND_ASSIGN_OP; }
                        | ASSIGN                    { $$ = ASSIGN_OP; }
                        | DIV_ASSIGN                { $$ = DIV_ASSIGN_OP; }
                        | MOD_ASSIGN                { $$ = MOD_ASSIGN_OP; }
                        | MUL_ASSIGN                { $$ = MUL_ASSIGN_OP; }
                        | OR_ASSIGN                 { $$ = OR_ASSIGN_OP; }
                        | SHL_ASSIGN                { $$ = SHL_ASSIGN_OP; }
                        | SHR_ASSIGN                { $$ = SHR_ASSIGN_OP; }
                        | SUB_ASSIGN                { $$ = SUB_ASSIGN_OP; }
                        | XOR_ASSIGN                { $$ = XOR_ASSIGN_OP; }
                        ;

    /* Literals. */
literal                 : FALSE                             { $$ = bool_node(0); }
                        | TRUE                              { $$ = bool_node(1); }
                        | INT_LITERAL                       { $$ = int_node($1); }
                        | FLOAT_LITERAL                     { $$ = float_node($1); }
                        | CHAR_LITERAL                      { $$ = char_node($1); }
                        | STRING_LITERAL                    { $$ = string_node($1); }
                        ;

%%
