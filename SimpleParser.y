%require "3.0"
%language "c++"
%parse-param {SimpleLexer& lexer}
%parse-param {Ast::Node *&root}
%define parse.trace

%define parse.error verbose
%define api.value.type variant
%define api.parser.class {Parser}
%define api.namespace {Expr}

%code requires {
    #include <unordered_map>
    #include "ExprAst.hpp"
    class SimpleLexer;
}

%{
#include <iostream>
#include <stdexcept>
#include "SimpleLexer.hpp"
#include "error.h"
#include "Tokens.hpp"


int yylex();
void yyerror(const char *s);

#define yylex(arg) (lexer.nextToken(arg) ? : 0) // Retorna 0 si falla

void yyerror(const char* msg);

namespace Expr {
    void Parser::error (const std::string& msg)
    {
        std::cerr << "Error de sintaxis: " << msg << '\n';
    }
}

void yyerror(const char* msg) {
    std::cerr << "Syntax error: " << msg << std::endl;
}

%}


%token OP_ADD "+"
%token OP_SUB "-"
%token OP_MUL "*"
%token OP_DIV "/"
%token OPEN_PAR CLOSE_PAR SEMICOLON
%token<int> INT_CONST "number"
%token<std::string> IDENTIFIER "identifier"
%token ERROR "unknown"

%type <Ast::Node *> statement_list statement expr term factor

%%

input:
      statement_list SEMICOLON {
            root = new Ast::Program($1);
            std::cout << "Análisis exitoso: programa válido." << std::endl;
      }
    | /* entrada vacía */ {
            root = nullptr;
            yyerror("Entrada vacía detectada");
      }
;

statement:
      expr { $$ = $1; }
;

statement_list:
      statement_list SEMICOLON statement {
            if ($1 && $3) {
                $$ = new Ast::LineSeq($1, $3);
            } else {
                yyerror("Nodo nulo en statement_list");
                $$ = nullptr;
            }
        }
    | statement { 
            if ($1) {
                $$ = new Ast::LineSeq($1, nullptr); 
            } else {
                yyerror("Nodo nulo en statement_list simple");
                $$ = nullptr;
            }
        }
;

expr:
      expr OP_ADD term { 
            $$ = new Ast::AddExpr($1, $3); 
        }
    | expr OP_SUB term { 
            $$ = new Ast::SubExpr($1, $3); 
        }
    | term             { 
            $$ = $1; 
        }
;

term:
      term OP_MUL factor { 
            $$ = new Ast::MulExpr($1, $3); 
        }
    | term OP_DIV factor {
            $$ = new Ast::DivExpr($1, $3);
        } 
    | factor { 
            $$ = $1; 
        }
;

factor:
      INT_CONST {
          std::cout << "num: " << $1 << std::endl;
          $$ = new Ast::Number($1);
      }
    | OPEN_PAR expr CLOSE_PAR {
          std::cout << "par" << std::endl;
          if ($2 == nullptr) {
              yyerror("Expresión nula dentro de paréntesis");
              $$ = nullptr;
          } else {
              $$ = $2;
          }
      }
    | IDENTIFIER {
          std::cout << "ident: " << $1 << std::endl;
          $$ = new Ast::Identifier($1);
      }
;

%%