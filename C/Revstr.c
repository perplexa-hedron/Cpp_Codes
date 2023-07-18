#include <stdio.h>
#include <string.h>
int str_len(char arr[])
{
    int i = 0,count = 0;
    scanf("%s", arr);
    while(arr[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
int main()
{
    char arr[200];
    scanf("%s", arr);
    int l = str_len(arr)-1;
    for(int i = 0;i<=l;i++,l--)
    {
        char temp =arr[i];
        arr[i] = arr[l];
        arr[l] = temp;
    }
    printf("%s \n", arr);
    return 0;
}