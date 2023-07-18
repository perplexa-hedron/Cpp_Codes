#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr = NULL;
    fptr = fopen("file.txt", "r");
    char c[100];
    fgets(c, 100, fptr);
    fclose(fptr);
    fptr = fopen("copied.txt", "w");
    fputs(c, fptr);
    printf("Copied Successfully");
    return 0;
}
