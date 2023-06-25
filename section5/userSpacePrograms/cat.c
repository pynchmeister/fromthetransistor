#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE * file;
    char ch;

    file = fopen(argv[1], "r");

    while((ch = fgetc(file)) != EOF)
        putchar(ch);

    fclose(file);

    return 0;
}
