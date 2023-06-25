#include <stdio.h> 
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(argv[1]);

    while ((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);

    closeddir(dir);

    return 0;
}
