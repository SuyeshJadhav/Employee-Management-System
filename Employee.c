#include <stdio.h>
#include <stdlib.h>

void addEmployee();

struct employee
{
      int age, salary, id, experience;
      char fname[20];
      char lname[20];
      struct employee *next;
} * head;

typedef struct employee employee;

int main()
{
      head = NULL;
      return 0;
}

void addEmployee()
{
      employee *newEmp = (employee *)malloc(sizeof(employee));
      printf("Enter the FirstName: ");
      scanf("%s", &newEmp->fname);

      printf("Enter the LastName: ");
      scanf("%s", &newEmp->lname);

      printf("Enter the age: ");
      scanf("%d", &newEmp->age);

      printf("Enter id: ");
      scanf("%d", &newEmp->id);

      printf("Enter salary: ");
      scanf("%d", &newEmp->salary);
}