cmake_minimum_required(VERSION 3.10)
project(SimpleLexer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Reflex REQUIRED)
find_package(BISON REQUIRED)


BISON_TARGET(SimpleParser SimpleParser.y ${CMAKE_BINARY_DIR}/SimpleParser.cpp
            DEFINES_FILE ${CMAKE_BINARY_DIR}/SimpleParser.hpp
)

add_custom_command(
    OUTPUT Tokens.hpp SimpleLexer.cpp SimpleLexer.hpp 
    COMMAND Reflex::Reflex -o SimpleLexer.cpp --header-file=SimpleLexer.hpp ${CMAKE_SOURCE_DIR}/SimpleLexer.l
    DEPENDS ${CMAKE_SOURCE_DIR}/SimpleLexer.l
    COMMENT "Generating lexer source file with Reflex"
)



BISON_TARGET(SimpleParser SimpleParser.y ${CMAKE_BINARY_DIR}/SimpleParser.cpp
            DEFINES_FILE ${CMAKE_BINARY_DIR}/SimpleParser.hpp
)

add_executable(${PROJECT_NAME} Tokens.hpp 
                               SimpleLexer.cpp 
                               SimpleLexer.hpp 
                               SimpleParser.cpp
                               SimpleParser.hpp 
                               Main.cpp)


target_link_libraries(${PROJECT_NAME} PRIVATE Reflex::ReflexLibStatic)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR} 
                                           PRIVATE ${CMAKE_SOURCE_DIR})

