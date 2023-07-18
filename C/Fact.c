#include <stdio.h>
int main()
{
   unsigned long long int n,i,fact=1;
    printf("Enter the number for factorial");
    scanf("%lld",&n);
    if(n>0){
        for(i=1;i<=n;i++)
        {
            fact=fact*i;

        }
        printf("The factorial of %lld is %lld",n,fact);
    }
    else{
        printf("Factorial is 1");

    }

}