#include<stdio.h>
#include<math.h>
int main()
{
    int y,sum1=0;
    printf("Enter your number: ");
    scanf("%d",&y);
    int x=y;
    while(x!=0)
    {
        sum1=sum1+x%10;
        x=x/10;
    }
    printf("Sum of the digits of %d is %d",y,sum1);
}