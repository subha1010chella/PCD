#include <stdio.h>
#include <string.h>

struct symbol {
    char name[10];
    char type[10];
    int size;
};

char *types[] = {"int", "float", "long", "double", "short"}; 
int sizes[] = {2, 4, 8, 8, 2};

int main() {
    FILE *fp = fopen("out.c", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    printf("\nSymbol table maintenance\n");
    printf("\n\tVariable\tType\t\tSize\n");

    struct symbol st[50];
    int sp = 0;
    char line[100], *token;

    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " ");
        if (token == NULL)
            continue;

        int i;
        for (i = 0; i < 5; i++) {
            if (strcmp(token, types[i]) == 0) {
                token = strtok(NULL, ",");
                while (token != NULL) {
                    struct symbol sym;
                    strcpy(sym.name, token);
                    strcpy(sym.type, types[i]);
                    sym.size = sizes[i];
                    st[sp++] = sym;

                    printf("%10s\t%10s\t%10d\n", sym.name, sym.type, sym.size);

                    token = strtok(NULL, ",");
                }
                break;
            }
        }
    }

    fclose(fp);

    for (int i = 0; i < sp - 1; i++) {
        for (int j = i + 1; j < sp; j++) {
            if (strcmp(st[i].name, st[j].name) == 0) {
                printf("\nMultiple Declaration for %s\n", st[i].name);
            }
        }
    }

    return 0;
}
