#include <stdio.h>
#include<string.h>
int main()
{
    char a[10],ch;
    int i=0;
    scanf("%s",a);
    printf ("Enter the char to search\n");
    scanf (" %c",&ch);
    while(a[i] != '\0'){
        if(a[i]==ch){
            printf("Ahh yes Found It at %d", i);
        }
        i++;
    }
    return 0;
}