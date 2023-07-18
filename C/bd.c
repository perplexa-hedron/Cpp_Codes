#include <stdio.h>
#include <math.h>
int main()
{
    int n,x=0,y=0,z=1;
    printf("Enter The number: ");
    scanf("%d",&n);
    while(n!=0){
        x=n%2; 
        n=n/2;
        y=y+(x*z);
        z=z*10;

    }
    printf("%d",y);
    
}