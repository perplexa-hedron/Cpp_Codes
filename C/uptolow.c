#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{ 
    char str[100];
    printf("Enter a string : ");
    scanf("%s",str);
    int i = 0;
    while (str[i] != '\0'){
        if(str[i] >= 'a' && str[i] <= 'z') {
             str[i] = str[i] - 32;
            }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32 ;
        }
        i++;
    }
    printf("\nString in tOGGLE Case = %s", str);
    return 0;
}