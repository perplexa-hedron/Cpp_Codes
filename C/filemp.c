#include <stdio.h>
#include <stdlib.h>
int main()
{
   FILE *ptr;
   ptr = fopen("file_emp.txt", "w");
   fprintf(ptr, "ID NAME SALARY\n");
   int id, salary;
   char name[10];
   for (int i = 0; i < 5; i++)
   {
      printf("\nEnter the id of employee %d:", i + 1);
      scanf("%d", &id);
      printf("\nEnter the name of employee %d:", i + 1);
      scanf("%s", name);
      printf("\nEnter the salary of employee %d:", i + 1);
      scanf("%d", &salary);
      fprintf(ptr, "%d %s %d\n", id, name, salary);
   }
   fclose(ptr);
   return 0;
}