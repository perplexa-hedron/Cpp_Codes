#include <stdio.h>
#include <math.h>
int main()
{
    int n,x,y;
    printf("Enter the number: ");
    scanf("%d",&n);
    x=n;
    while(x!=0){
        y=x%10;
        x=x/10;
        printf("%d",y);
    }
    return(0);
}