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

// Declaramos la función de análisis léxico.
int yylex();

#define yylex(arg) lexer.nextToken(arg) 

namespace Expr {
    void Parser::error (const std::string& msg)
    {
       std::cerr << "Error: " << msg << " on line " << lexer.lineno() << '\n';
    }
}



void yyerror(const char* msg) {
     std::cerr << "Error: " << msg << " on line " << '\n';
}




%}

%type <Ast::Node *> program variable_decl_list variable_decl ident_list type array_optional
%type <Ast::Node *> method_decl_list method_decl method_type opt_param_decl_list param_list param_decl ref_optional
%type <Ast::Node *> stmt_list stmt
%type <Ast::Node *> term factor
%type <Ast::Node *> assign_stmt array_access return_stmt if_stmt else_optional block
%type <Ast::Node *> while_stmt call_stmt call_param_list call_param_rest print_stmt print_param read_stmt
%type <Ast::Node *> expression array_access_opt arithmetic_expression
%type <Ast::Node *> method_body variable_decl_Body varmethod_decl_list
%type <Ast::Node *> boolean_term boolean_expression boolean_factor relational_expression
%token<int> INT_CONST CONSTANT
%token<std::string> IDENTIFIER STRING_LITERAL 
%token EndOfFile Error Hex Oct Dec Bin
%token KW_CLASS KW_INT KW_VOID KW_REF KW_IF KW_ELSE KW_WHILE KW_RETURN KW_PRINT KW_READ
%token OP_ASSIGN OP_BOOL_OR OP_BOOL_AND OP_BOOL_NOT OP_EQUAL OP_NOT_EQUAL OP_LESS_THAN OP_GREATER_THAN OP_LESS_EQUAL OP_GREATER_EQUAL
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD
%token OPEN_CURLY CLOSE_CURLY OPEN_PAR CLOSE_PAR OPEN_BRACKET CLOSE_BRACKET COMMA SEMICOLON COMMENT
%token ERROR 
%nonassoc LOWER_THAN_OPEN_PAR
%nonassoc OPEN_PAR
%nonassoc OP_EQUAL OP_NOT_EQUAL OP_LESS_THAN OP_GREATER_THAN OP_LESS_EQUAL OP_GREATER_EQUAL
%left OP_ADD OP_SUB
%left OP_MUL OP_DIV
%left OP_BOOL_OR
%left OP_BOOL_AND
%nonassoc OP_BOOL_NOT

%%


input: program { root = $1;}
;

program:
      KW_CLASS IDENTIFIER OPEN_CURLY varmethod_decl_list method_decl_list CLOSE_CURLY {
             $$ = new Ast::Program($2, $4, $5);
      }
      
;


varmethod_decl_list: 
      KW_INT IDENTIFIER method_body method_decl_list { 
         $$ =  new Ast::VarMethodDeclList(new Ast::MethodDeclList(new Ast::MethodDecl(new Ast::MethodType("INT"), $2, $3) , $4), nullptr);
      }
      |
      KW_INT IDENTIFIER method_body { 
         $$ = new Ast::VarMethodDeclList(new Ast::MethodDeclList(new Ast::MethodDecl(new Ast::MethodType("INT"), $2, $3) , nullptr), nullptr);     
      }
      |
      variable_decl variable_decl_list varmethod_decl_list{ 
        $$ = new Ast::VarMethodDeclList(new Ast::VariableDeclList($1, $2),  $3);
      }
      | variable_decl varmethod_decl_list{ 
        $$ = new Ast::VarMethodDeclList( new Ast::VariableDeclList($1, nullptr), $2);
      }
      |
      variable_decl variable_decl_list { 
        $$ = new Ast::VarMethodDeclList(new Ast::VariableDeclList($1, $2),  nullptr);
      }
      | variable_decl {
        $$ = new Ast::VarMethodDeclList(new Ast::VariableDeclList($1, nullptr),  nullptr);
      }
      | %empty {}
;

variable_decl_list:
      variable_decl variable_decl_list { 
        $$ = new Ast::VariableDeclList($1, $2);
      }
     | variable_decl {
      $$ = new Ast::VariableDeclList($1, nullptr);
      }
      | %empty {}
