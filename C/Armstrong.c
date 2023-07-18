#include <stdio.h>
#include <math.h>
int main()
{
    int n,i=1,x,sum=0;
    printf("Enter the number: ");
    scanf("%d",&n);
    x=n;
    while(i!=0)
    {
        i=n%10;
        n=n/10;
        sum=sum+round(pow(i,3));
        printf("%d %d\n",sum,n);
    }
    if(sum==x)
    {
        printf("%d is Armstrong number");
    }
    else{
        printf("Not Armstrong");
    }

}