#include<stdio.h>
#include<math.h>
int main()
{
    int m1[3][3], m2[3][3], sum[3][3]={0};
    printf ("Enter the first matrix : \n");
    for (int i=0; i<3; i++) 
    {
        for (int j=0; j<3; j++)
        {
            scanf (" %d", &m1[i][j]);
        }
    }
    printf ("Enter the second matrix : \n");
    for (int i=0; i<3; i++) 
    {
        for (int j=0; j<3; j++)
        {
            scanf (" %d", &m2[i][j]);
        }
    }
    for (int i=0; i<3; i++) 
    {
        for (int j=0; j<3; j++)
        {
          sum[i][j]=m1[i][j] + m2[i][j];
        }
    }
    for (int i=0; i<3; i++) 
    {
        for (int j=0; j<3; j++)
        {
            printf (" %d", sum[i][j]);
        }
     printf ("\n");
    }
    return 0;

    
}