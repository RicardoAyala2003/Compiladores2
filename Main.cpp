#include <iostream>
#include "SimpleLexer.hpp"
#include <fstream>
#include "Tokens.hpp"

int main()
{
    SimpleLexer lexer;

    for (Token token = static_cast<Token>(lexer.lex()); token != Token::EndOfFile; token = static_cast<Token>(lexer.lex()))
    {
        if (token == Token::Error)
        {
            std::cerr << "Error: Se ha encontrado un token no reconocido." << std::endl;
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