;

variable_decl_Body:
  ident_list SEMICOLON { 
      $$ = new Ast::VariableDecl_Body($1); 
      }    
;

variable_decl:
       KW_INT IDENTIFIER OPEN_BRACKET INT_CONST CLOSE_BRACKET variable_decl_Body {
            $$ = new Ast::VariableDecl(new Ast::Type("INT", new Ast::ArrayOptional($4)), $2, $6);
      }
      |  KW_INT IDENTIFIER variable_decl_Body {
            $$ = new Ast::VariableDecl(new Ast::Type("INT", nullptr), $2, $3);
       }
      
;

array_optional:
      OPEN_BRACKET INT_CONST CLOSE_BRACKET { 
            $$ = new Ast::ArrayOptional($2); 
      }
      | %empty {}
;

ident_list:
      COMMA IDENTIFIER ident_list { 
            $$ = new Ast::IdentList($2, $3); 
      }
      | %empty {}
;

type:
      KW_INT array_optional { 
            $$ = new Ast::Type("INT", $2); 
      }
      
;

method_decl_list:
      method_decl method_decl_list {
          $$ = new Ast::MethodDeclList($1, $2); 
       
      }
        | %empty {}
;

method_decl:
      method_type IDENTIFIER method_body{
        $$ = new Ast::MethodDecl($1, $2, $3);
      }
;

method_body: 
      OPEN_PAR opt_param_decl_list CLOSE_PAR OPEN_CURLY variable_decl_list stmt_list CLOSE_CURLY {
      $$ = new Ast::MethodDecl_Body($2, $5, $6); 
      }
;

method_type:
      KW_INT {     
            $$ = new Ast::MethodType("INT");
      }
    | KW_VOID { 
            $$ = new Ast::MethodType("VOID"); 
      }
;

opt_param_decl_list:
      param_decl param_list {  
         $$ = new Ast::OptParamDeclList($1, $2); 
      }
     | %empty {}
;

param_list:
      COMMA param_decl param_list {   
            $$ = new Ast::ParamList($2, $3);
      }
       | %empty {}
;

param_decl:
      ref_optional type IDENTIFIER {    
            $$ = new Ast::ParamDecl($1, $2, $3);
      }
;

ref_optional:
      KW_REF {   
            $$ = new Ast::RefOptional(true); 
      }
      | %empty {}
;

stmt_list:
      stmt stmt_list { 
         $$ = new Ast::StmtList($1, $2); 
      }
        | %empty {}
;

array_access:
      OPEN_BRACKET expression CLOSE_BRACKET { 
            $$ = new Ast::ArrayAccess($2);
           
      }
;

array_access_opt:
      array_access { $$ = $1; }
    | %empty {  }
;


assign_stmt:
      IDENTIFIER array_access_opt OP_ASSIGN expression SEMICOLON {
            $$ = new Ast::AssignStmt($1, $2, $4);
      }
;


call_stmt:
    IDENTIFIER OPEN_PAR call_param_list CLOSE_PAR SEMICOLON {
         $$ = new Ast::CallStmt($1, $3);
    }
;
stmt:
      call_stmt {
          $$ = $1;
      }
      |
      assign_stmt {
          $$ = $1;
      }
  
    | return_stmt {
          $$ = $1;
      }
    | if_stmt {   
          $$ = $1;
      }
    | while_stmt {  
          $$ = $1;
      }
    | print_stmt { 
          $$ = $1;
      }
    | read_stmt {  
          $$ = $1;
      }
;

return_stmt:
      KW_RETURN expression SEMICOLON {     
            $$ = new Ast::ReturnStmt($2); 
      }
;

if_stmt:
      KW_IF OPEN_PAR expression CLOSE_PAR block else_optional {   
            $$ = new Ast::IfStmt($3, $5, $6); 
      }
;

else_optional:
      KW_ELSE block { 
            $$ = new Ast::ElseOptional($2);
      }
      | %empty {}
;

block:
      OPEN_CURLY stmt_list CLOSE_CURLY {    
            $$ = new Ast::Block($2);
      }
