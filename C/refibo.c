#include <stdio.h>
void fibo(int a, int b, int n)
{
    
    if(n == 0)
    {
        return ;
    }


    printf("%d\n", a);
    int c = a + b;
    fibo(b, c, n-1);


}
int main()
{
    int n, a = 0, b =1;
    printf("Enter the limit\n");
    scanf("%d", &n);
    fibo(a, b, n);
    return 0;
}