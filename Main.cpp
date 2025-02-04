#include <iostream>
#include "SimpleLexer.hpp"
#include "SimpleParser.hpp"
#include "Tokens.hpp"
#include <fstream>
#include <unordered_map>

int main(int argc, char *argv[])
{
    std::ifstream in;
    in.open(argv[1]);

    if (argc != 2)
    {
        std::cerr << "Error: Argumentos invalidos" << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> vars;
    vars.insert({{"a", 1}});

    SimpleLexer lexer(in);
    Expr::Parser::value_type yylval;
    Expr::Parser parser(lexer, vars);
 

    try
    {
        parser.parse();
        std::cout << "Success\n";
    }
    catch (const std::runtime_error &err)
    {
        std::cerr << err.what() << '\n';
        return 1;
    }

    return 0;
}