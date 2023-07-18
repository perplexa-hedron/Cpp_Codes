#include <stdio.h>
#include <sql.h>
#include <math.h>
int main()
{
    int x[3][3],y[3][3],z[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",x[i][j]);
            scanf("%d",y[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            z[i][j]=x[i][j]+y[i][j];
            printf("%d\t",z[i][j]);

        }
    }
}   