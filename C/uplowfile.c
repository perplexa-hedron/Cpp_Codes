#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr = NULL;
    fptr = fopen("file.txt", "r");
    char str[100];
    fgets(str, 100, fptr);
    printf("%s\n", str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    fclose(fptr);
    fptr = fopen("copy.txt", "w");
    fputs(str, fptr);
    printf("Copying Successful ");
    return 0;
}