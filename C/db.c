#include <stdio.h>
#include <math.h>
int main()
{
    long int n,x=0,y=0,z=0;
    printf("Enter The number: ");
    scanf("%d",&n);
    while(n!=0){
        x=n%10; 
        if(x!=0)
        {
            y=y+(pow(2,z));
        }
        n=n/10;
        z++;
    }
    printf("%d",y);
    
}