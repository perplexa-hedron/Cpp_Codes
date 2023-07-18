#include <stdio.h>
struct employee{
    int id;
    char name[10];
    int salary;
} emp1, emp2;

int main()
{
    printf("Enter the id of Employee 1:\n");
    scanf("%d", &emp1.id);
    printf("Enter the salary of Employee 1: \n");
    scanf("%d", &emp1.salary);
    printf("Enter the name 1: \n");
    scanf("%s", &emp1.name);

    printf("Enter the id of Employee 2:\n");
    scanf("%d", &emp2.id);
    printf("Enter the salary of Employee 2: \n");
    scanf("%d", &emp2.salary);
    printf("Enter the name 2: \n");
    scanf("%s", &emp2.name);
    
    printf("%d %s %d \n",emp1.id,emp1.name,emp1.salary);
    printf("%d %s %d",emp2.id,emp2.name,emp2.salary);
    return 0;
    
}