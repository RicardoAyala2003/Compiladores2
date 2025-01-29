%option lexer="SimpleLexer"
%option lex="nextToken"
%option token-type = "Token"

%{
#include <iostream>
#include "SimpleLexer.hpp"
#include "Tokens.hpp"
%}

%top{
#include "Tokens.hpp"
}

%class{
public:
    static const char *tokenToString(Token token) {
        switch (token) {
            case Token::EndOfFile: return "EndOfFile";
            case Token::Error: return "Error";
            case Token::Hex: return "Hex";
            case Token::Oct: return "Oct";
            case Token::Dec: return "Dec";
            case Token::Bin: return "Bin";
            case Token::KW_CLASS: return "KW_CLASS";
            case Token::KW_INT: return "KW_INT";
            case Token::KW_VOID: return "KW_VOID";
            case Token::KW_REF: return "KW_REF";
            case Token::KW_IF: return "KW_IF";
            case Token::KW_ELSE: return "KW_ELSE";
            case Token::KW_WHILE: return "KW_WHILE";
            case Token::KW_RETURN: return "KW_RETURN";
            case Token::KW_PRINT: return "KW_PRINT";
            case Token::KW_READ: return "KW_READ";
            case Token::OP_ASSIGN: return "OP_ASSIGN";
            case Token::OP_BOOL_OR: return "OP_BOOL_OR";
            case Token::OP_BOOL_AND: return "OP_BOOL_AND";
            case Token::OP_BOOL_NOT: return "OP_BOOL_NOT";
            case Token::OP_EQUAL: return "OP_EQUAL";
            case Token::OP_NOT_EQUAL: return "OP_NOT_EQUAL";
            case Token::OP_LESS_THAN: return "OP_LESS_THAN";
            case Token::OP_GREATHER_THAN: return "OP_GREATHER_THAN";
            case Token::OP_LESS_EQUAL: return "OP_LESS_EQUAL";
            case Token::OP_GREATHER_EQUAL: return "OP_GREATHER_EQUAL";
            case Token::OP_ADD: return "OP_ADD";
            case Token::OP_SUB: return "OP_SUB";
            case Token::OP_MUL: return "OP_MUL";
            case Token::OP_DIV: return "OP_DIV";
            case Token::OP_MOD: return "OP_MOD";
            case Token::IDENTIFIER: return "IDENTIFIER";
            case Token::INT_CONST: return "INT_CONST";
            case Token::STRING_LITERAL: return "STRING_LITERAL";
            case Token::CONSTANT: return "CONSTANT";
            case Token::OPEN_CURLY: return "OPEN_CURLY";
            case Token::CLOSE_CURLY: return "CLOSE_CURLY";
            case Token::OPEN_PAR: return "OPEN_PAR";
            case Token::CLOSE_PAR: return "CLOSE_PAR";
            case Token::OPEN_BRACKET: return "OPEN_BRACKET";
            case Token::CLOSE_BRACKET: return "CLOSE_BRACKET";
            case Token::COMMA: return "COMMA";
            case Token::SEMICOLON: return "SEMICOLON";
            default: return "Unknown";
        }
    }
};

%%


[ \t\r\n]+                { }
#.*                       { }


0[xX][0-9a-fA-F]+         { return Token::Hex; }
0[0-7]+                   { return Token::Oct; }
[1-9][0-9]*               { return Token::Dec; }
0[bB][0-1]+               { return Token::Bin; }


class                      { return Token::KW_CLASS; }
int                        { return Token::KW_INT; }
void                       { return Token::KW_VOID; }
ref                        { return Token::KW_REF; }
if                         { return Token::KW_IF; }
else                       { return Token::KW_ELSE; }
while                      { return Token::KW_WHILE; }
return                     { return Token::KW_RETURN; }
print                      { return Token::KW_PRINT; }
read                       { return Token::KW_READ; }


=                          { return Token::OP_ASSIGN; }
\|\|                       { return Token::OP_BOOL_OR; }
\&\&                       { return Token::OP_BOOL_AND; }
!                          { return Token::OP_BOOL_NOT; }
==                         { return Token::OP_EQUAL; }
!=                         { return Token::OP_NOT_EQUAL; }
<                          { return Token::OP_LESS_THAN; }
>                          { return Token::OP_GREATHER_THAN; }
<=                         { return Token::OP_LESS_EQUAL; }
>=                         { return Token::OP_GREATHER_EQUAL; }
\+                         { return Token::OP_ADD; }
\-                         { return Token::OP_SUB; }
\*                         { return Token::OP_MUL; }
\/                         { return Token::OP_DIV; }
\%                         { return Token::OP_MOD; }


[a-zA-Z_][a-zA-Z0-9_]*     { return Token::IDENTIFIER; }
[0-9]+                     { return Token::INT_CONST; }
string                     { return Token::STRING_LITERAL; }
[0-9]+                     { return Token::CONSTANT; }


\{                         { return Token::OPEN_CURLY; }
\}                         { return Token::CLOSE_CURLY; }
\(                         { return Token::OPEN_PAR; }
\)                         { return Token::CLOSE_PAR; }
\[                         { return Token::OPEN_BRACKET; }
\]                         { return Token::CLOSE_BRACKET; }
,                          { return Token::COMMA; }
;                          { return Token::SEMICOLON; }


<<EOF>>                    { return Token::EndOfFile; }
.                          { return Token::Error; }

%%
