%{
#include <stdio.h>
int a_count = 0;
int b_count = 0;
%}

%%
a { a_count++; }
b {
    if (a_count > 0) {
        b_count++;
        a_count--;
    }
    else {
        printf("Invalid input: b should not appear before a\n");
        exit(1);
    }
}
. { printf("Invalid input: Only 'a' and 'b' are allowed\n"); exit(1); }
%%

int main() {
    yylex();
    if (a_count == 0 && b_count > 0) {
        printf("Accepted\n");
    }
    else {
        printf("Rejected\n");
    }
    return 0;
}
