#include <stdio.h>
#include <string.h>
int main()
{
    char arr[200];
    int i = 0,count = 0;
    printf("Enter the string: ");
    scanf("%s", arr);
    while(arr[i] != '\0')
    {
        count++;
        i++;
    }
    printf("Length of the string is: %d", count);
    return 0;
}