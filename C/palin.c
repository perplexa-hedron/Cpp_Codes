#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char str[20],ans;
    printf("enter the string :");
    scanf("%s", str);
   
    for(int i=0, j=strlen(str)-1;i<=j;i++,j--){
        if(str[i]==str[j]){
            ans=1;
        }
        else{
            ans=0;
            break;
        }
    }
   if(ans==1){
       printf("the string is pallindrome ");
    }
    else{
       printf("the string is not a pallindrome ");
    }
   

    return 0;
}