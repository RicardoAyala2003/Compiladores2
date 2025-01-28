
#ifndef TOKENS_HPP
#define TOKENS_HPP

enum Token
{
    EndOfFile = 0,
    Error,
    Hex,
    Oct,
    Dec,
    Bin
};

const char *tokenToString(Token token);

#endif


//cambio para ver si es este 
