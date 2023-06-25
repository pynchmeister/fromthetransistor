#include <stdio.h> 

int main(int argc, char *argv[]) {
    int ret = remove(argv[1]);

    if(ret == 0)
        printf("File deleted successfully");
    else
        printf("Error: unable to delete the file");

    return 0;
}
