#include <stdio.h>
int perfect(int n)
{
    int sum = 0;
    for(int i = 1; i <= n/2; i++)
    {
        if(n%i == 0)
        {
            sum+=i;
        }
    }
    if(sum == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int prime(int n)
{
    int cond = 0,i;
    for(i = 2; i < n; i++)
    {
        if(n%i == 0)
        {
            cond = 0;
            return cond;
        }
    }
    if(i == n)
    {
        cond = 1;
        return cond;
    }
}
int main()
{
    int n;
    printf("Enter the number: ");               
    scanf("%d", &n);
    if(prime(n))                                
    {                               
        printf("Number is Prime");
    }
    else{
        if(perfect(n))
        {
            printf("Given is a perfect number");
        }
        else
        {
            printf("Number is neither Prime nor Perfect");
        }
    }
    return 0;
}