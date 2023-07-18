#include <stdio.h>
int main() 
{
   int i,s,n,x=0;
   printf("Enter the number of rows: ");
   scanf("%d",&n);
   for (i=1;i<=n;++i,x=0)
   {
      for (s=1;s<=n-i;++s) 
      {
         printf("  ");
      }
      while (x!=2*i-1) 
      {
         printf("* ");
         ++x;
      }
      printf("\n");
   }
   return 0;
}