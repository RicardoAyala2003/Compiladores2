%option lexer="SimpleLexer"

%{
#include <iostream>
#include "SimpleLexer.hpp"

int num_lines = 0;
int num_chars = 0;
%}

%class{

public:
	int num_lines = 0;
	int num_chars = 0;

%}

%%

\n { num_lines++; num_chars++;}
.  { num_chars++;}

%%

