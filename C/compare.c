#include <stdio.h>
#include <string.h>
int compare_str(char arr1[], char arr2[])
{
    int i = 0;
    int count = 0;
    if(strlen(arr1) > strlen(arr2) || strlen(arr1) < strlen(arr2)){
        count = 0;
        return count;
    }
    while(arr1[i] != '\0' && arr2[i] != '\0')
    {
        if(arr1[i] == arr2[i])
        {
            count = 1;
            i++;
        }
        else{
            count = 0;
            break;
        }
        i++;
    }
    return count;
}
int main()
{
    char arr2[200];
    char arr1[200];
    printf("Enter the string 1 \n");
    scanf("%s", arr1);
    printf("Enter the string 2 \n");
    scanf("%s", arr2);
    int result = compare_str(arr1,arr2);
    if(result)
    {
        printf("Given strings are same");
    }
    else{
        printf("Strigs are not same");
    }
}