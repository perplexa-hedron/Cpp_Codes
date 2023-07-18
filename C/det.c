#include <stdio.h>
int main(){
    int m[3][3],det=0;
    printf ("Enter the matrix: ");
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++){
            scanf ("%d", &m[i][j]);
        }
    }
    for (int i=0;i<3;i++){
        det+=m[0][i]*((m[1][(i+1)%3]*m[2][(i+2)%3])-(m[1][(i+2)%3]*m[2][(i+1)%3]));
    }
    printf("Determinant of the given matrix is: %d", det);
}