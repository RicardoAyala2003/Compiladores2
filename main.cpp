#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "ExprAst.hpp"
#include "SimpleLexer.hpp"
#include "SimpleParser.hpp"

namespace Ast
{
    class Node;
}

int main(int argumentCount, char *argumentValues[])
{
    if (argumentCount != 2)
    {
        std::cerr << "Error: Se esperaba un archivo de entrada como argumento." << std::endl;
        return 1;
    }
    std::ifstream inputFile;
    inputFile.open(argumentValues[1]);
    std::unordered_map<std::string, variables> variableStore;
    std::unordered_map<std::string, methodVariable> methodStore;
    std::unordered_map<std::string, arrayVariables> arrayStore;
    std::unordered_map<std::string, std::string> textStore;
    std::vector<std::string> argumentList;
    int parameterPosition = 0;
    SimpleLexer lexerInstance(inputFile);
    Ast::Node *syntaxTreeRoot = nullptr;
    Expr::Parser parserInstance(lexerInstance, syntaxTreeRoot);

    try
    {
        parserInstance.parse();
        CodegenResult compilationResult = exprCompile(
            syntaxTreeRoot,
            variableStore,
            methodStore,
            argumentList,
            arrayStore,
            "",
            textStore,
            parameterPosition
        );
        std::cout << compilationResult.code << std::endl;
    }
    catch (const std::runtime_error &error){
        std::cerr << "Error: " << error.what() << std::endl;
        return 1;
    }
    inputFile.close();
    return 0;
}