%require "3.0"
%language "c++"

%parse-param { SimpleLexer& lexer }
%parse-param { std::unordered_map<std::string, int>& vars }

%define parse.trace
%define parse.error verbose
%define api.value.type variant
%define api.parser.class { Parser }
%define api.namespace { Expr }

%code requires {
    #include <unordered_map>
    class SimpleLexer;
}

%{
#include <iostream>
#include <stdexcept>
#include "SimpleLexer.hpp"
#include "error.h"

void yyerror(const char *s);

#define yylex(arg) lexer.nextToken(arg)

void yyerror(const char* msg);

namespace Expr {
    void Parser::error(const std::string& msg)
    {
        std::cerr << "Error de sintaxis: " << msg << '\n';
    }
}

void yyerror(const char* msg) {
    std::cerr << "Syntax error: " << msg << std::endl;
}
%}


%token EndOfFile         "EndOfFile"
%token Hex               "Hex"
%token Oct               "Oct"
%token Dec               "Dec"
%token Bin               "Bin"

%token KW_CLASS          "class"
%token KW_INT            "int"
%token KW_VOID           "void"
%token KW_REF            "ref"
%token KW_IF             "if"
%token KW_ELSE           "else"
%token KW_WHILE          "while"
%token KW_RETURN         "return"
%token KW_PRINT          "print"
%token KW_READ           "read"

%token OP_ASSIGN         "="
%token OP_BOOL_OR        "||"
%token OP_BOOL_AND       "&&"
%token OP_BOOL_NOT       "!"
%token OP_EQUAL          "=="
%token OP_NOT_EQUAL      "!="
%token OP_LESS_THAN      "<"
%token OP_GREATER_THAN   ">"
%token OP_LESS_EQUAL     "<="
%token OP_GREATER_EQUAL  ">="

%token OP_ADD            "+"
%token OP_SUB            "-"
%token OP_MUL            "*"
%token OP_DIV            "/"
%token OP_MOD            "%"

%token OPEN_CURLY        "{"
%token CLOSE_CURLY       "}"
%token OPEN_PAR          "("
%token CLOSE_PAR         ")"
%token OPEN_BRACKET      "["
%token CLOSE_BRACKET     "]"
%token COMMA             ","
%token SEMICOLON         ";"
%token COMMENT           "comment"

%token<int> INT_CONST    "number"
%token<std::string> IDENTIFIER      "identifier"
%token<std::string> STRING_LITERAL  "string"
%token<std::string> CONSTANT        "constant"

%token ERROR             "error"

/* Declaración de tipos semánticos para las no terminales usadas en la gramática */
%type <int> expr term factor

%%

input:
      program
    | statement_list
    ;

    variable_decl_list:
  
    ;

method_decl_list:

    ;

program:
      KW_CLASS IDENTIFIER OPEN_CURLY variable_decl_list method_decl_list CLOSE_CURLY
    ;


statement:
      expr { std::cout << "Resultado: " << $1 << '\n'; }
    ;

statement_list:
      statement_list statement SEMICOLON
    | statement SEMICOLON
    ;

expr:
      expr OP_ADD term { $$ = $1 + $3; }
    | expr OP_SUB term { $$ = $1 - $3; }
    | term            { $$ = $1; }
    ;

term:
      term OP_MUL factor { $$ = $1 * $3; }
    | term OP_DIV factor {
          if ($3 == 0) {
              yyerror("Division by zero");
              YYABORT;
          } else {
              $$ = $1 / $3;
          }
      }
    | factor { $$ = $1; }
    ;

factor:
      INT_CONST { $$ = $1; }
    | OPEN_PAR expr CLOSE_PAR { $$ = $2; }
    | IDENTIFIER {
          auto it = vars.find($1);
          if (it == vars.end()){
              yyerror(("Unknown Variable " + $1).c_str());
              YYABORT;
          } else {
              $$ = it->second;
          }
      }
    ;

%%
