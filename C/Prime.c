#include <stdio.h>
#include <math.h>
int main()
{
    int x, i;
    printf("Enter the number: ");
    scanf("%d",&x);
    for(i=2;i<x;i++)
    {
      
      if(x%i==0)
      {
          printf("Number is not prime");
          break;
      }
    }
    if(i==x){
        printf("Number is prime");
      }

}
