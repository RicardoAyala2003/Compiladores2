#ifndef TOKENS_HPP
#define TOKENS_HPP

enum Token
{
    INT_CONST,
    STRING_LITERAL,
    CONSTANT,
    IDENTIFIER,

    EndOfFile,
    Error,

    Hex,
    Oct,
    Dec,
    Bin,

    KW_CLASS,
    KW_INT,
    KW_VOID,
    KW_REF,
    KW_IF,
    KW_ELSE,
    KW_WHILE,
    KW_RETURN,
    KW_PRINT,
    KW_READ,

    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,

    OP_ASSIGN,
    OP_EQUAL,
    OP_NOT_EQUAL,
    OP_LESS_THAN,
    OP_GREATHER_THAN,
    OP_LESS_EQUAL,
    OP_GREATHER_EQUAL,

    OP_BOOL_OR,
    OP_BOOL_AND,
    OP_BOOL_NOT,

    OPEN_CURLY,
    CLOSE_CURLY,
    OPEN_PAR,
    CLOSE_PAR,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    COMMA,
    SEMICOLON
};

const char *tokenToString(Token token);

#endif

