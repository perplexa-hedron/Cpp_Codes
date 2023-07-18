#include<stdio.h>
int main()
{
    int m,n,a,b;
    printf("Enter the dimesion of matrix a1: ");
    scanf("%d %d",&m,&n);
    printf("Enter the dimesion of matrix a2: ");
    scanf("%d %d",&a,&b);
    if(n==a){
        int a1[m][n], a2[a][b], pd[3][3]={0};
            printf ("Enter the first matrix: ");
            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++){
                    scanf ("%d", &a1[i][j]);
                }
            }
            printf ("Enter the second matrix: ");
            for (int i=0; i<a; i++){
                for (int j=0; j<b; j++){
                    scanf ("%d", &a2[i][j]);
                }
            }
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    for (int k=0; k<a; k++){
                        pd[i][j]+= a1[i][k] * a2[k][j];
                    }
                }
            }
        for (int i=0; i<n; i++){
            for (int j=0; j<a; j++){
                printf (" %d", pd[i][j]);
            }
            printf ("\n");
        }
    }
    else{
        printf("Can't be multiplied");
    }
    
    return 0;
}