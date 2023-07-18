#include <stdio.h>
#include <math.h>
int main()
{
    int x,y,z;
    printf("Enter the marks ");
    scanf("%d",x);
    if (x==100)
    {
        y=1;
    }
    else if(x>=90&&x<100)
    {
        y=2;
    }
    else if(x>=80&&x<90)
    {
        y=3;
    }
    else if(x>=70&&x<80)
    {
        y=4;
    }
    else if(x>=60&&x<70)
    {
        y=5;
    }
    else if(x>=50&&x<60)
    {
        y=6;
    }
    else if(x>=40&&x<50)
    {
        y=7;
    }
    else if(x<40&&x>=0){
        y=8;
    }
    switch(y)
    {
        case 1: printf("E");
            break;
        case 2: printf("O");
            break;
        case 3: printf("A+");
            break;
        case 4: printf("A");
            break;
        case 5: printf("B");
            break;
        case 6: printf("C");
            break;
        case 7: printf("D");
            break;
        case 8: printf("F");
            break;
        default: printf("Entered number is not valid");
            break;

    }
}