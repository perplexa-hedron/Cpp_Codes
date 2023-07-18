#include <stdio.h>
#include <math.h>
int main()
{
    int x,y=0,z=1,w;
    printf("Enter the limit: ");
    scanf("%d",&x);
    printf("\n%d %d ",y,z);
    for (int i=2;i<x;++i)
    {
        w=y+z;
        printf("%d ",w);
        y=z;
        z=w;
    }
    return(0);

}