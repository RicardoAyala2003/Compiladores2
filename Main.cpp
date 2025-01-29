#include <iostream>
#include <fstream>
#include "SimpleLexer.hpp"
#include "Tokens.hpp"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        std::cerr << "Error: Argumentos inválidos" << std::endl;
        return 1;
    }

    std::ifstream in(argv[1]);

    if (!in) {
        std::cerr << "Error: No se pudo abrir el archivo " << argv[1] << std::endl;
        return 1;
    }

    SimpleLexer lexer(in);
    Token token = lexer.nextToken();

    std::cout << "Token: " << lexer.tokenToString(token) << std::endl;

    while (token != Token::EndOfFile) {
        token = lexer.nextToken();
        std::cout << "Tokens: " << lexer.tokenToString(token) << std::endl;

        if (token == Token::Error) {
            std::cerr << "Error: Token no reconocido" << std::endl;
        }
    }

    return 0;
}
