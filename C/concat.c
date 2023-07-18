#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{ 
    char arr1[200], arr2[200];
    int i=0, j=0;
    printf("Enter the first string: \t");
    scanf("%s", arr1);
    printf("Enter the second string: \t");
    scanf("%s", arr2);
    
    while (arr1[i] != '\0')
    {
        ++i;
    }

    while (arr2[j] != '\0')
    {
        arr1[i] = arr2[j];
        ++i;
        ++j;
    }
    
    for (j = 0; j < i; ++j)
    {
        printf ("%c", arr1[j]);
    }
    return 0;
}