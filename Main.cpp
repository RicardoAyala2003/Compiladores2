#include <iostream>
#include <fstream>
#include "SimpleLexer.hpp"
#include "Tokens.hpp"

void processTokens(SimpleLexer &lexer) {
    Token token;

    
    while ((token = lexer.nextToken()) != Token::EndOfFile) {
        std::cout << "Token: " << lexer.tokenToString(token) << std::endl;

        if (token == Token::Error) {
            std::cerr << "Error: Token no reconocido" << std::endl;
        }
    }
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        std::cerr << "Error: Uso correcto: " << argv[0] << " <archivo>" << std::endl;
        return 1;
    }

   
    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "Error: No se pudo abrir el archivo " << argv[1] << std::endl;
        return 1;
    }

    SimpleLexer lexer(in);

   
    processTokens(lexer);

    return 0;
}
