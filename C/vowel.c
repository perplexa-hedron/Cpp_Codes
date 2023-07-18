#include <stdio.h>
#include <string.h>
int main()
{
    char arr[200];
    int i = 0,count = 0;
    printf("Enter the string: \n");
    scanf("%s", arr);
    while(arr[i] != '\0')
    {
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
        {
            count++;
            i++;
        }
        else if(arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')
        {
            count++;
            i++;
        }
        i++;
    }
    printf("Number of vowels are: %d", count);
}