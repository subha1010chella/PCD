%{
#include <stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z0-9_]*   { printf("Identifier: %s\n", yytext); }
[0-9]+                  { printf("Integer: %s\n", yytext); }
[(){};,:]               { printf("Punctuation: %s\n", yytext); }
[+\-*/=<>]              { printf("Operator: %s\n", yytext); }
"\""[^\n\"]*\""         { printf("String: %s\n", yytext); }
"//"(.*)\n               { /* Ignore single-line comments */ }
"/*"([^*]|"*"+[^*/])*"*/" { /* Ignore multi-line comments */ }
[ \t\n]                 { /* Ignore whitespace */ }
.                       { printf("Invalid token: %s\n", yytext); }
%%

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: ./tokenizer <input_file>\n");
        return 1;
    }
    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }
    yyin = inputFile;
    yylex();
    fclose(inputFile);
    return 0;
}
