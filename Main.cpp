#include <iostream>
#include <fstream>
#include "SimpleLexer.hpp"
#include "Tokens.hpp"

int main(int argc, char *argv[])
{
    // Verificar si se proporcionó exactamente un argumento
    if (argc != 2)
    {
        std::cerr << "Error: Argumentos inválidos" << std::endl;
        return 1;
    }

    // Abrir el archivo especificado en los argumentos
    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: No se pudo abrir el archivo" << std::endl;
        return 1;
    }

    // Crear una instancia del lexer
    SimpleLexer lexer(inputFile);
    Token token;

    // Procesar tokens
    while (true)
    {
        token = static_cast<Token>(lexer.nextToken());
        if (token == Token::EndOfFile)
        {
            break;
        }
        if (token == Token::Error)
        {
            std::cerr << "Error: Token no reconocido" << std::endl;
            return 1;
        }
    }

    return 0;
}