;

while_stmt:
      KW_WHILE OPEN_PAR expression CLOSE_PAR block {        
            $$ = new Ast::WhileStmt($3, $5);
      }
;



call_param_list:
      expression call_param_rest {       
            $$ = new Ast::CallParamList($1, $2);
      }
      | %empty {}
;

call_param_rest:
      COMMA expression call_param_rest {          
            $$ = new Ast::CallParamRest($2, $3);
      }
       | %empty {}
;

print_stmt:
      KW_PRINT OPEN_PAR print_param CLOSE_PAR SEMICOLON {
     $$ = new Ast::PrintStmt($3); 
      }
;

print_param:
      expression {      
      $$ = new Ast::PrintParam($1, ""); 
      }
    | STRING_LITERAL {    
       $$ = new Ast::PrintParam(nullptr, $1);
   }
;

read_stmt:
      KW_READ OPEN_PAR IDENTIFIER CLOSE_PAR SEMICOLON {           
            $$ = new Ast::ReadStmt($3); 
      }
;

expression:
      boolean_expression {            
            $$ = $1; 
      }

boolean_expression:
      boolean_expression OP_BOOL_OR boolean_term { 
             $$ = new Ast::OrBoolean($1, $3);
        }
      | boolean_term {      
            $$ = $1;
      }
;


boolean_term: 
      boolean_term OP_BOOL_AND boolean_factor {            
            $$ = new Ast::AndBoolean($1, $3);
        }
      | boolean_factor {            
            $$ = $1;
        }
;

boolean_factor: 
      OP_BOOL_NOT boolean_factor {          
            $$ = new Ast::UnaryNotBoolean($2); 
        }
      | OPEN_PAR boolean_expression CLOSE_PAR {    
            $$ = $2;
        }
      | relational_expression {     
            $$ = $1; 
        }
;

arithmetic_expression:
      arithmetic_expression OP_SUB term {    
            $$ = new Ast::SubExpr($1, $3); 
        }
      | arithmetic_expression OP_ADD term {        
            $$ = new Ast::SumExpr($1, $3); 
        }
      | term {   
            $$ = $1; 
        }
;

relational_expression: 
             arithmetic_expression OP_EQUAL arithmetic_expression {                   
                  $$ = new Ast::EqualBoolean($1, $3);
            }
            | arithmetic_expression OP_NOT_EQUAL arithmetic_expression {      
                  $$ = new Ast::NEqualBoolean($1, $3);
            }
            | arithmetic_expression OP_LESS_THAN arithmetic_expression {                  
                   $$ = new Ast::Less_ThanBoolean($1, $3);
            }
            | arithmetic_expression OP_GREATER_THAN arithmetic_expression {                   
                   $$ = new Ast::Greater_ThanBoolean($1, $3);
            }
            | arithmetic_expression OP_LESS_EQUAL arithmetic_expression {                  
                   $$ = new Ast::LessEqualBoolean($1, $3);
            }
            | arithmetic_expression OP_GREATER_EQUAL arithmetic_expression {                  
                  $$ = new Ast::GreaterEqualBoolean($1, $3);
            }
      | arithmetic_expression {                    
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
      | term OP_MOD factor {           
            $$ = new Ast::ModExpr($1, $3); 
        } 
      | factor {      
            $$ = $1; 
        }
;

factor:

        OP_ADD factor {
            $$ = new Ast::UnaryAddExpr($2);
      }
      | OP_SUB factor {
            $$ = new Ast::UnarySubExpr($2); 
      }
      |
      INT_CONST { $$ = new Ast::Number($1);    
            $$ = new Ast::Number($1); 
      } 
      | OPEN_PAR arithmetic_expression CLOSE_PAR { $$ = $2; }
      | IDENTIFIER {
          $$ = new Ast::Identifier($1);  
      }
      | IDENTIFIER OPEN_PAR call_param_list CLOSE_PAR { 
            $$ = new Ast::FunctionCall($1, $3); 
        }
      | IDENTIFIER array_access {       
            $$ = new Ast::ArrayVariable($1, $2); 
        }
      
;
%%
