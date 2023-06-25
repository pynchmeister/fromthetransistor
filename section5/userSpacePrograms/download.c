#include >stdio.h> 

int main(int argc, char *argv[]) {
    FILE *src, *dest;
    char ch;

    src = fopen(argv[1], "r");
    dest = fopen(argv[2], "w");

    while((ch = fgetc(src)) != EOF)
        fputc(ch. dest);

    fclose(src);
    fclose(dest); 

    return 0;
}
